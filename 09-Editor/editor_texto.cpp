#include <iostream>
#include <list>
#include <sstream>

using namespace std;

struct Ambiente{
    list<char> texto;//lista que vai mostrar
    list<char>::iterator cursor;//o vai mostrar qd mandar imprimir uma letra. 

    Ambiente(){
        this->cursor = texto.begin();
    }

    void mostra_cursor(){
        for(list<char>::iterator it = this->texto.begin(); it != this->texto.end(); ++it){
            if(it == this->cursor)
                cout << '|';
            cout << (*it);
        }
        if(this->cursor == this->texto.end())
            cout << '|';
        cout << endl;
    }
    void enter(char letra){
        this->texto.insert(cursor, letra);
        this->cursor = this->cursor++;
    }
    void apaga_caractere(){//apaga o caractere a ESQUERDA do cursor
        if(this->cursor != this->texto.begin()){
            this->cursor--;
            this->cursor = this->texto.erase(this->cursor);//ERASE: elimina elemento referenciado por iterador it
        }
    }
    void deletar_caractere(){//apaga o caractere a DIREITA do cursor
        if(this->cursor != this->texto.end()){
            this->cursor = this->texto.erase(this->cursor);
        }
    }
    void move_direita(){
        if(this->cursor != this->texto.end())
            this->cursor++;
    }
    void move_esquerda(){
        if(this->cursor != this->texto.begin())
            this->cursor--;
    }

};
int main(){
    Ambiente * editor = new Ambiente();
    string opcao;
    char letra;

    while(true){
        getline(cin, opcao);//cin: informações digitadas pela teclado; 
        stringstream in(opcao);//opcao: string que será utilizada para armazenar os dados extraídos pelo método cin.
        while(in >> letra){//in = em
            if(letra == 'E'){//R: enter
                editor->enter('\n');
            }else if(letra == 'B'){//apagar
                editor->apaga_caractere();
            }else if(letra == 'D'){
                editor->deletar_caractere();
            }else if(letra == '>'){
                editor->move_direita();
            }else if(letra == '<'){
                editor->move_esquerda();
            }else{
                editor->enter(letra);
            }

        }
        editor->mostra_cursor();
    }
}
