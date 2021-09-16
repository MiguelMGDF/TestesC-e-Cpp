#include<iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

struct pessoa{

    string nome;
    int rg;
    struct pessoa *proximo;

};


void limpaTela(){
    system("CLS");
}

int retornaTamanho(pessoa *ponteiroEncadeada){

    if(ponteiroEncadeada->nome == ""){
        return 0;
    }

    int tamanho = 0;
    pessoa *p = ponteiroEncadeada;

    while (p != NULL){

        p = p->proximo;

        tamanho++;

    }
    return tamanho;
}

void imprimeEncadeada(pessoa *ponteiroEncadeada){

    pessoa *p = ponteiroEncadeada;

    while (p != NULL){

        cout << p->nome << "," << p->rg << "\n";

        p = p->proximo;
    }

}

void adcComecoEnc(pessoa *&ponteiroEncadeada, string nome, int rg){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;

    if (ponteiroEncadeada->nome == ""){
        novoValor->proximo = NULL;
    }else{
        novoValor->proximo = ponteiroEncadeada;
    }

    ponteiroEncadeada = novoValor;

}

void adcFimEnc(pessoa *&ponteiroEncadeada, string nome, int rg){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroEncadeada;

    while (p != NULL){

        if (p->proximo == NULL){
            p->proximo = novoValor;

            return;
        }

        p = p->proximo;

    }

}

void adcPosEnc(pessoa *&ponteiroEncadeada, string nome, int rg, int posicao){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroEncadeada;

    int cont = 0;

    while (cont <= posicao){

        if (cont == posicao - 1){

            pessoa *aux = new pessoa;
            aux->proximo = p->proximo;
            p->proximo = novoValor;
            novoValor->proximo = aux->proximo;

            free(aux);

        }

        p = p->proximo;
        cont++;
    }

}

void removeIniEnc(pessoa *&ponteiroEncadeada){

    if (ponteiroEncadeada->proximo == NULL){

        pessoa *novoValor = new pessoa;
        novoValor->nome = "";
        novoValor->rg = 0;
        novoValor->proximo = NULL;

        ponteiroEncadeada = novoValor;

    } else{
        ponteiroEncadeada = ponteiroEncadeada->proximo;
    }
}

void removeFimEnc(pessoa *&ponteiroEncadeada){

    pessoa *p = new pessoa;
    pessoa *aux = new pessoa;

    p = ponteiroEncadeada;

    while (p->proximo != NULL){

        aux = p;
        p = p->proximo;

    }

    aux->proximo = NULL;

}

void removePosEnc(pessoa *&ponteiroEncadeada, int posicao){

    pessoa *p = new pessoa;
    int cont = 0;

    while(cont <= posicao){

        if (cont == posicao - 1){

            pessoa *aux = new pessoa;

            aux = p->proximo;

            p->proximo = aux->proximo;

            free(aux);

        }

        p = p->proximo;
        cont++;

    }

}

string retornaNomeEnc(pessoa *&ponteiroEncadeada, int rg){

    string nome;

    pessoa *p = ponteiroEncadeada;

    while (p->proximo != NULL){

        if(p->rg == rg){
            nome = p->nome;
        }

        p = p->proximo;

    }

    return nome;

}

