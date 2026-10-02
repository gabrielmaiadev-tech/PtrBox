# PtrBox

Scaffold modular em C11 para uma CLI simples que imprime uma mensagem. A API
duplica a mensagem recebida, deixando explícita a propriedade da memória.

## Requisitos

- CMake 3.16 ou mais recente
- GCC ou Clang

## Compilar e testar

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

Para ativar AddressSanitizer e UndefinedBehaviorSanitizer:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DENABLE_SANITIZERS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

Execute `./build/ptrbox` ou passe uma mensagem: `./build/ptrbox "Ola, PtrBox"`.

## Estrutura

```text
.
|-- CMakeLists.txt
|-- include/app.h
|-- src/app.c
|-- src/main.c
|-- tests/test_app.c
|-- docs/STYLE.md
|-- .clang-format
|-- .clang-tidy
|-- .gitignore
`-- build/                 # gerado localmente pelo CMake
```

Convenções de nomenclatura e regras de gerenciamento de memória estão em
[`docs/STYLE.md`](docs/STYLE.md).