#include "ManipulacaoDatas.h"
using namespace std;
int dia, mes, ano, diaSemana; //Variaveis responsáveis pelo armazenamento da data e do dia da semana

bool lerData(){
    bool leituraCorreta = true;
    cin >> dia;
    leituraCorreta = consomeBarra();
    if(leituraCorreta){ //Verifica se a data está sendo digitada como o esperado
        cin >> mes;
        leituraCorreta = consomeBarra();
        if(leituraCorreta){ //Verifica se a data está sendo digitada como o esperado
            cin >> ano;
            return leituraCorreta;
        }
    }
    return leituraCorreta;
}

bool verificaFinalSemana(){
    if(diaSemana == 6 || diaSemana == 0){
        return true;
    }else{
        return false;
    }
}

void calculaDiaSemana(){
    static int mesMagico[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; //Vetor com valores de meses mágicos correspontes a cada mês do ano
    ano -= mes < 3;
    diaSemana =  ( ano + ano / 4 - ano / 100 + ano / 400 + mesMagico[mes- 1] + dia) % 7; //Formulá responsável pelo cálculo do dia correspondente a data
}

bool consomeBarra(){
    if ( cin.get() != '/' ){
      cout << "Esperado / para inserção da data\n" << endl;
      return false;
   }
   return true;
}
