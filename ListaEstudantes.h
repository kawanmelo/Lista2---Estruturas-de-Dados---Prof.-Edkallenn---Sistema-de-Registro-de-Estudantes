#ifndef LISTA_ESTUDANTES_H
#define LISTA_ESTUDANTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estudante.h"

/*
** Função : Desenvolver um sistema de registro de estudantes.
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/

typedef struct elemento Elemento;
struct elemento{
  Estudante *estudante;
  Elemento *next;
};

typedef struct{
  Elemento *head;
  int tam;
}ListaEstudantes;

ListaEstudantes* CriaListaEstudantes();
int IsEmptyListaEstudantes(ListaEstudantes* listaEstudantes);
void AdicionaEstudante(ListaEstudantes *listaEstudantes, Estudante* estudante);
Estudante* RemoveEstudante(ListaEstudantes *listaEstudantes, int matricula);
void ExibeListaEstudantes(ListaEstudantes *listaEstudantes);
Estudante* BuscaEstudante(ListaEstudantes *listaEstudantes, int matricula);
void DestroyListaEstudantes(ListaEstudantes *listaEstudantes);

#endif // LISTA_ESTUDANTES_H