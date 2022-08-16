//todos os tads precisam de contador !!//

#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct float_vector
{
    int capacity; //numero maximo de elementos
    int size; // numero atual de elementos
    float *data; // vetor de float
};

/**
 * @brief  cria(aloca) um vetor de floats com uma data capacidade.
 * 
 * @param capacity capacidade do vetor.
 * @return FloatVector* de um vetor de floats alocados/criado. 
 */

FloatVector *create(int tam)
{

    FloatVector *vet = (FloatVector*) calloc (1, sizeof(FloatVector));
    vet -> capacity = tam;
    vet -> size = 0;
    vet -> data = (float*) calloc (vet -> capacity, sizeof(float));
  
  
    return vet;
 }


 void destroy(FloatVector **vet_ref)
 {

    FloatVector *vet = *vet_ref;
    free(vet -> data);
    free(vet);
    *vet_ref = NULL;

 }


int size(const FloatVector *vector)
{
    return vector -> size;

}


int capacity(const FloatVector *vector)
{
    return vector -> capacity;

}


float at(const FloatVector *vector, int pos)
{

    //forma de driblar a saida do programa
    //recursividade, chamar a funcao novamente ate receber a posicao existente

    if(pos < 0 || pos >= vector -> size )
    {
        fprintf(stderr, "ERRO: posicao invalidade\n");
        fprintf(stderr, "Endereco [%d] fora do limite\n");

        exit(EXIT_FAILURE);
    }

    return vector -> data[pos];

}


//sem verificacao do elemento na posicao
//ele para quando o vetor estiver cheio(capacity == size)
float get(const FloatVector *vector, int endereco)
{
   return vector -> data[endereco];   
   
}


void append(FloatVector *vector, float n)
{
  if(vector -> size == vector -> capacity)
  {
    fprintf(stderr, "ERROR in append\nVector is full");
    exit(EXIT_FAILURE);
  }
  
  vector -> size++;
  vector -> data[vector -> size] = n;

}


void print(const FloatVector *vector)
{
    int a = 1;

    printf("\nCapacidade: [%d] \nTamanho: [%d] \nElementos: \n", vector -> capacity, vector -> size);
    while(a <= vector -> size)
    {
    printf("[%f]\n", vector -> data[a]);
    a++;
    }
}