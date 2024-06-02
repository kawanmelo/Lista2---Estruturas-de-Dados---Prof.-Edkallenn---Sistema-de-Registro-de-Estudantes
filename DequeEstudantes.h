#ifndef DEQUE_ESTUDANTES_H
#define DEQUE_ESTUDANTES_H

#include <stdio.h>
#include "Estudante.h"

/*
** Função : Desenvolver um sistema de registro de estudantes
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/

typedef struct elementoDeque ElementoDeque;
struct elementoDeque{
  Estudante *estudante;
  ElementoDeque *next;
  ElementoDeque *prev;
};

typedef struct{
  ElementoDeque *inicio;
  ElementoDeque *fim;
  int tam;
}DequeEstudantes;

DequeEstudantes* CriaDequeEstudantes();
int IsEmptyDeque(DequeEstudantes* dequeEstudantes);
void AdicionaEstudanteInicio(DequeEstudantes *dequeEstudantes, Estudante* estudante);
void AdicionaEstudanteFinal(DequeEstudantes *dequeEstudantes, Estudante *estudante);
Estudante* RemoveEstudanteInicio(DequeEstudantes *dequeEstudantes);
Estudante* RemoveEstudanteFinal(DequeEstudantes *dequeEstudantes);
void ExibeDeque(DequeEstudantes *dequeEstudantes);
void DestroyDeque(DequeEstudantes *dequeEstudantes);

#endif // DEQUE_ESTUDANTES_H