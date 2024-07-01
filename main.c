/*
Trabalho Final Estrutura de Dados I - Universidade Feevale

Implementação do algoritmo Heapsort em C.


Author: Pedro Arthur Zander
*/
#include <stdio.h>

// Função para trocar dois elementos de lugar dentro de um array.
void swap(int *n1, int *n2)
{
    int n = *n1;
    *n1 = *n2;
    *n2 = n;
}

/*
Transforma o array em uma estrutura max heap.
(Árvore binária onde o pai sempre  é maior do que os filhos)
- size é o tamanho do array
- n é o índice do elemento raiz
*/
void buildHeap(int array[], int size, int n)
{
    int bigger = n;

    // Calcula o índice dos filhos
    int leftChild = (2 * n) + 1;
    int rightChild = (2 * n) + 2;

    // Procura qual o filho que é maior que o pai
    if (leftChild < size && array[leftChild] > array[bigger])
    {
        bigger = leftChild;
    }

    if (rightChild < size && array[rightChild] > array[bigger])
    {
        bigger = rightChild;
    }

    // Troca de lugar o maior para o topo da heap, caso o topo não seja o maior
    if (bigger != n)
    {
        swap(&array[n], &array[bigger]);

        // Se utiliza da recursão para processar o resto.
        buildHeap(array, size, bigger);
    }
}

/*
Realiza o heap sort seguindo os passos:
- Constrói uma estrutura max heap
- Repete até que a heap contenha apenas um elemento:
  - Troca o primeiro nó da árvore com o último
  e remove esse primeiro nó (que vai ser o maior elemento), adicionando o no vetor final.
  - Remove o último elemento da heap (que agora estará no topo.)
  - Contrói a heap máxima novamente com os elementos que faltam.
*/
void performHeapSort(int array[], int size)
{
    // Contrói a max heap do array
    for (int i = size / 2 - 1; i >= 0; i--)
        buildHeap(array, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);

        // Contrói novamente a max heap para que o maior elemento seja a raiz
        buildHeap(array, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    int numbers[] = {9, 6, 3, 4, 1, 0, 7, 2, 99, 23};

    int N = sizeof(numbers) / sizeof(numbers[0]);

    performHeapSort(numbers, N);

    printf("O array ordenado é: \n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}