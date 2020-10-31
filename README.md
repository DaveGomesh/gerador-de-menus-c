# Gerador de Menus em C

Um simples gerador de Menus para Console em C.

As opções são selecionáveis pelo teclado usando as setas e o enter!

## Como usar o gerador

1. Coloque os arquivos [`console.h`](https://github.com/DavidGomesh/console-h) e `gerador-menus.h` na pasta do projeto.
2. Faça a inclusão da biblioteca `gerador-menus.h` no projeto.

```c
//Incluindo a biblioteca
#include "gerador-menus.h"

int main(){
    return 0;
}
```

3. Use a função `gerarMenu()` para gerar o menu.

## Exemplo

Usando o seguinte código:

```c
//Incluindo a biblioteca
#include "gerador-menus.h"

int main(){
    int opcao = gerarMenu("CADASTRO", 5, 
                          "Cadastrar", 
                          "Localizar", 
                          "Alterar", 
                          "Excluir", 
                          "Sair");

    return 0;
}
```

A saída será assim:

```c
//Exemplo de saída
╔═════════════════╗
║ CADASTRO        ║
║  » Cadastrar    ║
║  · Localizar    ║
║  · Alterar      ║
║  · Excluir      ║
║  · Sair         ║
╚═════════════════╝
```

## Função gerarMenu

**Definição da função:**

```c
int gerarMenu(char titulo[], int quant, ...);
```

**Funcionalidade:** gera um menu com base no que foi passado e aguarda que o usuário selecione uma opção, usando as setas e o enter.

**Parâmetros:**

Primeiro passamos o título do menu.

```c
char titulo[]
```

Depois, informamos a quantidade de opções que o Menu terá.

```c
int quant
```

Por fim, passamos cada opção que o menu terá.

```c
//Deve ser passado um vetor de caracteres (string)
...
```

## Observações

- O menu pode ter mais de ***4 bilhões de opções***;
  - Para ser mais exato: **4.294.967.296 (4 trilhões, 294 milhões, 967 mil, 296)**;
  - Ou ***2 elevado a 32***.
- O máximo opções testadas foram **30 mil opções**.
- O máximo opções testadas sem causar erros na interface foram **8.897 opções**.

***Mas acho que você não vai usar esse número de opções, né? ;)***
