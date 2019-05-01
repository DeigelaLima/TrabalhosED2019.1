#include <stdio.h>

int const TREE = '#';//arvore
int const FIRE = 'o';//fogo
int const EMPTY = '.';//vazio
//int const CAMINHO = 'x';

void mostrar_matriz(int nl, int nc, char mat[nl][nc]){
    for(int i = 0; i < nl; i++){
      for(int j = 0; j < nc; j++)
        	printf("%c", mat[i][j]);
      puts("");
    }
}
int tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc)) 
			return 0;
    if(mat[l][c] != TREE) 
			return 0;
        
    mat[l][c] = FIRE;
    mostrar_matriz(nl, nc, mat);
    getchar();
    
    int pegarFogo = 1;
    pegarFogo += tocar_fogo(nl, nc, mat, l, c + 1);
    pegarFogo += tocar_fogo(nl, nc, mat, l, c - 1);
    pegarFogo += tocar_fogo(nl, nc, mat, l - 1, c);
    pegarFogo += tocar_fogo(nl, nc, mat, l + 1, c);

    //mat[l][c] = CAMINHO;
    mostrar_matriz(nl, nc, mat);
    getchar();
	  return pegarFogo;
}
int main(){
    int nl = 0;
    int nc = 0;
    int l = 0;
    int c = 0;
    int incendio = 0;
    
    printf("Digite o numero de Linha e Coluna: ");
    scanf("%d %d", &nl, &nc);
    
    printf("Digite a posicao da Linha e da Coluna para queimar a arvore: ");
    scanf("%d %d", &l, &c);
    char mat[nl][nc];
    
    
    for(int i = 0; i < nl; i++){
    	for(int j = 0; j < nc; j++){
          scanf(" %c", &mat[i][j]);
        }
	}
    incendio = tocar_fogo(nl, nc, mat, l, c);
    mostrar_matriz(nl, nc, mat);
    printf("Total de arvores queimadas:%d\n", incendio);
    return 0;
}
