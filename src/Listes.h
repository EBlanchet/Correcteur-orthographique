#ifndef __Listes__
#define __Listes__

typedef struct cell{
    char * chaine;
    struct cell * suivant;
} Cellule, *Liste;

void afficher_liste (Liste lst);
Cellule * alloueCellule (char * mot);
void libereListe (Liste *l);
int insere_en_tete(Liste * L, char * mot);
void afficher_liste_inverse (Liste lst);

#endif