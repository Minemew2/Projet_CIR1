## Objectif
Réaliser une application de communication client-serveur permettant d'envoyer des requêtes via un site web afin de faire des recherches dans une DTB de film

## Client

Le côté client sera composée d'un site internet codé en HTML et CSS (frontend) et d'une partie logiciel codée en JavaScript (backend). L'utilisateur pourra formuler, dans des champs de recherches, des requêtes afin de chercher des films dans une filmothèque. Le site affichera ensuite à l'utilisateur le résultat de sa recherche.

### Fonctionnalités
- Page web design de recherche
- Réalisateur : barre de recherche
- Durée : Scrollbar nombre
- Bouton : Au clic,  afficher le réalisateur avec le plus de de films réalisés
- Bouton amenant vers une page avec tous le classement des réalisateurs selon le nombre de films qu'ils ont réalisés
- Récupérer les formulaires en JS au clic d'un bouton et en faire une requête
- Afficher les résultats et le temps d'éxecution de la requête
- Un bouton pour fermer le serveur
- Allumer le serveur au démarrage du site
- Créer un fichier request.txt
- Boucle d'attente du ready.txt

### Données
#### JS
- **string** <ins>requestedRealisator</ins> -> Le réalisateur demandé
- **number** <ins>requestedTime</ins> -> La durée demandée
- **bool** <ins>requestedFirst</ins> -> Si l'utilisateur demande le réalisateur avec le plus de films
- **bool** <ins>requestedRank</ins> -> Si l'utilisateur a demandé le classement des réalisateurs
- **number** <ins>executionTime</ins> -> Le temps d'exécution
- **FILE** <ins>resultFile</ins> -> Le fichier result.txt
- **FILE** <ins>requestFile</ins> -> Le fichier request.txt
- **bool** <ins>isReady</ins> -> Si le fichier ready.txt existe
- **bool** <ins>requestedClosing</ins> -> Si on veut fermer le serveur

### Fonctions
- <ins>getRequest()</ins> -> Récupère dans les input requestedRealisator, requestedTime, requestedFirst, requestedRank, requestedClosing, puis appelle createRequest dans requestFile
- <ins>createRequest()</ins> ->Crée un fichier texte request.txt selon les valeurs des input HTML
- <ins>printOnWebsite()</ins> -> Lit le fichier result.txt et affiches son contenu sur la page HTML
- <ins>startServer()</ins> -> Lance le serveur C

## Serveur
Le serveur tournera dans le langage C. Il devra récupérer la base de données, traiter les requêtes du client et lui envoyer le résultat.

### Dépendaces :
- La bibliothèque **time.h**
- La bibliothèque **stdio.h**
- La bibliothèque **stdlib.h**
- La bibliothèque **string.h**

### Fonctionnalités
- Compter le temps d'exécution (recherche, pas écriture d'un fichier)
- Trouver tous les films d'un réalisateur
- Afficher le réalisateur avec le plus de film
- Afficher le classement des réalisateurs selon le nombre de films
- Trouver tous les films avec une durée précise
- Supprimer la filmothèque
- Créer la filmothèque
- Créer un fichier result.txt et ready.txt

### Structures
- **Film :**
```C
struct Film{
	char * name;
	char * realisator;
	float time; // en minutes
	char * category;
};
```
- **Réalisateur :**
```C
struct Realisator{
	char * name;
	int nbrMovies;
}
```
- **Arbre construit selon le réalisateur :**
```C
struct Node_realisator{
	char character;
	bool isName;
	Film ** associateMovies; //Tous les films de l'auteur
	Node_realisator ** childs;
};
```
- **Tableau selon la durée :**
```C
Film ** time_array;
```
Tableau trié par ordre croissant de durée, incrémenté de 1 par index.
*Exemple :* Le film le plus court dure 120min. Donc index0 = 120min, index1 = 121min etc...
- **Tableau de classement par nombre de films :**
```C
Realisator ** byMoviesNumber;
```
Tableau trié par ordre décroissant selon le nombre de films du réalisateur

### Données
- **int** <ins>minTime</ins> -> La durée minimum parmi les films
- **int** <ins>maxTime</ins> -> La durée maximale parmi les films
- **Node_realisator \*** <ins>moviesByRealisator</ins> -> L'arbre de recherche des films par réalisateur
- des tableaux <ins>time_array</ins> et <ins>byMoviesNumber</ins>
- **bool** <ins>isRunning</ins> -> Indique que le serveur tourne
- **FILE \*** <ins>requestFile</ins> -> La dernière requête récupérée

### Fonctions

#### Création de la filmothèque

*Ces fonctions seront appelées au lancement du fichier C, lui-même lancé à l'ouverte du site internet. Ils liront un fichier csv contenant toutes les données sur les films*

- **Film \*** <ins>createMovie</ins>(**char \*** movieName, **char \*** realisatorName , **char \*** categoryName, float duration) -> Initialise un film et le renvoie
- **Realisator \*** <ins>createRealisator</ins>(**char \*** realisatorName, **int** nbrMovies) -> Initialise un réalisateur et le renvoie
- **Node_realisator \*** <ins>createRealisatorTree</ins>(**char \*** nom_fichier_csv) -> Crée un arbre où les films sont rangés selon leur réalisateur, permettant de rechercher le plus vite possible des films selon ce dernier.
- **Realisator \*\*** <ins>createByMoviesNumber</ins>(**char \*** nom_fichier_csv) -> Crée un tableau où les réalisateurs sont triés en fonction du nombre de films réalisés
- **Film \*\*\*** <ins>timeArray</ins>(**char \*** nom_fichier_csv) -> Crée des tableaux regroupant les films avec la même durée, puis range ces tableaux dans un tableau général, selon la durée des films

