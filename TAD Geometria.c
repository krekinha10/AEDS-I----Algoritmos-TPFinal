#include <stdio.h>
#include <stdlib.h>
#include "TAD Geometria.h"

#define MAX 100



void criaPonto(ponto *p, double x, double y)//Fun��o para criar ponto
{
    p->x=x;
    p->y=y;
}


int pontoCoincide(ponto p, ponto q)//fun��o para testar se dois pontos s�o iguais
{
    if ((p.x==q.x) && (p.y==q.y))
    {
        printf("o x e o y do ponto s�o ( %f , %f ) \n", p.x,q.y);
        return 1;
    }
    else
    {
        return 0;
    }
}

void imprimePonto(ponto p)//Fun��o para imprimir pontos
{
    printf("(%lf, %lf)", p.x,p.y);
}

void criaLinha(linha *l,int numVertices,ponto*vertices)//Fun��o para criar linhas
{
    (*l).l[numVertices].x=(*vertices).x;
    (*l).l[numVertices].y=(*vertices).y;
}


int linhaInterceptaPoligono(linha L, poligono P)//Fun��o para determinar se uma linha intercepta um poligono
{
    int i,j;
    double det, s, t;
    for(i=0; i<L.numVertices-1; i++)//Loop para calcular se h� interse��o
    {
        for(j=0; j<P.numVertices-1; j++)
        {
            det=(P.p[j+1].x - P.p[j].x) * (L.l[i+1].y - L.l[i].y) - (P.p[j+1].y - P.p[j].y) * (L.l[i+1].x - L.l[i].x);
            s=(((P.p[j+1].x - P.p[j].x) * (P.p[j].y - L.l[i].y)) - ((P.p[j+1].y - P.p[j].y) * (P.p[j].x - L.l[i].x))) / det;
            t=(((L.l[i+1].x - L.l[i].x) * (P.p[j].y - L.l[i].y)) - ((L.l[i+1].y - L.l[i].y) * (P.p[j].x - L.l[i].x))) / det;
            if((s>=0 && s<=1) && (t>=0 && t<=1))
                return 1; // Se ocorrer a interse��o retorna 1
        }
    }
    return 0; //N�o havendo interse��o retorna 0
}

int linhaSimples(linha L)
{
    int i,j;
    double det, s, t;
    for(i=0; i<L.numVertices-1; i++)
    {
        //semireta 1
        for(j=0; j<L.numVertices-1; j++)
        {
            //semireta 2
            det=(L.l[j+1].x - L.l[j].x) * (L.l[i+1].y - L.l[i].y) - (L.l[j+1].y - L.l[j].y) * (L.l[i+1].x - L.l[i].x);
            s=(((L.l[j+1].x - L.l[j].x) * (L.l[j].y - L.l[i].y)) - ((L.l[j+1].y - L.l[j].y) * (L.l[j].x - L.l[i].x))) / det;
            t=(((L.l[i+1].x - L.l[i].x) * (L.l[j].y - L.l[i].y)) - ((L.l[i+1].y - L.l[i].y) * (L.l[j].x - L.l[i].x))) / det;
            if((s>0 && s<=1) && (t>0 && t<=1))
                return 1;   //Se ocorrer interse��o retorna 1
        }
    }
    return 0;   //N�o havendo interse��o retorna 0
}


void criaPoligono(poligono *p, int numVertices, ponto *vertices)//Fun��o para criar poligono
{
    (*p).p[numVertices].x=(*vertices).x;
    (*p).p[numVertices].y=(*vertices).y;
}


int pontoEmPoligono(ponto P, poligono Pol)//Fun��o para verificar se um ponto esta dentro do poligono
{
    int i, count=0;
    double det, s, t;
    ponto AUX;
    AUX.x=INT_MAX;   //Criar um semireta apartir do ponto X usnado o valor maximo do programa
    AUX.y=P.y;  //Mantem o valor do Y
    for(i=0; i<Pol.numVertices-1; i++)
    {
        det=(Pol.p[i+1].x - Pol.p[i].x) * (AUX.y - P.y) - (Pol.p[i+1].y - Pol.p[i].y) * (AUX.x - P.x);
        s=(((Pol.p[i+1].x - Pol.p[i].x) * (Pol.p[i].y - P.y)) - ((Pol.p[i+1].y - Pol.p[i].y) * (Pol.p[i].x - P.x))) / det;
        t=(((AUX.x - P.x) * (Pol.p[i].y - P.y)) - ((AUX.y - P.y) * (Pol.p[i].x - P.x))) / det;
        if((s>=0 && s<=1) && (t>=0 && t<=1))
            count+=1;
    }
    if(count%2!=0)
    {
        return 1; //Se o ponto est� dentro do poligono retorna 1
    }

    else
    {

        return 0; //Se o ponto est� fora do poligono retorna 0
    }
}


int poligonoSimples(poligono Pol)// Fun��o para verificar se o pol�gono � simples (sem auto-interse��es)
{
    int i,j;
    double det, s, t;
    for(i=0; i<Pol.numVertices-1; i++)
    {
        for(j=0; j<Pol.numVertices-1; j++)
        {
            det=(Pol.p[j+1].x - Pol.p[j].x) * (Pol.p[i+1].y - Pol.p[i].y) - (Pol.p[j+1].y - Pol.p[j].y) * (Pol.p[i+1].x - Pol.p[i].x);
            s=(((Pol.p[j+1].x - Pol.p[j].x) * (Pol.p[j].y - Pol.p[i].y)) - ((Pol.p[j+1].y - Pol.p[j].y) * (Pol.p[j].x - Pol.p[i].x))) / det;
            t=(((Pol.p[i+1].x - Pol.p[i].x) * (Pol.p[j].y - Pol.p[i].y)) - ((Pol.p[i+1].y - Pol.p[i].y) * (Pol.p[j].x - Pol.p[i].x))) / det;
            if((s>0 && s<=1) && (t>0 && t<=1))
                return 1;   //Se h� interse��o retorna 1
        }
    }
    return 0; //N�o Havendo interse��o retorna 0
}
