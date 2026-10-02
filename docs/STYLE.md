# Guia de estilo

## Nomenclatura

- Arquivos e diretórios: `snake_case`; nomes de executáveis e projetos podem usar a marca do produto.
- Funções e variáveis: `snake_case`, com nomes descritivos. Prefixe funções públicas pelo módulo, como `app_create`.
- Tipos e enumerações: sufixo `_t`; constantes de enumeração: prefixo do módulo em maiúsculas, como `APP_STATUS_OK`.
- Macros e guards: maiúsculas com `_`; mantenha o guard específico do cabeçalho.
- Tipos opacos na API pública; mantenha a estrutura concreta no `.c` que a implementa.

## Ponteiros e alocação

- Inicialize ponteiros com `NULL` e valide parâmetros antes de desreferenciá-los.
- Ao retornar um objeto por parâmetro de saída, valide o parâmetro e inicialize `*out` para `NULL` antes de qualquer falha possível.
- Faça cada função documentar pela API quem aloca, quem é dono e quem libera cada objeto.
- Verifique falhas de `malloc` e contas de tamanho antes de alocar; libere recursos parciais em todos os caminhos de erro.
- Prefira `app_destroy(&obj)` que também zera o ponteiro. Torne destrutores tolerantes a `NULL` quando isso simplificar a limpeza.
- Não retorne ponteiros para variáveis locais nem mantenha referências a buffers cuja vida útil terminou.
- Evite casts desnecessários do retorno de `malloc`; em C, o cabeçalho apropriado deve declarar a função.

## Erros e manutenção

- Retorne códigos de erro explícitos em vez de ocultar falhas; não use `errno` sem uma API que o defina.
- Mantenha cabeçalhos públicos pequenos e independentes de detalhes internos.
- Compile com avisos tratados como erros e execute os testes com sanitizers durante o desenvolvimento.