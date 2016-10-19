#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

#define MAX 1000000000


void radix_sort(int *vetor, int tamanho) {
	int i;
	int *b;
	int maior = vetor[0];
	int exp = 1;

	b = (int *)calloc(tamanho, sizeof(int));

	for (i = 0; i < tamanho; i++) {
		if (vetor[i] > maior)
			maior = vetor[i];
	}

	while (maior / exp > 0) {
		int bucket[10] = { 0 };
		for (i = 0; i < tamanho; i++)
			bucket[(vetor[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = tamanho - 1; i >= 0; i--)
			b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
		for (i = 0; i < tamanho; i++)
			vetor[i] = b[i];
		exp *= 10;
	}

	free(b);
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
	radix_sort(vetor, tamanho);
	t = clock() - t;


	printf("\n\n%f Segundos.\n", ((float)t) / CLOCKS_PER_SEC);


	free(vetor);
	return 0;
}