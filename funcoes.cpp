#include "proto.h"
using namespace std;

//cria tabela
Hash* criaHash(int tamanho) {
    Hash* ha = new Hash;
    ha->tamanho = tamanho;
    ha->qtd = 0;
    ha->itens = new dicio*[tamanho];
    for (int i = 0; i < tamanho; i++)
        ha->itens[i] = nullptr;
    return ha;
}
//liberar tabela
void liberaHash(Hash* ha) {
    if (!ha) return;
    for (int i = 0; i < ha->tamanho; i++) {
        dicio* atual = ha->itens[i];
        while (atual) {
            dicio* temp = atual;
            atual = atual->prox;
            delete temp;
        }
    }
    delete[] ha->itens;
    delete ha;
}

//transfirma a string em numero(hash)
int valorString(const string &str) {
    int valor = 0;
    for (char c : str)
        valor = (31 * valor + c) % TABLE_SIZE;
    return valor;
}

//insere
int insereHash(Hash* ha, const string &pt, const string &en) {
    if (!ha) return 0;
    int pos = valorString(pt);
    dicio* novo = new dicio;
    novo->portugues = pt;
    novo->ingles = en;
    novo->prox = ha->itens[pos];
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

//remove
int removeHash(Hash* ha, const string &pt) {
    if (!ha) return 0;
    int pos = valorString(pt);
    dicio *ant = nullptr, *atual = ha->itens[pos];
    while (atual && atual->portugues != pt) {
        ant = atual;
        atual = atual->prox;
    }
    if (!atual) return 0;
    if (!ant)
        ha->itens[pos] = atual->prox;
    else
        ant->prox = atual->prox;
    delete atual;
    ha->qtd--;
    return 1;
}

//busca em portugues
dicio* buscaPorPt(Hash* ha, const string &pt) {
    if (!ha) return nullptr;
    int pos = valorString(pt);
    dicio* atual = ha->itens[pos];
    while (atual) {
        if (atual->portugues == pt) return atual;
        atual = atual->prox;
    }
    return nullptr;
}

//busca em ingles
dicio* buscaPorEn(Hash* ha, const string &en) {
    if (!ha) return nullptr;
    for (int i = 0; i < ha->tamanho; i++) {
        dicio* atual = ha->itens[i];
        while (atual) {
            if (atual->ingles == en) return atual;
            atual = atual->prox;
        }
    }
    return nullptr;
}

// printa
void mostraDicionario(Hash* ha, int modo) {
    if (!ha) return;
    cout <<endl<<"--- DICIONÁRIO ---"<<endl;
    for (int i = 0; i < ha->tamanho; i++) {
        dicio* atual = ha->itens[i];
        while (atual) {
            if (modo == 0)
                cout << atual->portugues << " -> " << atual->ingles <<endl;
            else
                cout << atual->ingles << " -> " << atual->portugues <<endl;
            atual = atual->prox;
        }
    }
}

//traduz
void traduzTexto(Hash* ha, string texto) {
    string palavra;
    stringstream ss(texto);
    while (ss >> palavra) {
        dicio* d = buscaPorPt(ha, palavra);
        if (d) cout << d->ingles << " ";
        else cout << palavra << " ";
    }
    cout << endl;
}