int main(){

    int funcaoDesejada = 0;

    pessoa *ponteiroEncadeada = new pessoa;
    ponteiroEncadeada->nome = "";
    ponteiroEncadeada->rg = 0;
    ponteiroEncadeada->proximo = NULL;

    pessoa *novoPrimVal = new pessoa;
    novoPrimVal->nome = "John";
    novoPrimVal->rg = 123;
    novoPrimVal->proximo = NULL;

    ponteiroEncadeada = novoPrimVal;

    pessoa *novoSegVal = new pessoa;
    novoSegVal->nome = "Jorge";
    novoSegVal->rg = 321;
    novoSegVal->proximo = NULL;

    novoPrimVal->proximo = novoSegVal;

    while (funcaoDesejada < 9 && funcaoDesejada > -1){
        cout << "\nTamanho atual: " << retornaTamanho(ponteiroEncadeada) << "\n\n";
        cout << " Operacoes: \n\n";
        cout << " 1 - Insercao de um node no inicio da lista \n";
        cout << " 2 - Insercao de um node no fim da lista\n";
        cout << " 3 - Insercao de um node na posicao N \n";
        cout << " 4 - Retirar um node do inicio da lista \n";
        cout << " 5 - Retirar um node no fim da lista \n";
        cout << " 6 - Retirar um node na posicao N \n";
        cout << " 7 - Procurar um node com o campo RG \n";
        cout << " 8 - Imprimir a lista. \n";
        cout << " 9 - Sair do sistema. \n";
        cout << " \nEscolha um numero e pressione ENTER: \n";

        if (retornaTamanho(ponteiroEncadeada) == 0){
            cout << "\n Lista Vazia!\n";
        }

        imprimeEncadeada(ponteiroEncadeada);

        cin >> funcaoDesejada;

        limpaTela();

        string nome;
        int rg;
        int posicao;

        switch(funcaoDesejada){

            case 1:
                cout << "Funcao escolhida: 1 - Insercao de um node no inicio da lista \n";

                cout << "Digite um nome: \n";
                cin >> nome;
                cout << "Digite um RG:\n";
                cin >> rg;

                adcComecoEnc(ponteiroEncadeada, nome, rg);

                break;
            case 2:
                cout << "Funcao escolhida: 2 - Insercao de um node no fim da lista\n";

                cout << "Digite um nome: \n";
                cin >> nome;
                cout << "Digite um RG:\n";
                cin >> rg;

                if (retornaTamanho(ponteiroEncadeada) == 0){
                    adcComecoEnc(ponteiroEncadeada, nome, rg);
                }else{
                    adcFimEnc(ponteiroEncadeada, nome, rg);
                }



                break;
            case 3:
                cout << "Funcao escolhida: 3 - Insercao de um node na posicao N \n";

                cout << "Digite um nome: \n";
                cin >> nome;
                cout << "Digite um RG:\n";
                cin >> rg;
                cout <<"Digite a posicao:\n";
                cin >> posicao;

                if (posicao == 0){
                    adcComecoEnc(ponteiroEncadeada, nome, rg);
                }else if(posicao == retornaTamanho(ponteiroEncadeada) - 1){
                    adcFimEnc(ponteiroEncadeada, nome, rg);
                }else{
                    adcPosEnc(ponteiroEncadeada, nome, rg, posicao);
                }

                break;
            case 4:
                cout << "Funcao escolhida: 4 - Retirar um node do inicio da lista \n";

                removeIniEnc(ponteiroEncadeada);

                break;
            case 5:
                cout << "Funcao escolhida: 5 - Retirar um node no fim da lista \n";

                if (retornaTamanho(ponteiroEncadeada) == 0){
                    removeIniEnc(ponteiroEncadeada);
                }else{
                    removeFimEnc(ponteiroEncadeada);
                }



                break;
            case 6:
                cout << "Funcao escolhida: 6 - Retirar um node na posicao N \n";

                cout <<"Digite a posicao:\n";
                cin >> posicao;

                if (posicao == 0){
                    removeIniEnc(ponteiroEncadeada);
                }else if(posicao == retornaTamanho(ponteiroEncadeada) - 1){
                    removeFimEnc(ponteiroEncadeada);
                }else{
                    removePosEnc(ponteiroEncadeada, posicao);
                }

                break;
            case 7:
                cout << "Funcao escolhida: 7 - Procurar um node com o campo RG \n";

                cout << "Digite o RG:\n";
                cin >> rg;

                cout << "o nome do rg " << rg << "e: " << retornaNomeEnc(ponteiroEncadeada, rg) << "\n";

                break;
            case 8:
                cout << "Funcao escolhida: 8 - Imprimir a lista. \n";
                imprimeEncadeada(ponteiroEncadeada);
                break;
            case 9:
                cout << "Funcao escolhida: 9 - Sair do sistema. \n";
                break;

        }

    }


    return 0;
}
