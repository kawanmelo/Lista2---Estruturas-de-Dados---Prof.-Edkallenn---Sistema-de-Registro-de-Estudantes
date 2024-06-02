#include "DequeEstudantes.h"
#include "FilaEstudantes.h"
#include "ListaEstudantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Função : Desenvolver um sistema de registro de estudantes.
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 01.05.2024
** Observações: Null
*/

void LimpaTela() {
  printf("Aperte enter para continuar...");
  getchar();
  system("clear");
}

int main() {
  ListaEstudantes *listaEstudantes = CriaListaEstudantes();
  FilaEstudantes *filaMatricula = CriaFilaEstudantes();
  DequeEstudantes *dequeAtendimento = CriaDequeEstudantes();

  int opcao, matricula;
  float notas[3];
  char nome[50];
  Estudante *estudante;

  do {
    printf("\n--- Registro de Estudantes ---\n");
    printf("1. Cadastrar Estudante\n");
    printf("2. Matricular próximo estudante da fila\n");
    printf("3. Cancelar matrícular do estudante\n");
    printf("4. Atualizar notas do estudante\n");
    printf("5. Adicionar estudante em deque de atendimento\n");
    printf("6. Chamar próximo estudante do deque de atendimento\n");
    printf("7. Calcular média do estudante\n");
    printf("8. Exibir histórico de notas do estudante\n");
    printf("9. Exibir lista de estudantes\n");
    printf("10. Exibir estudantes na fila da matrícula\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Limpar o buffer do teclado

    switch (opcao) {
    case 1:
      printf("Número da matrícula : ");
      scanf("%d", &matricula);
      getchar(); // Limpar o buffer do teclado
      printf("Nome: ");
      fgets(nome, sizeof(nome), stdin);
      nome[strcspn(nome, "\n")] = 0; // Remover o caractere de nova linha
      estudante = CriaEstudante(nome, matricula);
      AdiocionaNaFila(filaMatricula, estudante);
      printf("Estudante adicionado na fila de espera!\n");
      LimpaTela();
      break;
    case 2:
      if (IsEmptyFila(filaMatricula)) {
        printf("Não há estudantes na fila!\n");
        LimpaTela();
        break;
      }
      estudante = ProximoDaFila(filaMatricula);
      if (estudante != NULL) {
        AdicionaEstudante(listaEstudantes, estudante);
        printf("%s matriculado com sucesso!\n", estudante->nome);
      }
      LimpaTela();
      break;
    case 3:
      if (IsEmptyListaEstudantes(listaEstudantes)) {
        printf("Não há estudantes na lista!\n");
        LimpaTela();
        break;
      }
      printf("Informe o número da matrícula do estudante : ");
      scanf("%d", &matricula);
      getchar();
      estudante = RemoveEstudante(listaEstudantes, matricula);
      if (estudante != NULL) {
        printf("Matrícula do aluno %s cancelada com sucesso!\n",estudante->nome);
      }
      LimpaTela();
      break;
    case 4:
      printf("Número da matrícula do estudante: ");
      scanf("%d", &matricula);
      estudante = BuscaEstudante(listaEstudantes, matricula);
      if (estudante != NULL) {
        if (estudante->countPeriodos > 0) {
          Push(estudante->pilhaNotas, estudante->notas);
        }
        printf("Nota disicplina 1 (Portugês) : ");
        scanf("%f", &estudante->notas[0]);
        printf("Nota disicplina 2 (Matemática) : ");
        scanf("%f", &estudante->notas[1]);
        printf("Nota disicplina 3 (Inglês) : ");
        scanf("%f", &estudante->notas[2]);
        estudante->countPeriodos++;
        printf("Notas do estudante %s atualizadas com sucesso!\n",
               estudante->nome);
      }
      getchar();
      LimpaTela();
      break;
    case 5:
      printf("Número da matrícula do estudante: ");
      scanf("%d", &matricula);
      getchar();
      estudante = BuscaEstudante(listaEstudantes, matricula);
      if (estudante != NULL) {
        AdicionaEstudanteFinal(dequeAtendimento, estudante);
        printf("Estudante %s adicionado ao deque de atendimentos\n",
               estudante->nome);
      }
      LimpaTela();
      break;
    case 6:
      if (IsEmptyDeque(dequeAtendimento)) {
        printf("Não há estudantes no deque de antedimento!\n");
        LimpaTela();
        break;
      }
      estudante = RemoveEstudanteInicio(dequeAtendimento);
      if (estudante == NULL) {
        printf("Não há estudantes no deque de antedimento!\n");
        LimpaTela();
        break;
      }
      printf("Estudante %s foi chamado para o antedimento!\n", estudante->nome);
      LimpaTela();
      break;
    case 7:
      if (IsEmptyListaEstudantes(listaEstudantes)) {
        printf("Não há estudantes na lista!\n");
        LimpaTela();
        break;
      }
      printf("Número da matrícula do estudante: ");
      scanf("%d", &matricula);
      getchar();
      estudante = BuscaEstudante(listaEstudantes, matricula);
      if (estudante != NULL) {
        if (estudante->pilhaNotas->head == NULL) {
          printf("O estudante ainda não possui notas suficientes para calculo de média!\n");
          LimpaTela();
          break;
        }
        float *medias = CalculaMedia(estudante);
        printf("Média em Português : %.2f\n", medias[0]);
        printf("Média em Matemática : %.2f\n", medias[1]);
        printf("Média em Inglês : %.2f\n", medias[2]);
      }
      LimpaTela();
      break;
    case 8:
      if (IsEmptyListaEstudantes(listaEstudantes)) {
        printf("Não há estudantes na lista!\n");
        LimpaTela();
        break;
      }
      printf("Número da matrícula do estudante: ");
      scanf("%d", &matricula);
      getchar();
      estudante = BuscaEstudante(listaEstudantes, matricula);
      if (estudante != NULL) {
        if (estudante->pilhaNotas->head == NULL) {
          printf("O Estudante ainda não possui histórico de notas!\n");
          LimpaTela();
          break;
        }
        PrintStack(estudante->pilhaNotas);
      }
      LimpaTela();
      break;
    case 9:
      ExibeListaEstudantes(listaEstudantes);
      LimpaTela();
      break;
    case 10:
      ExibeFila(filaMatricula);
      LimpaTela();
      break;
    case 0:
      printf("Saindo do sistema...\n");
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
      LimpaTela();
      break;
    }
    //   VerificarTarefasAgendadas(tarefasAgendadas, toDoList);
  } while (opcao != 0);

  return 0;
}