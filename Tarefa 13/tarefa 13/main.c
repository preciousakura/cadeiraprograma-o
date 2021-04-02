#include "arquivo.h"

#define N 50000
#define K 1000000

int main(){
  No* list = inicializar(list);
  No_tree* arvore = inicializar_arvore();
  Value dado;
  srand(time(NULL));

  // gera a árvore binária e a lista encadeada com valores e chaves pseudo-aleatórias
  for(int i = 0; i < N; i++){
    dado = gerar_tupla_list_encad(arvore, N);
    arvore = inserir_abb(arvore, dado);
    list = inserir_list_encadeada(list, dado);
  }

  int i = 0; // indice do vetor
  int* i_p = &i; // ponteiro para indice do vetor
  int *vetor = inicializar_vetor(N);

  insere_chave_vetor(arvore,vetor,i_p); // preenche vetor com chaves da arvores em ordem (naturalmente) crescente

  // variaveis de tempo
  int ti_arvore, tf_arvore = 0, 
      ti_lista, tf_lista = 0, 
      ti_binaria, tf_binaria = 0, 
      ti_sequencial, tf_sequencial = 0,
      valor;

  // busca de valores aleatórios K vezes
  for(int i = 0; i < K; i++){
    valor = sortear_int(N);

    ti_arvore = marcar_tempo();
    buscar_arvore(arvore, valor);
    tf_arvore = tf_arvore + tempo_final(ti_arvore);

    ti_lista = marcar_tempo();
    busca_lista_encadeada(list, valor);
    tf_lista = tf_lista + tempo_final(ti_lista);

    ti_sequencial = marcar_tempo();
    busca_sequencial(vetor, valor, N);
    tf_sequencial = tf_sequencial + tempo_final(ti_sequencial);
    
    ti_binaria = marcar_tempo();
    busca_binaria(vetor, valor, 0, N);
    tf_binaria = tf_binaria + tempo_final(ti_binaria);
    
  }
  
  // mostramos os tempos totais de cada busca
  printf("Busca na Arvore Binaria: %d\n", tf_arvore);
  printf("Busca Sequencial na Lista Encadeada: %d\n", tf_lista);
  printf("Busca Sequencial no Vetor: %d\n", tf_sequencial);
  printf("Busca Binaria no Vetor: %d\n", tf_binaria);
  
}