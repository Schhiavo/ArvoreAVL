#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    void insere(int val);
    void remove(int val);
    void imprime();

private:
    NoArv* raiz; // ponteiro para o No raiz da árvore
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* libera(NoArv *p);
    void calcFator(NoArv *p); /// calcula fator
    int calcAltura(NoArv *p); /// calcula altura
    NoArv* rotacaoSimplesEsq(NoArv *p); /// rotaçao simples pra esquerda
    NoArv* rotacaoSimplesDir(NoArv *p); /// rotação simples pra direita
    NoArv* rotacaoDuplaEsq(NoArv *p); /// rotação dupla pra esquerda
    NoArv* rotacaoDuplaDir(NoArv *p); /// rotação dupla pra direita
    void auximprime(NoArv *p);
};

#endif // ARVBINBUSCA_H_INCLUDED
