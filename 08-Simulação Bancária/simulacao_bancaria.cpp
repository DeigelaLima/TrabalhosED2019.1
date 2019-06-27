#include <list>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Cliente{
    string id;
    int docs;
    int paciencia;

    Cliente(String id, int docs, int paciencia){
        this-> id = id;
        this-> docs = docs;
        this-> paciencia = paciencia;
    };

};
struct Banco{
    vector<Cliente*>caixas; // Eh um vector de ponteiro para cliente com nome caixas      (int vetor[10]) 
    list<Cliente*>fila_entrada;
    queue<Cliente*>fila_saida;

    void mostrar_vector(){
        for(int i = 0; i < this-> caixas.size(); i++){
            if(this-> caixas != nullptr){
                cout << "[" << this-> caixas-> id << ":" << this-> caixas-> docs ":" << this-> caixas->paciencia << "]";
            }else{
                cout << " []" << endl;
            }
        }
    }
    void mostrar_list(){
        list<Cliente*>::iterator it;
        cout << "in: {";
        for(it = this->fila_entrada.begin(); it != this->fila_entrada.end(); it++){
            cout << (*it)->id << ":" <<(*it)->docs << ":" << (*it)-> paciencia;
        }
        cout << "}" << endl;
            
    }
    void mostrar_queue(){
        cout << "out: {";
        while(!this->fila_saida.empty()){// empty = vazio -> nulo.
            cout << this->fila_saida.front()->id << ":" << this->fila_saida.front()->docs << ":" << this->fila_saida.front()->paciencia;
            this->fila_saida.pop();
        }
        cout << "}" << endl;
    }
    void mostrar_fucs(){
        mostrar_vector();
        mostrar_list();
        mostrar_queue();
    }

    void iniciar_caixas(int quant_caixas){
     
    void entrar_cliente(String id, int docs, int paciencia){
        Cliente *cliente1 = new Cliente(); // com construtor passava por parametro.
       

        fila_entrada.push_back(cliente1);//add cliente
    }
    void mostrar_caixas(){
        for(i = 0; i < quant; i++){
            if(caixas[i] == nullptr){
                


            }
        }


    }
  
    void passar_tempo(){

        /*para todos os clientes na fila de saida
            remova cliente do Banco
        para todos os caixas
            se existe um Cliente
                se o cliente tem documentos
                    processe um documento desse Cliente
                senao
                    mova cliente para a fila de saida
            senao 
                se hover clientes na fila de entrada
                    pegue um cliente da fila de entrada
        para todos os clientes da fila de entrada
            se paciencia maior que zero
                decremente um na paciencia
            senao 
                ponha na fila*/
    }
};


int main(){

}
