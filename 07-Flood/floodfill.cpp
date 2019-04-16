# include  " xpaint.h "
# include  " xmat.h "
# include  < vector >
# include  < list >
# include  < queue >
# include  < iostream >
usando  namespace  std ;

struct  Pos {
    int l, c;
    Pos ( int _l, int _c) {
        isso -> l = _l;
        isso -> c = _c;
    }
};

vetor <Pos> get_neibs ( int l, int c) {
    vetor de retorno <Pos> { Pos (l, c - 1 ), Pos (l - 1 , c), Pos (l, c + 1 ), Pos (l + 1 , c)};
}
 
bool  has_value (vetor <string> & mat, int l, int c, valor char ) {
    if (l < 0 || l> = ( int ) tamanho da esteira ())
        retorno  falso ;
    if (c < 0 || c> = ( int ) mat [ 0 ]. tamanho ())
        retorno  falso ;
    return mat [l] [c] == valor;
}

void  pintar (vetor <string> & mat, int l, int c, caractere cor_base, char cor_final) {
    if (! has_value (mat, l, c, cor_base))
        retorno ;
    mat [l] [c] = cor_final;
    xmat_draw (mat);
    x_step ( " mat " );
    for ( auto viz: get_neibs (l, c)) {
        pintar (tapete, viz, l , viz , c , cor_base, corfinal);
    }
}


void  mostrar (vetor <vetor < int >> & mat_int, vetor <string> & mat, fila <Pos> fila) {
    xmat_draw (mat);
    while (! fila. empty ()) {
        xmat_put_circle (fila. frente (). l , fila. frente (). c , BRANCO);
        fila. pop ();
    }
    para ( int l = 0 ; l <( int ) mat. tamanho (); l ++) {
        para ( int c = 0 ; c <( int ) mat [ 0 ]. tamanho (); c ++) {
            xmat_put_number (l, c, PRETO, mat_int [l] [c]);
        }
    }
    x_step ( " mat " );

}

void  floodfill (vetor <vetor < int >> & mat_int, vetor <string> & mat, int l, int c, caractere cor_base, char cor_final) {
    Fila <Pos> fila;
    fila. push ( Pos (l, c));
    mat [l] [c] = cor_final;
    while (! fila. empty ()) {
        Pos ref = fila. frente ();
        fila. pop ();
        for ( auto viz: get_neibs (ref. l , ref. c )) {
            if ( has_value (mat, viz. l , viz. c , cor_base)) {
                mat [viz. l ] [viz. c ] = cor_final;
                fila. empurre (viz);
                mostrar (mat_int, mat, fila);
            }
        }
    }
}


int  main () {
    int nl = 20 , nc = 20 ;
    xmat_init (nl, nc);
    vetor <string> mat (nl, string (nc, ' g ' ));
    vetor <vetor < int >> mat_int (nl, vetor < int > (nc, - 1 ));
    para ( int l = 0 ; l <( int ) mat. tamanho (); l ++) {
        para ( int c = 0 ; c <( int ) mat [ 0 ]. tamanho (); c ++) {
            if ( xm_rand ( 0 , 100 ) < 30 )
                mat [l] [c] = ' r ' ;
        }
    }
    xmat_draw (mat);
    x_save ( " mat " );
    int l = 0 , c = 0 ;
    puts ( " Digite o ponto de inicio lec " );
    scanf ( " % d% d " , & l, & c);
    getchar (); // remove \ n depois dos números

//     pintar (esteira, l, c, esteira [l] [c], 'b');
    inundação (mat_int, mat, l, c, mat [l] [c], ' b ' );
    xmat_draw (mat);
    x_save ( " mat " );
    x_close ();
}