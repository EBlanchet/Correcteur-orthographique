#ifndef __ATR__
#define __ATR__

#include "Listes.h"

typedef struct noeud {
    char lettre;
    int est_vide;
    struct noeud * gauche;
    struct noeud * fils;
    struct noeud * droit;
} Noeud, *ATR;


ATR creer_ATR_vide();
void liberer_ATR(ATR * A);
int inserer_dans_ATR(ATR * A, char * mot);
void supprimer_dans_ATR(ATR * A, char * mot);
void afficher_ATR(ATR A);

#endif