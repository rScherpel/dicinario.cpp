#include <bits/stdc++.h>
#include <locale.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "portuguese");

    int input;
    cout<< "Digite o numero da aperação desejada"<<endl;
    cout<< "1. Inserir palavra"<<endl<<"2. Remover palavra"<<endl<<"3. Buscar palavra"<<endl<<"4. Mostrar dicinário"<<endl<<"5. Traduzir frase"<<endl;
    cin >> input;
    switch(input) {
        case 1:
            system("clear");
            cout<< "inserir"<<endl;
            /*
            1- Inserir palavra (lista vazia, 1 elemento, 3 elemento)
            2- Ordernar? (ordernar toda vez tem muito custo, porem a busca fica mais facil)
            3- uma lista pra cada letra do alfabeto?
            */
            break;

        case 2:
            system("clear");
            /*
            1- buscar palavra
            2- liberar no
            3- realocar
            */
            break;

        case 3:
            system("clear");
            int op;
            cout<< "A palavra que você deseja buscar é em:"<<endl<<"1. PORTUGUÊS;"<<endl<< "2. INGLÊS;"<<endl;
            cin>>op;
            if (op == 1){
                //logica de busca
            };
            if (op == 2){
                //logica de busca
            };
            if (op < 1 || op > 2){
                system("clear");
                cout<<"Valor inválido!"<<endl;
            };
            break;

        case 4:
            system("clear");
            cout<< "mostrar"<<endl;
            /*
            1- Mostrar tudo??
            2- mostrar so 10? e depois o resto?
            */
            break;

        case 5:
            system("clear");
            cout<< "traduzir"<<endl;
            /*
            TODO: PENSAR NISSO DEPOIS
            */
            break;

        default:
            cout<< "Insira um valor valido"<<endl;
    }
    return 0;
}
