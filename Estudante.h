#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <stdio.h>
#include "PilhaNotas.h"

/*
** Função : Desenvolver um sistema de registro de estudantes.
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Vinculei a estrutura de pilha das notas na estrutura do estudante a fim de  facilitar o manuseio do histórico de notas.
*/

typedef struct {
char nome[50];
int matricula;
float notas[3];
int countPeriodos;
PilhaNotas *pilhaNotas;
} Estudante;

Estudante* CriaEstudante(char nome[50], int matricula);
float* CalculaMedia(Estudante *estudante);

#endif // ESTUDANTE_H