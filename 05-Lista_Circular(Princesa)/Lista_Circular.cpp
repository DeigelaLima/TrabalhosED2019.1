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
void remover_Esquerda(No * no){
    remover(no->anterior);
}
void remover_Direita(No * no){
    remover(no->proximo);
}
void mostrar_lista(No * no, No * espada = nullptr){//mostra lista_ligada
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

void mostrar_ordenado(No * no){//NO pode ser qualquer posicao da lista
    //para ordenar eh so descobrir quem eh o menor
    No * menor = no;
    No * aux = no;
    do{//ando pela lista
        if(aux->valor < menor->valor)
            menor = aux;
        aux = aux->proximo;
    }while(aux != no);
    //depois q sai do loop imprimo o menor
    mostrar_lista(menor, no);

}
int main(int argc, char * argv[]){

    if(argc == 1){//so o nome do programa
      cout << "Passe o tamanho por argumento:\n ";
      exit(1);
    }
    No * lista = nullptr;
    mostrar_lista(lista);//lista vazia
    lista = new No(0);
    //mostrar_lista(lista);//mostra quem esta com a espada(proprio no)
    int tamanho = atoi(argv[1]);
    //std::cin >> tamanho;

    for(int i = 1; i < tamanho; i++)
        inserir_Direita(lista, i);//insere o valor de i a direta
    //mostrar_lista(lista);
    while(lista->proximo != lista){
        //std::cout << lista->proximo->valor << " ";//mostra quem morre
        remover_Direita(lista);
        lista = lista->proximo;
        mostrar_ordenado(lista);
    }
    mostrar_lista(lista);

}