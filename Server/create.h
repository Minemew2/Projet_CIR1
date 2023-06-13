#ifndef CREATE_H
#define CREATE_H

#define MAX_MOVIE_DURATION 401

typedef struct Film Film;
struct Film
{
    char * name;
    char * realisator;
    int time;
    char * category;
};

typedef struct Film_List Film_List;
struct Film_List
{
    Film_List * next;
    Film * data;
};

typedef struct Realisator Realisator;
struct Realisator
{
    char * name;
    int nbrMovies;
    Film_List * movies;
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

typedef struct byMovieNumber byMovieNumber;
struct byMovieNumber
{
    Realisator * data;
    byMovieNumber * next;
};




Film * createMovie(char * name, char * realisatorName, char * categoryName, int duration);
void printMovie(Film * movie);

Realisator * createRealisator(char * name, int movieNumber);

Node_realisator * initNode(char character);
void addWord(Node_realisator * root, char * word, Realisator * associateRealisator);
void printTree(Node_realisator * root);
void printRealisator(Realisator * real);
Node_realisator * createRealisatorTeee(char * nom_fichier_csv);
void addMovietoRealisator(Film * movie, Realisator * realisator);
void addWordwithArray(Node_realisator * root, char * word, Realisator * associatedReal);

void readCSV(char * nom_fichier_csv, Node_realisator * root, byMovieNumber * byMoviesNumber, Film_List **);
Realisator * findRealisator(Node_realisator * root, char * realisator);

void addRealisatorbyMovies(byMovieNumber * array, Realisator * realisator);

byMovieNumber * createByMovieNumber(Realisator * realisator);
void printByMovieNumber(byMovieNumber * base);
byMovieNumber * sortingByMovieNumber(byMovieNumber * array);

Film_List * createFilmList();

Realisator * foundRealisatorInMovieNumber(byMovieNumber * array, char * name);
void addMoviebyDuration(Film_List ** array, int duration, Film * movie);
void printFilmList(Film_List * array);

#endif