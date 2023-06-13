
#include <time.h>
#include <stdio.h>

#include "research.h"


Film_List * moviesByRealisator(Node_realisator * root, char * requestedRealisator){
    Film_List * fake_list = createFilmList();
    fake_list->data = createMovie("Film 1", "Leandre", "comedy", 50);

    fake_list->next = createFilmList();

    fake_list->next->data = createMovie("Film 2", "Leandre", "comedy", 100);

    return fake_list;
}

Realisator *topRealisator(byMovieNumber * ranking){
    return ranking->next->data;
}


