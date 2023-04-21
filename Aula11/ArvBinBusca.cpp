#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}


void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            NoArv *aux = menorSubArvDireita(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}



/// ROTAÇÕES----------------------------------------------------------------------------------------

NoArv* ArvBinBusca::rotacaoSimplesEsq(NoArv *p){

    NoArv *q = p->getDir();
	p->setDir(q->getEsq());
	q->setEsq(p);
	return q;
}

NoArv* ArvBinBusca::rotacaoSimplesDir(NoArv *q){

    NoArv *r;
    r = q->getEsq()
    q->setEsq(r->getDir);
    r->setDir(q);
    return r;

}

NoArv* ArvBinBusca::rotacaoDuplaEsq(NoArv* p){

NoArv *q = p->getDir();
NoArv *r = q->getEsq();
p->setDir(r->getEsq());
q->setEsq(r->getDir());
r->setEsq(p);
r->setDir(q);

return r;
}

NoArv* ArvBinBusca::rotacaoDuplaDir(NoArv* p){

NoArv *q = p->getEsq();
NoArv *r = q->getDir();
p->setDir(r->getDir());
q->setEsq(r->getEsq());
r->setDir(p);
r->setEsq(q);

return r;
}

///------------------------------------------------------------------------------------------



/// IMPRIME----------------------------------------------------------------------------------
void ArvBinBusca::imprime(){

auximprime(raiz);

}

void ArvBinBusca::auximprime(NoArv *p){

if(p == NULL){
    return;
}

cout << p->getInfo() << " ";
auximprime(p->getEsq());
auximprime(p->getDir());

}

///-----------------------------------------------------------


///CALCULA ALTURA--------------------------------------------

int ArvBinBusca::calcAltura(NoArv *p){

if(p == NULL){
    return 0;
}  /// CASO BASE



p->setAltura(1 + calcAltura(p->getEsq()) + calcAltura(p->getDir())); /// ALTURA DO NO É 1 + RETORNO DE ESQ + DIR

if(p->getEsq() == NULL && p->getDir() == NULL){
    p->setAltura(0);
    return 0;
} /// CONDIÇÃO PARA GARANTIR QUE TODA SUBARVORE SEM FILHOS TENHA 0 DE ALTURA

return 1 /// A CONDIÇÃO ANTERIOR VAI GARANTIR QUE ESSE RETORNO SEJA SEMPRE DE UM NÓ PAI

}

/// CALCULA FATOR-------------------------------------------------------

void ArvBinBusca::calcFator(NoArv *p){

if(p == NULL){
    return;
} /// CASO BASE

if(p->getEsq() == NULL && p->getDir() == NULL){
    p->setFator(0);
    return;
}  /// GARANTE QUE O FATOR DE QUALQUER NÓ SEM FILHOS É ZERO

calcFator(p->getEsq());
calcFator(p->getDir());


if(p->getEsq() == NULL){
    p->setFator(p->getDir()->getAltura() - 0);
    return;
} /// CONDIÇÃO PRA EVITAR CONTA DE INT COM NULL, GARANTE FATOR POSITIVO

if(p->getDir() == NULL){
    p->setFator(0 - (p->getDir()->getAltura()) );
    return;
} /// CONDIÇÃO PRA EVITAR CONTA DE INT COM NULL, GARANTE FATOR NEGATIVO

p->setFator((p->getDir()->getAltura()) - (p->getEsq()->getAltura()) );
/// CASO NORMAL, ONDE É GARANTIDO QUE O NÓ TENHA NO MINIMO 2 FILHOS

return;
}
///-----------------------------------------------------------------------------
