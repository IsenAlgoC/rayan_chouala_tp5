#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

int main() {
	TABLEAU tab;
	tab = newArray();
	//incrementArraySize(&tab,12);
	printf("\n");
	//setElement(&tab, 11, 4);
	//displayElements(&tab, 105, 105);
	printf("\n");
	//setElement(&tab, 100, 48);
	printf("\n");
	printf("%d ", deleteElements(&tab, 14, 1));
	for (int i = 0; i < tab.size; ++i) {
		printf("%d ", tab.elt[i]);
	}
	printf("\n");
	system("pause");
	return(EXIT_SUCCESS);
}