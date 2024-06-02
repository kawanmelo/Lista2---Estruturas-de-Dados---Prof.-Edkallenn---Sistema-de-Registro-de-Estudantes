#ifndef FILA_ESTUDANTES_H
#define FILA_ESTUDANTES_H

#include <stdio.h>
#include "Estudante.h"

/*
** Função : Desenvolver um sistema de registro de estudantes
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/

typedef struct elementoFila ElementoFila;
struct elementoFila{
  Estudante *estudante;
  ElementoFila *next;
  ElementoFila *prev;
};

typedef struct{
  ElementoFila *inicio;
  ElementoFila *fim;
  int tam;
}FilaEstudantes;

FilaEstudantes* CriaFilaEstudantes();
int IsEmptyFila(FilaEstudantes *fila);
void AdiocionaNaFila(FilaEstudantes *fila, Estudante *estudante);
Estudante* ProximoDaFila();
void ExibeFila(FilaEstudantes *fila);
void DestroyFila(FilaEstudantes *fila);

#endif // FILA_ESTUDANTES_H