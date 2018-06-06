#ifndef BISSECAO_H_INCLUDED
#define BISSECAO_H_INCLUDED

class Bisseccao
{
private:
    long double funcao(long double val);
public:
    Bisseccao();
    ~Bisseccao();

    long double metodo(long double precisao, int iteracoes, long double xo, long double x1);
};

#endif // BISSECAO_H_INCLUDED
