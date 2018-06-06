#include "Bissecao.h"
#include <cmath>
#include <math.h>
#include <fstream>
#include <iostream>

using namespace std;

Bisseccao::Bisseccao() {};
Bisseccao::~Bisseccao() {};

long double Bisseccao::funcao(long double x)
{
    return pow(x,3) - 5;
}
long double Bisseccao::metodo(long double precisao, int iteracoes, long double a, long double b)
{
    FILE* saida;
    saida = fopen("Bissecao.txt","w");
    int i = 0;
    long double xk = 0, xk1 = 0;//xk-1
    cout.precision(9);
    fprintf(saida,"%4s %16s %16s %16s %16s %16s %16s", "IT: ", "A: ", "B: ","XK: ",  "F(A): ", "F(B): ", "F(XK):");
    if(funcao(a)*funcao(b) < 0)
    {
        xk = (a+b)/2;
        while(i<iteracoes)
        {
            fprintf(saida,"\n");
            fprintf(saida,"%1d |%.10Le |%.10Le |%.10Le |%.10Le |%.10Le |%.10Le", i, a, b, xk, funcao(a), funcao(b), funcao(xk));

            cout<<"ite:  "<<i
            <<"     ||a: "<<a
            <<"     ||b: "<<b
            <<"     ||xk: "<<xk
            <<"     ||f(a): "<<funcao(a)
            <<"     ||f(b): "<<funcao(b)
            <<"     ||f(xk): "<<funcao(xk)<<endl;

            if(fabs(funcao(xk)) < precisao )//||(b-a) < precisao || fabs(xk - xk1)/fabs(xk) < precisao)
            {
                fprintf(saida,"\n");
                fprintf(saida, "resposta: ");
                fprintf(saida,"%.10Le", xk1);
                return xk;
            }

            if(funcao(xk) == 0)
            {
                fprintf(saida,"\n");
                fprintf(saida, "resposta: ");
                fprintf(saida,"%.10Le", xk1);
                return xk;
            }

            if(funcao(a)*funcao(xk) < 0)
            {
                b = xk;
            }
            else
            {
                a = xk;
            }
            i++;
            xk1 = xk;
            xk = (a+b)/2;
        }
    }
    else
    {
        cout<<"intervalo incompativel!"<<endl;
    }
    fprintf(saida,"\n");
    fprintf(saida, "resposta: ");
    fprintf(saida,"%.10Le", xk1);
    return xk;
}
