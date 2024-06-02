#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estudante.h"

/*
** Função : Desenvolver um sistema de registro de estudantes
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/

Estudante* CriaEstudante(char nome[50], int matricula){
  Estudante *estudante = malloc(sizeof(Estudante));
  strcpy(estudante->nome, nome);
  estudante->matricula = matricula;
  estudante->countPeriodos = 0;
  PilhaNotas *pilhaNotas = CreateStack();
  estudante->pilhaNotas = pilhaNotas;
  return estudante;
}

float* CalculaMedia(Estudante *estudante){
  if(IsEmptyStack(estudante->pilhaNotas)){
    printf("Histórico de notas vazio!");
    return NULL;
  }
  ElementoPilha *elementoPilha = estudante->pilhaNotas->head;
  float somaA, somaB, somaC;
  float count;
  while(elementoPilha != NULL){
    somaA += elementoPilha->notas[0];
    somaB += elementoPilha->notas[1];
    somaC += elementoPilha->notas[2];
    count++;
    elementoPilha = elementoPilha->next;
  }
  float *medias = malloc(sizeof(float) * 3);
  medias[0] = somaA / count;
  medias[1] = somaB / count;
  medias[2] = somaC / count;
  return medias;
}