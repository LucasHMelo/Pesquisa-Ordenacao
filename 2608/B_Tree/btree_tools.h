#ifndef BTREE_TOOLS_H_INCLUDED
#define BTREE_TOOLS_H_INCLUDED

#include <stdio.h>

#include "btree.h"

/*
    Executa uma DFS em node, imprimindo as chaves associadas � ele.
    Usa o par�metro level no print dos dados do n�.
 */
void _btree_dfs_node(node_t *node, int level);
/*
    Executa uma DFS na B-Tree, imprimindo dados associados aos seus n�s
    (em especial suas chaves) em ordem POSFIXA.
 */
void btree_dfs(BTree *bt);

/*
    Fun��o para testes.
    Pesquisa a key na tree com print's para debug.
 */
void print_find(BTree *tree, int key);
/*
   Fun��o para testes.
   Pesquisa n key's na tree com print's para debug.
 */
void print_find_n(BTree *tree, int *nums, int n);
/*
    Fun��o para testes.
    Pesquisa n key's na tree com print's para debug
    e a verifica��o de que a chave nums[i] foi encontrada na posi��o pos[i] esperada.
 */
void print_find_assert_n(BTree *tree, int *nums, int *pos, int n);

/*
    Fun��o para testes.
    Insere a key na tree com print's para debug
 */
void print_insert(BTree *tree, int key);
/*
    Fun��o para testes.
    Insere n key's na tree com print's para debug
 */
void print_insert_n(BTree *tree, int *nums, int n);

/*
    Fun��o para testes.
    Remove a key na tree com print's para debug
 */
void print_remove(BTree *tree, int key);
/*
    Fun��o para testes.
    Remove n key's na tree com print's para debug
 */
void print_remove_n(BTree *tree, int *nums, int n);


#endif // BTREE_TOOLS_H_INCLUDED
