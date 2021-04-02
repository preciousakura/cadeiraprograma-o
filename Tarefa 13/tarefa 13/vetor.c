#include "arquivo.h"

int *inicializar_vetor(int tamanho) { // aloca um vetor de inteiros
	int *vetor = (int *)malloc(tamanho * sizeof(int));
	memset(vetor,-1,sizeof(int));
	return vetor;
}
// insere chave da árvore no vetor
void insere_chave_vetor(No_tree* arvore, int* vetor, int *i) {
    if (arvore != NULL){
        insere_chave_vetor(arvore->left,vetor, i);
        vetor[(*i)] = arvore->dado.key;
        (*i) = (*i) + 1;
        insere_chave_vetor(arvore->right,vetor, i);
    }
}
// busca sequencial no vetor
int busca_sequencial(int *vetor, int chave,int N){
  int i;
  for (i = 0 ; i < N ; i++){
    if (vetor[i] == chave)
      return 1;
  }
  return 0;
} 
// busca binaria recursiva no vetor
int busca_binaria(int* vetor, int chave, int begin, int end){
  if(begin<=end){
    int mid = (begin+end)/2;
    if(vetor[mid] == chave)
      return chave;
    if(chave < vetor[mid])
      return busca_binaria(vetor, chave, begin, mid-1);
    else
      return busca_binaria(vetor, chave, mid+1, end);
  } return -1;
}