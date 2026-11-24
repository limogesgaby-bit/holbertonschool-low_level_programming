
## 1. Analyse de `heap_example.c`

### Objectif

Utiliser Valgrind pour identifier les fuites mémoire provoquées par les allocations dynamiques.

### Résultat de Valgrind

```text
in use at exit: 6 bytes in 1 blocks
definitely lost: 6 bytes in 1 blocks
ERROR SUMMARY: 1 errors from 1 contexts
```

Valgrind détecte une fuite mémoire de **6 octets**, correspondant aux cinq lettres de `"Alice"` et au caractère `\0`.

L'allocation concernée est signalée dans `person_new()` à la ligne 21 :

```c
p->name = (char *)malloc(len + 1);
```

### Origine de l'erreur

La fonction `person_free_partial()` libère la structure `Person`, mais pas la chaîne de caractères `p->name`.

La structure d'Alice est donc libérée, tandis que la mémoire contenant son prénom reste allouée et devient inaccessible.

À l'inverse, Bob est correctement libéré grâce aux deux appels :

```c
free(bob->name);
free(bob);
```

**Conclusion :** une structure contenant un pointeur vers une allocation dynamique nécessite de gérer séparément la libération de cette allocation.

## 2. Analyse de `aliasing_example.c`

### Objectif

Identifier les accès mémoire invalides provoqués par l'utilisation d'un pointeur après la libération du bloc qu'il désignait.

### Résultat de Valgrind

```text
Invalid read of size 4  : ligne 42
Invalid write of size 4 : ligne 44
Invalid read of size 4  : ligne 45

All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 3 errors from 3 contexts
```

Valgrind identifie trois accès invalides :

1. **Ligne 42 :** lecture de `b[2]` après libération.
2. **Ligne 44 :** écriture dans `b[3]` après libération.
3. **Ligne 45 :** nouvelle lecture de `b[3]` pour l'afficher.

Le bloc de **20 octets** avait été alloué dans `make_numbers()` à la ligne 12, puis libéré par `free(a)` à la ligne 38.

Comme `a` et `b` désignaient le même tableau, `b` devient un pointeur pendant après la libération.

**Conclusion :** aucune fuite mémoire n'est détectée, mais le programme contient trois erreurs de type *use-after-free*. Un programme peut donc libérer toute sa mémoire et effectuer malgré tout des accès invalides.

## 3. Vérification critique de l'IA

### Omission identifiée

Dans sa première analyse de `aliasing_example.c`, l'IA avait identifié seulement deux accès invalides : la lecture de `b[2]` et l'écriture dans `b[3]`.

Elle avait oublié la troisième opération :

```c
printf("  wrote b[3]=%d", b[3]);
```

### Vérification et correction

La sortie réelle de Valgrind signale une troisième erreur : `Invalid read of size 4` à la ligne 45.

Cette instruction relit `b[3]` pour afficher sa valeur, alors que le bloc mémoire a déjà été libéré.

L'analyse a donc été corrigée pour comptabiliser **trois accès invalides**, et non deux.

Cette vérification montre l'importance de comparer les explications de l'IA aux résultats réels des outils.

## Conclusion générale

Les deux programmes présentent des problèmes différents :

- **`heap_example.c` :** une fuite mémoire de 6 octets.
- **`aliasing_example.c` :** trois accès invalides, sans fuite mémoire détectée.

Valgrind permet de repérer ces erreurs et de les relier aux instructions responsables dans le code C.