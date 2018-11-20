///TESTE SUDOKU - jiko10
///REMOVER O CASO TESTE E AJUSTAR DETALHES
#include<stdio.h>
#include<locale.h>
#define N 9
void preenchezero(int tabuleiro[][N]){
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            tabuleiro[i][j] = 0;
}
void le_casas(int tabuleiro[][N]){
    printf("Preencha casas vazias com 0(zero):\n");
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("Preenchendo linha %d, coluna %d: ",i+1,j+1);
            scanf("%d",&tabuleiro[i][j]);
        }
    }
}
void teste(int tabuleiro[][N]){
   tabuleiro[0][0]=2;
   tabuleiro[0][6]=9;
   tabuleiro[1][2]=5;
   tabuleiro[2][2]=4;
   tabuleiro[3][8]=1;
   tabuleiro[4][7]=8;
   tabuleiro[6][8]=6;
   tabuleiro[6][1]=2;
   tabuleiro[5][3]=7;
   tabuleiro[7][1]=3;
   tabuleiro[8][0]=1;
   tabuleiro[8][5]=5;
}
void mostra(int tabuleiro[][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",tabuleiro[i][j]);
            if(j==2||j==5)
                printf(" ");
        }
    if(i==2||i==5)
        printf("\n");
    printf("\n");
    }
}
int checazero(int tabuleiro[][N]){
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(tabuleiro[i][j]==0)
                return 0;
    return 1;
}
int identificaquadrante(int linha, int coluna){
    if(linha<=2&&coluna<=2)
        return 1;
    else if(linha<=2&&coluna>=3&&coluna<=5)
        return 2;
    else if(linha<=2&&coluna>=6)
        return 3;
    else if(linha>=3&&linha<=5&&coluna<=2)
        return 4;
    else if(linha>=3&&linha<=5&&coluna>=3&&coluna<=5)
        return 5;
    else if(linha>=3&&linha<=5&&coluna>=6)
        return 6;
    else if(linha>=6&&coluna<=2)
        return 7;
    else if(linha>=6&&coluna>=3&&coluna<=5)
        return 8;
    else
        return 9;
}
int checaquadrante(int valor, int tabuleiro[][N], int linha, int coluna){
    int quadrante = identificaquadrante(linha,coluna),i,j,qtdvalor = 0;
    switch(quadrante){
    case 1:
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(tabuleiro[i][j]==valor)
                    qtdvalor++;
            }
        }
        if(qtdvalor!=1)
            return 0;
        break;
    case 2:
        for(i=0;i<3;i++){
            for(j=3;j<6;j++){
                if(tabuleiro[i][j]==valor)
                    qtdvalor++;
            }
        }
        if(qtdvalor!=1)
            return 0;
        break;
    case 3:
        for(i=0;i<3;i++){
            for(j=6;j<9;j++){
                if(tabuleiro[i][j]==valor)
                    qtdvalor++;
            }
        }
        if(qtdvalor!=1)
            return 0;
        break;
    case 4:
        for(i=3;i<6;i++){
            for(j=0;j<3;j++){
                if(tabuleiro[i][j]==valor)
                    qtdvalor++;
            }
        }
        if(qtdvalor!=1)
            return 0;
        break;
    case 5:
        for(i=3;i<6;i++){
            for(j=3;j<6;j++){
                if(tabuleiro[i][j]==valor)
                    qtdvalor++;
            }
        }
        if(qtdvalor!=1)
            return 0;
        break;
    case 6:
        for(i=3;i<6;i++){
            for(j=6;j<9;j++){
                if(tabuleiro[i][j]==valor)
                    qtdvalor++;
            }
        }
        if(qtdvalor!=1)
            return 0;
        break;
    case 7:
        for(i=6;i<9;i++){
            for(j=0;j<3;j++){
                if(tabuleiro[i][j]==valor)
                    qtdvalor++;
            }
        }
        if(qtdvalor!=1)
            return 0;
        break;
    case 8:
        for(i=6;i<9;i++){
            for(j=3;j<6;j++){
                if(tabuleiro[i][j]==valor)
                    qtdvalor++;
            }
        }
        if(qtdvalor!=1)
            return 0;
        break;
    case 9:
        for(i=6;i<9;i++){
            for(j=6;j<9;j++){
                if(tabuleiro[i][j]==valor)
                    qtdvalor++;
            }
        }
        if(qtdvalor!=1)
            return 0;
    }
    return 1;
}
int possivel(int valor,int tabuleiro[][N],int linha, int coluna){
    int i,j;
    for(j=0;j<N;j++){
        if(tabuleiro[linha][j]==valor&&j!=coluna){ ///checa a linha
            return 0;
        }
    }
    for(i=0;i<N;i++){
        if(tabuleiro[i][coluna]==valor&&i!=linha){
            return 0;
        }
    }
    if(checaquadrante(valor,tabuleiro,linha,coluna)==1){
        return 1;
    }
    return 0;
}
int solucionar(int tabuleiro[][N],int linha, int coluna){
    int i,j,aux;
    if(checazero(tabuleiro)==1)
        return 1;

    if(tabuleiro[linha][coluna]!=0){
        if(coluna==8&&linha!=8){
            if(solucionar(tabuleiro,linha+1,0)==1)
                return 1;
        }
        else{
            if(solucionar(tabuleiro,linha,coluna+1)==1)
                return 1;
        }
    }
    else{
    for(i=1;i<=N;i++){

        tabuleiro[linha][coluna] = i;
        aux = possivel(tabuleiro[linha][coluna],tabuleiro,linha,coluna);
        if(aux==1){
           if(coluna==8&&linha!=8){
                if(solucionar(tabuleiro,linha+1,0)==1){
                    return 1;
                }
           }
           else{
                if(solucionar(tabuleiro,linha,coluna+1)==1){
                    return 1;
                }
           }
        }else{
            tabuleiro[linha][coluna]=0;
        }
    }
    tabuleiro[linha][coluna]=0;
    }
    return 0;
}
void iniciar(){
    setlocale(LC_ALL, "Portuguese");
    printf("Resolvedor Automático de Sudoku! Digite o valor da casa e pressione ENTER\n");
    int tabuleiro[N][N], resultado;
    preenchezero(tabuleiro);
    le_casas(tabuleiro);
    //teste(tabuleiro);
    mostra(tabuleiro);
    resultado = solucionar(tabuleiro,0,0);
    printf("\n\n");
    if(resultado == 1){
        printf("Resolvido com sucesso!\n");
        mostra(tabuleiro);
    }else{
        printf("Sudoku impossivel!\n");
    }
    printf("Pressione qualquer tecla para finalizar...");
    getchar();
getchar();
}
int main(){
    iniciar();
    return 0;
}
