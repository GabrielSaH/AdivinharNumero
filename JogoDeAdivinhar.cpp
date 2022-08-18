#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){    
    cout << "********************************************************" << endl;
    cout << "*******Ola, Bem-vindo ao jogo de adivinhacao************" << endl;
    cout << "********************************************************" << endl; 
    int chute(0), tentativas(1), pontuacao(1000), tentativasMax(0), contRand(0), dificuldadeNum(1);
    char dificuldade;
    bool acertou(false);

    


    cout << "Escolha o seu nivel de dificuldade" << endl;
    cout << "Facil (F)    Medio (M)    Dificil (D)" << endl;
    cin >> dificuldade;

    if (dificuldade == 'F'){
        tentativasMax = 15;
    }

    if (dificuldade == 'M'){
        tentativasMax = 10;
    }

    if (dificuldade == 'D'){
        tentativasMax = 10;
        dificuldadeNum = 10;
    }

    srand(time(NULL));
    const int NUMEROSECRETO (rand() % (100 * dificuldadeNum)); 

    for (tentativas; tentativas <= tentativasMax; tentativas++){
        cout << "qual o seu chute? " << endl;
        cin >> chute;
        
        if (chute == NUMEROSECRETO){
            acertou = true;
            break;
        }

        else if (chute > NUMEROSECRETO){
            cout << "Seu chute foi maior que o numero secreto!" << endl << endl; 
            pontuacao = pontuacao - (chute - NUMEROSECRETO);
        }

        else if (chute < NUMEROSECRETO){
            cout << "Seu numero foi menor que o numero secreto!" << endl << endl;
            pontuacao = pontuacao - (NUMEROSECRETO - chute);


        }


        else{
            cout << endl << "aconteceu algo de errado tente novamente!" << endl;
        }

    }
    
    if (acertou){
        cout << endl << "Parabens voce acertou em " << tentativas << " Tentantivas!!" << endl;
        cout << "Sua pontuacao foi " << pontuacao << " pontos!!" << endl;
    }

    else{
        cout << endl << "Acabou as tentativas, Voce perdeu!!" << endl;
    }

    return 0;
}