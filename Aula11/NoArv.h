#ifndef NOARV_H_INCLUDED
#define NOARV_H_INCLUDED

class NoArv
{
  public:
    NoArv()               { };
    ~NoArv()              { };
    void setEsq(NoArv *p) { esq = p; };
    void setInfo(int val) { info = val; };
    void setFator(int val) {fator = val;}; /// altera fator do no
    void setDir(NoArv *p) { dir = p; };
    NoArv* getEsq()       { return esq; };
    int getInfo()         { return info; };
    NoArv* getDir()       { return dir; };
    int getFator() {return fator;}; /// obtem o fator do no
    void setAltura(int val) {altura = val;}; /// altera altura
    int getAltura() {return altura;}; /// obtem altura
  private:
    NoArv* esq; // ponteiro para o filho a esquerda
    int info;   // informação do No (int)
    NoArv* dir; // ponteiro para o filho a direita
    int fator; /// fator do No
    int altura; /// altura do No
};

#endif // NOARV_H_INCLUDED
