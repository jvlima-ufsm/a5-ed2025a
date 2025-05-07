/*
 * lista.c
 * Implementação da TAD lista_t.
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
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

/* insere no comeco da lista, retorna a lista atualizada */
lista_t* lista_insere( lista_t* l, int dado )
{
	lista_t *p = (lista_t*)malloc(sizeof(lista_t));
	p->prox = l;
	p->dado = dado;
	return p;
}


/* remove da lista o elemento que contem 'dado'.
   Se lista ficar vazia, retorna NULL.
   Se encontrou, o elemento da lista deve ser liberado com free(). ATENCAO: nao liberar o dado.
   Se nao encontrou, retorna a lista 'l'.
*/
lista_t* lista_remove( lista_t* l, int dado )
{
	lista_t *p = l;
	lista_t *ant = NULL;

	while( (p != NULL) && (p->dado != dado) ){
		ant = p;
		p = p->prox;
	}
	if(p == NULL) return l;
	if(ant == NULL)
		l = p->prox;
	else
		ant->prox = p->prox;

	free(p);
	return l;
}

/* libera a memória de cada nó da lista.
 * ATENÇÃO: não libera memória dos dados.
 */
void lista_destroi( lista_t* l )
{
	lista_t* p = l;
	while( l != NULL ){
		l = p->prox;
		free(p);
		p = l;
	}
}


/* cria lista vazia */
lista_t* lista_cria(void)
{
	return NULL;
}

/* retorna se a lista esta vazia (true), ou false caso contrario */
int lista_vazia( lista_t* l )
{
	return (l == NULL);
}

/* busca um elemento na lista por meio da funcao f():
  bool f(void* a, void* b) {}
  que retonar 'true' caso a e b sejam iguais.
*/
int lista_busca( lista_t* l, int dado )
{
	lista_t* primeiro = l;

	while( lista_vazia(primeiro) == 0 ){
		if( primeiro->dado == dado )
			return 1;

		primeiro = primeiro->prox;
	}
	return 0;
}

/* compara as duas listas encadeadas
 * Retorna 1 quando as listas sao iguais, ou 0 caso contrario
 */
int lista_compara(lista_t* l1, lista_t* l2)
{
	if(l1 == NULL || l2 == NULL)
		return 0;

	while( (l1 != NULL) && (l2 != NULL) ){
		if(l1->dado != l2->dado)
			return 0;
		l1 = l1->prox;
		l2 = l2->prox;
	}

	return ((l1 == NULL) && (l2 == NULL));
}

void lista_imprime(lista_t* l)
{
	while(l != NULL){
		printf("%d -> ", l->dado);
		l= l->prox;
	}
	printf("\n");
}
