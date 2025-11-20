#include <stdio.h>
#include <stdlib.h>
#define tam 10
#define hab 5 
#define navio 3

//Função para plicação de habilidade no tabuleiro 
void aplicarHabilidade(int tabuleiro1 [tam][tam], int habilidade[hab][hab], int origem_linha, int origem_coluna){
    for (int  i = 0; i < hab; i++)
    {
        for (int j = 0; j < hab; j++)
        {
            int linha_tab = origem_linha - hab / 2 + i;
            int coluna_tab = origem_coluna - hab / 2 + j;

            if (linha_tab>= 0 && linha_tab < tam && coluna_tab >= 0 && coluna_tab < tam)
            {
                if (habilidade[i][j] == 1 && tabuleiro1[linha_tab][coluna_tab]!= 3)
                {
                    tabuleiro1[linha_tab][coluna_tab] = 5;
                }
                
            }
            
        }
        
    }
    
}
//inicializando a matriz
int main(){
    int tabuleiro1[tam][tam] = {0};
    char linha[tam] = {'A','B', 'C','D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int i, j;
   
    //Posicionamento do navio na horizontal (linha 3, colunas D a F -> indíce [3][3] a [4][4])
    for (j = 3; j < 3 + navio; j++)
    {    
        tabuleiro1[3][j] = 3;
    }  

     //Posicionamento do navio na vertical (coluna G, linha 7a 9-> índice [7][9] a [7][7])
     for (i= 6 ; i < 6+  navio; i++)
        {
           tabuleiro1[i][6] = 3;
        }

    //posicionamento do navio na diagonal(da esquerda para direita A1 -> C3)
    int linha1 = 0;
    int coluna1 = 0;
    for ( i = 0; i < navio; i++)
    {
        tabuleiro1[linha1 + i][coluna1 + i] = 3;
    }
    
    //posicionamento do navio na diagonal (da direita pra esquerda J1 -> H3)
   int linha2 = 0;
   int coluna2 = 9;
   for ( i = 0; i < navio; i++)
   {
     tabuleiro1[linha2 + i][coluna2 - i] = 3;
   }
 
     
    //fazendo a construção do tabuleiro (matriz 10x10)
    int cone[hab][hab] = {0};
    int cruz[hab][hab] = {0};
    int octaedro[hab][hab] = {0};

//Criar as matrizes de habilidades
    //Cone: forma triangular apontando para baixo
    for (i = 0; i < hab; i++)
    {
        for(j = 0; j < hab; j++){
            if (j >= hab/ 2 - i && j <= hab/ 2 + i)
            {
                cone[i][j] = 1;
            }
            
        }
    }

    //Cruz: linha vertical e horizontal cruzando no centro
    for (i = 0; i < hab; i++)
    {
        for (j = 0; j < hab; j++)
        {
            if (i == hab/2 ||j == hab/2)
            {
                cruz[i][j] = 1;
            }
            
        }
        
    }
    
    //Octaedro: formato de losango 
    for ( i = 0; i < hab; i++)
    {
        for ( j = 0; j < hab; j++)
        {
            if (abs(i-hab/2) + abs(j -hab/2)<= hab/2)
            {
                octaedro[i][j] = 1;
            }
            
        }
        
    }
    
   //Aplicar as habilidades no tabuleiro
   aplicarHabilidade(tabuleiro1, cone, 2, 2); //canto superior esquerdo
   aplicarHabilidade(tabuleiro1, cruz, 5, 5); //centro do tabuleiro
   aplicarHabilidade(tabuleiro1, octaedro, 7, 8); //canto inferior direito
    
    //Imprimindo o cabeçalho da coluna
    printf("\n-----TABULEIRO BATALHA NAVAL-----\n  ");

    printf("  ");
    for (j = 0; j < tam; j++)
    {
        printf("%c ", linha[j]);
    }
    printf("\n ");

 //Imprimindo tudo desde as linhas até os espaços dos navios
 for (i = 0; i < tam; i++)
 {
    printf("%2d ", i +1); //Linhas númeradas de 1 a 10
    for (j = 0; j < tam; j++)
    {
        printf("%d ",tabuleiro1[i][j]);
    }
    printf("\n ");
}
printf("\n *** Informações do tabuleiro ***\n");
printf("-> Água representada pelo (0)\n-> Navio representado pelo (3)\n-> Área afetada pela habilidade(5)");

    return 0;
}

