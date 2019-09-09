#ifndef BTREE_UTIL_H_INCLUDED
#define BTREE_UTIL_H_INCLUDED

#if DEBUG
#include <stdio.h>
#endif

#include <stdlib.h>
#include <assert.h>

#include "util.h"

/*
   pair <int key, void* value>

   Como o valor associado � chave � um ponteiro void,
   a B-Tree ter� capacidade de armazenar qualquer tipo de dado
   index�vel por uma chave inteira.
 */
typedef struct pair_t {
	int key;
	void *value;
} pair_t;

/*
   N� da B-Tree
   is_leaf:    esse � um n�-folha?
   n_keys:     n�mero de chaves ativas

   children:   ponteiro para a lista de (ponteiros para) n�s-filhos
   keys:       ponteiro para a lista de (ponteiros para) pairs<key, value>
 */
typedef struct node_t {
	bool is_leaf;
	int n_keys;

	struct node_t **children;
	pair_t **keys;
} node_t;

/*
   Posi��o de uma key/elemento da B-Tree
   Aten��o ao uso:
    Exp�e acesso direto � um n� da B-Tree, incluindo suas chaves e n�s-filhos

   node:    ponteiro para o n�
   index:   indice da key dentro do n�
 */
typedef struct node_position_t {
	node_t *node;
	int index;
} node_position;

/*
    Cria um novo node_position com os valores passados
 */
node_position _node_position_new(node_t *node, int index);
/*
    Aloca e retorna um novo node, com espa�o para at� 2*order-1 ponteiros .
    para pair's e 2*order ponteiros para node's.
    O par�metro is_leaf � atribu�do ao atributo de mesmo nome no node.
 */
node_t* _node_new(int order, bool is_leaf);
/*
    Aloca e retorna um novo pair com os valores passados.
 */
pair_t* _pair_new(int key, void *value);

/*
    Aloca e retorna um novo pair com os valores do pair passado como par�metro
 */
inline pair_t* _pair_copy(pair_t *p);

/*
    node:   n� em que a key ser� pesquisada
    key:    chave � se procurar
    pos:    retorno da posi��o em que a chave foi encontrada. Default: -1
    @return: se a chave key pertence ou n�o ao n� node
 */
inline bool _node_find_key(node_t *node, int key, int* pos);

/*
    As fun��es a seguir correspondem � execu��o de um FOR.
    Tratam-se apenas de fun��es auxiliares para aumentar a legibilidade
    do c�digo principal (remove_key) e precisam do contexto em que
    foram chamadas para serem compreendidas.
    O contador CONT do FOR ser� executado de [beg, end).

    A opera��o executada no FOR ser�:
        to.keys[padding_to + CONT] <- from.keys[padding_from + CONT]
 */
inline void _node_deslocate_keys_up(node_t *to, node_t *from, int beg, int end, int padding_to, int padding_from);
inline void _node_deslocate_keys_down(node_t *to, node_t *from, int beg, int end, int padding_to, int padding_from);
/*
    A opera��o executada no FOR ser�:
        to.children[padding_to + CONT] <- from.children[padding_from + CONT]
 */
inline void _node_deslocate_children_up(node_t *to, node_t *from, int beg, int end, int padding_to, int padding_from);
inline void _node_deslocate_children_down(node_t *to, node_t *from, int beg, int end, int padding_to, int padding_from);

/*
    Deleta um node alocado pela fun��o _node_new(),
    isto �, essa fun��o n�o tem como responsabilidade deletar
    a chaves e os n�s-filhos associados � node.
 */
inline void _node_delete(node_t *node);

#endif // BTREE_UTIL_H_INCLUDED
