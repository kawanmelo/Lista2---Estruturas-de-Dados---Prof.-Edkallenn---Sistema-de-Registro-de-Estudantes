#include <stdio.h>
#include <stdlib.h>
#include "FilaEstudantes.h"

/*
** Função : Desenvolver um sistema de registro de estudantes
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/

FilaEstudantes* CriaFilaEstudantes(){
  FilaEstudantes *fila = malloc(sizeof(FilaEstudantes));
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tam = 0;
  return fila;
}


int IsEmptyFila(FilaEstudantes *fila){
  return (fila->tam == 0);
}


void AdiocionaNaFila(FilaEstudantes *fila, Estudante *estudante){
  ElementoFila *elemento = malloc(sizeof(ElementoFila));
  elemento->estudante = estudante;
  elemento->prev = fila->fim;
  elemento->next = NULL;
  if(fila->fim != NULL){
    fila->fim->next = elemento;
  }
  if(IsEmptyFila(fila)){
    fila->inicio = elemento;
  }
  fila->fim = elemento;
  fila->tam++;
}


Estudante* ProximoDaFila(FilaEstudantes *fila){
  if(IsEmptyFila(fila)){
    printf("Não há estudantes na fila!");
    return NULL;
  }
  ElementoFila *elemento = fila->inicio;
  Estudante *estudante = elemento->estudante;
  fila->inicio = fila->inicio->next;
  fila->tam--;
  free(elemento);
  return estudante;
}

void ExibeFila(FilaEstudantes *fila) {
  if (IsEmptyFila(fila)) {
    printf("Não há estudantes na fila!\n");
    return;
    }
  ElementoFila *elemento = fila->inicio;
  while (elemento != NULL) {
    if (elemento->estudante != NULL) {
      printf("Estudante : %s\n", elemento->estudante->nome);
      printf("Matrícula : %d\n\n", elemento->estudante->matricula);
    }
    elemento = elemento->next;
  }
}


void DestroyFila(FilaEstudantes *fila){
  ElementoFila *elemento = fila->inicio;
  while(elemento != NULL){
    ElementoFila *aux = elemento;
    free(aux);
    elemento = elemento->next;
  }
}