#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"


#define TAILLEINITIALE 100



TABLEAU newArray() {
	TABLEAU tab;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));     // on alloue la mémoire necessaire
	tab.eltsCount = 0;
	tab.size = TAILLEINITIALE;
	if (tab.elt != NULL) {
		for (int i = 0; i < TAILLEINITIALE; ++i) {
			tab.elt[i] = 0;                                   //initialisation avec les zeros
		}
		return tab;
	}
	else {
		tab.elt = NULL;
		return tab;
	}
}
int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if ((*tab).elt == NULL || ((*tab).size + incrementValue) < 1) {         // test de validité
		return -1;
	}
	int* new = tab->elt;
	new = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));              //on alloue la nouvelle mémoire necessaire (plus ou moins)
	if (new != NULL) {
		(*tab).elt = new;
		if (incrementValue < 0) {
			for (int i = 0; i < (*tab).size + incrementValue; ++i) {                           //cas ou l'on veut réduire le tableau on réinitialise le tableau avec des zeros 
				(*tab).elt[i] = new[i];                                                       //mais avec une taille plus petite UTILE POUR L'EXO 5
				(*tab).size = (*tab).size + incrementValue;
				return (*tab).size;
			}
		}
		for (int i = (*tab).size; i < (*tab).size + incrementValue; ++i) {
			(*tab).elt[i] = 0;                                                       //on ajoute les zeros pour la taille ajouté
		}
		(*tab).size = (*tab).size + incrementValue;
		return (*tab).size;
	}
	else {
		(*tab).elt = new;
		return -1;
	}
}

int setElement(TABLEAU* tab, int pos, int element) {
	if ((*tab).elt == NULL || pos < 1) {                      // test de validité
		return 0;
	}
	if (pos - 1 < (*tab).size) {
		(*tab).elt[pos - 1] = element;                        // cas ou l'on a pas besoin d'agrandir le tableau
		return pos;
	}
	else {
		if (incrementArraySize(tab, pos - (*tab).size) != -1) {
			(*tab).elt[pos - 1] = element;                               // on agrandi d'abord le tableaau le rempli de zero puis change la valeur a la position souhaite
			return pos;
		}
		else {
			return 0;
		}
	}
};
int displayElements(TABLEAU* tab, int startPos, int endPos) {
	int temp = 0;
	if (startPos<1 || endPos<1 || startPos>(*tab).size || endPos>(*tab).size) {           //test de validité
		return -1;
	}
	if (startPos > endPos) {                                                              // cas où l'utilisateur inverse les bornes
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {
		printf("%d", (*tab).elt[startPos - 1]);
		return 0;
	}
	for (int i = startPos - 1; i < endPos; ++i) {
		printf("%d ", tab->elt[i]);
	}
	return 0;
};

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int temp = 0;
	if (startPos<1 || endPos<1 || startPos>(*tab).size || endPos>(*tab).size) {       // test de validité
		return -1;
	}
	if (startPos > endPos) {
		temp = startPos;
		startPos = endPos;                                                             // de meme cas où l'utilisateur a échanger les bornes
		endPos = temp;
	}
	if (startPos == endPos) {                                                        // si startpos egale endpos on eneleve qu'un seul element 
		if (startPos == (*tab).size) {
			incrementArraySize(tab, -1);    // si c'est le dernier element alors on a juste a réduire la taille du tableau de 1 cela va juste supprimer le dernier element
			return (*tab).size;
		}
		for (int i = 0; i < (*tab).size - startPos; ++i) {
			(*tab).elt[startPos + i - 1] = (*tab).elt[startPos + i];   //sinon on décale tout vers la gauche puis on enleve le dernier element grace a incrementarraysize
		}
		if (incrementArraySize(tab, -1) == -1) {
			return -1;
		}
		return (*tab).size;
	}
	for (int c = 0; c < (endPos - startPos) + 1; ++c) {               // on repete l'action au dessus où startpos=endpos (end-startpos) fois afin d'enelever (endpos-startpos)elements
		for (int i = 0; i < (*tab).size - startPos; ++i) {
			(*tab).elt[startPos + i - 1] = (*tab).elt[startPos + i];;
		}
		incrementArraySize(tab, -1);
	}
	return (*tab).size;
};