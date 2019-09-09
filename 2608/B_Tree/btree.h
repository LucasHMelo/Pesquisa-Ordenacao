#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#if DEBUG
#include <stdio.h>
#endif

#include <stdlib.h>
#include <assert.h>

#include "util.h"
#include "btree_util.h"

/*
   B-Tree
   order:  n�mero da ordem da B-Tree (cada n� da B-Tree possui [order-1, 2*order] filhos)
   root:   ponteiro para o n� raiz da B-Tree (possui [2, 2*order] filhos)
 */
typedef struct btree_t {
	int order;
	node_t *root;
} BTree;

/*
    Aloca e retorna uma B-Tree na Heap de ordem order
 */
BTree* btree_new(int order);
/*
    Inicializa uma B-Tree de ordem order.
    Utilizada como sub-procedimento na fun��o btree_new().
    Pode ser utilizada para inicializar uma B-Tree criada na Stack.
 */
void btree_init(BTree *bt, int order);
/*
    Deleta uma B-Tree alocada na Stack.
    Utilizada como sub-procedimento na fun��o btree_delete_h().
    N�O tenta dar free na B-Tree: free(bt).
 */
void btree_delete_s(BTree *bt);
/*
    Deleta uma B-Tree alocada na Heap.
    EXECUTA um FREE na B-Tree: free(bt).
    Undefined behavior caso bt n�o tenha sido alocado com uma chamada � malloc().
 */
void btree_delete_h(BTree *bt);

/*
    Procura a chave key na B-Tree bt.
    Chama a fun��o _btree_find_node() sobre a raiz de bt.
 */
node_position btree_find(BTree *bt, int key);
/*
    Insere a chave key na B-Tree bt, associando-a ao valor value.
    Trata o caso em que a raiz est� cheia analisando a raiz
    e chamando (possivelmente) a fun��o _btree_split().
    Chama a fun��o _btree_insert_nonfull() sobre a raiz de bt.
 */
node_position btree_insert(BTree *bt, int key, void *value);
/*
    Remove a chave key na B-Tree bt.
    Chama a fun��o _btree_remove_node() sobre a raiz de bt.
    ATEN��O: Pode n�o ser seguro acessar tal posi��o.
 */
node_position btree_remove(BTree *bt, int key);

/*
    Procura a key na sub-�rvore com raiz node.
    Retorna um node_position para permitir a recupera��o do valor
    associado � key.
    Retorna node_position(NULL, -1) caso key n�o seja encontrada.
 */
node_position _btree_find_node(node_t *node, int key);
/*
    Trata todos os casos de inser��o de um pair na B-Tree.
    Retorna um node_position indicando onde a chave foi inserida.
    Retorna node_position(NULL, -1) caso key j� exista em bt.

    order:  ordem da �rvore � qual node pertence. Utilizado para alocar um novo n�.
 */
node_position _btree_insert_nonfull(node_t *node, pair_t *pair, int order);
/*
    Realiza a fun��o split sobre x, na posi��o pos.
    order:  ordem da �rvore � qual node pertence. Utilizado para alocar um novo n�.
 */
void _btree_split(node_t *x, int pos, int order);
/*
    Trata todos os casos de remo��o de uma key na B-Tree.
    Realizada poss�veis chamadas recursivas.

    Retorna um node_position indicando onde a chave estava localizada.
    ATEN��O: Pode n�o ser seguro acessar tal posi��o.
    Retorna node_position(NULL, -1) caso key n�o exista em bt.
 */
node_position _btree_remove_node(node_t *node, int key, int order);

/*
    Retorna o node_position da maior key em node
 */
inline node_position _node_find_max(node_t *node);
/*
    Retorna o node_position da menor key em node
 */
inline node_position _node_find_min(node_t *node);


#endif // BTREE_H_INCLUDED
