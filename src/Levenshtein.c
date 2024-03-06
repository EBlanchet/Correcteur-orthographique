#include <string.h>

#include "Levenshtein.h"

int min(int un, int deux) {
    if (un < deux) return un;
    return deux;
}

int max(int un, int deux) {
    if (un > deux) return un;
    return deux;
}

int Levenshtein(char * un, char * deux) {
    if (un[0] == deux[0]) return Levenshtein(&un[1], &deux[1]);
    if (min(strlen(un), strlen(deux)) == 0) return max(strlen(un), strlen(deux));
    return 1 + min(min(Levenshtein(&un[1], deux), Levenshtein(un, &deux[1])), Levenshtein(&un[1], &deux[2]));
}