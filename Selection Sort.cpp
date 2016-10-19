#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

#define MAX 2000000


void selection_sort(int vetor[], int tam)
{
	int i, j, min, aux;
	for (i = 0; i < (tam - 1); i++)
	{
		min = i;
		for (j = (i + 1); j < tam; j++) {
			if (vetor[j] < vetor[min])
				min = j;
		}
		if (i != min) {
			aux = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = aux;
		}
	}
}

void imprimir(int *vetor, int tamanho){
	int i = 0;
	for (i = 0; i < tamanho; i++)
		printf("%d\n", vetor[i]);
}



int main()
{									
	int tamanho, i, *vetor, op;
	srand(time(NULL));

	clock_t t;

	scanf_s("%d", &tamanho);
	vetor = (int *)malloc(tamanho * sizeof(int));

	printf("Ordem inicial:\n1-Ordem aleatoria.\n2-Ordem crescente.\n3-Ordem decrescente.\n");
	scanf_s("%d", &op);

	switch (op){
	case 1:
		for (i = 0; i < tamanho; i++)
			vetor[i] = rand() % MAX;
		break;
	case 2:
		for (i = 0; i < tamanho; i++)
			vetor[i] = i;
		break;
	case 3:
		for (i = 0; i < tamanho; i++)
			vetor[i] = tamanho - i - 1;
		break;
	}

	t = clock();
	selection_sort(vetor, tamanho);
	t = clock() - t;


	printf("\n%f seconds.\n", ((float)t) / CLOCKS_PER_SEC);



	free(vetor);
	return 0;
}