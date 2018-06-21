#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;


// affichage d'une date seule
void putDate(const Date* date){
    printf("%02d-%02d-%4d", date->jour, date->mois, date->annee);
}

// affichage d'un tableau de dates
void putDates(const Date* tabDate, size_t taille){
    for(size_t i=0; i < taille; ++i){
        putDate(tabDate+i);
    }
}

// comparaison pour qsort
int dateCompare(const void* l, const void* r){
    const Date* d1 = (const Date*) l;
    const Date* d2 = (const Date*) r;

    if(d1->annee != d2->annee){
        return d1->annee - d2->annee;
    }

    if(d1->mois != d2->mois){
        return d2->mois - d2->mois;
    }

    return d1->jour - d2->jour;
}

int main(void){

    Date dates[] = {{4,7,1991},
            {21,3,2001},
            {14,2,2009}};

    // affichage & sorting
    putDates(dates, 3);
    qsort(dates, 3, sizeof(Date), dateCompare);
    putDates(dates, 3);

    return EXIT_SUCCESS;
}