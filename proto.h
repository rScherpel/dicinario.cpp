#ifndef PROTO_H
#define PROTO_H

#include <bits/stdc++.h>
using namespace std;

struct dicio {
    int id;
    string palavra_pt;
    string palavra_en;
};
typedef struct hash Hash;
Hash* criaHash (int TABLE_SIZE);
void liberaHash (Hash* ha);
int valorString(char *str);
int insereHash_semColisao (Hash* ha, struct dicio a1);
int buscaHash_semColisao (Hash* ha, int id,struct dicio* a1);

int insereHash_enderAberto (Hash* ha, struct dicio a1);
int buscaHash_enderAberto (Hash* ha, int id,struct dicio* a1);

// Funções básicas da lista
//insere OK
//remove OK
//busca OK
//print
//tradução
#endif
