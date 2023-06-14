#include "communication.h"
#include <string.h>
#include <stdlib.h>

#include "research.h"
#include <time.h>
#include "delete.h"

#define RESULT_ROOT "../Site/result.txt"

void readRequest(FILE * request_file, Node_realisator * tree, byMovieNumber * ranking, Film_List ** byDuration, int * mustExit, char * pathToRequest){
    char line[1024];

    int type_of_request = 0;
    char * request_value = NULL;
    int number_of_request = 0;

    clock_t starter;
    clock_t end;
    float execution;
    Film_List * result;

    int * all_request_type = malloc(sizeof(int)*2);
    char  ** all_request_value = malloc(sizeof(char*)*2);

    while(fgets(line, 1024, request_file)){
        char* tmp = strdup(line);
        char * tok = strtok(tmp, ";");

        type_of_request = atoi(tok);

        tok = strtok(NULL, "\n");

        request_value = tok;
        // printf("requete : %d value : %s\n",type_of_request, request_value);

        number_of_request++;
        all_request_type[number_of_request-1] = type_of_request;
        all_request_value[number_of_request-1] = request_value;
        free(tmp);
    }

    if(number_of_request){
        printf("It's ok !");
        remove(pathToRequest);
    } else {
        fclose(request_file);
    }
    // printf("requetes : %d\n", number_of_request);
    if(number_of_request == 2){
        printf("Deux requetes !");
        Film_List ** all_result = malloc(sizeof(Film_List*)*2);
        starter = clock();
        for(int i = 0; i<number_of_request; i++){
            if(all_request_type[i] == 1){
                all_result[i] = moviesByRealisator(tree, all_request_value[i]);
            } else if(all_request_type[i] == 2){
                all_result[i] = moviesByTime(byDuration, atoi(all_request_value[i]));
            }
        }
        result = movie_list_comparator(all_result[0], all_result[1]);
        end = clock();
        execution = (float)(end-starter)/CLOCKS_PER_SEC;
        execution*=1000;
        
        filmResult(result, execution, 1);


    } else {
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

    case 5:
        *mustExit = 1;
        freeTree(tree);
        freeByDuration(byDuration);
        freeByMoviesNumber(ranking);
        break;

    default:
        errorResult();
        break;
    }
    }

    createReady();


    

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
    remove(RESULT_ROOT);
    FILE * result = fopen(RESULT_ROOT, "w");

    fprintf(result, "%d\n", type_of_result);    
    fprintf(result, "%.4f\n", executionTime);

    writeFilmList(movie_list, result);
    
    fclose(result);

}

void realisatorResult(Realisator * realisator, float executionTime, int type_of_result){
    remove(RESULT_ROOT);
    FILE * result = fopen(RESULT_ROOT, "w");

    fprintf(result, "%d\n", type_of_result);
    fprintf(result, "%.4f\n", executionTime);
    fprintf(result, "%s;%d\n", realisator->name, realisator->nbrMovies);

    writeFilmList(realisator->movies, result);

    fclose(result);
}

void rankResult(byMovieNumber * array, float execution, int type_of_result){

    remove(RESULT_ROOT);
    FILE * result = fopen(RESULT_ROOT, "w");
    
    fprintf(result, "%d\n", type_of_result);
    fprintf(result, "%.4f\n", execution);

    byMovieNumber * parcours = array->next;
    
    while(parcours != NULL){
        fprintf(result, "%s;%d\n", parcours->data->name, parcours->data->nbrMovies);
        parcours = parcours->next;
    }
    
    fclose(result);
}

void errorResult(){
    FILE * result = fopen(RESULT_ROOT, "w");
    fprintf(result, "error");
    fclose(result);
}

void createReady(){
    FILE * result = fopen("../Site/ready.txt", "w");
    fclose(result);
}