#### Suppression de la filmothèque

*Ces fonctions seront appelées à la fermeture du serveur*

- **void** <ins>freeRealisatorTree</ins>(**Node_realisator \*** realisatorTree) -> Supprimes l'arbre créée par createRealisatorTree
- **void** <ins>freeByMoviesNumber</ins>(**Realisator \*\*** byMoviesNumber) -> Supprimes le tableau créée par createByMoviesNumber
- **void** <ins>freeTimeArray</ins>(**Film \**\*\*** timeArray) -> Supprime le tableau créée par timeArray
 
#### Fonctions de recherche

*Pour chacune des fonctions de recherche, on lancera au début de celle-ci la fonction clock() de la bibliothèque time.h, puis une seconde fois à la fin de la fonction, afin de savoir le temps d'exécution de la requête. On écrira ce résultat dans un fichier result.txt*

- **Film \*\*** <ins>moviesByTime</ins>(**int** timeAsked, **int** minTime, **int** maxTime, **Film \*\*\*** time_array) -> Recherche les films par durée. Pour cela, on accède au tableau time_array avec comme index *timeAsked - minTime*
*Exemple* : Si on veut accéder aux films de 125 minutes, et que les films les plus court sont de 120 minutes, on sait que les films recherchés seront en 6ème dans time_array, soit à l'index 5.
- **Film \*\*** <ins>moviesByRealisator</ins>(**Node_realisator \*** root, **char \*** requestedRealisator ) -> Cherche tous les films d'un réalisateur en parcourant un arbre selon l'algorithme avancée trie
- **Realisator \***  <ins>topRealisator</ins>(**Realisator *\*\*** byMoviesNumber) -> Renvoie le premier élément de byMoviesNumber, qui correspond au réalisateur avec le plus de film

#### Fonctions de gestions des fichiers textes

*On listera ici toutes les fonctions gérant les fichiers textes permettant au client et au serveur de communiquer*

- **void** <ins>readRequest</ins>(**FILE \*** requestFile) -> Lit le fichier request.txt et appelle une des fonctions de recherches selon son contenu. Appellera les fonctions créant result.txt
- **void** <ins>filmResult</ins>(**Film \*\*** movies) -> Créé un fichier result.txt contenant tous les films dans le tableau movies
- **void** <ins>realisatorResult</ins>(**Realisator \*** realisator) -> Créé un fichier result.txt contenant les informations du réalisateur en paramètre
- **void** <ins>rankResult</ins>(**Realisator \*\*** realisators) -> Créé un fichier result.txt contenant les informations de tous les réalisateurs, dans l'ordre du tableau en paramètre

## Données communes au serveur et au client 
- **FILE** <ins>request.txt</ins> -> Fichier csv contenant la requête du client.
Forme :
```txt
request;request_value
```
avec :
**request** la demande du client : chaque type de requête est représenté par un nombre.

| Valeur de request | Signification                                                   |
| ----------------- | --------------------------------------------------------------- |
| 0                 | Valeur de base de request : aucune requête du client            |
| 1                 | Rechercher les films par réalisateur                            |
| 2                 | Rechercher les films par durée                                  |
| 3                 | Afficher le réalisateur avec le plus de films réalisés          |
| 4                 | Afficher tous les réalisateurs par classement de films réalisés |
| 5                  |      Fermer le serveur                                                           |

**request_value** ce que l'utilisateur recherche précisement
**un float** pour la durée, **une chaine de caractères** pour le réalisateur

- **FILE** <ins>result.txt</ins>() -> Fichier csv contenant le résultat de la requête (pour la recherche de film)
```txt
executionTime
movieName1;time1;category1
movieName2;time2;category2
movieName3;time3;category3
```
<ins>executionTime</ins> le temps d'exécution de la requête
une **chaine de caractères** représentant le nom du film
<ins>time</ins> un **float** représentant la durée du film
<ins>category</ins> une **chaine de caractères** représentant la catégorie du film

OU

- **FILE** <ins>result.txt</ins>() -> Fichier csv contenant le résultat de la requête (pour la recherche de réalisateurs)
```txt
executionTime
realisator1;moviesNbr1
realisator2;moviesNbr2
```
<ins>realisator</ins> Le nom du réalisateur
<ins>moviesNbr</ins> le nombre de films du réalisateur

- **FILE** <ins>ready.txt</ins> -> Un fichier texte vide permettant au client de savoir quand il peut lire le fichier result.txt


## Distribution des rôles
**Léandre MEUNIER-CRIQUET :** fonctions de créations, gestion de fichiers textes
**Alban GLACIAL :** fonctions de recherches et de destruction
**Gwengann LE CORVIC :** Partie Client

## Planning

| Séance         | Léandre                        | Alban                    | Gwengann            |
| -------------- | ------------------------------ | ------------------------ | ------------------- |
| Vendredi Matin | Fonctions de création          | Fonctions de recherche   | Site Internet       |
| Vendredi aprem | Fonctions de création          | Fonctions de recherche   | Site Internet       |
| Lundi Matin    | création, gestion des fichiers | Fonctions de destruction | Finition du site    |
| Lundi aprem    | Gestion des fichiers           | JS                       | JS                  |
| Mardi Matin    | Gestion des fichiers, JS       | JS                       | JS                  |
| Mardi aprem    | Test finaux                    | Test finaux              | Test finaux         |
| Merecredi      | Bonus, Tests finaux            | Bonus, Tests finaux      | Bonus, Tests finaux |
