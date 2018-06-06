#ifndef FALSAPOSICAO_H_INCLUDED
#define FALSAPOSICAO_H_INCLUDED
class FalsaPosicao
{
private:
    long double funcao(long double val);
    long double Xk(long double a, long double b);
public:
    FalsaPosicao();
    ~FalsaPosicao();
    long double metodo(long double precisao, int iteracoes, long double xo, long double x1);
};

#endif // FALSAPOSICAO_H_INCLUDED
