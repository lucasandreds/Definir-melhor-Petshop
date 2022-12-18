#include <iostream>
#include <time.h>
#include <string.h>

#include "Petshops.h"
#include "ManipulacaoDatas.h"
#include "ManipulacaoQuantidade.h"

using namespace std;
void calculoMelhorPetshop(MeuCaninoFeliz meuCaninoFeliz, VaiRex vaiRex, ChowChawgas chowChawgas); //Função Responsável por receber o valor total em cada petshop e selecionar qual seria o melhor petshop

int main(){
    bool leituraCorreta = true;
    char confirmarContinuacao = 's';

    //Inicializa o objeto de cada petshop
    MeuCaninoFeliz meuCaninoFeliz;
    VaiRex vaiRex;
    ChowChawgas chowChawgas;


    while(tolower(confirmarContinuacao) == 's'){ //Sistema de repetição do sistema
        system("clear"); //Limpa a tela

        //Chama as função de leitura de dados
        printf("Digite as informações no formato: **/**/** * *, sendo respectivamente a data, a quantidade de cães pequenos e quantidade de cães grandes:\n\n");
        leituraCorreta = lerData();
        if(leituraCorreta) leituraCorreta = lerQuantidade();
        if(leituraCorreta){
            //Verifica o dia da semana correspondente a data digitada
            calculaDiaSemana();

            //Define se a data é em um final de semana
            meuCaninoFeliz.defineData(verificaFinalSemana());
            vaiRex.defineData(verificaFinalSemana());

            //Chama a função de verificação do melhor petshop
            calculoMelhorPetshop(meuCaninoFeliz, vaiRex, chowChawgas);
        }

        cout << "Deseja verificar novamente o melhor petshop ? (Digite 's' para sim)\n" << endl; //Verifica se o usuário quer digitar novamente outra data e outra quantidade de animais
        cin >> confirmarContinuacao;
    }

    return 0;
}

void calculoMelhorPetshop(MeuCaninoFeliz meuCaninoFeliz, VaiRex vaiRex, ChowChawgas chowChawgas){
    cout << endl;

    //Recebe o preco total em cada petshop disponível
    float precoMeuCaninoFeliz = meuCaninoFeliz.SomaPrecoTotal(getQuantidadePequenos(),getQuantidadeGrandes());
    float precoVaiRex = vaiRex.SomaPrecoTotal(getQuantidadePequenos(),getQuantidadeGrandes());
    float precoChowChawgas = chowChawgas.SomaPrecoTotal(getQuantidadePequenos(),getQuantidadeGrandes());

    //Estruturas de decisão responsáveis por comparar os preços e descobrir o melhor petshop
    if(precoMeuCaninoFeliz < precoVaiRex){ //Verifica se o preco no Meu Canino Feliz é menor que no Vai Rex
        if(precoMeuCaninoFeliz < precoChowChawgas){ // Verifica se o preco no Meu Canino Feliz é menor que no Chow Chawgas
            cout << "Melhor opção: Meu Canino Feliz - R$ " << precoMeuCaninoFeliz << endl;
        }else if(precoMeuCaninoFeliz == precoChowChawgas){ //Verifica se o preco no Meu Canino Feliz é igual no Chow Chawgas
            if(meuCaninoFeliz.getDistancia() < chowChawgas.getDistancia()){ //Verifica se a distancia do Meu Canino feliz é menor que no Chow Chawgas
                cout << "Melhor opção: Meu Canino Feliz - R$ " << precoMeuCaninoFeliz << endl;
            }else{ //Verifica-se que a distancia para o Chow Chawgas é menor que do Meu Canino Feliz
                cout << "Melhor opção: ChowChawgas - R$ " << precoChowChawgas << endl;
            }
        }else{ //Verifica-se que o preco no Chow Chawgas é menor que no Meu Canino Feliz
            cout << "Melhor opção: ChowChawgas - R$ " << precoChowChawgas << endl;
        }
    }else if(precoMeuCaninoFeliz == precoVaiRex){ //Verifica se o preco no Meu Canino Feliz é igual no Vai Rex
        if(precoChowChawgas < precoMeuCaninoFeliz){ //Verifica se o preco no Chow Chawgas é menor que no Meu Canino Feliz
            cout << "Melhor opção: ChowChawgas - R$ " << precoChowChawgas << endl;
        }else if (precoMeuCaninoFeliz == precoChowChawgas){ //Verifica se o preco no Meu Canino Feliz é igual ao do Chow Chawgas

            if(meuCaninoFeliz.getDistancia() < chowChawgas.getDistancia()){ //Verifica se a distancia do Meu Canino Feliz é menor que o do Chow Chawgas
                if(meuCaninoFeliz.getDistancia() < vaiRex.getDistancia()){ //Verifica se a distancia do Meu Canino Feliz é menor que o do Vai Rex
                    cout << "Melhor opção: Meu Canino Feliz - R$ " << precoMeuCaninoFeliz << endl;
                }else{ //Verifica-se que a distancia do Vai Rex é menor que o do Meu Canino Feliz
                    cout << "Melhor opção: Vai Rex - R$ " << precoVaiRex << endl;
                }
            }else{ // Verifica-se que a distancia do Chow Chawgas é menor que o do Meu Canino Feliz
                if(chowChawgas.getDistancia() < vaiRex.getDistancia()){ // Verifica se a distancia do Chow Chawgas é menor que o do Vai Rex
                    cout << "Melhor opção: ChowChawgas - R$ " << precoChowChawgas << endl;
                }else{ // Verifica-se que distancia do Vai Rex é menor que a do Chow Chawgas
                    cout << "Melhor opção: Vai Rex - R$ " << precoVaiRex << endl;
                }
            }
        }else{ // Verifica-se que o preço Meu Canino Feliz e do Vai Rex é menor que o do Chow Chawgas
            if(meuCaninoFeliz.getDistancia() < vaiRex.getDistancia()){ //Verifica se a distancia do Meu Canino Feliz é menor que o do Vai Rex
                cout << "Melhor opção: Meu Canino Feliz - R$ " << precoMeuCaninoFeliz << endl;
            }else{ // Verifica-se que a distancia do Vai Rex é menor que o do Meu Canino Feliz
                cout << "Melhor opção: Vai Rex - R$ " << precoVaiRex << endl;
            }
        }

    }else { //Verifica-se que o preco do Vai Rex é menor que o do Meu Canino Feliz
        if(precoVaiRex < precoChowChawgas){ //Verfica se o preco do Vai Rex é menor que o preço do Chow Chawgas
             cout << "Melhor opção: Vai Rex - R$ " << precoVaiRex << endl;
        }else if(precoVaiRex == precoChowChawgas){ // Verifica se o preco do Vai Rex é igual ao preço do Chow Chawgas
            if(vaiRex.getDistancia() < chowChawgas.getDistancia()){ //Verifica se a distancia do Vai Rex é menor que a distancia do Chow Chawgas
                cout << "Melhor opção: Vai Rex - R$ " << precoVaiRex << endl;
            }else{ //Verifica-se que a distancia do Chow Chawgas é menor que a distancia do Vai Rex
                cout << "Melhor opção: ChowChawgas - R$ " << precoChowChawgas << endl;
            }
        }else{ //Verifica-se que o preço do Chow Chawgas é menor que o do Vai Rex
            cout << "Melhor opção: ChowChawgas - R$ " << precoChowChawgas << endl;
        }
    }
    cout << endl;
}
