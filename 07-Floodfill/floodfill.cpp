# include  " xpaint.h "
# include  " xmat.h "
//#include <stdbool.h>
# include  < vector >
# include  < list >
# include  < iostream >
using  namespace  std ;

/*char *create_vet(vector<string> &mat){//matriz para vetor
    char * vet = new char[mat.tamanho() * mat[0].tamanho()];//criação do vetor dinamico
    //preencher vetor
    for(int l = 0; l < mat.tamanho(); l++){
        for(int c = 0; c < mat[0].tamanho(); c++){
            vet[l * mat[0].tamanho() * c] = mat[l][c];//montando vetor
        }
    }
    return vet;
}*/
struct  Pos {
    int l, c;
    Pos ( int _l, int _c) {
        this -> l = _l;
        this -> c = _c;
    }
};

vector <Pos> get_neibs ( int l, int c) {//as posições para todos os lados
    return vector <Pos> { Pos (l, c - 1 ), Pos (l - 1 , c), Pos (l, c + 1 ), Pos (l + 1 , c)};
}
 
bool  tem_valor(vector <string> &mat, int l, int c, valor char ) {//saber se tem um valor
    if (l < 0 || l >= ( int ) mat.tamanho())//se a posição existe
        return  false ;
    if (c < 0 || c >= ( int ) mat [ 0 ]. tamanho ())//mat[0] -> primeira posição da matriz
        rerurn false ;
    return mat [l] [c] == valor;//se os valores as iguais
}

void  pintar (vetor <string> &mat, int l, int c, char cor_base, char cor_final) {
    if (! tem_valor (mat, l, c, cor_base))//se não for a cor_base retorne
        return;
    mat [l][c] = cor_final;//pintar a matriz cor_final -> azul
    xmat_draw (mat);//desenha matriz
    x_step ( " mat " );
    for ( auto viz: get_neibs (l, c)) {//para cada um dos vizinho
        pintar (mat, viz.l , viz.c , cor_base, cor_final);
    }
}
void  mostrar_matriz (vector <vector < int >> & mat_int, vetor <string> & mat, fila <Pos> fila) {
    xmat_draw (mat);
    while (! fila. empty ()) {
        xmat_put_circle (fila. frente (). l , fila. frente (). c , BRANCO);
        fila. pop ();
    }
    for ( int l = 0 ; l < ( int ) mat. tamanho (); l ++) {
        for ( int c = 0 ; c < ( int ) mat [ 0 ]. tamanho (); c ++) {
            xmat_put_number (l, c, PRETO, mat_int [l] [c]);
        }
    }
    x_step ("mat");

}
void  floodfill (vector <vector < int >> & mat_int, vector <string> & mat, int l, int c, char cor_base, char cor_final) {
    Fila <Pos> fila;
    fila.push( Pos (l, c));
    mat [l] [c] = cor_final;
    while (! fila. empty ()) {
        Pos ref = fila.front();//frente
        fila.pop();
        for ( auto viz: get_neibs (ref.l , ref.c )) {
            if ( tem_valor (mat, viz. l , viz. c , cor_base)) {
                mat [viz.l] [viz.c] = cor_final;
                fila.push(viz);//empurre
                mostrar_matriz (mat_int, mat, fila);
            }
        }
    }
}
int  main () {
    int nl = 20 , nc = 20 ;
    xmat_init (nl, nc);
    vector <string> mat (nl, string (nc, ' g ' ));//criou a matriz
    //vector <vetor < int >> mat_int (nl, vetor < int > (nc, - 1 ));
    
    for ( int l = 0 ; l < (int) mat. tamanho (); l++) {
        for ( int c = 0 ; c < (int) mat [ 0 ]. tamanho (); c++) {
            if ( xm_rand ( 0 , 100 ) < 30 )
                mat [l][c] = ' r ' ;
        }
    }
    xmat_draw (mat);
    x_save ("mat");
    int l = 0 , c = 0 ;
    puts (" Digite o ponto de inicio l e c ");
    scanf ("%d %d " , &l, &c);
    getchar (); // remove \ n depois dos números

//     pintar (esteira, l, c, esteira [l] [c], 'b');
    floodfill(mat_int, mat, l, c, mat [l][c], ' b ' );// cor final da matriz azul
    xmat_draw (mat);//desenha matriz
    x_save ( " mat " );
    x_close ();
}