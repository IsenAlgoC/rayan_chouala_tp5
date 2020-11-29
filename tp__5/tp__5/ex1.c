#include <stdio.h>
#include <stdlib.h>
#define TAB2SIZE 100
#define TAILLEAJOUT 50

#include "ex1.h"

int initTab(int* tab, int size) {
	if (tab == NULL) {
		return -1;
	}
	if (size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < size; ++i) {
			tab[i] = 0;
		}
	}
	return size;
}
int afficheTab20(int* tab, int size, int nbElts) { //affiche tab mais pour afficher les nb de 1 a 20 comme dit dans l'énoncé
	if (tab == NULL) {
		return -1;
	}
	if (size < 0) {
		return -1;
	}
	if (size < nbElts) {                         //on test les validités
		return -1;
	}
	else {
		for (int i = 0; i < 20; ++i) {
			tab[i] = i + 1;
			printf("%u ", tab[i]);
		}
	}
	return 0;
}
int afficheTab(int* tab, int size, int nbElts) {
	if (tab == NULL) {
		return -1;
	}
	if (size < 0) {
		return -1;
	}
	if (size < nbElts) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; ++i) {
			printf("%u ", tab[i]);
		}
		return 0;
	}
}
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (*nbElts == *size) {
		int* tabnew = (int*)realloc(tab, (TAB2SIZE + TAILLEAJOUT) * sizeof(int)); // on crée un tableau tampon auquel on ajoute la mémoire
		if (tabnew == NULL) {
			return -1;
		}//si ça ne marche pas on renvoie -1
		else { // sinon on remplace tab par tabnew et on change les valeurs.
			tab = tabnew;
			tab[*nbElts] = element;
			*nbElts = *nbElts + 1;
		}
	}
	else {
		tab[*nbElts] = element;
		*nbElts = *nbElts + 1;
	}
	return tab;
}