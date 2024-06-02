#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaNotas.h"

/*
** Função : Desenvolver um sistema de registro de estudantes
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/




PilhaNotas* CreateStack(){
  PilhaNotas *pilhaNotas = malloc(sizeof(PilhaNotas));
  pilhaNotas->head = NULL;
  return pilhaNotas;
}

void Push(PilhaNotas *pilhaNotas, float notas[3]){
  ElementoPilha *elementoPilha = malloc(sizeof(ElementoPilha));
  elementoPilha->notas = notas;
  if(pilhaNotas->head != NULL){
    elementoPilha->next = pilhaNotas->head;
  }
  pilhaNotas->head = elementoPilha;
}

int IsEmptyStack(PilhaNotas *pilhaNotas){
  return (pilhaNotas->head == NULL);
}

float* Pop(PilhaNotas *pilhaNotas){
  if(IsEmptyStack(pilhaNotas)){
    printf("Pilha vazia!\n");
    return NULL;
  }
  ElementoPilha *elementoPilha = pilhaNotas->head;
  float *notas = elementoPilha->notas;
  if(pilhaNotas->head->next != NULL){
    pilhaNotas->head = pilhaNotas->head->next;
  }
  free(elementoPilha);
  return notas;
}

void Peek(PilhaNotas *pilhaNotas){
  if(IsEmptyStack(pilhaNotas)){
    printf("Pilha vazia!\n");
    return;
  }
  printf("Notas do período anterior\n");
  printf("Nota Portugês : %.2f\n", pilhaNotas->head->notas[0]);
  printf("Nota Matemática : %.2f\n", pilhaNotas->head->notas[1]);
  printf("Nota Inglês : %.2f\n\n", pilhaNotas->head->notas[2]);
}

void PrintStack(PilhaNotas *pilhaNotas){
  if(IsEmptyStack(pilhaNotas)){
    printf("Pilha vazia!\n");
    return;
  }
  ElementoPilha *element = pilhaNotas->head;
  int count=1;
  while(element != NULL){
    printf("%dº Período\n", count);
    printf("Nota Portugês : %.2f\n", element->notas[0]);
    printf("Nota Matemática : %.2f\n", element->notas[1]);
    printf("Nota Inglês : %.2f\n\n", element->notas[2]);
    count++;
    element = element->next;
  }
}


void DestroyStack(PilhaNotas *pilhaNotas){
  ElementoPilha *element = pilhaNotas->head;
  while(element != NULL){
    ElementoPilha *aux = element->next;
    free(element);
    element = aux;
  }
  free(pilhaNotas);
}
