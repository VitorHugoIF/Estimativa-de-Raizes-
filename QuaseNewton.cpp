#include "QuaseNewton.h"
#include <cmath>
#include <math.h>
#include <fstream>
#include <iostream>
#include <limits.h>

using namespace std;
QuaseNewton::QuaseNewton() {}

QuaseNewton::~QuaseNewton() {}

long double QuaseNewton::funcao(long double x)
{
    return (pow(x,0.5) - 5*pow(M_E,-x));
}

long double QuaseNewton::derivada(long double x)
{
    return funcao(x+1)-funcao(x)/((x+1)-x);//derivada progressiva
}

long double QuaseNewton::metodo(long double precisao, int iteracoes, long double xo)
{
    FILE* saida;
    saida = fopen("QuaseNewton.txt","w");
    int i = 0;
    long double xk1 = 0;//xk+1
    fprintf(saida,"%4s %14s %14s %14s", "IT: ", "XO: ", "F'(Xo): ", "F(Xo): ");
    while(i<iteracoes)
    {
        xk1 = xo - (funcao(xo)/derivada(xo));
        fprintf(saida,"\n");
        fprintf(saida,"% 1d |%.10Le |%.10Le |%.10Le", i, xo, derivada(xo), funcao(xo));
        //cout.precision(9);

        cout<<"ite: "<<i
            <<"       ||xo: "<<xo
            <<"       ||f'(xo): "<<derivada(xo)
            <<"       ||f(xo): "<<funcao(xo)<<endl;

        if(derivada(xo) == 0)
        {
            cout<<"Divisao por zero, nao converge!"<<endl;
            return 0;
        }
        else if(funcao(xo) == 0 && derivada(xo) == 0 )
        {
            cout<<"indeterminacao, nao converge!"<<endl;
            return 0;
        }
        else if (funcao(xo) >= LONG_MAX && derivada(xo) >= LONG_MAX)
        {
            cout<<"indeterminacao, nao converge!"<<endl;
            return 0;
        }
        if( fabs(funcao(xk1)) < precisao )//|| fabs(xk1 - xo) < precisao || fabs(xk1 - xo)/fabs(xk1) < precisao)
        {
            fprintf(saida,"\n");
            fprintf(saida, "resposta: ");
            fprintf(saida,"%.10Le", xk1);
            return xk1;
        }
        i++;
        xo=xk1;
    }
    if(i==iteracoes){

    cout<<"Parou pelo criterio de iteracoes ! :  "<<iteracoes<<" iteracoes"<<endl;
    fprintf(saida,"\n");
    fprintf(saida, "resposta: ");
    fprintf(saida,"%.10Le", xk1);
    fprintf(saida,"\n");
    fprintf(saida, "Parou pelo criterio de iteracoes ! :  ");
    fprintf(saida, "%d ", iteracoes);
    return xk1;}
}


