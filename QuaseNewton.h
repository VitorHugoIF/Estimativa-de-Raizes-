#ifndef QUASENEWTON_H_INCLUDED
#define QUASENEWTON_H_INCLUDED

class QuaseNewton
{
private:
    long double funcao(long double val);
    long double derivada(long double val);
public:
    QuaseNewton();
    ~QuaseNewton();
    long double metodo(long double precisao, int iteracoes, long double xo);
};

#endif // QUASENEWTON_H_INCLUDED
