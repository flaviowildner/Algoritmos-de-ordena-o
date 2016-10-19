#include "stdafx.h"
#include <stdlib.h>
#include <time.h>


#define MAX 1000000000


void heap_sort(int *a, int n) {
	int i = n / 2, pai, filho, t;

	for (;;){
		if (i > 0) {
			i--;
			t = a[i];
		}
		else {
			n--;
			if (n == 0)
				return;
			t = a[n];
			a[n] = a[0];
		}

		pai = i;

		filho = i * 2 + 1;

		while (filho < n) {
			if ((filho + 1 < n) && (a[filho + 1] > a[filho]))
				filho++;
			if (a[filho] > t) {
				a[pai] = a[filho];
				pai = filho;
				filho = pai * 2 + 1;
			}
			else {
				break;
			}
		}
		a[pai] = t;
	}
}

void imprimir(int *vetor, int tamanho){
	int i = 0;
	for (i = 0; i < tamanho; i++)
		printf("%d\n", vetor[i]);
}



int main()
{
	int tamanho, i, op;
	int *vetor;
	srand(time(NULL));

	clock_t t;
																				
	scanf_s("%d", &tamanho);
	vetor = (int *)malloc(tamanho * sizeof(int));

	printf("Ordem inicial:\n1-Ordem aleatoria.\n2-Ordem crescente.\n3-Ordem decrescente.\n");
	scanf_s("%d", &op);

	switch (op){
	case 1:
		for (i = 0; i < tamanho; i++)
			vetor[i] = rand() % tamanho;
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
	//imprimir(vetor, tamanho);
	//printf("\n");
	heap_sort(vetor, tamanho);
	//imprimir(vetor, tamanho);
	t = clock() - t;


	printf("\n%f Segundos.\n", ((float)t) / CLOCKS_PER_SEC);


	free(vetor);
	return 0;
}