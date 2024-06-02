# Sistema de Registro de Estudantes

Este projeto consiste no desenvolvimento de um sistema de registro de estudantes em C, utilizando Tipos Abstratos de Dados (TADs), Listas Encadeadas, Pilhas, Filas e Deques para gerenciar informações dos estudantes.

## Objetivo

O objetivo deste projeto é criar um sistema capaz de registrar e gerenciar informações de estudantes, como nome, número de matrícula, notas, etc., utilizando diferentes estruturas de dados.

## Funcionalidades

O sistema oferece as seguintes funcionalidades:

1. **Definição do TAD Estudante**: Cria um TAD para representar as informações de um estudante.
2. **Listas Encadeadas**: Utiliza listas encadeadas para armazenar informações dos estudantes, permitindo adição, remoção e busca de estudantes na lista.
3. **Pilhas**: Implementa uma pilha para armazenar históricos de notas de um estudante, empilhando o histórico anterior ao atualizar as notas.
4. **Filas**: Utiliza uma fila para simular uma fila de espera de estudantes para matrícula em disciplinas, permitindo adicionar estudantes à fila e remover quando matriculados.
5. **Deques**: Utiliza um deque para gerenciar uma lista de espera para atendimento, adicionando estudantes no início ou final da fila de espera.
6. **Funções Adicionais**: Implementa funções para calcular médias de notas de um estudante ou realizar outras operações específicas nos dados dos estudantes.

## Estrutura dos Arquivos

O projeto está dividido em vários arquivos principais, cada um responsável por uma parte específica do sistema:

- **ListaEstudantes.c/h**: Implementa a lista encadeada para armazenar informações dos estudantes.
- **FilaEstudantes.c/h**: Implementa a fila para o agendamento de matrículas em disciplinas.
-  **PilhaNotas.c/h**: Implementa a pilha para lidar com o histórico de notas dos estudantes.
- **DequeEstudantes.c/h**: Implementa o deque para gerenciar a lista de espera para atendimento.
- **main.c**: Contém a função `main` e a interface de usuário para interagir com o sistema de registro.

## Contato
- **Autor:** Kawan Melo
- **Email:** [kawangcmelo@gmail.com](mailto:kawangcmelo@gmail.com)
- **LinkedIn:** [linkedin.com/in/kawanmelo](https://linkedin.com/in/kawanmelo)
