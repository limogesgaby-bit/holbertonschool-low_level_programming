# Memory maps — AI Memory Visualizer + Valgrind Tracer

> Brouillon à vérifier. Les adresses sont celles d'une exécution précise (ASLR) : elles changent à chaque lancement. Ce qui compte, ce sont les écarts entre adresses et les états mémoire.

## 1. Stack vs heap (distinction générale)

- **Pile (stack)** : variables locales et paramètres. Chaque appel de fonction crée une frame, détruite au retour. Durée de vie = durée de l'appel.
- **Tas (heap)** : blocs alloués par `malloc`. Durée de vie = jusqu'au `free` explicite, indépendamment des fonctions. Un pointeur vers le tas peut survivre à la frame qui le contient.

## 2. `stack_example.c`

### Frames observées

`walk_stack(depth, 3)` s'appelle récursivement de 0 à 3. Dans chaque frame de `walk_stack` : `marker = depth * 10`. `dump_frame` crée sa propre frame à chaque appel.

| depth | `&local_int` (enter) | `&marker` | `&local_buf` |
|---|---|---|---|
| 0 | 0x16cf7a908 | 0x16cf7a964 | 0x16cf7a918 |
| 1 | 0x16cf7a8c8 | 0x16cf7a924 | 0x16cf7a8d8 |
| 2 | 0x16cf7a888 | 0x16cf7a8e4 | 0x16cf7a898 |
| 3 | 0x16cf7a848 | 0x16cf7a8a4 | 0x16cf7a858 |

- Chaque niveau de récursion descend de **0x40 (64 octets)** : la pile croît vers les adresses basses.
- `marker` est dans la frame de `walk_stack` ; `local_int`, `local_buf` et `p_local` sont dans la frame de `dump_frame`, qui est créée au-dessous de celle de `walk_stack` du même niveau.

### Lignes `[exit]`

Les lignes `[exit]` ne relisent pas les anciennes variables de `[enter]`. `dump_frame("exit", depth)` crée de nouvelles variables locales à la même position dans la pile, donc mêmes adresses et mêmes valeurs (`100 + depth`, `'A' + depth`). `marker` n'a pas changé, car sa frame est encore vivante.

### Durées de vie

- `local_int`, `local_buf`, `p_local` : vivent pendant l'appel de `dump_frame`. `p_local` ne doit jamais être utilisé après le retour de `dump_frame`.
- `marker` : vit pendant tout l'appel de `walk_stack` correspondant.

### Aliasing

- `p_local` est un alias de `local_int` (même adresse). Modifier l'un modifie l'autre.

## 3. `heap_example.c`

### Allocations

`person_new` fait deux `malloc` :
1. la structure `Person` (pointeur `name` + `age`) ;
2. le tampon de `name`, de taille `len + 1` (le `\0` compte).

Exécution observée :
- `alice = 0x1053855c0`, `alice->name = 0x1053855d0` (16 octets plus loin)
- `bob = 0x1053855e0`, `bob->name = 0x1053855f0`

### Libérations dans `main`

- `free(bob->name)` puis `free(bob)` : correct, dans le bon ordre (libérer `bob` avant `bob->name` aurait lu un pointeur libéré).
- `person_free_partial(alice)` libère **seulement** la structure `alice`. Le tampon `alice->name` (6 octets : `Alice\0`) n'est jamais libéré.

### Fuite (volontaire)

- Bloc « definitely lost » attendu : **6 octets**, alloué dans `person_new`. À confirmer avec Valgrind.
- Cause : la propriété de `alice->name` est perdue, car plus aucun pointeur ne contient son adresse après la fin de `main`.

## 4. `aliasing_example.c`

### Allocation et alias

`make_numbers(5)` alloue 5 entiers et remplit `arr[i] = i * 11` : `0, 11, 22, 33, 44`.

```
main : a ──┐
           ├──► tas : [0][11][22][33][44]   (bloc de 5 int)
main : b ──┘
```

Sortie observée : `a=0x104d855c0 b=0x104d855c0 a[2]=22 b[2]=22`. `a` et `b` sont deux alias : `b = a` copie l'adresse, pas les données.

