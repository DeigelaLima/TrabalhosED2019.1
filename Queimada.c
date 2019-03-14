#include <stdio.h>

int const TREE = '#';//Arvore3
int const FIRE = 'o';//Fogo
int const EMPTY = '.';//Vazio

void mostrar_matriz(int nl, int nc, char mat[nl][nc]){
	int l = 0;
	int c = 0;
    for(l = 0; l < nl; l++){
      for(c = 0; c < nc; c++)
        	printf("%c", mat[l][c]);
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
    pegarFogo = pegarFogo + tocar_fogo(nl, nc, mat, l, c + 1);
    pegarFogo = pegarFogo + tocar_fogo(nl, nc, mat, l, c - 1);
    pegarFogo = pegarFogo + tocar_fogo(nl, nc, mat, l - 1, c);
    pegarFogo = pegarFogo + tocar_fogo(nl, nc, mat, l + 1, c);
    mostrar_matriz(nl, nc, mat);
	return pegarFogo;
}
int main(){
    int nl = 0;
    int nc = 0;
    int l = 0;
    int c = 0;
    int incendio = 0;
    
    
    scanf("%d %d %d %d", &nl, &nc, &l, &c);
    char mat[nl][nc];
    
    for(l = 0; l < nl; l++){
    	for(c = 0; c < nc; c++){
          scanf(" %c", &mat[l][c]);
        }
	}
    incendio = tocar_fogo(nl, nc, mat, l, c);
    mostrar_matriz(nl, nc, mat);
    printf("Total de arvores queimadas:%d\n", incendio);
    return 0;
}
