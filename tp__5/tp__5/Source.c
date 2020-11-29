#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"
#define TAB2SIZE 100


int main() {
	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 100;
	printf("\n");
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));//Initialisation dynamique du tableau
	if (myTab2 != NULL) { initTab(myTab2, tabSize); }
	else { printf("mémoire insuffisante"); return(-1); }
	printf("%d\n", initTab(myTab2, 100));//Initialise le tableau
	printf("Le tableau initialise est :");
	printf("\n");
	afficheTab(myTab2, tabSize, 100);           //affiche le tableau initialisé
	printf("\n");
	int* tab3;
	tab3 = ajoutElementDansTableau(myTab2, &tabSize, &nbElts, 40);     //test de l'ajout d'un element qui vaut ici 40
	for (int i = 0; i < nbElts; i++)
	{
		printf("%u ", tab3[i]);
	}

}