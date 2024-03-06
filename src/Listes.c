/* Author : Matthieu Garnier - Elise Blanchet */
/* Creation : 16/03/2022 */
/* Modification : 16/03/2022 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Listes.h"

void afficher_liste (Liste lst) {
	if (!lst) return;
	afficher_liste(lst->suivant);
	printf("%s\n", lst->chaine);
}

void afficher_liste_inverse (Liste lst) {
	if (!lst) return;
	printf("%s\n", lst->chaine);
	afficher_liste_inverse(lst->suivant);
}

Cellule * alloueCellule (char * mot){
	Cellule *c = (Cellule *) malloc (sizeof(Cellule));
	if(c){
		c->chaine = (char *) malloc(sizeof(char) * 50);
		strcpy(c->chaine, mot);
		c->suivant = NULL;
	}
	return c;
}
	
void libereListe (Liste *l){
	Liste tmp;
	if (!*l){
		return;
	}
	while (tmp){
		tmp = (*l)->suivant;
		free(*l);
		*l = tmp;
	} 
}

int insere_en_tete(Liste * L, char * mot){
    Liste cell = alloueCellule(mot);
    if(!cell)
		return 0;
	cell->suivant = *L;
	*L = cell;
    return 1;
}