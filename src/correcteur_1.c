/* Author : Matthieu Garnier - Elise Blanchet */
/* Creation : 19/03/2022 */
/* Modification : 19/03/2022 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "ATR.h"
#include "Levenshtein.h"

char * recup_fichier(char *nom, int * taille) {
    int taille_fichier, i;
    FILE * f;
    char * tmp;
    f = fopen(nom, "r");
    fseek(f, 0, SEEK_END);
    taille_fichier = ftell(f);
    rewind(f);
    *taille = taille_fichier;
    tmp = (char *) malloc(sizeof(char) * (taille_fichier + 1));
    if (!tmp) return NULL;
    for (i = 0; i < taille_fichier; i++) {
        tmp[i] = fgetc(f);
        if(tmp[i] == EOF) break;
    }
    fclose(f);
    tmp[taille_fichier] = '\0';
    return tmp;
}

Liste stock_mots(char *recup, int taille) {
    int i, ecrit_mot = 0;
    char mot[50];
    Liste tmp;
    tmp = NULL;
    for (i = 0; recup[i] != '\0'; i++) {
        if (ispunct(recup[i]) || isspace(recup[i])) {
            if (ecrit_mot) {
                mot[ecrit_mot] = '\0';
                if (!insere_en_tete(&tmp, mot)) return NULL;
                ecrit_mot = 0;

                mot[ecrit_mot] = '\0';
            }
        } else {
            if (isalpha(recup[i])){
                mot[ecrit_mot] = tolower(recup[i]);
                ecrit_mot++;
            } else {
                ecrit_mot = 0;
                mot[ecrit_mot] = '\0';
                do {
                    i++;
                } while (!ispunct(recup[i]) && !isspace(recup[i]));
            }
        }
    }
    if (ecrit_mot) {
        mot[ecrit_mot] = '\0';
        if (!insere_en_tete(&tmp, mot)) return NULL;
    }
    return tmp;
}

int est_dans_dico(char * mot, ATR dico) {
    if (!dico) return 0;
    if (!mot[0]) {
        if (dico->lettre == '\0')
            return 1;
        return 0;
    }
    if (mot[0] == dico->lettre) return est_dans_dico(&mot[1], dico->fils);
    if (mot[0] < dico->lettre) return est_dans_dico(&mot[0], dico->gauche);
    return est_dans_dico(&mot[0], dico->droit);
}

char * corrige(Liste dico, char * mot) {
    int dmin, d;
    char * tmp;
    dmin = 10000;
    for (; dico; dico = dico->suivant) {
        d = Levenshtein(dico->chaine, mot);
        if (d <= dmin) {
            tmp = dico->chaine;
            dmin = d;
        }
    }
    return tmp;
}

int main(int argc, char ** argv) {
    Liste lst, erreurs, lstdico, correction, tmperr;
    ATR dico;
    FILE * fichier;
    char * texte, dictionnaire[50];
    int taille;
    lst = NULL;
    lstdico = NULL;
    texte = recup_fichier(argv[1], &taille);
    lst = stock_mots(texte, taille);
    dico = creer_ATR_vide();
    fichier = fopen(argv[2], "r");
    while (fscanf(fichier, "%s", dictionnaire) != EOF){
        inserer_dans_ATR(&dico, dictionnaire);
        insere_en_tete(&lstdico, dictionnaire);
    }
    erreurs = NULL;
    for (; lst; lst = lst->suivant) {
        if (!est_dans_dico(lst->chaine, dico))
            insere_en_tete(&erreurs, lst->chaine);
    }
    correction = NULL;
    tmperr = erreurs;
    for (; tmperr; tmperr = tmperr->suivant) {
        insere_en_tete(&correction, corrige(lstdico, tmperr->chaine));
    }
    printf("Voici les mots mal orthographiés :\n");
    afficher_liste(erreurs);
    printf("\nVoici des propositions de corrections pour chaque mots :\n");
    afficher_liste_inverse(correction);
    return 0;
}