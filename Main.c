#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Directory.h"
#include "Url.h"

char Funcao1[10], Funcao2[50];

int main(){
  char Op[6], Valor[50], NomeAnt[50];

  url *Url = (url *) malloc(sizeof (url));
  InicializaUrl(Url);

	Directory* Root = Inicializar();
	Directory* Atual = Root;
  InsereElementoUrl(Url, Atual->Nome);
  do {
      MostraUrl(Url);

      fflush(stdin);
      gets(Op); // Pega o pedido
      if(strcmp(Op, "ls") == 0){
        MostrarDiretorios(Atual);
      }
      else if(strcmp(Op, "ma") == 0){
        fflush(stdin);
        gets(Valor); // Pega o pedido
        Atual = InserirFile(Atual, Valor);
      }
      else if(strcmp(Op, "mp") == 0){
        fflush(stdin);
        gets(Valor); // Pega o pedido
        Atual = InserirDirectory(Atual, Valor);
      }
      else if(strcmp(Op, "cd ..") == 0){
        strcpy(NomeAnt, Atual->Nome);

        Atual = VoltarDiretorio(Atual);

        if(strcmp(Atual->Nome, NomeAnt) != 0)
        DesempilhaElementoUrl(Url);
      }
      else if(strcmp(Op, "cd") == 0){
        strcpy(NomeAnt, Atual->Nome);

        fflush(stdin);
        gets(Valor); // Pega o pedido

        Atual = EntraDiretorio(Atual, Valor);

        if(strcmp(Atual->Nome, NomeAnt) != 0)
          InsereElementoUrl(Url, Atual->Nome);
      }
      else if(strcmp(Op, "rm") == 0){

      }
      else if(strcmp(Op, "ex") == 0){
        return 0;
      }
      else{
        printf("comando invalido \n");
      }

  } while(1);
  FinalizaPilha(Url);
  return 0;
}
