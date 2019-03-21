#include "xpaint.h"
#include <stdio.h>
#include <stdlib.h>

void tree(int x, int y, float ang, int tamanho){
    if(tamanho < 10)
        return;
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
    xd_thick_line(x, y, xf, yf, 4);
    x_step("Arvore");

    tree(xf, yf, ang - 26, tamanho - xm_rand(5, 10));
    tree(xf, yf, ang + 26, tamanho - xm_rand(5, 10));   
}

int main(){
    int largura = 600, altura = 600;
    x_open(largura, altura); 
    x_clear(BLACK);
    float ang = 90;
    int x = largura / 2;
    int y = altura - 10;
    float tamanho = 90;
    tree(x, y, ang, tamanho);
    x_save("Arvore");
    x_close();
    return 0;
}