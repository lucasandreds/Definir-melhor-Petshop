#include "ManipulacaoQuantidade.h"
using namespace std;
int quantidadeCaesPequenos, quantidadeCaesGrandes; //Variaveis responsável por armazenar a quantidade de caes grandes e pequenos

bool lerQuantidade(){
    bool leituraCorreta = true;
    leituraCorreta = consomeEspaco();
    if(leituraCorreta){ //Verifica se a quantidade está sendo digitada como o esperado
        cin >> quantidadeCaesPequenos;
        leituraCorreta = consomeEspaco();
        if(leituraCorreta){ //Verifica se a quantidade está sendo digitada como o esperado
            cin >> quantidadeCaesGrandes;
            return leituraCorreta;
        }
    }
    return leituraCorreta;
}
int getQuantidadeGrandes(){
    return quantidadeCaesGrandes;
}
int getQuantidadePequenos(){
    return quantidadeCaesPequenos;
}

bool consomeEspaco(){
    if ( cin.get() != ' ' ){
      cout << "Esperado espaço para inserção da quantidade\n" << endl;
      return false;
   }
   return true;
}


