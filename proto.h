#ifndef proto_h
#define proto_h

#include <bits/stdc++.h>
#include <string>
using std::string;

#define TABLE_SIZE 307

struct dicio {
    string portugues;
    string ingles;
    dicio* prox;
};

struct Hash {
    int qtd;
    int tamanho;
    dicio** itens;
};

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);

int valorString(const string &str);

int insereHash(Hash* ha, const string &pt, const string &en);
int removeHash(Hash* ha, const string &pt);

dicio* buscaPorPt(Hash* ha, const string &pt);
dicio* buscaPorEn(Hash* ha, const string &en);

void mostraDicionario(Hash* ha, int modo);
void traduzTexto(Hash* ha, string texto);

//string viraMinuscula(string s);
//TODO: quando coloco essa função o codigo tranforma tudo em lowercase, mas calcula o hash com a palavra original ai não acha na busca.
#endif
