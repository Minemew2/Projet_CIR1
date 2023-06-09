#include "create.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Film * createMovie(char * name, char * realisatorName, char * categoryName, int duration){
    Film * newFilm = malloc(sizeof(Film));
    newFilm->name = name;
    newFilm->category = categoryName;
    newFilm->realisator = realisatorName;
    // strcpy(newFilm->name, name);
    // strcpy(newFilm->realisator, realisatorName);
    // strcpy(newFilm->category, categoryName);
    newFilm->time = duration;

    return newFilm;
}

void printMovie(Film * movie){
    printf("Nom : %s\n, Realisateur : %s\n, categorie : %s\n, duree : %d\n", movie->name, movie->realisator, movie->category, movie->time);
}

Node_realisator * initNode(char character){
    Node_realisator * result = malloc(sizeof(Node_realisator));
    result->childsNumber = 0;
    result->character = character;
    result->isName = 0;
    result->childs = NULL;
    return result;
}

void addWord(Node_realisator * root, char * word, Realisator * associateRealisator){
    char actual_char  = 0;
    int isExisting = 0;
    Node_realisator * parcours = root;
    char * comparator = malloc(sizeof(char)*strlen(word));

    for(int i = 0; i<strlen(word) ; i++){
        actual_char = word[i];

        for(int j = 0; j< parcours->childsNumber; j++){
            if(parcours->childs != NULL){
                printf("hello : %c\n", actual_char);
                if(parcours->childs[j]->character == actual_char){
                    printf("hello : %c\n", actual_char);
                    isExisting = 1;
                    parcours = parcours->childs[i];
                }
            }
        }
        if(isExisting == 0){
            printf(" childsNumber : %d\n", parcours->childsNumber);
            parcours->childsNumber++;
            parcours->childs = realloc(parcours->childs, parcours->childsNumber*sizeof(Node_realisator*));
            parcours->childs[parcours->childsNumber-1] = initNode(actual_char);



            parcours = parcours->childs[parcours->childsNumber-1];
        }
        isExisting = 0;

        comparator[i] = actual_char;
    }

    if(strcmp(comparator, word) == 0){
        parcours->isName = 1;
        parcours->associateRealisator  = associateRealisator;
    }
}

void printTree(Node_realisator * root){
    if(root != NULL){
        printf("%c\n", root->character);
        if(root->associateRealisator != NULL){
            printRealisator(root->associateRealisator);
        }
        for(int i = 0; i < root->childsNumber; i++){
            printTree(root->childs[i]);
        }
    }
}

Realisator * createRealisator(char * name, int movieNumber){
    Realisator * newRealisator = malloc(sizeof(Realisator));
    newRealisator->name = name;
    newRealisator->nbrMovies = movieNumber;
    newRealisator->movies = malloc(sizeof(Film)*movieNumber);
    return newRealisator;
}

void printRealisator(Realisator * real){
    printf("Nom : %s, nombre de films : %d\n", real->name, real->nbrMovies);
}