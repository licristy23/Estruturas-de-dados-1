#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mergesort(int arr[], int inicio, int fim);
void merge(int arr[], int inicio, int meio, int fim);

int main()
{
    int arr[] = {3, 0, 7, 1, 5, 2, 4, 6};

}

int mergesort(int arr[], int inicio, int fim)
{

    if(inicio < fim)
    {
        int meio = inicio + (fim - inicio) /2;

        mergesort(arr, inicio, meio);
        mergesort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}

void merge(int arr[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio +1;
    int n2 = fim - meio;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1 ; i++)
    {
        L[i] = arr[inicio + 1];
    }

    for(int i = 0; i < n2 ; i++)
    {
        R[i] = arr[meio + 1]; //pensar            
    }

    int i = 0, j= 0, k =0; // i varrer o lado direito, j varrer lado esquerdo e k varrer o 
    // laco para saber se ja chegou no final de um sub vetor
    while(i < n1 && j <n2)
    {
        if(L[i] <= R[j]) //verificar quem é maior
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (j < n2) //pegou o que sobrou
    {
        arr[k] = R[j];
        j++;
        k++;
    }

     while (i < n1) //pegou o que sobrou
    {
        arr[k] = L[j];
        i++;
        k++;
    }

   // testar a mergsort, tad



}