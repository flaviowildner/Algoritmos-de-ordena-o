#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

#define MAX 1000000000


int max(int *vetor, int tamanho){
	int i, m = 0;
	for (i = 0; i < tamanho; i++){
		if (vetor[i] > vetor[m])
			m = i;
	}
	return m;
}


int *counting_sort(int *vetor, int tamanho){
	int i = 0;
	int *aux = (int *)malloc((MAX + 1) * sizeof(int));
	int *result = (int *)malloc(tamanho * sizeof(int));

	for (i = 0; i < MAX + 1; i++)
		aux[i] = 0;

	for (i = 0; i < tamanho; i++)
		aux[vetor[i]]++;

	for (i = 1; i < MAX + 1; i++)
		aux[i] += aux[i - 1];

	for (i = 0; i < tamanho; i++)
		result[--aux[vetor[i]]] = vetor[i];

	free(vetor);
	free(aux);
	return result;
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
	vetor = counting_sort(vetor, tamanho);
	t = clock() - t;



	printf("\n%f Segundos.\n", ((float)t) / CLOCKS_PER_SEC);


	free(vetor);
	
	return 0;
}

