#include "delete.h"
#include "create.h"

#include <stdlib.h>
#include <stdio.h>

void freeTree(Node_realisator * root){
    if(root != NULL){
        for(int i = 0; i < 27; i++){
            if(root->childs != NULL){
                freeTree(root->childs[i]);
            }
            
        }
        if(root->childs != NULL){
            
            free(root->childs);
        }
        if(root->associateRealisator != NULL){
            freeRealisator(root->associateRealisator);
        }
        
       free(root);
    }
}

void freeRealisator(Realisator * real){
    freeFilmList(real->movies);
    free(real);
}

void freeFilmList(Film_List * list){
    Film_List * parcours = list;
    Film_List * save = NULL;

    while (parcours != NULL)
    {

        save = parcours->next;

        if(parcours->data != NULL){
            free(parcours->data);
        }
        
        printf("parcours : %p\n", parcours);
        free(parcours);
        parcours = save;
    }
    

}

void freeMovie(Film * movie){
    free(movie);
}

void freeByDuration(Film_List ** byDuration){
    free(byDuration);
}

void freeByMoviesNumber(byMovieNumber * array){
    byMovieNumber * parcours = array;
    byMovieNumber * save = NULL;

    while (parcours != NULL)
    {

        save = parcours->next;

        if(parcours->data != NULL){
            free(parcours->data);
        }
        
        free(parcours);
        parcours = save;
    }

}