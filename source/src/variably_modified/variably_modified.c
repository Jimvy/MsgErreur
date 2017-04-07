#include <stdlib.h>
#include <stdio.h>
const int taille=1000;
int tableau[taille];
int main(int argc, char **argv)
{
	int i;
	for (i=0; i<taille; i++)
		printf("%d ", tableau[i]);
	return 0;
}

