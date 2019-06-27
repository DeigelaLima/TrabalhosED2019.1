#include <iostream>
using namespace std;

//obs.: o NO representa a lista
//sem cabeca e sem rapo. 
//lista circular eh so o NO
struct No{
    int valor;
    No * anterior;
    No * proximo;
    No(int valor){//o anterior e o proximo do NO eh ele mesmo
        this->valor = valor;
        this->anterior = this;//o anterior eh ele mesmo
        this->proximo = this; //proximo eh ele mesmo

    }
};
// x  ref N  y
void inserir_Direita(No * ref, int valor){
        No * no = new No(valor);//criando o NO
        no->proximo = ref->proximo;//criou um NO depois do NO de referencia
        no->anterior = ref;//o NO de referencia anterior eh a propria referencia
        ref->proximo = no;
        no->proximo->anterior = no;
}
//X
//A  X B C
void inserir_Esquerda(No * ref, int valor){
       inserir_Direita(ref->anterior, valor);//Eh a mesma coisa de inserir no lugar de ref
}
void remover(No * no){
    no->proximo->anterior = no->anterior;
    no->anterior->proximo = no->proximo;
}
void remover_Direita(No * no){
    remover(no->proximo);
}
void remover_Esquerda(No * no){
    remover(no->anterior);
}


void mostrar_lista(No * no, No * espada){//mostra lista_ligada
        cout << "[";
        if(no != nullptr){//entra na condicao e imprime
            No * aux = no;//guarda um ponto do NO
            do{
                cout << " " << aux->valor;
                if((espada != nullptr) && (aux == espada)){
                    cout << ">";
                }
                aux = aux->proximo;//vou para o proximo NO
            }while(aux != no);
        }
        cout << " ]\n";
}

void mostrar_ordenado(No * no, No * escolhido){//NO pode ser qualquer posicao da lista
    //para ordenar eh so descobrir quem eh o menor
    No * menor = no;
    No * aux = no;
    do{//ando pela lista
        if((aux->valor) < (menor->valor)){
            menor = aux;
            aux = aux->proximo;
    }while(aux != no);
    //depois q sai do loop imprimo o menor
    mostrar_lista(menor, escolhido);

}
int main(){

    No * lista = new No(1);
    int participantes = 0;
    int escolhido = 0;

    cout << "Digite a quantidade de participantes e o escolhido:\n " <<endl;
    cin >> participantes >> escolhido;

    for(int i = 1; i < participantes; i++)
        inserir_Esquerda(lista, i + 1);//insere o valor de i a esquerda
    No * no_temporario = lista;
    while(no_temporario->proximo->valor != escolhido + 1)
        no_temporario = no_temporario->proximo;
        mostrar_lista(lista, no_temporario);
    while(no_temporario->proximo != no_temporario){
        remover_Direita(no_temporario);
        no_temporario = no_temporario->proximo;
        mostrar_ordenado(no_temporario, no_temporario);
    }
}