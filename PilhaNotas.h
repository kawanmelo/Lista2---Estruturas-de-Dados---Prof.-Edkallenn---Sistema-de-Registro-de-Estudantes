#ifndef PILHA_NOTAS_H
#define PILHA_NOTAS_H

#include <stdio.h>


/*
** Função : Desenvolver um sistema de registro de estudantes
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/

typedef struct elementoPilha ElementoPilha;
struct elementoPilha{
  float *notas;
  ElementoPilha *next;
};


typedef struct pilhaNotas PilhaNotas;
struct pilhaNotas{
  ElementoPilha *head;
};

PilhaNotas* CreateStack();
void Push(PilhaNotas *pilhaNotas, float[3]);
int IsEmptyStack(PilhaNotas *pilhaNotas);
float* Pop(PilhaNotas *pilhaNotas);
void Peek(PilhaNotas *pilhaNotas);
void PrintStack(PilhaNotas *pilhaNotas);
void DestroyStack(PilhaNotas *pilhaNotas);

#endif // PILHA_NOTAS_H