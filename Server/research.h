#ifndef RESEARCH_H
#define RESEARCH_H

#include "create.h"

Film_List * moviesByRealisator(Node_realisator * root, char * requestedRealisator);
/*
Fonction qui recherche les films selon un realisateur, selon l'algorithme trie
Parametres :
Root -> Un arbre construit pour l'algorithme trie
requestedRealisator -> Le nom du realisateur recherche

Retour:
-> La liste des films realisees par le realisateur
*/

Realisator *topRealisator(byMovieNumber * ranking);
/*
Fonction qui trouve le realisateur avec le plus de film
Parametres :
ranking -> Une liste chainee de realisateurs, triee par ordre decroissant de films realises

Retour :
-> Le realisateur trouvé
*/

Film_List * moviesByTime(Film_List ** byDuration, int duration);
/*
Fonction qui trouve les films avec une duree donnee
Parametres :
byDuration -> Un tableau de listes de films
duration -> la duree demandee

Retour :
La liste des films trouves
*/

Film_List * movie_list_comparator(Film_List * first, Film_List * second);

#endif