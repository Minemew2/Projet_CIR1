
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "research.h"


Film_List * moviesByRealisator(Node_realisator * root, char * requestedRealisator){
    return findRealisator(root, requestedRealisator)->movies;
}

Realisator *topRealisator(byMovieNumber * ranking){
    return ranking->next->data;
}

Film_List * moviesByTime(Film_List ** byDuration, int duration){
    return byDuration[duration-1];
}

Film_List * movie_list_comparator(Film_List * first, Film_List * second){
    Film_List * first_route = first;
    Film_List * second_route = second;

    Film_List * result = NULL;
    Film_List * newFilm = NULL;

    while(first_route != NULL){
        second_route = second;

        while(second_route != NULL){
            if(strcmp(first_route->data->name, second_route->data->name) == 0){
                printf("YES\n");
                if(result == NULL){
                    result = second_route;
                } else {
                    newFilm = createFilmList();
                    newFilm->data = second_route->data;
                    newFilm->next = result;
                    result = newFilm;
                }
            }

            second_route = second_route->next;
        }

        first_route = first_route->next;
    }

    printFilmList(result);
    return result;
}