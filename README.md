
# TDD- Árvore Binária de Busca

Este é o código exemplo do trabalho usando TDD (*Test Driven Development*) com o framework C++ [Catch2](https://github.com/catchorg/Catch2/tree/v2.x).

O framework Catch2 consegue ser utilizado apenas com o arquivo header [catch.hpp](catch.hpp) sem necessidade de instalação.

**NÃO MODIFIQUE OS TESTES** 

Todos os testes estão prontos no arquivo [testes.cpp](testes.cpp). A compilação e teste pode ser feita com os comandos:
```
g++ -Wall -g -c catch_amalgamated.cpp
g++ -Wall -g -c testes.cpp
gcc -Wall -g -c lista.c
gcc -Wall -g -c abb.c
g++ -Wall -g lista.o abb.o testes.o  catch_amalgamated.o
valgrind --leak-check=full ./a.out --reporter compact --success
```

