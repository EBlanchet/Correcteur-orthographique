typedef struct noeudBK{
    char * mot;
    int valeur;
    struct areteBK * filsG;
    struct areteBK * frereD;
}NoeudBK, * ArbreBK;

int inserer_dans_ArbreBK(ArbreBK * A, char * mot);

Liste rechercher_dans_ArbreBK(ArbreBK A, char * mot);

ArbreBK creer_ArbreBK(File * dico);

void liberer_ArbreBK(ArbreBK * A);

void afficher_ArbreBK(ArbreBK A);

