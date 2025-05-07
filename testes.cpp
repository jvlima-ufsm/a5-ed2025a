/*
 * testes.cpp
 * Exercício sobre TAD lista.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2025 João Vicente, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* NÃO MUDAR ESSSE ARQUIVO!!!*/

#include "catch_amalgamated.hpp"

#include <cstring>
#include <cstdlib>

extern "C" {
    #include "lista.h"
    #include "abb.h"
}

TEST_CASE("Teste vazio") {
    abb_t* a;
    a= abb_cria();
    REQUIRE(abb_vazia(a) == 1);
    abb_destroi(a);
}

TEST_CASE("Teste nao vazio") {
    abb_t* a;
    lista_t *l;
    l = lista_cria();
    l = lista_insere(l, 1);

    a = abb_cria();
    a = abb_inicia_preordem(l);
    REQUIRE(abb_vazia(a) != 1);
    
    abb_destroi(a);
    lista_destroi(l);
}

TEST_CASE("Caso 1") {
    abb_t* a;
    lista_t *entrada, *resultado, *saida;
    entrada = lista_cria();
    resultado = lista_cria();
    saida = lista_cria();

    // lista de entrada: {5, 3, 7}
    entrada = lista_insere(entrada, 7);
    entrada = lista_insere(entrada, 3);
    entrada = lista_insere(entrada, 5);
    
    // lista de saida: {3, 7, 5}
    resultado = lista_insere(resultado, 3);
    resultado = lista_insere(resultado, 7);
    resultado = lista_insere(resultado, 5);

    a = abb_inicia_preordem(entrada);
    REQUIRE(abb_vazia(a) != 1);
    saida = abb_lista_posordem(a, saida);
    REQUIRE(lista_vazia(saida) != 1);

    REQUIRE(lista_compara(resultado, saida) == 1);

    abb_destroi(a);
    lista_destroi(entrada);
    lista_destroi(resultado);
    lista_destroi(saida);
}

TEST_CASE("Caso 3") {
    abb_t* a;
    lista_t *entrada, *resultado, *saida;
    entrada = lista_cria();
    resultado = lista_cria();
    saida = lista_cria();

    // lista de entrada:  {50, 30, 24, 5, 28, 45, 98, 52, 60}
    entrada = lista_insere(entrada, 60);
    entrada = lista_insere(entrada, 52);
    entrada = lista_insere(entrada, 98);
    entrada = lista_insere(entrada, 45);
    entrada = lista_insere(entrada, 28);
    entrada = lista_insere(entrada, 5);
    entrada = lista_insere(entrada, 24);
    entrada = lista_insere(entrada, 30);
    entrada = lista_insere(entrada, 50);

    // lista de saida: {5, 28, 24, 45, 30, 60, 52, 98, 50}
    resultado = lista_insere(resultado, 5);
    resultado = lista_insere(resultado, 28);
    resultado = lista_insere(resultado, 24);
    resultado = lista_insere(resultado, 45);
    resultado = lista_insere(resultado, 30);
    resultado = lista_insere(resultado, 60);
    resultado = lista_insere(resultado, 52);
    resultado = lista_insere(resultado, 98);
    resultado = lista_insere(resultado, 50);

    a = abb_inicia_preordem(entrada);
    REQUIRE(abb_vazia(a) != 1);
    saida = abb_lista_posordem(a, saida);
    REQUIRE(lista_vazia(saida) != 1);

    REQUIRE(lista_compara(resultado, saida) == 1);

    abb_destroi(a);
    lista_destroi(entrada);
    lista_destroi(resultado);
    lista_destroi(saida);
}
