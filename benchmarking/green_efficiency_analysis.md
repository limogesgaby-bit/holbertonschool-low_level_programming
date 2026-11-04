Analyse de l’éfficacité énergétique
Comment j’ai mesuré

J’ai compilé tout mes programmes avec gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long, puis je les ai lancé trois fois de suite, sur la même machine et dans la même session. J’ai noté les résultats tel quel. Pour le temps, j’ai utilisé clock() divisé par CLOCKS_PER_SEC. Sa donne le temps CPU du programme, pas le temps réel. Dans instrumentation_lab.c, j’ai un chrono pour tout le programme et un chrono pour chaque phase, donc TOTAL est toujours plus grand ou égale à chaque phase. A la fin, j’ai fait la moyenne des trois lancements.

Ce que j’ai observé

La boucle de base. Ma boucle de 100 000 000 d’itérations a pris 0.056465 s, 0.053956 s et 0.053106 s, soit 0.054509 s en moyenne. La première fois, elle était environ 6,3 % plus lente que la troisième, alors que le calcul est le même. Une seule mesure ne suffit donc pas.

La comparaison des deux algorithmes. L’algorithme naïf a pris 0.793114 s, 0.769609 s et 0.778108 s (moyenne : 0.780277 s). Celui qui parcour le tableau une seule fois a pris 0.000041 s, 0.000031 s et 0.000031 s (moyenne : 0.000034 s). La version naïve est donc environ 22 700 fois plus lente.

Ça correspond a la théorie. Pour n = 50 000, la version naïve fait environ 1,25 milliard de vérifications, contre 50 000 pour l’autre, soit un rapport d’environ 25 000. Mon rapport mesuré est un peu plus bas (environ 9 %). D’un lancement a l’autre, il varie de 19 300 à 25 100, parce que le temps du passage unique est tellement court que 10 microsecondes de différence change déjà beaucoup le résultat.

Attention : les deux fonctions ne renvoie pas la même valeur (625 025 000 contre 25 000). La version naïve compte les nombres pairs en cumulant sur chaque début de tableau. Ma comparaison montre donc la quantité de travail, pas deux résultats équivalent.

Le programme avec les phases. Voici les moyennes :

BUILD_DATA : 0.000146 s (environ 47 % du total)
PROCESS : 0.000108 s (environ 35 %)
REDUCE : 0.000051 s (environ 17 %)
TOTAL : 0.000307 s

BUILD_DATA à été la phase la plus lente à chaque lancement. TOTAL est 1 à 3 microsecondes plus grand que la somme des phases, sans doute a cause des appels à clock() entre les phases.

Temps d’exécution et énergie

Je n’ai mesuré aucune puissance, donc je ne peut donner aucun chiffre d’énergie. Je prend le temps d’exécution comme indice : plus un programme tourne longtemps, plus le processeur reste actif. L’algorithme naïf a fait travailler le CPU pendant 0.78 s, contre environ 34 microsecondes pour l’autre sur le même tableau. Cet écart de 22 700 fois est le seul indice sur l’énergie que j’ai, et il ne dit pas combien de joules on été consommés.

Les limites de mon expérience
clock() n’est pas très précis. Mes phases dure entre 51 et 150 microsecondes, donc quelques microsecondes de bruit pèse déjà beaucoup.
Je n’ai fait que trois lancements par programme, sur une seule machine, sans controler ce qui tournait en arrière-plan.
Je n’ai pas testé avec les optimisations du compilateur (par exemple -O2).
Les deux algorithmes ne renvoie pas la même valeur, donc je compare le travail éffectué, pas des résultats identique.
Je n’ai fait aucune vrai mesure de puissance.
Ce que j’en retiens

Il faut mesurer avant d’optimiser, et refaire les mesures plusieurs fois : ma boucle de base a varié d’environ 6 % d’un lancement a l’autre. La plus grosse différence vient de l’algorithme. Avec une seule boucle au lieu de deux boucles imbriqué, je suis passé d’environ 1,25 milliard de vérifications à 50 000, et de 0.78 s à 0.000034 s. Pour écrire du code éfficace, il faut d’abord choisir le bon algorithme, puis vérifier le gain avec des mesures.