#ifndef COMM_H
#define COMM_H

#include <stdio.h>
#include "create.h"

void readRequest(FILE * request_file, Node_realisator * tree, byMovieNumber * ranking, Film_List ** byDuration, int * mustExit, char * pathToRequest);
void filmResult(Film_List * movie_list, float executionTime, int type);
void realisatorResult(Realisator * realisator, float executionTime, int type_of_result);
void rankResult(byMovieNumber * realisator, float executionTime, int type_of_result);
void errorResult();
void createReady();

#endif