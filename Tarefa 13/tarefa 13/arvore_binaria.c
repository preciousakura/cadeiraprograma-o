#include "arquivo.h"

// inicializa a árvore
No_tree* inicializar_arvore() {
  return NULL;
}
// insere um nó na arvore 
No_tree* inserir_abb(No_tree* arvore, Value dado){
  if(arvore == NULL){ // se o no estiver vazio, insere nele
    arvore = malloc(sizeof(No_tree));
    arvore->dado = dado;
    arvore->left = NULL;
    arvore->right = NULL;
    return arvore; // retorna o nó
  } else {
    if(dado.key > arvore->dado.key) 
      arvore->right = inserir_abb(arvore->right, dado);
    else 
      arvore->left = inserir_abb(arvore->left, dado);
  } return arvore; // retorna a árvore com o nó adicionado
}

// busca de chave na árvore binária de busca
int buscar_arvore(No_tree *arvore, int chave){
  if (arvore == NULL || arvore->dado.key == chave){
    if (arvore == NULL) 
      return 0;
    else if (arvore->dado.key == chave)
      return 1;
  }

  if (arvore->dado.key > chave) 
    return buscar_arvore(arvore->left, chave); 
  else 
    return buscar_arvore(arvore->right, chave);
}

