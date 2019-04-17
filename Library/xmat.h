#define H_ONLY // importante para não dar problema incluir na principal
#include "xpaint.h"


int XMAT_SIDE = 35;
int XMAT_DELTA = 1;
int XMAT_NL = 0;
int XMAT_NC = 0;
float XMAT_FONT_FACTOR = 1,0;

void xmat_init (int nl, int nc);
void xmat_put_square (int l, int c, cor XColor);
void xmat_put_circle (int l, int c, cor XColor);
void xmat_put_number (int l, int c, cor XColor, valor int);

#ifdef __cplusplus
#include <vector>
#include <iostream>
void xmat_draw (std :: vector <std :: string> & mat);
#outro
void xmat_draw (int nl, int nc, caractere de caractere [nl] [nc]);
#fim se

void xmat_init (int nl, int nc) {
    lado int = XMAT_SIDE;
    x_open (lado * (nc + 2), lado * (nl + 2));
    XMAT_NL = nl;
    XMAT_NC = nc;
    / *  
    float prop_image = xg_width () / (flutuante) xg_height ();
    float prop_mat = nc / (float) nl;
    if (prop_imagem <prop_mat)
        XMAT_SIDE = xg_width () / (float) (nc + 2);
    outro
        XMAT_SIDE = xg_height () / (float) (nl + 2); 
    * /
}

void xmat_put_square (int l, int c, cor XColor) {
    xs_color (cor);
    xd_filled_rect ((c + 1) * XMAT_SIDE + XMAT_DELTA, (l + 1) * XMAT_SIDE + XMAT_DELTA, 
                   (c + 2) * XMAT_SIDE - XMAT_DELTA, (l + 2) * XMAT_SIDE - XMAT_DELTA);
}

void xmat_put_circle (int l, int c, cor XColor) {
    xs_color (cor);
    xd_filled_circle ((c + 1) * XMAT_SIDE + XMAT_SIDE / 2, (l + 1) * XMAT_SIDE + XMAT_SIDE / 2, 
                   XMAT_SIDE / 2 - XMAT_DELTA);
}

void xmat_put_number (int l, int c, cor XColor, valor int) {
    float font_factor = XMAT_FONT_FACTOR;
    if (valor <0)
        font_factor * = 0,7;
    xs_color (cor);
    if (valor <10) {
        xs_font_size (XMAT_SIDE * 0.9 * font_factor);   
        x_write ((c + 1.3) * XMAT_SIDE, (l + 1.1) * XMAT_SIDE, "% d", valor);
    } else if (valor <100) {
        xs_font_size (XMAT_SIDE * 0.7 * font_factor);   
        x_write ((c + 1.2) * XMAT_SIDE, (l + 1.2) * XMAT_SIDE, "% d", valor);
    } else if (valor <1000) {
        xs_font_size (XMAT_SIDE * 0.5 * font_factor);   
        x_write ((c + 1.18) * XMAT_SIDE, (l + 1.3) * XMAT_SIDE, "% d", valor);
    } else if (valor <10000) {
        xs_font_size (XMAT_SIDE * 0,4 * font_factor);   
        x_write ((c + 1.13) * XMAT_SIDE, (l + 1.35) * XMAT_SIDE, "% d", valor);
    } else if (valor <100000) {
        xs_font_size (XMAT_SIDE * 0.35 * font_factor);   
        x_write ((c + 1.10) * XMAT_SIDE, (l + 1.35) * XMAT_SIDE, "% d", valor);
    }
}

#ifdef __cplusplus
#include <vector>
#include <iostream>
void xmat_draw (std :: vector <std :: string> & mat) {
    int nl = mat.size ();
    int nc = mat [0] .size ();
    para (int l = 0; l <nl; l ++) {
        para (int c = 0; c <nc; c ++) {
            xmat_put_square (l, c, xg_palette (mat [l] [c])); 
        }
    }
}
#outro
void xmat_draw (int nl, int nc, caractere de caractere [nl] [nc]) {
    para (int l = 0; l <nl; l ++) {
        para (int c = 0; c <nc; c ++) {
            xmat_put_square (l, c, xg_palette (mat [l] [c])); 
        }
    }
}
#endif / * cplusplus * /

