#include "Petshops.h"

using namespace std;

int Petshops::getDistancia(){
    return distancia;
}

void Petshops::defineData(bool finalDeSemana){
    finalSemana = finalDeSemana;
}
// Meu Canino Feliz

MeuCaninoFeliz::MeuCaninoFeliz(){
    //Aplicando os valores padrões do Meu Canino Feliz
    distancia = 2000;
    precoGrande = 40.00;
    precoPequeno = 20.00;
    multiplicador = 0.20;
}

float MeuCaninoFeliz::SomaPrecoTotal(int quantidade_pequenos, int quantidade_grandes){
    float soma;
    if(finalSemana){ //Verifica se é final de semana
        soma = (((precoGrande + (precoGrande* multiplicador)) * quantidade_grandes) + ((precoPequeno + (precoPequeno * multiplicador)) * quantidade_pequenos)); //Formula do calculo no final de semana do preco final
    }else{ //Verifica-se que não é um final de semana
        soma = ((precoGrande * quantidade_grandes) + (precoPequeno * quantidade_pequenos)); //Formula do calculo no dia de semana do preco final
    }
    return soma;
}

// Vai Rex

VaiRex::VaiRex(){
    //Aplicando os valores padrões do Vai Rex
    distancia = 1700;
    precoGrande = 50.00;
    precoPequeno = 15.00;
    valorSoma = 5;
}

float VaiRex::SomaPrecoTotal(int quantidade_pequenos, int quantidade_grandes){
    float soma;
    if(finalSemana){ //Verifica se é final de semana
        soma = (((precoGrande + valorSoma) * quantidade_grandes) + ((precoPequeno + valorSoma) * quantidade_pequenos)); //Formula do calculo no final de semana do preco final
    }else{ //Verifica-se que não é um final de semana
        soma = ((precoGrande * quantidade_grandes) + (precoPequeno * quantidade_pequenos)); //Formula do calculo no dia de semana do preco final
    }
    return soma;
}

// ChowChawgas

ChowChawgas::ChowChawgas(){
    //Aplicando os valores do ChowChawgas
    distancia = 800;
    precoGrande = 45.00;
    precoPequeno = 30.00;
}

float ChowChawgas::SomaPrecoTotal(int quantidade_pequenos, int quantidade_grandes){
    float soma = ((precoGrande * quantidade_grandes) + (precoPequeno * quantidade_pequenos)); //Formula do calculo do preco final
    return soma;
}
