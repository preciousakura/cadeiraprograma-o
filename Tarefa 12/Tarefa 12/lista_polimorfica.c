#include "lista_polimorfica.h"

List** inicializar(List **list){
    *list = malloc(sizeof(List));
    return list;
}

int inserir_no(List **list, List* novo, int chave){
  List *aux;
  if(*list == NULL){ // se a lista estiver vazia 
      *list = novo;
      novo->next = novo;
      novo->prev = novo;
      return 1;
  } if((*list)->data.chave >= chave){ // se for inserção no ínicio
      if((*list)->data.chave == chave){
          printf("Chave duplicada!\n");
          free(novo->data.info);
          free(novo);
          return 0;
      } 
      novo->next = *list;
      novo->prev = (*list)->prev;
      (*list)->prev->next = novo;
      (*list)->prev = novo;
      (*list) = novo;
      return 1;
  } 

  aux = (*list)->prev;
  if(chave >= aux->data.chave){ // se for inserção no fim
    if(aux->data.chave == chave){
          printf("Chave duplicada!\n");
          free(novo->data.info);
          free(novo);
          return 0;
    } 
    aux->next = novo;
    novo->prev = aux;
    novo->next = *list;
    (*list)->prev = novo;
    return 1;
  } 

  aux = (*list);
  while(aux->next->data.chave < chave) // se for inserção no meio
    aux = aux->next; // atualiza o valor até achar um menor que a chave para inserir antes

  if(aux->next->data.chave == chave){
      printf("Chave duplicada!\n");
      free(novo->data.info);
      free(novo);
      return 0;
  }

  novo->next = aux->next;
  novo->prev = aux;
  novo->next->prev = novo;
  aux->next = novo;
  return 1;
}

int inserir_float(List **list, double val, int chave){
    List *novo;
    novo = malloc(sizeof(List));
    if(!novo)
        return 0;
    novo->data.info = malloc(sizeof(double));
    if(!novo->data.info) {
        free(novo);
        return 0; 
    }

    *((double*)novo->data.info) = val;
    novo->data.tipo = T_FLOAT;
    novo->data.chave = chave; 
    return inserir_no(list, novo, chave);
}

int inserir_inteiro(List **list, int val, int chave){
    List *novo;
    novo = malloc(sizeof(List));
    if(!novo)
        return 0;
    novo->data.info = malloc(sizeof(int));
    if(!novo->data.info) {
        free(novo);
        return 0; 
    }

    *((int*)novo->data.info) = val;
    novo->data.tipo = T_INT;
    novo->data.chave = chave;
    return inserir_no(list, novo, chave); 
}

int inserir_char(List **list, char *val, int chave){
    List *novo;
    novo = malloc(sizeof(List));
    if(!novo)
        return 0;
    novo->data.info = malloc(sizeof(char));
    if(!novo->data.info) {
        free(novo);
        return 0; 
    }

    *((char*)novo->data.info) = val[0];
    novo->data.tipo = T_CHAR;
    novo->data.chave = chave;
    return inserir_no(list, novo, chave); 
}

int inserir_string(List **list, char* val, int chave){
    List *novo;
    novo = malloc(sizeof(List));
    if(!novo)
        return 0;
    novo->data.info = malloc(strlen(val));
    if(!novo->data.info) {
        free(novo);
        return 0; 
    }
    strcpy((char*)novo->data.info, val);
    novo->data.tipo  = T_STRING;
    novo->data.chave = chave;
    return inserir_no(list, novo, chave); 
}

void listar_elementos (List* list){
  if(!list) {
    printf("Lista Vazia!\n");
    return;
  }
  List *aux = list;
  do {
    if(aux->data.tipo == T_INT)
      printf("%d: %d\n", aux->data.chave, *((int*)aux->data.info));
    else if(aux->data.tipo == T_FLOAT)
      printf("%d: %.1f\n", aux->data.chave, *((double*)aux->data.info));
    else if(aux->data.tipo == T_CHAR)
      printf("%d: %c\n", aux->data.chave, *((char*)aux->data.info));
    else 
      printf("%d: %s\n", aux->data.chave, aux->data.info);

    aux = aux->next;
  } while(aux != list);
}

int obter_tipo (List* list, int chave){
  if(!list) {
    printf("Lista Vazia!\n");
    return 0;
  }
  List *aux = list;
  do {
    if(aux->data.chave == chave){
      printf("Chave encontrada!\n");
      if(aux->data.tipo == T_INT)
        printf("Valor: %d\n", *((int*)aux->data.info));
      else if(aux->data.tipo == T_FLOAT)
        printf("Valor: %.1f\n", *((double*)aux->data.info));
      else if(aux->data.tipo == T_CHAR)
        printf("Valor: %c\n", *((char*)aux->data.info));
      else 
        printf("Valor: %s\n", aux->data.info);
      return 1;
    }
    aux = aux->next;
  } while(aux != list); 
  printf("Chave não encontrada!");
  return 0;
}

int obter_inteiro (List *list, int chave){
  if(!list) {
    printf("Lista Vazia!\n");
    return 0;
  } 
  List *aux = list;
  do {
    if(aux->data.chave == chave){
      if(aux->data.tipo == T_INT){
        printf("Inteiro encontrado!\n");
        printf("Valor: %d\n", *((int*)aux->data.info));
        return 1;
      }
    }
    aux = aux->next;
  } while(aux != list);
  printf("Inteiro não encontrado!");
  return -99999;
}

int obter_p_flutuante (List *list, int chave){
  if(!list) {
    printf("Lista Vazia!\n");
    return 0;
  } 
  List *aux = list;
  do {
    if(aux->data.chave == chave){
      if(aux->data.tipo == T_FLOAT){
        printf("Float encontrado!\n");
        printf("Valor: %.1f\n", *((double*)aux->data.info));
        return 1;
      }
    }
    aux = aux->next;
  } while(aux != list);
  printf("Float não encontrado!");
  return -99999;
}

int obter_caractere (List *list, int chave){
  if(!list) {
    printf("Lista Vazia!\n");
    return 0;
  } 
  List *aux = list;
  do {
    if(aux->data.chave == chave){
      if(aux->data.tipo == T_CHAR){
        printf("Caracter encontrada!\n");
        printf("Valor: %c\n", *((char*)aux->data.info));
        return 1;
      }
    }
    aux = aux->next;
  } while(aux != list);
  printf("Caracter não encontrado!");
  return -99999;
}

int obter_c_caracteres (List *list, int chave){
  if(!list) {
    printf("Lista Vazia!\n");
    return 0;
  } 
  List *aux = list;
  do {
    if(aux->data.chave == chave){
      if(aux->data.tipo == T_STRING){
        printf("String encontrada!\n");
        printf("Valor: %s\n", aux->data.info);
        return 1;
      }
    }
    aux = aux->next;
  } while(aux != list);
  printf("String não encontrado!");
  return -99999;
}

char *getString(char *nome) { // le uma string com tamanho dinamico
    int i = 0;
    char letra;

    nome = malloc(sizeof(char));

    while(letra != '\n') {
        letra = getchar(); // pega o getchar
        if(letra != '\n')
        {
            nome[i] = letra;
            i++;
            nome = realloc(nome, sizeof(char) * i+1);
        }
    }

    nome[i] = '\0';
    return nome;
}