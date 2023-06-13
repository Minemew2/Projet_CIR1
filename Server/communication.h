#ifndef COMM_H
#define COMM_H

#include <stdio.h>
#include "create.h"

void readRequest(FILE * request_file);
void filmResult(Film_List * movie_list, float executionTime);
void realisatorResult(Realisator * realisator, float executionTime);


#endif