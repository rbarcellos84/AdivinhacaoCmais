#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

//compilação
//g++ Jogo.cpp -o Jogo.out
//executando
//./Jogo.out

int main (){
    int chute;
    int tentativas = 0;
    int quantidade_tentativas;
    int quantidade_jogadores;
    int jogador = 0;
    bool acertou = false;
    bool perdeu = false;
    bool maior = false;
    bool nao_acertou = false;
    char nivel = 'I';
    double pontos = 1000.0;
    double pontos_perdidos = 0;

    cout << "*********************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao em c++! *" << endl;
    cout << "*********************************************" << endl;

    cout << "Escolha o numer do jogo:" << endl;
    while (toupper(nivel) != 'F' && toupper(nivel) != 'M' && toupper(nivel) != 'D')
    {
        cout << " (F) Facil    (M) Medio    (D) Dificil" << endl;
        cin >> nivel;

        if (toupper(nivel) != 'F' && toupper(nivel) != 'M' && toupper(nivel) != 'D')
            cout << "Opcao invalida. Vamos tentar novamente!" << endl;
    }
    
    if (toupper(nivel) == 'F')
        quantidade_tentativas = 15;
    else if (toupper(nivel) == 'M')
        quantidade_tentativas = 10;
    else
        quantidade_tentativas = 5;

    srand(time(NULL));
    const int SECRETO = rand() % 101;

    cout << "Informe a quantidade de jogadores?" << endl;
    cin >> quantidade_jogadores;

    while (quantidade_jogadores > 0)
    {
        quantidade_jogadores --;
        jogador++;
        pontos = 1000.0;
        pontos_perdidos = 0;
        cout << "Seja bem-vindo jogador " << jogador << endl;

        while (!nao_acertou){
            tentativas++;
            cout << "Numero de tentativas: " << tentativas << ". De " << quantidade_tentativas << endl;

            cout << "Chute um valor?" << endl;
            cin >> chute;

            pontos_perdidos = abs(chute - SECRETO) / 2.0;
            pontos = pontos - pontos_perdidos;

            cout << "O valor do seu chute e: " << chute << endl;

            acertou = chute == SECRETO;
            maior = chute > SECRETO;
            nao_acertou = acertou;

            if (acertou)
                cout << "Parabens voce acertou!" << endl;
            else if (maior)
                cout << "Seu chute foi maior que o numero secreto." << endl;
            else
                cout << "Seu chute foi menor que o numero secreto." << endl;

            perdeu = quantidade_tentativas == tentativas;
            if (nao_acertou){
                cout << "Fim de jogo. Voce venceu!" << endl;
                cout.precision(2);
                cout << fixed;
                cout << "Sua pontuacao e de " << pontos << endl;
            }
                
            if (perdeu){
                cout << "Fim de jogo. Voce perdeu!" << endl; 
                cout << "O numero secreto e " << SECRETO << endl;
                cout << "Tente novamente!" << endl;
                nao_acertou = true;
            }
        }
    }
}