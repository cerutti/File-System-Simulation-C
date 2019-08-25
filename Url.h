#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char Nome[50];
    struct node *prox;
} url;

int tam;

//Inicio de declaração de Funções
void InicializaUrl(url *Url);
void MostraUrl(url *Url);
url *AlocaElemento();
int VerificaVazio(url *Url);
void FinalizaCaixa(url *Url);
void InsereElementoUrl(url *Url, char v[]);
void *DesempilhaElementoUrl(url *Url);
//Fim de declaração de Funções

// Fução responsavel por inicializar o caixa
void InicializaUrl(url *Url) {
    Url->prox = NULL;
    tam = 0;
}

// Função responsavel por verificar se o caixa está vazio
int VerificaVazio(url *Url) {
    if (Url->prox == NULL) //Verifica se o caixa é nulo
        return 1;
    else
        return 0;
}

// Função responsavel por alocar e retornar novo elemento que será inserido no caixa
url *AlocaElemento() {
    url *novo = (url *) malloc(sizeof (url)); //Aloca elemento
    return novo; //Retorna elemento alocado
}



// Função resonsavel por listar todos os elementos armazenados no caixa
void MostraUrl(url *Url) {
    int count = 0;

    if (VerificaVazio(Url)) { //Verifica se o caixa está vazio
        printf("Nao existe URL\n\n");
        return;
    }

    url* tmp; //Cria um elemento caixa temporario
    tmp = Url->prox; //Atribui ao elemento temporario o caixa com os dados

    while (tmp != NULL) { //Laço que percorre o caixa temporario
        count++;
        printf("%s\\", tmp->Nome); //Exibe o valor inserido nessa posição
        tmp = tmp->prox; //Passa para a proxima posição
    }
}


// Função responsavel por finalizar o caixa e liberar toda a memoria alocada
void FinalizaCaixa(url *Url) {
    if (!VerificaVazio(Url)) { //Verifia se o caixa está diferente de vazio
        url *proxNode, *atual; //Declara Variaveis auxiliares

        atual = Url->prox; //Atribui a atual o primeiro valor do caixa
        while (atual != NULL) { //Verifica se chegou no final
            proxNode = atual->prox; //Pega o proximo valor a liberar
            free(atual); //Libera o atual
            atual = proxNode; //Atribui ao atual o proximo
        }
    }
}

// Função responsavel por inserir um novo elemento no caixa
void InsereElementoUrl(url *Url, char v[]) {
    url *novo = AlocaElemento(); //Chama função que aloca novo elemento
    strcpy(novo->Nome, v); //Atribui um nome ao novo elemento
    novo->prox = NULL; //atribui ao prox o valor null

    if (VerificaVazio(Url)) //verifica se o caixa esta vazio
        Url->prox = novo; //Se estiver vazio insere o elemento
    else {
        url *tmp = Url->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
    tam++;
}

void *DesempilhaElementoUrl(url *Url)
{
 if(Url->prox == NULL){
  printf("PILHA ja vazia\n\n");
  return NULL;
 }else{
  url *ultimo = Url->prox, *penultimo = Url;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
 }
}
