#ifndef PETSHOPS_H
#define PETSHOPS_H


#include <time.h>


class Petshops //Classe pai responsável por todas as funções e varíaveis comuns à todos os petshops
{
    public:
        void defineData(bool finalSemana); //Função responsável por receber se a data digitada é um final de semana
        virtual float SomaPrecoTotal(int quantidade_pequenos, int quantidade_grandes)=0; //Função virtual modificada em cada classe filho
        int getDistancia(); //Função responsável por permitir que outros códigos acessem a distancia de cada petshop
    protected:
        //Variaveis comuns a cada petshop, sendo diferente e modificada em cada petshop
        int distancia;
        float precoPequeno;
        float precoGrande;
        bool finalSemana;
};

class MeuCaninoFeliz : public Petshops { //Classe MeuCaninoFeliz que herda a classe Petshops com todas as funções exclusivas do MeuCaninoFeliz
    public:
        MeuCaninoFeliz(); //Função construtura responsável por definir os valores de todas as varíaveis
        float SomaPrecoTotal(int quantidade_pequenos, int quantidade_grandes); //Função responsável por calcular o preço total no petshop, aplicando a multiplicador caso seja final de semana
    private:
        float multiplicador; //Variavel que armazena o multiplicador do MeuCaninoFeliz
};

class VaiRex : public Petshops { //Classe VaiRex que herda a classe Petshops com todas as funções exclusivas do VaiRex
    public:
        VaiRex(); //Função construtura responsável por definir os valores de todas as varíaveis
        float SomaPrecoTotal(int quantidade_pequenos, int quantidade_grandes); //Função responsável por calcular o preço total no petshop, aplicando a soma caso seja final de semana
    private:
        int valorSoma; //Variavel que armazena o valor somado do VaiRex
};

class ChowChawgas : public Petshops { //Classe ChowChawgas que herda a classe Petshops com todas as funções exclusivas do ChawChawgas
    public:
        ChowChawgas(); //Função construtura responsável por definir os valores de todas as varíaveis
        float SomaPrecoTotal(int quantidade_pequenos, int quantidade_grandes); //Função responsável por calcular o preço total no petshop
};
#endif // PETSHOPS_H
