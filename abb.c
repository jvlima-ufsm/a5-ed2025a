/*
 * abb.c
 * Implementação da TAD abb_t.
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

#include "abb.h"
#include "lista.h"

abb_t* abb_cria(void)
{
	return NULL;
}

/* Recebe uma lista em pre-ordem e cria a arvore */
abb_t* abb_inicia_preordem(lista_t *l)
{
	/* TODO */
	return NULL;
}

/* Recebe uma arvore e uma lista encadeada.
 * Retorna uma lista com os elementos em pos-ordem
 */
lista_t* abb_lista_posordem(abb_t *a, lista_t* saida)
{
	/* TODO */
	return NULL;
}

abb_t* abb_insere( abb_t* a, int dado )
{
	if(a == NULL){
		a = (abb_t*)malloc(sizeof(abb_t));
		a->esq = a->dir = NULL;
		a->dado = dado;
		return a;
	}

	if( dado > a->dado )
		a->dir = abb_insere( a->dir, dado );
	else if ( dado < a->dado )
		a->esq = abb_insere( a->esq, dado );
	
	return a;
}

abb_t* abb_remove( abb_t* a, int dado )
{
	return NULL;
}

void abb_destroi( abb_t* a )
{
	if(a != NULL){
		abb_destroi(a->esq);
		abb_destroi(a->dir);
		free(a);
	}
}

int abb_vazia( abb_t* a )
{
	return (a == NULL);
}

int abb_busca( abb_t* a, int dado )
{
	if( a->dado == dado )
		return 1;
	else if (dado > a->dado)
		return abb_busca(a->dir, dado);
	else if (dado < a->dado)
		return abb_busca(a->esq, dado);

	return 0;
}

void abb_imprime(abb_t* a)
{
	if(a==NULL)
		return;
	abb_imprime(a->esq);
	printf("%d ", a->dado);
	abb_imprime(a->dir);
}
