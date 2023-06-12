#ifndef CREATE_H
#define CREATE_H

typedef struct Film Film;
struct Film
{
    char * name;
    char * realisator;
    int time;
    char * category;
};

typedef struct Realisator Realisator;
struct Realisator
{
    char * name;
    int nbrMovies;
    Film ** movies;
};


typedef struct Node_realisator Node_realisator;
struct Node_realisator
{
    char character;
    int isName;
    Realisator * associateRealisator;
    Node_realisator ** childs;
    int childsNumber;
};



Film * createMovie(char * name, char * realisatorName, char * categoryName, int duration);
void printMovie(Film * movie);

Realisator * createRealisator(char * name, int movieNumber);

Node_realisator * initNode(char character);
void addWord(Node_realisator * root, char * word, Realisator * associateRealisator);
void printTree(Node_realisator * root);
void printRealisator(Realisator * real);

#endif