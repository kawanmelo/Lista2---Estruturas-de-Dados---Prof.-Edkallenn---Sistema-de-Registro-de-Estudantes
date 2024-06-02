#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEstudantes.h"

/*
** Função : Desenvolver um sistema de registro de estudantes
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/

ListaEstudantes* CriaListaEstudantes() {
    ListaEstudantes *lista = (ListaEstudantes*)malloc(sizeof(ListaEstudantes));
    lista->head = NULL;
    lista->tam = 0;
    return lista;
}


int IsEmptyListaEstudantes(ListaEstudantes* listaEstudantes){
  return (listaEstudantes->tam == 0);
}



void AdicionaEstudante(ListaEstudantes *listaEstudante, Estudante *estudante) {
    Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->estudante = estudante;
    novoElemento->next = listaEstudante->head;
    listaEstudante->head = novoElemento;
    listaEstudante->tam++;
}


Estudante* RemoveEstudante(ListaEstudantes *list, int matricula) {
    if (IsEmptyListaEstudantes(list)) {
        printf("Não há estudantes na lista!\n");
        return NULL;
    }
    Elemento *atual = list->head;
    Elemento *anterior = NULL;
    while (atual != NULL && atual->estudante->matricula != matricula) {
        anterior = atual;
        atual = atual->next;
    }
    if (atual == NULL) {
        printf("int not found!\n");
        return NULL;
    }
    if (anterior == NULL) {
        list->head = atual->next;
    } else {
        anterior->next = atual->next;
    }
    list->tam--;
    free(atual);
}



void ExibeListaEstudantes(ListaEstudantes *listaEstudantes){
    if (IsEmptyListaEstudantes(listaEstudantes)) {
        printf("Não há estudantes na lista!\n");
        return;
    }
  Elemento *elemento = listaEstudantes->head;
  while(elemento != NULL){
    if(elemento->estudante != NULL){
      printf("Estudante : %s\n", elemento->estudante->nome);
      printf("Matrícula : %d\n\n", elemento->estudante->matricula);
      elemento = elemento->next;
    }
  }
}

Estudante* BuscaEstudante(ListaEstudantes *listaEstudantes, int matricula){
    Elemento *elemento = listaEstudantes->head;
    while(elemento != NULL && elemento->estudante->matricula != matricula){
        elemento = elemento->next;
    }
    if(elemento == NULL){
        printf("Estudante não encontrado!\n");
        return NULL;
    }
    if(elemento->estudante == NULL){
        printf("Estudante não encontrado!\n");
        return NULL;
    }
    return elemento->estudante;
}


void DestroyListaEstudantes(ListaEstudantes *listaEstudantes){
  Elemento *elemento = listaEstudantes->head;
  while(elemento != NULL){
    Elemento *aux = elemento;
    free(aux);
    elemento = elemento->next;
  }
}