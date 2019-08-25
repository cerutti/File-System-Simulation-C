#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Directory.h"

int main(){
  char Op[6], Valor[50];

	Directory* Root = Inicializar();
	Directory* Atual = Root;
  do {
      printf("%s\\", Atual->Nome);
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
        Atual = VoltarDiretorio(Atual);
      }
      else if(strcmp(Op, "cd") == 0){
        fflush(stdin);
        gets(Valor); // Pega o pedido
        Atual = EntraDiretorio(Atual, Valor);
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

  return 0;
}
