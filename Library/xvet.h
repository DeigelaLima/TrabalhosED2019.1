#define H_ONLY
#include "xpaint.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

flutuante estático bar_width = 20; // largura da barra
yfactor de flutuação estática = 1; // fator multiplicativo da altura da barra
static int begin_partition = 0;
static int end_partition = 0;
estático int pivot_value = 0;


void xd_vet (int * vet, tamanho int, char * cores, ...);
void _xd_vet_and_save (int * vet, int qtd, int * indices, const char * cores);
void _xd_vet_all (int * vet, int tamanho, int * indices, const char * cores);
void _xd_vet_i (int * vet, tamanho int, int i);
void _xd_vet_all (int * vet, int tamanho, int * indices, const char * cores);

void xs_partition (int inicio, int fim) {
    begin_partition = begin;
    end_partition = end;
}

void xs_pivot (int valor) {
    pivot_value = value;
}

void calc_bar_width (int vet_size) {
    bar_width = xg_width () / (vet_size + 2);
}

void calc_yfactor (int * vet, tamanho int) {
    int max = 0;
    para (int i = 0; i <tamanho; i ++)
        if (vet [i]> max)
            max = vet [i];
    yfactor = (xg_height () - 4,0 * bar_width);
    yfactor = yfactor <0? -fator: yfactor;
    yfactor / = max;
    if (yfactor <0,2)
        yfactor = 0,2;
    // printf ("yf% f", yfactor);
}

// processa cores e parametros
void xd_vet (int * vet, int tamanho, char * cores, ...) {
    calc_bar_width (tamanho);
    calc_yfactor (vet, tamanho);
    
    int qtd_ind = 0;
    if (cores! = NULL)
        qtd_ind = strlen (cores);
    if (qtd_ind == 0)
        _xd_vet_and_save (vet, tamanho, NULL, NULL);
    outro{
        int vet_ind = malloc (qtd_ind * sizeof (int)); / * crie um vetor de inteiros na heap * /
        va_list va; / * inicia uma variável que vai guardar os parametro de ... * /
        va_start (va, cores); / * define uma variável que precede ... * /
        int i = 0;
        para (; i <qtd_ind; i ++)
            vet_ind [i] = va_arg (va, int); / * vai puxando inteiros dos parametros de ... * /
        va_end (va); / * finaliza uma lista variadica * /
        _xd_vet_and_save (vet, size, vet_ind, colors);
        livre (vet_ind); / * libera memoria * /
    }
}

void _xd_partition () {
/ * if (begin_partition + 1> = end_partition)
        Retorna; * /
    xs_color (AMARELO);
    xd_filled_rect (bar_width * (1 + begin_partition), xg_height () - (largura_barra * 3/4), 
                   bar_width * (2 + end_partition), xg_height () - (bar_width * 1/4));
}

void _xd_pivot (int size) {
/ * if (begin_partition + 1> = end_partition)
        Retorna; * /
    xs_color (RED);
    xd_line (bar_width, xg_height () - bar_width - pivot_value * yfactor, 
            (1 + tamanho) * bar_width, xg_height () - bar_width - pivot_value * yfactor);
}

// limpa, pinta, salva
void _xd_vet_and_save (int * vet, int tamanho, int * indices, const char * cores) {
    static int atual = 0;
    x_clear (PRETO);
    _xd_vet_all (vet, tamanho, índices, cores);
    _xd_partition ();
    _xd_pivot (tamanho);
// printf ("% d \ n", atual);
    x_write (0, 0, "% d", atual ++);
    x_step ("sort");
}

void _xd_vet_i (int * vet, tamanho int, int i) {
    if ((i <0) || (i> = tamanho))
        Retorna;
    int x = bar_width * (i + 1);
    int ybase = xg_height () - bar_width;
    int j;
    para (j = 0; j <((int) bar_width - 2); j ++)
        xd_line (x + j, ybase, x + j, ybase -fator * vet [i]);
}

void _xd_vet_all (int * vet, int tamanho, int * indices, const char * cores) {
    int i = 0;
    xs_color (branco);
    para (i = 0; i <tamanho; i ++)
        _xd_vet_i (vet, tamanho, i);

    if (cores == NULL)
        Retorna;
    int qtd_indices = strlen (cores);
    int j = 0;
    para (j = 0; j <qtd_indices; j ++) {
        i = índices [j];
        xs_color (xg_palette (cores [j]));
        _xd_vet_i (vet, tamanho, i);
    }
}