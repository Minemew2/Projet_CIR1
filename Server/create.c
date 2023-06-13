#include "create.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


Film * createMovie(char * name, char * realisatorName, char * categoryName, int duration){
    Film * newFilm = malloc(sizeof(Film));
    newFilm->name = name;
    newFilm->category = categoryName;
    newFilm->realisator = realisatorName;
    newFilm->time = duration;

    return newFilm;
}

void printMovie(Film * movie){
    printf("Nom : %s, Realisateur : %s, categorie : %s, duree : %d\n", movie->name, movie->realisator, movie->category, movie->time);
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
                // printf("hello : %c\n", actual_char);
                if(parcours->childs[j]->character == actual_char){
                    // printf("hello : %c\n", actual_char);
                    isExisting = 1;
                    parcours = parcours->childs[i];
                }
            }
        }
        if(isExisting == 0){
            // printf(" childsNumber : %d\n", parcours->childsNumber);
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
        for(int i = 0; i < 27; i++){
            if(root->childs != NULL){
                printTree(root->childs[i]);
            }
            
            // printTree(root->childs[i]);
            
        }
    }
}

Realisator * createRealisator(char * name, int movieNumber){
    Realisator * newRealisator = malloc(sizeof(Realisator));
    newRealisator->name = name;
    newRealisator->nbrMovies = movieNumber;
    newRealisator->movies = NULL;
    return newRealisator;
}

void printRealisator(Realisator * real){
    printf("Nom : %s, nombre de films : %d\n", real->name, real->nbrMovies);
    
    printFilmList(real->movies);
    
}

Realisator * findRealisator(Node_realisator * root, char * realisator){

    char actual_char  = 0;
    Node_realisator * parcours = root;

    for(int i = 0; i<strlen(realisator) ; i++){
        actual_char = tolower(realisator[i]);

        if(actual_char >= toascii('a') && actual_char <= toascii('z')){
            parcours = parcours->childs[actual_char-toascii('a')];
        } else {
            parcours = parcours->childs[26];
        }
    }
    return parcours->associateRealisator;
}




void readCSV(char * nom_fichier_csv, Node_realisator * root, byMovieNumber * byMoviesNumber, Film_List ** durationArray){
    FILE * csv = fopen(nom_fichier_csv, "r");

    char line[1024];
    int field = 0;

    char * realisator_name = NULL;
    char * movie_name = NULL;
    char * category = NULL;
    int duration = 0;
    Realisator * newRealisator = NULL;
    Film * newFilm = NULL;

    int minTime = 0;
    int maxTime = 0;
    
    while (fgets(line, 1024, csv))
    {
        char* tmp = strdup(line);
        // printf("%s\n", tmp);
        char * tok;
        for (tok = strtok(tmp, ";"); tok && *tok; tok = strtok(NULL, ";\n")){
            switch (field)
            {
            case 1:
                movie_name = tok;
                break;
            
            case 2:
                duration = atoi(tok);
                if(minTime == 0 && maxTime == 0){
                    minTime = duration;
                    maxTime = duration;
                } else if(duration < minTime){
                    minTime = duration;
                } else if(duration > maxTime){
                    maxTime = duration;
                }
                break;

            case 3:
                category = tok;
                newFilm = createMovie(movie_name, realisator_name, category, duration);
                addMovietoRealisator(newFilm, findRealisator(root, realisator_name));
                addMovietoRealisator(newFilm, foundRealisatorInMovieNumber(byMoviesNumber, realisator_name));
                addMoviebyDuration(durationArray, duration, newFilm);
                break;

            default:
                realisator_name = tok;
                newRealisator = createRealisator(tok, 0);
                addWordwithArray(root, tok, newRealisator);

                addRealisatorbyMovies(byMoviesNumber, createRealisator(realisator_name, 0));
                break;
            }
            field++;
        }
        field = 0;
        // addWord(root, movieName, createRealisator(realisatorName, 0));

    }



}   


void addMovietoRealisator(Film * movie, Realisator * realisator){ 
    realisator->nbrMovies++;
    if(realisator->movies == NULL){
        realisator->movies = createFilmList();
        realisator->movies->data = movie;
    } else {
        Film_List * parcours = realisator->movies;
        Film_List * end_of_list = NULL;
        while (parcours != NULL)
        {
            end_of_list = parcours;
            parcours = parcours->next;
        }

        end_of_list->next = createFilmList();
        end_of_list->next->data = movie;
    }

    

    
        
}

