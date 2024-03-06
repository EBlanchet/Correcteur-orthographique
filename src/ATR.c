/* Author : Matthieu Garnier - Elise Blanchet
 * Creation : 16/03/2022
 * Modification : 16/03/2022
 *                19/03/2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ATR.h"

ATR creer_ATR_vide() {
    ATR tmp;
    tmp = (ATR) malloc(sizeof(Noeud));
    if (!tmp) return NULL;
    tmp->lettre = '\0';
    tmp->gauche = NULL;
    tmp->fils = NULL;
    tmp->droit = NULL;
    tmp->est_vide = 1;
    return tmp;
}

void liberer_ATR(ATR * A) {
    if (!A) return;
    if (&(*A)->gauche) liberer_ATR(&(*A)->gauche);
    if (&(*A)->fils) liberer_ATR(&(*A)->fils);
    if (&(*A)->droit) liberer_ATR(&(*A)->droit);
    free(*A);
    *A = NULL;
}

int inserer_dans_ATR(ATR * A, char * mot) {
    ATR tmp;
    if (!mot[0]) {
        if ((*A)->lettre != '\0') {
            if ((*A)->fils){
                tmp = (*A);
                (*A)->droit = tmp;
            }
            (*A)->lettre = '\0';
        }
        (*A)->est_vide = 0;
        return 1;
    }
    if (!((*A)->gauche) && !((*A)->fils) && !((*A)->droit)){
        if ((*A)->est_vide) {
            (*A)->lettre = mot[0];
            (*A)->est_vide = 0;
            (*A)->fils = creer_ATR_vide();
            return inserer_dans_ATR(&((*A)->fils), &mot[1]);
        }
        (*A)->droit = creer_ATR_vide();
        return inserer_dans_ATR(&((*A)->droit), &mot[1]);
    }
    (*A)->est_vide = 0;
    if ((*A)->lettre == mot[0]){
        if (!(*A)->fils)
            (*A)->fils = creer_ATR_vide();
        return inserer_dans_ATR(&((*A)->fils), &mot[1]);
    }
    else {
        if (mot[0] < (*A)->lettre) {
            if (!(*A)->gauche)
                (*A)->gauche = creer_ATR_vide();
            return inserer_dans_ATR(&((*A)->gauche), mot);
        } else {
            if (!(*A)->droit)
                (*A)->droit = creer_ATR_vide();
            return inserer_dans_ATR(&((*A)->droit), mot);
        }
    }
}

void supprimer_dans_ATR(ATR * A, char * mot) {
    ATR tmp;
    if (!(*A)) return;
    if (mot[0] == (*A)->lettre){
        supprimer_dans_ATR(&(*A)->fils, &mot[1]);
        if (!(*A)->gauche && !(*A)->droit && !(*A)->fils) *A = NULL;
        if ((*A)->fils->lettre == '\0') {
            tmp = (*A)->fils;
            (*A)->fils = (*A)->fils->droit;
            free(tmp);
        }
    } else {
        if (mot[0] < (*A)->lettre)
            supprimer_dans_ATR(&(*A)->gauche, mot);
        else supprimer_dans_ATR(&(*A)->droit, mot);
    }
}

void afficher_ATR_aux(ATR A, Liste * lst, char * mot) {
    char * tmp;
    tmp = (char *) malloc(sizeof(char) * 50);
    if (!A) return;
    afficher_ATR_aux(A->gauche, lst, mot);
    mot[0] = A->lettre;
    if (A->fils->lettre == '\0') {
        strcpy(mot, tmp);
        insere_en_tete(lst, tmp);
    }
    afficher_ATR_aux(A->fils, lst, &mot[1]);
    afficher_ATR_aux(A->droit, lst, mot);
}

void afficher_ATR(ATR A) {
    Liste lst;
    char mot[50];
    if (!A) return;
    afficher_ATR_aux(A, &lst, mot);
    afficher_liste(lst);
    return;
}