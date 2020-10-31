#include "gerador-menus.h"

int main(){
    
    int opcao = gerarMenu("CADASTRO", 5, 
                          "Cadastrar", 
                          "Localizar", 
                          "Alterar", 
                          "Excluir", 
                          "Sair"
    );

    printf("Opcao selecionada: %i\n", opcao);
    
    return 0;
}