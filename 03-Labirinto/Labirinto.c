#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
	
typedef struct Pos{
	int l;
	int c;
}Pos;
#define pegar_vizinhos(l,c) {{l,c-1},{l-1,c},{l,c+1},{l+1,c}}//Pega tudo que escreveu e substitui
	
void embaralhar_vizinhos(Pos vet[], int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		int posic = rand() % tamanho;
		Pos aux = vet[i];
		vet[i] = vet[posic];
		vet[posic] = aux;
	}
}
//Compara se o elemento(l,c) da matriz tem o mesmo VALOR passado por parametro
bool Eh_igual_a(int nl, int nc, char matriz[nl][nc], int l, int c, char valor){
	if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))//Fora da matriz
		return false;
	return matriz[l][c] == valor;//Dentro da matriz
}
bool eh_Furavel(int nl, int nc, char matriz[nl][nc], int l, int c){
	
	int i;
	if(!Eh_igual_a(nl, nc, matriz, l, c, '#'))//Nao for parede
		return false;
	int cont = 0;
	Pos vizinhos[] = pegar_vizinhos(l, c);
	for(i = 0; i < 4; i++)// (4) -> Sao as 4 posicao do vetor de vizinhos 
		if(Eh_igual_a(nl, nc, matriz, vizinhos[i].l, vizinhos[i].c, '#'))
		cont ++;// Quantas paredes
	if(cont < 3)
		return false;
	return true;//(3) -> 3 ou +, posso furar
}
void furar_lab(int nl, int nc, char matriz[nl][nc], int l, int c){
	int i;
		
	if(!eh_Furavel(nl, nc, matriz, l,c))//nao furo
		return;
	matriz[l][c] = ' ';//Fura
	Pos vizinhos[] = pegar_vizinhos(l,c);
	embaralhar_vizinhos(vizinhos, 4);
	for(i = 0; i < 4; i++)
		furar_lab(nl, nc, matriz, vizinhos[i].l, vizinhos[i].c);//Fura vizinhos
}	 
void mostrar_matriz(int nl, int nc, char matriz[nl][nc]){
		int l;
		int c;
		
	    for(l = 0; l < nl; l++){
	        for(c = 0; c < nc; c++){
	            printf("%c", matriz[l][c]);
	        }
	       	    puts("");
	    }
}
bool matriz_visitados(int nl, int nc, char matriz[nl][nc], int l, int c){
	if(matriz[l][c] == '.')
		return true;
}
bool procurar_saida(int nl, int nc, char matriz[nl][nc], int l, int c, char matriz_visitados[l][c], int Lsaida, int Csaida){ // (Lsaida e Csaida)-> posicao que eu quero chargar
	int i;
	
	if(matriz[l][c] !=  ' ')
		return false;
	
	if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))//Fora da matriz
		return false;
	
	matriz[l][c] = '.';
	if(l == Lsaida && c == Csaida){//Se a coordenda eh igual a cordenada da saida entao chegamos no objetivo
		return true;               //podemos retornar TRUE.
	}
	//Iremos procurar o caminho atraves dos vizinhos.
	int vet[4][2] = {{l,c-1}, 0
					 {l-1,c}, 1
					 {l,c+1}, 2
					 {l+1,c}  3
					 }; //pegar_vizinhos(l,c);

	for(int i = 0; i < 4; i++){
		if(procurar_saida(nl, nc, matriz, vet[i][0], vet[i][1], matriz_visitados, Lsaida,Csaida))
			return true;
	}

	//Nao eh possivel chegar no objetivo entao retorna FALSE. Como nao existe caminho retira-se o PONTO.
	matriz[l][c] = ' ';
	return false;
}
//ARQC -> Diz quantas coisas foram dizitada
//ARGV -> Vetor de Strings
int main(int argc, char * argv[]){// pega o tamanho da matriz via ARGUMENTO
	srand(time(NULL));
	int i;
	int nl = 0;
	int nc = 0;
	
	printf("Digite o tamanho da matriz: ");
	scanf("%d %d", &nl, &nc);
	char matriz[nl][nc];
	char matriz_visitados[nl][nc];
	char * posic = &matriz[0][0];//O endereco comeca na primera posicao da matriz
	
	for(i = 0; i < nl * nc; i++)
		posic[i] = '#';
	
	furar_lab(nl, nc, matriz, 1 ,1);
	printf("%d %d\n", nl, nc);
	mostrar_matriz(nl, nc, matriz);
	int l_inicio = 0;
	int c_inicio = 0;
	printf("Digite o inicio das coordenadas do labirinto: ");
	scanf("%d %d",&l_inicio, &c_inicio);
	int l_fim = 0;
	int c_fim = 0;
	printf("Digite o fim das coordenadas do labirintos: ");
	scanf("%d %d", &l_fim, &c_fim);
	while(procurar_saida(nl, nc, matriz, l_inicio, c_inicio, matriz_visitados, l_fim, c_fim)){
		printf("Digite o fim das coordenadas do labirintos: ");
		scanf("%d %d", &l_fim, &c_fim);
	}
	procurar_saida(nl, nc, matriz, l_inicio, c_inicio, matriz_visitados, l_fim, c_fim);
	mostrar_matriz(nl, nc, matriz);
	
	return 0;
}