### Après `free(a)`

- Le bloc est rendu à l'allocateur. Propriétaire unique : `a`, qui vient d'être libéré. `b` contient toujours l'adresse : c'est un **pointeur pendant (dangling)**.
- `b[2]` : **lecture après libération** (comportement indéfini). La valeur affichée (`4`) est sans signification fiable.
- `b[3] = 1234` : **écriture après libération**. Peut corrompre les métadonnées de l'allocateur.

### Valgrind attendu (à vérifier)

- « Invalid read of size 4 » sur `b[2]`.
- « Invalid write of size 4 » sur `b[3]`.
- Section « Address ... is 8 bytes inside a block of size 20 free'd » : le bloc est libéré à `free(a)`.

## 5. `crash_example.c`

- `allocate_numbers(0)` retourne `NULL` (`n <= 0`). Cas valide.
- `main` n'en vérifie pas le retour. `nums[0] = 42` écrit à l'adresse `NULL + 0`, non mappée : `SIGSEGV`.
- Le programme s'arrête après `requesting n=0`. Le `free(nums)` n'est jamais atteint.
- Chaîne causale : `n = 0` → `allocate_numbers` retourne `NULL` → `nums` vaut `NULL` → écriture à l'adresse 0 → segmentation fault.

## 6. Erreurs de l'IA (à compléter par l'étudiant)

> Section obligatoire : au moins un cas où l'IA s'est trompée, expliqué et corrigé. Remplir **après** avoir généré la carte avec une IA et l'avoir comparée à ces observations.

- **Cas 1 :** _(à compléter : ce que l'IA a affirmé, pourquoi c'est faux, la correction)_

Exemple à vérifier avant de le retenir : l'IA affirme souvent que les lignes `[exit]` affichent d'anciennes valeurs de la pile, alors que `dump_frame` recrée ses variables à chaque appel.

## 7. Utilisation de l'IA

- Outil utilisé : _(à compléter)_
- Prompts : résumés dans le tableau ci-dessous.

Chaque affirmation de l'IA a été comparée à la sortie réelle du programme et au code source. Le verdict indique si l'affirmation est correcte, incomplète ou trompeuse.

| # | Prompt (résumé) | Affirmation de l'IA | Verdict | Correction et justification |
|---|---|---|---|---|
| 1 | Définir la pile | Une frame contient variables locales, paramètres et informations de retour. | Incomplet | La disposition exacte dépend du compilateur et de l'architecture ; certaines valeurs peuvent résider dans des registres. |
| 2 | Déterminer le sens de croissance | La pile croît vers les adresses basses. | Correct pour l'observation rapportée | Sur la plateforme utilisée, les adresses de `marker` diminuent pendant la récursion ; cette propriété ne se généralise pas à toutes les plateformes. |
| 3 | Interpréter l'écart de 48 octets | Cet écart représente la place d'une frame. | Trompeur | L'écart mesuré entre deux `marker` successifs est de **0x40 = 64 octets**, et non 48. Cet écart mesure le pas entre deux frames ; il ne prouve pas, à lui seul, la taille totale d'une frame. |
| 4 | Durée de vie de `dump_frame` | Sa frame disparaît avant l'appel récursif suivant. | Correct | `dump_frame("enter", 0)` retourne avant le début de `walk_stack(1)` ; cet espace peut être réutilisé. |
| 5 | Comprendre `b = a` | `b` pointe vers le même tableau que `a`. | Correct | L'affectation copie l'adresse et n'alloue aucun bloc supplémentaire. |
| 6 | Effet de `free(a)` | `b` devient un pointeur pendant. | Correct | Le tableau a été libéré ; les accès par `b` après `free(a)` ont un comportement indéfini. |
| 7 | Étudier la fuite du tas | Le nom d'Alice fuit sur six octets. | Correct pour le chemin normal | `person_free_partial` appelle `free(p)` sans `free(p->name)` ; la chaîne `"Alice\0"` occupe six octets. |