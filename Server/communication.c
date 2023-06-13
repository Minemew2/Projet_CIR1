#include "communication.h"
#include <string.h>
#include <stdlib.h>

void readRequest(FILE * request_file){

    char line[1024];

    int type_of_request = 0;
    char * request_value = NULL;

    while(fgets(line, 1024, request_file)){
        char* tmp = strdup(line);
        char * tok = strtok(tmp, ";");

        type_of_request = atoi(tok);

        tok = strtok(NULL, "\n");

        request_value = tok;
        printf("requete : %d value : %s\n",type_of_request, request_value);


    }

}

void writeFilmList(Film_List * film_list, FILE * fileToWrite){

    Film_List * parcours = film_list;
    while (parcours != NULL)
    {
        fprintf(fileToWrite, "%s;%d;%s\n", parcours->data->name, parcours->data->time, parcours->data->category);

        parcours = parcours->next;
    }
}

void filmResult(Film_List * movie_list, float executionTime){
    remove("result.txt");
    FILE * result = fopen("result.txt", "w");

    fprintf(result, "%.2f\n", executionTime);

    writeFilmList(movie_list, result);
    
    fclose(result);

}

void realisatorResult(Realisator * realisator, float executionTime){
    remove("result.txt");
    FILE * result = fopen("result.txt", "w");

    fprintf(result, "%.2f\n", executionTime);
    fprintf(result, "%s;%d\n", realisator->name, realisator->nbrMovies);

    writeFilmList(realisator->movies, result);

    fclose(result);
}