#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct Cliente{
    string id;
    int docs;
    int paciencia;

    Cliente(string id, int docs, int paciencia){
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
            //MOSTRA O VETOR DE CAIXAS
            for(int i = 0; i < this-> caixas.size(); i++){
                if(this-> caixas[i] != NULL){
                    cout << "[" << this-> caixas[i]-> id << ":" << this-> caixas[i]-> docs << ":" << this-> caixas[i]->paciencia << "]";
                }else{
                    cout << "[]";
                }
            }
            cout << endl;
            //MOSTRA FILA DE ENTRADA
            cout << "in :{";
            list<Cliente*>::iterator it;
            for(it = this->fila_entrada.begin(); it != this->fila_entrada.end(); it++){
                cout << (*it)->id << ":" <<(*it)->docs << ":" << (*it)-> paciencia << " ";
            }
            cout << "}" << endl;
    
            //MOSTRA FILA DE SAIDA
            cout << "out :{";
            while(!this->fila_saida.empty()){// empty = vazio -> nulo.
                cout << this->fila_saida.front()->id << ":" << this->fila_saida.front()->docs << ":" << this->fila_saida.front()->paciencia << " ";
                this->fila_saida.pop();
            }
            cout << "}" << endl;
    }

    void simulacao_banco(int &docs_processados, int &docs_perdidos){
        while(!this->fila_saida.empty()){
            this->fila_saida.pop();
        }
        for(int i = 0; i < this->caixas.size(); i++){
            if(this->caixas[i] != NULL){
                if(this->caixas[i]->docs > 0){
                    this->caixas[i]->docs--;
                    docs_processados++;
                }else{
                    this->fila_saida.push(this->caixas[i]);
                    this->caixas[i] = NULL;
                }
            }else{
                if(!this->fila_entrada.empty()){
                    this->caixas[i] = this->fila_entrada.front();
                    this->fila_entrada.pop_front();
                }
            }
        }
        
        //Diminuindo a paciência
        list<Cliente*>::iterator it;
        for(it = this->fila_entrada.begin(); it != this->fila_entrada.end(); ++it){
            if((*it)->paciencia > 0){
                (*it)->paciencia--;
            }
            //Docs perdidos
            if((*it)->paciencia == 0 || (*it)->docs == 0){
                this->fila_saida.push(*it);
                docs_perdidos = docs_perdidos + (*it)->docs;
                it = this->fila_entrada.erase(it);
                it--;
            }
        }
    }
    int aumento_lucro(int &docs_processados, int &quant_caixas){
        int quant_ideal_caixas = (docs_processados - (quant_caixas * 100));
        return quant_ideal_caixas;
    }
};

int main(){
    Banco banco;
    string opcao;
    string id;
    int docs = 0;
    int paciencia = 0;
    int quant_caixas = 0;
    int tempo = 0;
    int docs_processados = 0;
    int docs_perdidos = 0;

    while(true){
        getline(cin, opcao);
        stringstream in(opcao);
        in >> opcao;

        if(opcao == "init"){
            in >> quant_caixas;
            for(int i = 0; i < quant_caixas; i++){
                banco.caixas.push_back(NULL);
            }
        }else if(opcao == "show"){
            banco.mostrar_vector();
        }else if(opcao == "in"){
            in >> id >> docs >> paciencia;
            Cliente* elemento = new Cliente(id, docs, paciencia);
            banco.fila_entrada.push_back(elemento);
        }else if(opcao == "tic"){
            banco.simulacao_banco(docs_processados, docs_perdidos);
            tempo++;
        }else if(opcao == "finish"){
            cout << "Recebidos: " << docs_perdidos << endl;
            cout << "Perdidos: " << docs_perdidos << endl;
            cout << "Tempo: " << tempo << endl;
                break;
            }else{
                cout << "opcao invalida." << endl;
            }
        }
        int Lucro = banco.aumento_lucro(docs_perdidos, quant_caixas);
        cout << "Numero de caixas ideal: " << Lucro << " " << " caixas." << endl;
}