void addWordwithArray(Node_realisator * root, char * word, Realisator * associatedReal){
    char actual_char  = 0;
    Node_realisator * parcours = root;

    for(int i = 0; i<strlen(word) ; i++){
        actual_char = tolower(word[i]);
        if(parcours->childs == NULL){
            parcours->childs = malloc(27*sizeof(Node_realisator*));
        }

        if(actual_char >= toascii('a') && actual_char <= toascii('z')){
            if(parcours->childs[actual_char-toascii('a')] != NULL){
                parcours = parcours->childs[actual_char-toascii('a')];
            } else {
                parcours->childs[actual_char-toascii('a')] = initNode(actual_char);
                parcours = parcours->childs[actual_char-toascii('a')];
            }
        } else {
            if(parcours->childs[26] != NULL){
                parcours = parcours->childs[26];
            } else {
                parcours->childs[26] = initNode('-');
                parcours = parcours->childs[26];
            }
        }
    }
    parcours->isName = 1;
    if(parcours->associateRealisator == NULL){
        parcours->associateRealisator = associatedReal;
    }
    
}

byMovieNumber * createByMovieNumber(Realisator * realisator){
    byMovieNumber * newMember = malloc(sizeof(byMovieNumber));
    newMember->next = NULL;
    newMember->data = realisator;
    return newMember;

}

void addRealisatorbyMovies(byMovieNumber * array, Realisator * realisator){
    int newRealisator = 1;

    byMovieNumber * parcours = array;
    byMovieNumber * before = NULL;
    
    while (parcours != NULL)
    {
        if(strcmp(parcours->data->name, realisator->name) == 0){
            // parcours->data->nbrMovies++;
            newRealisator = 0;
        }
        before = parcours;
        parcours = parcours->next;
        
    }
    
    if(newRealisator){
        before->next = createByMovieNumber(realisator);
    }

}

void printByMovieNumber(byMovieNumber * base){
    byMovieNumber * parcours = base;
    while (parcours != NULL)
    {
        printRealisator(parcours->data);
        parcours = parcours->next;
    }
    
}

byMovieNumber * sortingByMovieNumber(byMovieNumber * array){

    byMovieNumber * previous_head = array;
    byMovieNumber * head = previous_head->next;

    byMovieNumber * second_route = head->next;
    int bestNumber = head->data->nbrMovies;

    byMovieNumber * bestRealisator = NULL;

    byMovieNumber * previous_of_best = NULL;
    byMovieNumber * previous_of_second_route = NULL;
    byMovieNumber * save = NULL;

    int newChampion = 0;

    int compteur = 0;

    while (head != NULL)
    {

        second_route = head->next;
        previous_of_second_route = head;
        bestNumber = head->data->nbrMovies;
        
        while(second_route != NULL){
            if(second_route->data->nbrMovies > bestNumber){
                if(compteur == 2){
                    printf("Je rentre\n");
                }

                bestNumber = second_route->data->nbrMovies;
                bestRealisator = second_route;
                previous_of_best = previous_of_second_route;
                newChampion = 1;
            }

            previous_of_second_route = second_route;
            second_route = second_route->next;
        }

        if(compteur == 2){
            printRealisator(previous_of_second_route->data);
            printf("Un champion a %d ? : %d\n", compteur, newChampion);
        }

        

        if(newChampion){

            save = bestRealisator->next;

            if(strcmp(head->next->data->name, bestRealisator->data->name) == 0){
                printf("Reel\n");
                bestRealisator->next = head;
                head->next = save;
            } else  {
                bestRealisator->next = head->next;
                head->next = save;
                previous_of_best->next = head;
            }

            previous_head->next = bestRealisator;
            previous_head = previous_head->next;
            head = previous_head->next;
        
        } else {
            head = head->next;
        }

        newChampion = 0;
          

    }

    return array;
}

Film_List * createFilmList(){
    Film_List * newList = malloc(sizeof(Film_List));
    newList->data = NULL;
    newList->next = NULL;
    return newList;
}

Realisator * foundRealisatorInMovieNumber(byMovieNumber * array, char * name){
    byMovieNumber * parcours = array;
    Realisator * found = NULL;

    while (parcours != NULL)
    {
        if(strcmp(parcours->data->name, name) == 0){
            found = parcours->data;
        }

        parcours = parcours->next;
    }
    
    return found;

}

void addMoviebyDuration(Film_List ** array, int duration, Film * movie){
    if(array[duration-1] == 0){
        array[duration-1] = createFilmList();
        array[duration-1]->data = movie;
    } else {
        Film_List * parcours = array[duration-1];
        Film_List * end_of_list = NULL;
        while (parcours != NULL)
        {
            end_of_list = parcours;
            parcours = parcours->next;
        }

        end_of_list->next = createFilmList();
        end_of_list->next->data = movie;
    }
}

void printFilmList(Film_List * array){
    Film_List * parcours = array;
    while (parcours != NULL)
    {
        printMovie(parcours->data);
        parcours = parcours->next;
    }
}