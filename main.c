#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "TAD Geometria.h"

#define MAX 100

int main (int argc,char*argv[])//Programa para leitura do Arquivo.txt
{
    int numPontos, numVertices, numLinhas,numPoligonos,numverticelinha,numverticepoligonos,numTeste,i,j,aux1,aux2,tipoteste;
    double x,y;
    ponto *p, *verticeLinhas,*verticePoligono;
    linha*l;
    poligono*Po;
    char *opcao;
    FILE*ARQ;
    ARQ=fopen("arquivoentrada.txt", "r");
    if(ARQ==NULL)
    {
        printf("Erro ao abrir o arquivo \n");
        exit(1);
    }
    else
    {
        printf("Arquivo aberto com sucesso \n");
        fscanf(ARQ,"%d", &numPontos);
        p=calloc(numPontos,sizeof(ponto));
        for(i=0; i<numPontos; i++)
        {
            fscanf(ARQ,"%lf %lf",&x,&y);
            criaPonto(&p[i],x,y);
        }
        fscanf(ARQ,"%d", &numLinhas);
        l=calloc(numLinhas,sizeof(linha));
        for(i=0; i<numLinhas; i++)
        {
            fscanf(ARQ,"%d",&numverticelinha);
            l[i].numVertices=numverticelinha;
            verticeLinhas=calloc(numverticelinha,sizeof(ponto));
            for(j=0; j<numverticelinha; j++)
            {
                fscanf(ARQ,"%lf %lf",&x,&y);
                criaPonto(&verticeLinhas[j],x,y);
                criaLinha(&l[i],j,&verticeLinhas[j]);
            }
        }
        fscanf(ARQ,"%d",&numPoligonos);
        Po=calloc(numPoligonos,sizeof(poligono));
        for(i=0; i<numPoligonos; i++)
        {
            fscanf(ARQ,"%d",&numverticepoligonos);
            Po[i].numVertices = numverticepoligonos;
            verticePoligono = calloc(numverticepoligonos,sizeof(ponto));
            for(j=0; j<numverticepoligonos; j++)
            {
                fscanf(ARQ,"%lf %lf", &x, &y);
                criaPonto(&verticePoligono[j],x,y);
                criaPoligono(&Po[i], j, &verticePoligono[j]);
            }
        }
        fscanf(ARQ,"%d",&numTeste);
        opcao=calloc(numTeste,sizeof(char));
        for(i=0; i<numTeste; i++)
        {
            fscanf(ARQ,"%d", &tipoteste);
            fscanf(ARQ,"%s",opcao);
            if(strcmp(opcao,"LINSIMP")==0)
            {
                fscanf(ARQ,"%d",&aux1);
                if(linhaSimples(l[aux1-1])==0)
                {
                    printf("Linha %d: simples\n", aux1);
                }
                else
                {
                    printf("Linha %d: nao simples\n", aux1);
                }
            }
            else
            {
                if(strcmp(opcao,"POLSIMP")==0)
                {
                    fscanf(ARQ,"%d", &aux1);
                    if(poligonoSimples(Po[aux1-1])==0)
                    {
                        printf("Poligono %d: simples\n", aux1);
                    }
                    else
                    {
                        printf("Poligono %d: nao simples\n", aux1);
                    }
                }
                else
                {
                    if(strcmp(opcao,"LINPOL")==0)
                    {
                        fscanf(ARQ,"%d %d", &aux1, &aux2);
                        if(linhaInterceptaPoligono(l[aux1-1], Po[aux2-1])==1)
                        {
                            printf("Linha %d: intercepta o poligono %d\n", aux1, aux2);
                        }
                        else
                        {
                            printf("Linha %d: nao intercepta o poligono %d\n", aux1, aux2);
                        }
                    }
                    else
                    {
                        if(strcmp(opcao,"PTOPOL")==0)
                        {
                            fscanf(ARQ,"%d %d", &aux1, &aux2);
                            if(pontoEmPoligono(p[aux1-1], Po[aux2-1])==1)
                            {
                                printf("Ponto %d: dentro do poligono %d\n", aux1, aux2);
                            }
                            else
                            {
                                printf("Ponto %d: fora do poligono %d\n", aux1, aux2);
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(ARQ);
    free(p);
    free(verticeLinhas);
    free(verticePoligono);
    free(l);
    free(Po);
    free(opcao);
    return 0;
}
