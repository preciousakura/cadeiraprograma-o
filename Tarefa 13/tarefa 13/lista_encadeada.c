#include "arquivo.h"
// inicializa a lista duplamente encadeada
No* inicializar(No* list){
  return NULL;
}
// insere nó na lista duplamente encadeada
No* inserir_list_encadeada(No* node, Value dado){
  if(node ==  NULL) {
    node = malloc(sizeof(No));
    node->next = NULL;
    node->prev = NULL;
    node->dado = dado;
    return node;
  } 
  if(!node->next){
    node->next = (No*)malloc(sizeof(No));
    node->next->dado = dado;
    node->prev = node;
    node->next->next = NULL;
  } else {
    inserir_list_encadeada(node->next, dado);
  } return node;
}

// busca sequencial recursiva na lista duplamente encadeada
int busca_lista_encadeada(No* node, int chave){
  if(node == NULL || node->dado.key == chave) {
    if (node == NULL) 
      return 0;
    else if (node->dado.key == chave)
      return 1;
  } 
  return busca_lista_encadeada(node->next, chave);
}