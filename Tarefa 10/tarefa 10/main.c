#include "listaencadeada.h"

int main(int argc, char *argv[]) {
    List* list = create_List();
    carregar("arquivo.txt", list);
    percorrer(list);
    salvar(list, "salvar_contatos.txt");
    
    return 0;
}