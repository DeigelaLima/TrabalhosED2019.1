#include "xpaint.h"
#include <stdio.h>

void circulos(int x, int y, int tamRaio){

    xs_color((XColor){155,20,20});
    if(tamRaio < 1){
        return;
    }
    int angulo = 0;
    for (int i = 0; i < 6; i++) {
        xd_circle(x, y, tamRaio);
        int xf = x + tamRaio * xm_cos(angulo);
        int yf = y - tamRaio * xm_sin(angulo);
        
        xd_circle(xf, yf, tamRaio / 3);
        circulos(xf, yf, tamRaio / 3);
        angulo = angulo + 60;
        x_step("circulos"); //salva o arquivo, mas permite ao usuario controlar
    }
}
int main(){
    //int tamRaio;
    int largura = 800, altura = 800;
    int x = largura / 2;
    int y = altura / 2;
    printf("Vamos desenhar\n");
    x_open(largura, altura);
    x_clear(BLACK); //Cor de plano de fundo
    //printf("Ta limpo");
    circulos(x, y, 250);
    x_save("circulos");//salva um png no arquivo, nao inclui a extensao .png no nome do arquivo
    x_close();//finaliza o bitmap liberando os recursos
    return 0;
}