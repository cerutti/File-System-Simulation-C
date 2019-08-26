#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Definição da estrutura
typedef struct directory{
  char Nome[50];
  struct directory *Pai;
  struct directory *Filho;
  struct directory *Irmao;
  int Tipo;
}Directory;
//Fim da definicação da estrutura

//Inicio de declaração de Funções
Directory* Inicializar();
Directory* InserirDirectory(Directory* Atual, char Nome[]);
Directory* InserirFile(Directory* Atual, char Nome[]);
void MostrarDiretorios(Directory* Atual);
Directory* EntraDiretorio(Directory* Atual, char Nome[]);
Directory* VoltarDiretorio(Directory* Atual);
Directory* DeletaElemento(Directory* Atual, char Nome[]);
//Fim de declaração de Funções

//Função responsavel por inicializa a raiz do sistema de arquivos
Directory* Inicializar()
{
	Directory* Root = (Directory*)malloc(sizeof(Directory)); //Aloca o novo elemento
  if(Root != NULL){ //Verifica se o elemento foi alocado
      Root->Pai = NULL; //Atribui null ao pai
      strcpy(Root->Nome, "root"); //Atribui o nome como root
      Root->Irmao = NULL; //atribui ao irmao null
      Root->Filho = NULL; //atribui ao filho null
      Root->Tipo = 0; //atribui ao tipo o valor 0, que no sistema 0 é considerado como uma pasta
      }
      return Root; //Retorna o elemento root
}
//Fim da função

//Função responsavel por entrar em um diretorio determinado pelo usuario
Directory* EntraDiretorio(Directory* Atual, char Nome[]){
  Directory* tmp = (Directory*)malloc(sizeof(Directory)); //Aloca uma variavel temporaria
  tmp = Atual; //Atribui a variavel o atual

  Atual = Atual->Filho; //Pega o filho do atual
  if((strcmp(Atual->Nome, Nome)==0)&&(Atual->Tipo == 0)) //Verifica se o nome do filho é o mesmo informado,se o tipo é uma pasta
    tmp = Atual; //Caso seja atribui ao tmp o valor do atual
  else{
    Atual = Atual->Irmao; //Pega o irmao do atual
  while((Atual!=NULL)&&(strcmp(Atual->Nome, Nome)!=0)&&(Atual->Tipo != 1)){ //Percorre os irmaos até encontrar um arquivo com o nome desejadp
    Atual = Atual->Irmao; //Atribui ao atual o proximo irmao
  }
  if(Atual != NULL)
    tmp = Atual; //Atribui ao tmp o atual
  else
    printf("O Sistema nao pode encontrar o caminho especificado.\n\n");
}
    return tmp; //Retorna o valor encontrado
}

//Função responsavel por retornar a pasta pai
Directory* VoltarDiretorio(Directory* Atual){
  if(Atual->Pai != NULL){ //Verifica se o pai existe
    Atual = Atual->Pai; //Atribui a atual o pai
  }
  return Atual; //Retorna o atual
}
//Fim da função

//Função responsavel pela inserção de uma pasta
Directory* InserirDirectory(Directory* Atual, char Nome[])
{
  Directory* Pai = (Directory*)malloc(sizeof(Directory)); //Aloca um elemento
	Pai = Atual; //Elemento pai recebe o atual
  if(Atual->Filho != NULL){ //Verifica se se existe filho
    Atual = Atual->Filho; //Atual recebe o filho
    while (Atual->Irmao != NULL) //Percorre os diretorios enquanto ouverem irmaos
    {
      Atual = Atual->Irmao; //Pega o proximo irmao
    }
    Directory *novoDirectory = (Directory*)malloc(sizeof(Directory)); //Aloca novo elemento
    novoDirectory->Pai = Pai; //Atribui ao Pai o elemento pai
    novoDirectory->Irmao = NULL; //Atribui ao Irmao o valor null
    Atual->Irmao = novoDirectory; // Atribui como irmao do atual o novo elemento
    strcpy(novoDirectory->Nome, Nome); //Atribui um nome ao novo elemento
    novoDirectory->Filho = NULL; //Atribui null ao filho do novo elemento
    novoDirectory->Tipo = 0; //Atribui 0 ao Tipo representando uma pasta
  }
else{
		Directory* novoDirectory = (Directory*)malloc(sizeof(Directory)); //Aloca novo elemento
		novoDirectory->Pai = Pai; //Atribui ao Pai o elemento pai
		novoDirectory->Filho = NULL; //Atribui null ao filho do novo elemento
		novoDirectory->Irmao = NULL; //Atribui ao Irmao o valor null
    novoDirectory->Tipo = 0; //Atribui 0 ao Tipo representando uma pasta
		strcpy(novoDirectory->Nome, Nome); //Atribui um nome ao novo elemento
		Atual->Filho = novoDirectory; //Atribui ao Atual filho o novo elemento
    }
return Pai; //Retorna o elemento pai
}
//Fim da função

//Função responsavel pela inserção de um arquivo
Directory* InserirFile(Directory* Atual, char Nome[])
{
  Directory* Pai = (Directory*)malloc(sizeof(Directory)); //Aloca um elemento
	Pai = Atual; //Elemento pai recebe o atual
  if(Atual->Filho != NULL){ //Verifica se se existe filho
    Atual = Atual->Filho; //Atual recebe o filho
    while (Atual->Irmao != NULL) //Percorre os diretorios enquanto ouverem irmaos
    {
      Atual = Atual->Irmao; //Pega o proximo irmao
    }
    Directory *novoDirectory = (Directory*)malloc(sizeof(Directory)); //Aloca novo elemento
    novoDirectory->Pai = Pai; //Atribui ao Pai o elemento pai
    novoDirectory->Irmao = NULL; //Atribui ao Irmao o valor null
    Atual->Irmao = novoDirectory; // Atribui como irmao do atual o novo elemento
    strcpy(novoDirectory->Nome, Nome); //Atribui um nome ao novo elemento
    novoDirectory->Filho = NULL; //Atribui null ao filho do novo elemento
    novoDirectory->Tipo = 1;  //Atribui 1 ao Tipo representando um arquivo
  }
else{
		Directory* novoDirectory = (Directory*)malloc(sizeof(Directory));
		novoDirectory->Pai = Pai; //Atribui ao Pai o elemento pai
		novoDirectory->Filho = NULL; //Atribui null ao filho do novo elemento
		novoDirectory->Irmao = NULL; //Atribui ao Irmao o valor null
    novoDirectory->Tipo = 1; //Atribui 1 ao Tipo representando um arquivo
		strcpy(novoDirectory->Nome, Nome); //Atribui um nome ao novo elemento
		Atual->Filho = novoDirectory;  // Atribui como filho do atual o novo elemento
    }
return Pai; //Retorna o elemento pai
}
//Fim da função

//Função responsavel por listar elementos dentro da pasta
void MostrarDiretorios(Directory* Atual)
{
	if (Atual->Filho == NULL) //Verifica se existem arquivos
		printf("\n Diretorio Vazio \n\n"); //Exibe mensagem caso não houver
	else {
		Atual = Atual->Filho; //Pega o filho do elemento atual
    printf("\n");
		while (Atual != NULL) //Percorre enquanto o atual for diferente de null
		{
			printf("%s\n", Atual->Nome); //Imprime o nome do atual
			Atual = Atual->Irmao; //Pega o proximo irmao
		}
    printf("\n");
	}
}
//Fim da função

Directory* DeletaElemento(Directory* Atual, char Nome[]){

}
