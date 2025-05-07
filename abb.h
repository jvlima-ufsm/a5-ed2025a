/*
 * abb.h
 * Definição da TAD abb_t.
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

#pragma once

#include "lista.h"

/* Definicao de Arvore de Busca Binaria (ABB) para inteiros
 */
struct _abb {
    int dado;            /* dado armazenado */
    struct _abb* esq;    /* filho da esquerda */
    struct _abb* dir;    /* filho da direita */
};

/* define o tipo abb_t, derivado da 'struct _abb' */
typedef struct _abb abb_t;

/* cria uma abb vazia, ou seja, retorna NULL */
abb_t* abb_cria(void);

/* Recebe uma lista em pos-ordem e cria a arvore */
abb_t* abb_inicia_preordem(lista_t *l);

/* Recebe uma arvore e uma lista encadeada.
 * Retorna uma lista com os elementos em pos-ordem
 */
lista_t* abb_lista_posordem(abb_t *a, lista_t* saida);

/* insere na abb, retorna a abb atualizada,
 */
abb_t* abb_insere( abb_t* a, int dado );

/* remove da abb o elemento que contem 'dado'.  Se abb ficar vazia, retorna NULL.
   Se nao encontrou, retorna a abb 'a'.
*/
abb_t* abb_remove( abb_t* a, int dado );

/* libera a memória de cada nó da abb.
 * ATENÇÃO: não libera memória dos dados.
 */
void abb_destroi( abb_t* a );

/* retorna se a abb esta vazia (1), ou 0 caso contrario */
int abb_vazia( abb_t* a );

/* busca um elemento na abb.
*/
int abb_busca( abb_t* a, int dado );

void abb_imprime(abb_t* a);