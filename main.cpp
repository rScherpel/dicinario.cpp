#include <bits/stdc++.h>
#include <locale.h>
#include "proto.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "portuguese");

    int input;
    string pt, en, texto;
    Hash* ha = criaHash(TABLE_SIZE);

    do{
        cout<< "Digite o numero da operação desejada"<<endl;
        cout<< "1. Inserir palavra"<<endl<<"2. Remover palavra"<<endl<<"3. Buscar palavra em PT"<<endl<<"4. Buscar palavra em EN"<<endl<<"5. Mostrar dicinário"<<endl<<"6. Traduzir frase"<<endl;
        cin >> input;

          switch(input) {
            case 1:{
                    system("clear");
                    string pt, en;

                    cout << "Digite a palavra em português: ";
                    cin >> pt;
                    
                    cout << "Digite a tradução em inglês: ";
                    cin >> en;

                    if (insereHash(ha, pt, en)) {
                        cout << "Palavra inserida com sucesso!" << endl;
                    } else {
                        cout << "Erro ao inserir a palavra." << endl;
                    }
                    system("clear");
                break;
                }
                case 2: {
                    system("clear");
                    cout << "Remover palavra (PT): ";
                    cin>>pt;
                    if (removeHash(ha, pt)) cout << "Removida!"<<endl;
                    else cout << "Não encontrada."<<endl;
                    break;
                }
                case 3: {
                    system("clear");
                    cout << "Buscar palavra em português: ";
                    cin>>pt;
                    dicio* r1 = buscaPorPt(ha, pt);
                    if (r1) cout << "Tradução: " << r1->ingles<<endl;
                    else cout << "Não encontrada."<<endl;
                    break;
                }

                case 4: {
                    system("clear");
                    cout << "Buscar palavra em inglês: ";
                    cin>>en;
                    dicio* r2 = buscaPorEn(ha, en);
                    if (r2) cout << "Tradução: " << r2->portugues <<endl;
                    else cout << "Não encontrada."<<endl;
                    break;
                }

                case 5:{
                    system("clear");
                    mostraDicionario(ha, 0);
                    break;
                }
                case 6: {
                    system("clear");
                    cout << "Digite o texto em português: "; getline(cin >> ws, texto);
                    traduzTexto(ha, texto);
                    break;
                }
                default:
                    system("clear");
                    cout << "Opção inválida!"<<endl;
            }

        } while (input != 7);

    liberaHash(ha);
    return 0;
}
