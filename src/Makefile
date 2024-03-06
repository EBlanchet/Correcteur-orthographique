CFLAGS = -ansi -pedantic -Wall -g
OBJ0 = correcteur_0.o ATR.o Listes.o
OBJ1 = correcteur_1.o ATR.o Listes.o Levenshtein.o
CC = gcc

Correcteur1: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

Correcteur0: $(OBJ0)
	$(CC) -o $@ $^ $(CFLAGS)

correcteur_1.o: correcteur_1.c ATR.h Levenshtein.h
	$(CC) -c $< $(CFLAGS)

correcteur_0.o: correcteur_0.c ATR.h
	$(CC) -c $< $(CFLAGS)

Levenshtein.o: Levenshtein.c Levenshtein.h
	$(CC) -c $< $(CFLAGS)

ATR.o: ATR.c ATR.h Listes.h
	$(CC) -c $< $(CFLAGS)

Listes.o: Listes.c Listes.h
	$(CC) -c $< $(CFLAGS)