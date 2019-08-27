/*
Trabalho de Estrutura de Dados
Tema: Sistema que simula de forma simples o funcionamento de um sistema de arquivos, com funções como adicionar pasta/arquivo, navegar entre diretórios e remoção de pastas/arquivos.
Alunos: Alisson Cerutti, Mitchell Luiz Damasceno Lopes, Thiago Leite de Oliveira Acco
https://github.com/cerutti/File-System-Simulation-using-C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Directory.h"
#include "Url.h"


int main() {
    char Op[5], Nome[50], NomeAnt[50];

    url *Url = (url *) malloc(sizeof (url)); //Aloca url
    InicializaUrl(Url); //Inicializa url

    Directory* Root = Inicializar(); //inicializa o diretorio
    Directory* Atual = Root; //atribui ao atual o root
    InsereElementoUrl(Url, Atual->Nome); //insere o root na url
    do {
        MostraUrl(Url); //lista a url

        fflush(stdin);
        gets(Op); // Pega a nome
        if (strcmp(Op, "ls") == 0) {

            MostrarDiretorios(Atual);

        } else if (strcmp(Op, "ma") == 0) {

            fflush(stdin);
            gets(Nome); // Pega o nome
            Atual = InserirFile(Atual, Nome);

        } else if (strcmp(Op, "mp") == 0) {

            fflush(stdin);
            gets(Nome); // Pega o nome
            Atual = InserirDirectory(Atual, Nome);

        } else if (strcmp(Op, "cd ..") == 0) {

            strcpy(NomeAnt, Atual->Nome);

            Atual = VoltarDiretorio(Atual);

            if (strcmp(Atual->Nome, NomeAnt) != 0)
                DesempilhaElementoUrl(Url);

        } else if (strcmp(Op, "cd") == 0) {

            strcpy(NomeAnt, Atual->Nome);

            fflush(stdin);
            gets(Nome); // Pega o nome

            Atual = EntraDiretorio(Atual, Nome);

            if (strcmp(Atual->Nome, NomeAnt) != 0)
                InsereElementoUrl(Url, Atual->Nome);

        } else if (strcmp(Op, "rm") == 0) {

            fflush(stdin);
            gets(Nome); // Pega o nome

            Atual = DeletaElemento(Atual, Nome);

        } else if (strcmp(Op, "ex") == 0) {

            break;

        } else {

            printf("comando invalido \n");
        }

    } while (1);
    FinalizaPilha(Url); //Finaliza URL
    return 0;
}
