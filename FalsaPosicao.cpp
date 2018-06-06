#include "FalsaPosicao.h"
#include <cmath>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <limits.h>

using namespace std;

FalsaPosicao::FalsaPosicao() {};
FalsaPosicao::~FalsaPosicao() {};
long double FalsaPosicao::Xk(long double a, long double b)//formula da falsa posicao que calcula o valor de XK
{
    return ((a*funcao(b) - b*funcao(a))/(funcao(b)-funcao(a)));
}
long double FalsaPosicao::funcao(long double x)
{
    return pow(x/2,2) - sin(x);//pow(x,3) - 5;
}
long double FalsaPosicao::metodo(long double precisao, int iteracoes, long double a, long double b)
{
    FILE* saida;
    saida = fopen("FalsaPosicao.txt","w");
    int i = 0;
    long double xk = 0, xk1 = 0;//xk-1
    cout.precision(9);
    fprintf(saida,"%4s %16s %16s %16s %16s %16s %16s", "IT: ", "A: ", "B: ","XK: ",  "F(A): ", "F(B): ", "F(XK):");
    if(funcao(a)*funcao(b) < 0)
    {
        xk = Xk(a,b);
        while(i< iteracoes)
        {
            fprintf(saida,"\n");
            fprintf(saida,"%1d |%.10Le |%.10Le |%.10Le |%.10Le |%.10Le |%.10Le", i, a, b, xk, funcao(a), funcao(b), funcao(xk));

            cout<<"ite:  "<<i
                <<"       ||a: "<<a
                <<"       ||b: "<<b
                <<"       ||xk: "<<xk
                <<"       ||f(a): "<<funcao(a)
                <<"       ||f(b): "<<funcao(b)
                <<"       ||f(xk): "<<funcao(xk)<<endl;
            if((funcao(b) - funcao(a)) == 0)
            {
                cout<<"Divisao por zero, nao converge!"<<endl;
                return 0;
            }
            else if((funcao(b) - funcao(a)) == 0 && (a*funcao(b) - b*funcao(a)) == 0 )
            {
                cout<<"indeterminacao, nao converge!"<<endl;
                return 0;
            }
            else if ((funcao(b) - funcao(a)) >= LONG_MAX && (a*funcao(b) - b*funcao(a)) >= LONG_MAX )
            {
                cout<<"indeterminacao, nao converge!"<<endl;
                return 0;
            }

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
            xk = Xk(a,b);
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
