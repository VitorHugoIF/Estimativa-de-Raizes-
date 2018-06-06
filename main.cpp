#include <iostream>
#include "NewtonRaphson.h"
#include "Bissecao.h"
#include "QuaseNewton.h"
#include "FalsaPosicao.h"
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    NewtonRaphson *newton = new NewtonRaphson();
    cout<<"resposta: "<<newton->metodo(pow(10,-20), 2,1)<<endl;
    cout<<"******************************************************"<<endl;

   /* QuaseNewton *quase = new QuaseNewton();
    cout<<"resposta: "<<quase->metodo(pow(10,-5), 2, 1.4)<<endl;
    cout<<"******************************************************"<<endl;

    Bisseccao *bissecao = new Bisseccao();
    cout<<"resposta: "<<bissecao->metodo(pow(10,-2), 7, 1, 2)<<endl;
    cout<<"******************************************************"<<endl;

    FalsaPosicao *falsaposicao = new FalsaPosicao();
    cout<<"resposta: "<<falsaposicao->metodo(pow(10,-4), 7, 1.5,2)<<endl;
    cout<<"******************************************************"<<endl;*/

    return 0;
}
