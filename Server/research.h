#ifndef RESEARCH_H
#define RESEARCH_H

#include "create.h"

Film_List * moviesByRealisator(Node_realisator * root, char * requestedRealisator);

Realisator *topRealisator(byMovieNumber * ranking);

Film_List * moviesByTime(Film_List ** byDuration, int duration);

Film_List * movie_list_comparator(Film_List * first, Film_List * second);
#endif