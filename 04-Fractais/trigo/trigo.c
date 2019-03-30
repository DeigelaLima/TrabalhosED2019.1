#include "xpaint.h"

void trigo(int x, int y, int tamanho, int angulo){
    int aux = x;
    int auy = y;

    if(tamanho < 1){ 
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xf = x + tamanho * xm_cos(angulo);
        int yf = y - tamanho * xm_sin(angulo);
        xd_thick_line(x, y, xf, yf, 3);
        trigo(xf, yf, tamanho / 3, (angulo + 45));
        trigo(xf, yf, tamanho / 3, (angulo - 45));
        aux = x; //salva x
        auy = y; //salva y
        x_step("trigo");
    }
}
int main(){
    int largura = 800, altura = 800;
    x_open(largura, altura);// abre um bitmap com essas dimensoes
    //x_clear(BLACK);
    int x = largura / 2;
    int y = altura - 100;
    trigo(x, y, 110, 90);//tamanho,angulo
    x_save("trigo");
    x_close();
    return 0;
}