#include "xpaint.h"
#include "xmat.h"
#include <vector>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

struct Pos{
    int l, c;
    Pos(int _l, int _c){
        this->l = _l;
        this->c = _c;
    }
};
vector<Pos> get_neibs(int l, int c){
    return vector<Pos> {Pos(l, c - 1), Pos(l - 1, c), Pos(l, c + 1), Pos(l + 1, c)};
}
bool has_value(vector<string> &mat, int l, int c, char value){
    if(l < 0 || l >= (int) mat.size())
        return false;
    if(c < 0 || c >= (int) mat[0].size())
        return false;
    return mat[l][c] == value;
}
void pintar(vector<string> &mat,int l, int c, char cor_base, char cor_final){
    if(!has_value(mat, l, c, cor_base))
        return;
    mat[l][c] = cor_final;
    xmat_draw(mat);
    x_step("mat");
    for(auto viz : get_neibs(l, c)){
        pintar(mat, viz.l, viz.c, cor_base, cor_final);
    }
}
void mostrar(vector<vector<int>>& mat_int, vector<string>& mat, queue<Pos> fila){
    xmat_draw(mat);
    while(!fila.empty()){
        xmat_put_circle(fila.front().l, fila.front().c, WHITE);
        fila.pop();
    }
    for(int l = 0; l < (int) mat.size(); l++){
        for(int c = 0; c < (int) mat[0].size(); c++){
            xmat_put_number(l, c, BLACK, mat_int[l][c]);
        }
    }
    x_step("mat"); 
}
void floodfill(vector<vector<int>>& mat_int, vector<string>& mat, int l, int c, char cor_base, char cor_final, int lfinal, int cfinal){
    queue<Pos> fila;
    bool encontrou = false;
    int i = 1;
    fila.push(Pos(l, c));
    mat[l][c] = cor_final;
    while(!fila.empty()){
        Pos ref = fila.front();
        fila.pop();
        for(auto viz : get_neibs(ref.l, ref.c)){
            if(has_value(mat, viz.l, viz.c, cor_base)){
                mat[viz.l][viz.c] = cor_final;
		        mat_int[viz.l][viz.c] = i;
                fila.push(viz);
                mostrar(mat_int, mat, fila);
            }
        }
    }
}
void pathfind(vector<vector<int>> & mat_int, vector<string> & mat, int l, int c, char cor_base, char cor_final, int lfinal, int cfinal){
    queue<Pos> fila;
    queue<Pos> fila2;
    vector<string> mat_estoque = mat;
    bool encontrou = false;
    int aux = 0;
    fila.push(Pos(l,c));
    mat[l][c] = cor_final;

    while(!fila.empty()){
        Pos ref = fila.front();
        fila.pop();//pop: Remover proximo elemento
        aux = mat_int[ref.l][ref.c] + 1;
        for(auto viz : get_neibs(ref.l, ref.c)){
            if(has_value(mat, viz.l, viz.c, cor_base)){
                mat[viz.l][viz.c] = cor_final;
                mat_int[viz.l][viz.c] = aux;
                fila.push(viz);
                mostrar(mat_int, mat, fila);
            }
            if(has_value(mat, viz.l, viz.c, cor_final) && (viz.l == lfinal) && (viz.c == cfinal)){
                encontrou = true;
                break;
            }
        }
        if(encontrou)
            break;
    }
    if(encontrou){
        fila2.push(Pos(lfinal, cfinal));
        bool terminou = false;

        while(!terminou){
            Pos ref = fila2.back();//Acessar ultimo elemento
            int  aux = mat_int[ref.l][ref.c];
            for(auto viz : get_neibs(ref.l, ref.c)){
                if(has_value(mat, viz.l, viz.c, cor_final) && (mat_int[viz.l][viz.c] == 0)){
                    fila2.push(Pos(viz.l, viz.c));//Insere um novo elemento
                    terminou = true;
                    break;
                }
                if(has_value(mat, viz.l, viz.c, cor_final) && (mat_int[viz.l][viz.c]) == aux - 1){
                    fila2.push(Pos(viz.l, viz.c));//push: insere
                    break;
                }
            }
        }
        mat = mat_estoque;

        while(!fila2.empty()){
            Pos ref = fila2.front();//Retorna a referencia ao proximo elemento da fila
            mat[ref.l][ref.c] = cor_final;
            fila2.pop();
        }
    }
    if(!encontrou){
        mat = mat_estoque;
        printf("O caminho nao eh valido!");
    }

}
int main(){
    int nl = 20, nc = 20;
    xmat_init(nl, nc);
    vector<string> mat(nl, string(nc, 'g'));
    vector<vector<int>> mat_int(nl, vector<int>(nc, 0));
    for(int l = 0; l < (int) mat.size(); l++){
        for(int c = 0; c < (int) mat[0].size(); c++){
            if(xm_rand(0, 100) < 30)
                mat[l][c] = 'r'; 
        }
    }
    xmat_draw(mat);
    x_save("mat");
    int linicio = 0, cinicio = 0;
    int lfim = 0, cfim = 0;
    puts("Digite o ponto de inicio l e c: ");
    scanf("%d %d", &linicio, &cinicio);
    puts("Digite o ponto do fim l e c: ");
    scanf("%d %d", &lfim, &cfim);
    getchar();//remove \n after numbers

//    pintar(mat, l, c, mat[l][c], 'b');
    pathfind(mat_int, mat, linicio, cinicio, mat[linicio][cinicio], 'b', lfim, cfim);
    xmat_draw(mat);
    x_save("mat");
    x_close();
}