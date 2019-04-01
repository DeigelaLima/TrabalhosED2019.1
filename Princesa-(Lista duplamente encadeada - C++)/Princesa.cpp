#include <iostream>
#include <sstream>
using namespace std;

//LISTA DUPLA -> Cada no da lista sabe quem eh o seu PROXIMO e o s eu ANTERIOR.
struct Node{// Nó da lista (Guarda um elemento)
    int value;
    Node * next;//Ponteiro para proximo elemento
    Node * prev;//Pontero para o elemento anterior
    Node(int value = 0, Node * next = nullptr, Node * prev = nullptr){// Construtor(se o usuario não digitar os parametros os valores sera -> 0 e null)
        this->value = value;
        this->next = next; //Se o usuario digitar os valores serao atribuidos a VALUE, NEXT E PREV.
        this->prev = prev;
    }
};
//Lista com cabeca e rabo (nao tem caso especiais)
struct Lista{ 
    Node * head;//cabeca        //Noo de marcacao, noo que exite e estao alocados (comeco da lista(C) e fim da lista(R))
    Node * tail;// rabo         //Os Noos nao serve para ter VALOR, serve APENAS para saber onde COMECA e onde TERMINA
    //Node * ref;

    Lista(){
        head = new Node();//Criando um noo
        tail = new Node();
        head->next = tail;//Juntando o meu novo noo com a CABECA e com o RABO 
        tail->prev = head;
    }

    void show(){
        cout << "[ ";
        Node * node = head->next;// Primeiro Noo comeca com CABECA + PROXIMO
        while(node != tail){//Ando em Noo em Noo quando nao chego no RABO
            cout << node->value << " ";//Imprimo todo mundo
            node = node->next;//Vou para o proximo noo
        }
        cout << "]\n";
    }
    //Insere no ultimo elemento
    void push_back(int value){//Insere um VALOR no final da lista
        insert(tail, value);//Coloco alguem antes do RABO
    }

    void pop_back(){
        if(head->next == tail)
            return;
        remove(tail->prev);
    }
    
    void pop_front(){
        if(head->next == tail)
            return;
        remove(head->next);
    }
    //Insere no primeiro elemento
    void push_front(int value){
        insert(head->next, value);
    }

    void insert(Node * ref, int value){
        Node * node = new Node(value, ref, ref->prev);
        ref->prev = node;
        node->prev->next = node;
    }

    void remove(Node * ref){//REF = TAIL
        ref->prev->next = ref->next;
        ref->next->prev = ref->prev;
        delete ref;
    }
};

int main(){
    Lista lista;
    //Faz isso pra sempre
    while(true){
        string line;// leio uma linha
        getline(cin, line);//Pego CIN e transformo em LINE
        stringstream ui(line);//Transforma em um fluxo
        string cmd;//COMANDO -> palavra que vai ser digitada
        ui >> cmd;//Leu um COMANDO
        if(cmd == "end"){
            break;
        }else if(cmd == "show"){
            lista.show();//Mostrar lista
        }else if(cmd == "pb"){
            int value;
            while(ui >> value){//Enquanto nao conseguir ler VALOR
                lista.push_back(value);
            }
        }else if(cmd == "pf"){
            int value;
            while(ui >> value){
                lista.push_front(value);
            }
        }else if(cmd == "popf"){
            lista.pop_front();
        }else if(cmd == "popb"){
            lista.pop_back();
        }else{
            cout << "fail: comando invalido\n";
        }
    }

}
