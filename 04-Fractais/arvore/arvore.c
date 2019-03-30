#include "xpaint.h"
#include <stdio.h>
#include <stdlib.h>

void arvore(int x, int y, float ang, int tamanho){
    
   
     xs_color((XColor){120,50,20});//cor do tronco
    if(tamanho < 80)
        xs_color(GREEN);//cor do galho do meio
    if(tamanho < 25)
        xs_color(RED);//cor das pontas
    if(tamanho < 10)//codicao de parada do galho
        return;
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);

    xd_thick_line(x, y, xf, yf, 5);//espessura do galho
    x_step("arvore");
    int temp = xm_rand(5, 15);

    arvore(xf, yf, ang - 27, tamanho - temp);//angulo e tamanho para esquerda
    arvore(xf, yf, ang + 27, tamanho - temp);//angulo e tamanho para a direita   
}

int main(){
    int largura = 800, altura = 800;
    x_open(largura, altura); 
    x_clear(BLACK);
    float ang = 90;//angulo da arvore para cima
    int x = largura / 2;// posicao da arvore no eixo X
    int y = altura - 10;//posicao da arvore no eixo Y
    float tamanho = 100;//tamanho do galho
    arvore(x, y, ang, tamanho);
    x_save("arvore");
    x_close();
    return 0;
}