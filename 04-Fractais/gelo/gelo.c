#include "xpaint.h"

void gelo(int x, int y, int tamanho){

    xs_color((XColor){155,80,80});
    if(tamanho < 1){
        return;
    }
    int angulo = 270; //angulo inicial
    for (int i = 0; i < 5; i++) {
        int xf = x + tamanho * xm_cos(angulo);
        int yf = y - tamanho * xm_sin(angulo);
        xd_thick_line(x, y, xf, yf, 3); //desenha uma linha com espessura de pixels entre os pontos (x0, y0) e (x1, y1) 
        gelo(xf, yf, tamanho / 3);
        angulo += 70; //soma no proximo angulo 70
        x_step("gelo");
    }
}
int main(){

    int largura = 800, altura = 800;
    //x_clear(BLACK);
    int x = largura / 2;
    int y = altura / 2;
    x_open(largura, altura);
    gelo(x, y, 200); //tamanho
    x_save("gelo");
    x_close();
    return 0;
}