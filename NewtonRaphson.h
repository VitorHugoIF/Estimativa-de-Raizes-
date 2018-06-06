#ifndef NEWTONRAPHSON_H_INCLUDED
#define NEWTONRAPHSON_H_INCLUDED
#include <stdlib.h>
#include <iostream>
using namespace std;
class NewtonRaphson
{
private:
    /*long double f;
    long double d;
    long double xki;
    long double xko;*/
    long double funcao(long double val);
    long double derivada(long double val);
    long double Xk(long double xk, long double x);
public:
    NewtonRaphson();
    ~NewtonRaphson();
    long double metodo(long double precisao, int iteracoes, long double xo);
};


#endif // NEWTONRAPHSON_H_INCLUDED
