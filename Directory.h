#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct directory{
  char Nome[50];
  struct directory *Pai;
  struct directory *Filho;
  struct directory *Irmao;
  int Tipo;
}Directory;

Directory* Inicializar();
Directory* InserirDirectory(Directory* Atual, char Nome[]);
Directory* InserirFile(Directory* Atual, char Nome[]);
void MostrarDiretorios(Directory* Atual);
Directory* EntraDiretorio(Directory* Atual, char Nome[]);
Directory* VoltarDiretorio(Directory* Atual);

Directory* Inicializar()
{
	Directory* Root = (Directory*)malloc(sizeof(Directory));
  if(Root != NULL){
      Root->Pai = NULL;
      strcpy(Root->Nome, "root");
      Root->Irmao = NULL;
      Root->Filho = NULL;
      Root->Tipo = 0;
      }
      return Root;
}

Directory* EntraDiretorio(Directory* Atual, char Nome[]){
  Directory* tmp = (Directory*)malloc(sizeof(Directory));
  Directory* Current = (Directory*)malloc(sizeof(Directory));
  tmp = Atual;
  Current = Atual;

  Atual = Atual->Filho;
  if((strcmp(Atual->Nome, Nome)==0)&&(Atual!=NULL)&&(Atual->Tipo == 0))
    tmp = Atual;
  else{
    Atual = Atual->Irmao;
  while((strcmp(Atual->Nome, Nome)!=0)&&(Atual!=NULL)&&(Atual->Tipo != 1)){
    Atual = Atual->Irmao;
  }
  tmp = Atual;
}
    return tmp;
  //return tmp;
}

Directory* VoltarDiretorio(Directory* Atual){
  if(Atual->Pai != NULL){
    Atual = Atual->Pai;
  }
  return Atual;
}

Directory* InserirDirectory(Directory* Atual, char Nome[])
{
  Directory* Pai = (Directory*)malloc(sizeof(Directory));
	Pai = Atual;
  if(Atual->Filho != NULL){
    Atual = Atual->Filho;
    while (Atual->Irmao != NULL)
    {
      Atual = Atual->Irmao;
    }
    Directory *novoDirectory = (Directory*)malloc(sizeof(Directory));
    novoDirectory->Pai = Pai;
    novoDirectory->Irmao = NULL;
    Atual->Irmao = novoDirectory;
    strcpy(novoDirectory->Nome, Nome);
    novoDirectory->Filho = NULL;
    novoDirectory->Tipo = 0;
  }
else{
		Directory* novoDirectory = (Directory*)malloc(sizeof(Directory));
		novoDirectory->Pai = Pai;
		novoDirectory->Filho = NULL;
		novoDirectory->Irmao = NULL;
    novoDirectory->Tipo = 0;
		strcpy(novoDirectory->Nome, Nome);
		Atual->Filho = novoDirectory;
    }
return Pai;
}

Directory* InserirFile(Directory* Atual, char Nome[])
{
  Directory* Pai = (Directory*)malloc(sizeof(Directory));
	Pai = Atual;
  if(Atual->Filho != NULL){
    Atual = Atual->Filho;
    while (Atual->Irmao != NULL)
    {
      Atual = Atual->Irmao;
    }
    Directory *novoDirectory = (Directory*)malloc(sizeof(Directory));
    novoDirectory->Pai = Pai;
    novoDirectory->Irmao = NULL;
    Atual->Irmao = novoDirectory;
    strcpy(novoDirectory->Nome, Nome);
    novoDirectory->Filho = NULL;
    novoDirectory->Tipo = 1;
  }
else{
		Directory* novoDirectory = (Directory*)malloc(sizeof(Directory));
		novoDirectory->Pai = Pai;
		novoDirectory->Filho = NULL;
		novoDirectory->Irmao = NULL;
    novoDirectory->Tipo = 1;
		strcpy(novoDirectory->Nome, Nome);
		Atual->Filho = novoDirectory;
    }
return Pai;
}

void MostrarDiretorios(Directory* Atual)
{
	if (Atual->Filho == NULL)
		printf("\n Diretorio Vazio \n");
	else {
		Atual = Atual->Filho;
    printf("\n");
		while (Atual != NULL)
		{
			printf("%s\n", Atual->Nome);
			Atual = Atual->Irmao;
		}
    printf("\n");
	}
}
