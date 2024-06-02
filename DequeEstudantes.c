#include <stdio.h>
#include <stdlib.h>
#include "DequeEstudantes.h"

/*
** Função : Desenvolver um sistema de registro de estudantes
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/

DequeEstudantes* CriaDequeEstudantes(){
  DequeEstudantes *dequeEstudantes = malloc(sizeof(DequeEstudantes));
  dequeEstudantes->inicio = NULL;
  dequeEstudantes->fim = NULL;
  dequeEstudantes->tam = 0;
  return dequeEstudantes;
}


int IsEmptyDeque(DequeEstudantes* dequeEstudantes){
  return (dequeEstudantes->tam == 0);
}


void AdicionaEstudanteInicio(DequeEstudantes *dequeEstudantes, Estudante* estudante){
  ElementoDeque *elemento = malloc(sizeof(ElementoDeque));
  elemento->estudante = estudante;
  elemento->next = dequeEstudantes->inicio;
  if(dequeEstudantes->inicio != NULL){
    dequeEstudantes->inicio->prev = elemento;
  }
  dequeEstudantes->inicio = elemento;
  elemento->prev = NULL;
  if(IsEmptyDeque(dequeEstudantes)){
    dequeEstudantes->fim = elemento;
  }
  dequeEstudantes->tam++;
}


void AdicionaEstudanteFinal(DequeEstudantes *dequeEstudantes, Estudante *estudante){
  ElementoDeque *elemento = malloc(sizeof(ElementoDeque));
  elemento->estudante = estudante;
  elemento->prev = dequeEstudantes->fim;
  if(dequeEstudantes->fim != NULL){
    dequeEstudantes->fim->next = elemento;
  }
  dequeEstudantes->fim = elemento;
  elemento->next = NULL;
  if(IsEmptyDeque(dequeEstudantes)){
    dequeEstudantes->inicio = elemento;
  }
  dequeEstudantes->tam++;
}


Estudante* RemoveEstudanteInicio(DequeEstudantes *dequeEstudantes){
  if(IsEmptyDeque(dequeEstudantes)){
    printf("Não há estudantes no deque de atendimento!\n");
    return NULL;
  }
  ElementoDeque *elemento = dequeEstudantes->inicio;
  Estudante *estudante = elemento->estudante;
  dequeEstudantes->inicio = dequeEstudantes->inicio->next;
  free(elemento);
  dequeEstudantes->tam--;
  return estudante;
}


Estudante* RemoveEstudanteFinal(DequeEstudantes *dequeEstudantes){
  if(IsEmptyDeque(dequeEstudantes)){
    printf("Não há estudantes no deque de atendimento!\n");
    return NULL;
  }
  ElementoDeque *elemento = dequeEstudantes->fim;
  Estudante *estudante = elemento->estudante;
  dequeEstudantes->fim = dequeEstudantes->fim->prev;
  if(dequeEstudantes->fim != NULL){
    dequeEstudantes->fim->next = NULL;
  } else {
    dequeEstudantes->inicio = NULL;
  }
  free(elemento);
  dequeEstudantes->tam--;
  return estudante;
}

void ExibeDeque(DequeEstudantes *dequeEstudantes){
  if(IsEmptyDeque(dequeEstudantes)){
    printf("Não há estudantes no deque de atendimento!\n");
    return;
  }
  ElementoDeque *elemento = dequeEstudantes->inicio;
  while(elemento != NULL){
    if(elemento->estudante != NULL){
      printf("Estudante : %s\n", elemento->estudante->nome);
      printf("Matrícula : %d\n\n", elemento->estudante->matricula);
      elemento = elemento->next;
    }
  }
}

void DestroyDeque(DequeEstudantes *dequeEstudantes){
  ElementoDeque *elemento = dequeEstudantes->inicio;
  ElementoDeque *aux = NULL;
  while(elemento != NULL){
    aux = elemento;
    elemento = elemento->next;
    free(aux);
  }
}