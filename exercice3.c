#include <stdlib.h>
#include <stdio.h>

const int* nouvelleMatrice(size_t ligne, size_t colonne, int valeur){
    if(!ligne || !colonne){
        return NULL;
    }

    int* matrice = (int*) calloc(ligne*colonne, sizeof(int));
    if(!matrice){
        return NULL;
    }

    for(size_t l=0; l<ligne; ++l){
        for(size_t c=0; c<colonne; ++c) {
            *(matrice + l*colonne + c) = valeur;
        }
    }

    return matrice;
}

// affichage
void putMatrice(const int* matrice, size_t ligne, size_t colonne){
    for(size_t l=0; l<ligne; ++l){
        for(size_t c=0; c<colonne; ++c){
            printf("%d ", *(matrice + l*colonne+c));
        }
        printf("\n");
    }
}

int main(void){
    return EXIT_SUCCESS;
}