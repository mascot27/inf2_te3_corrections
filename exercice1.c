#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define TAILLE 80

typedef struct {
    size_t taille;
    char text[TAILLE];
} Chaine;

// affiche chaine reçue en parametre
void putChaine(const Chaine* chaine){
    if(!chaine){
        return;
    }

    // affichage charactere par charactere
    for(int i=0; i < chaine->taille; ++i){
        printf("%c", chaine->text[i]);
    }
}

const char* copy(char* dest, const char* src){
    char* crt = dest;

    while( (*crt++ = * src++) != '\0');

    return dest;
}

/**
 * calcule la longuer de la chaine sans \o
 * @param text
 * @return longeur sans ending char
 */
size_t longueur(const char* text){
    const char* crt = text;
    while(*crt++);

    return (size_t) (crt-text);  // ptr diff
}

void getChaine(Chaine* chaine){
    chaine->taille = (size_t) scanf("%s", chaine->text);
}

void setChaine(Chaine* chaine, const char* text){
    copy(chaine->text, text);
    chaine->taille = longueur(text);
}


int main(void){

    Chaine chaine1 = {.taille = 3, .text="abc"};
    putChaine(&chaine1);

    return EXIT_SUCCESS;
}