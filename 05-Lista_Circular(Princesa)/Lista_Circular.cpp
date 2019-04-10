#include <iostream>

//obs.: o NO representa a lista
//sem cabeca e sem rapo. 
//lista circular eh so o NO
struct No{
    int valor;
    No * anterior;
    No * proximo;
    No(int valor = 0){//o anterior e o proximo do NO eh ele mesmo
        this->valor = valor;
        this->anterior = this;//o anterior eh ele mesmo
        this->priximo = this; //proximo eh ele mesmo
    }
};
// x  ref N  y
void inserir_Direita(No * ref, int value){
        No * no = new No(valor);//criando o NO
        no->proximo = ref->proximo;//criou um NO depois do NO de referencia
        no->anterior = ref;//o NO de referencia anterior eh a propria referencia
        ref->proximo = no;
        no->proximo->anterior = no;
}
//X
//A  X B C
void inserir_Esquerda(No * ref, int value){
       inserir_Direita(ref->anterior, valor);//Eh a mesma coisa de inserir no lugar de ref
}
void remover(No * no){
    no->proximo-> = no->anterior;
    no->anterior-> = no->proximo;
}
void remover_Esquerda(No * no){
    remover(no->anterior);
}
void remover_Direita(No * no){
    remover(no->proximo);
}
void mostrar_lista(No * no){//mostra lista_ligada
        std::cout << "[ ";
        if(no != nullptr){//entra na condicao e imprime
            No * aux = no;//guarda um ponto do NO
            do{
                std::cout << aux->valor << " ";
                aux = aux->proximo;//vou para o proximo NO
            }while(aux != no);
        }
        std::cout << "]\n";
}
int main(){

    No * lista = nullptr;
    Mostrar_lista(lista);//lista vazia
    lista = new No(5);
    Mostrar_lista(lista);


}