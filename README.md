# Correcteur-orthographique
Implémentation d'un mini correcteur orthographique

# Etape 1 : recherche des mots mal orthographié
Dans ce sujet, on appelle dictionnaire un ensemble de mots qui, par convention, sont correctement orthographiés. <p>
En machine, un dictionnaire sera toujours sauvegardé sous forme d’un fichier texte dont l’extension est .dico. Il contiendra toujours un et un seul mot par ligne. Les mots n’y sont pas nécessairement classés par ordre alphabétique. <p>
En mémoire, l’ensemble des mots du dictionnaire sera contenu dans un arbre lexicographique implémenté sous forme d’arbre ternaire de recherche (ATR, en abrégé).

# Etape 2 : Correction orthographique par force brute
On appelle distance de Levenshtein entre deux chaînes de caractères s et t, et on note L(s, t), le nombre minimal d’étapes pour transformer s en t en effectuant les opérations suivantes : <p>
• substitution de deux caractères ;<p> 
• insertion d’un caractère ; <p>
• suppression d’un caractère.<p>
Etant donnée une chaine de caractères s, on note l(s) sa longueur et s[i] son i-ième caractère. s’ est aussi la chaine de caractères privée de son premier élément. Avec ses notations, la distance de Levenshtein se calcule récursivement comme suit : <p>

<img width="499" alt="Capture d’écran 2024-03-06 à 18 47 07" src="https://github.com/EBlanchet/Correcteur-orthographique/assets/86469825/bb74dfd3-ee88-4fc7-8961-ce270497844b">


Par exemple, L("dure", "gare") = 2 en modifiant ’d’ en ’g’, puis ’u’ en ’a’ et L("avait", "saint") ≥ 3 grâce à la suite de transformation de mots : "avait"−→"avaint"−→"vaint"−→"saint" . <p>
La distance de Levenshtein est une vraie distance, au sens mathématique du terme. En particulier, une inégalité triangulaire y est associée : si u,v et w sont trois mots,alors : L(u,w)≤L(u,v)+L(v,w) .


# Utilisation
L’étape 1 peut donc être exécutée avec la commande suivante : make Correcteur0 <p>
Et l’étape 2 avec la commande suivante : make Correcteur1 <p>
Pour lancer ce sera donc : ./Correcteur1 a_corriger_0/1/2.txt dico_1/2.dico
