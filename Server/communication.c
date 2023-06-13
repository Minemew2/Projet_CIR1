#include "communication.h"
#include <string.h>
#include <stdlib.h>

#include "research.h"
#include <time.h>

void readRequest(FILE * request_file, Node_realisator * tree, byMovieNumber * ranking, Film_List ** byDuration){
    char line[1024];

    int type_of_request = 0;
    char * request_value = NULL;
    int number_of_request = 0;

    clock_t starter;
    clock_t end;
    float execution;
    Film_List * result;

    while(fgets(line, 1024, request_file)){
        char* tmp = strdup(line);
        char * tok = strtok(tmp, ";");

        type_of_request = atoi(tok);

        tok = strtok(NULL, "\n");

        request_value = tok;
        printf("requete : %d value : %s\n",type_of_request, request_value);

        number_of_request++;
    }
    if(number_of_request){
        remove("request.txt");
    } else {
        fclose(request_file);
    }
    

    switch (type_of_request)
    {
    case 1:
        starter = clock();
        result = moviesByRealisator(tree, request_value);
        end = clock();
        execution = (float)(end-starter)/CLOCKS_PER_SEC;
        execution*=1000;
        
        filmResult(result, execution, type_of_request);

        break;
    
    case 2:
        starter = clock();
        result = moviesByTime(byDuration, atoi(request_value));
        end = clock();
        execution = (float)(end-starter)/CLOCKS_PER_SEC;
        execution*=1000;

        filmResult(result, execution, type_of_request);

        break;

    case 3:
        starter = clock();
        Realisator * realisator_result = topRealisator(ranking);
        end = clock();
        execution = (float)(end-starter)/CLOCKS_PER_SEC;
        execution*=1000;

        realisatorResult(realisator_result, execution, type_of_request);
        break;

    case 4:
        starter = clock();
        byMovieNumber * ranking_result = ranking;
        end = clock();
        execution = (float)(end-starter)/CLOCKS_PER_SEC;
        execution*=1000;

        rankResult(ranking_result, execution, type_of_request);
        break;
    default:
        break;
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

void filmResult(Film_List * movie_list, float executionTime, int type_of_result){
    remove("result.txt");
    FILE * result = fopen("result.txt", "w");

    fprintf(result, "%d\n", type_of_result);    
    fprintf(result, "%.4f\n", executionTime);

    writeFilmList(movie_list, result);
    
    fclose(result);

}

void realisatorResult(Realisator * realisator, float executionTime, int type_of_result){
    remove("result.txt");
    FILE * result = fopen("result.txt", "w");

    fprintf(result, "%d\n", type_of_result);
    fprintf(result, "%.4f\n", executionTime);
    fprintf(result, "%s;%d\n", realisator->name, realisator->nbrMovies);

    writeFilmList(realisator->movies, result);

    fclose(result);
}

void rankResult(byMovieNumber * array, float execution, int type_of_result){
    remove("result.txt");
    FILE * result = fopen("result.txt", "w");
    
    fprintf(result, "%d\n", type_of_result);
    fprintf(result, "%.4f\n", execution);

    byMovieNumber * parcours = array->next;
    
    while(parcours != NULL){
        fprintf(result, "%s;%d\n", parcours->data->name, parcours->data->nbrMovies);
        parcours = parcours->next;
    }
    
    fclose(result);
}