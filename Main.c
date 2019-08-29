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

void copyStr(char dest[], char orig[],int ini, int fim){
    int i=0;
    while(i<fim && orig[i+ini] !='\0'&& orig[i+ini] != '\n'){
        dest[i] = orig[i+ini];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    char cmdStr[55], Op[5];

    char Nome[50], NomeAnt[50], Aux[20];
    int i,j = 0;

    url *Url = (url *) malloc(sizeof (url)); //Aloca url
    InicializaUrl(Url); //Inicializa url

    Directory* Root = Inicializar(); //inicializa o diretorio
    Directory* Atual = Root; //atribui ao atual o root
    InsereElementoUrl(Url, Atual->Nome); //insere o root na url
    do {
        MostraUrl(Url); //lista a url

        fflush(stdin);
        fgets(cmdStr,55,stdin);

        //printf("%d\n", strcmp(cmdStr, "cd ..") == 0);

        if(strncmp(cmdStr, "cd ..", 5) == 0){
          strcpy(Op, cmdStr);
        }
        else{
        copyStr(Nome,cmdStr,3,55);
        copyStr(Op,cmdStr,0,2);
        //printf("%s\n", Nome);
        //printf("%s\n", Op);
        }
        //printf("%s\n", Op);

        if (strncmp(Op, "ls", 2) == 0) {

            MostrarDiretorios(Atual);

        } else if (strncmp(Op, "ma", 2) == 0) {

            //fflush(stdin);
            //gets(Nome); // Pega o nome
            Atual = InserirFile(Atual, Nome);

        } else if (strncmp(Op, "mp", 2) == 0) {

            //fflush(stdin);
            //gets(Nome); // Pega o nome
            Atual = InserirDirectory(Atual, Nome);

        } else if (strncmp(Op, "cd ..", 5) == 0) {
            strcpy(NomeAnt, Atual->Nome);

            Atual = VoltarDiretorio(Atual);

            if (strcmp(Atual->Nome, NomeAnt) != 0)
                DesempilhaElementoUrl(Url);

        } else if (strncmp(Op, "cd", 2) == 0) {

            strcpy(NomeAnt, Atual->Nome);

            //fflush(stdin);
            //gets(Nome); // Pega o nome
            if(Atual->Filho == NULL)
              printf("Comando Invalido \n");
            else
            Atual = EntraDiretorio(Atual, Nome);

            if (strcmp(Atual->Nome, NomeAnt) != 0)
                InsereElementoUrl(Url, Atual->Nome);

        } else if (strncmp(Op, "rm", 2) == 0) {

            //fflush(stdin);
            //gets(Nome); // Pega o nome

            Atual = DeletaElemento(Atual, Nome);

        } else if (strncmp(Op, "ex", 2) == 0) {

            break;

        } else {

            printf("comando invalido \n");
        }


    } while (1);
    FinalizaPilha(Url); //Finaliza URL
    return 0;
}
