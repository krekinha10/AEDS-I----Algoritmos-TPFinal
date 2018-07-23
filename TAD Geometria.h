//ponto, representado por coordenadas cartesianas x e y
typedef struct
{
    double x;
    double y;
} ponto;

//linha, representada por uma sequencia de 2 a 100 pontos/vertices
typedef struct
{
    ponto l[99];
    int numVertices;
} linha;

//poligono, representada por uma sequencia de 3 a 100 pontos/vertices
typedef struct
{
    ponto p[99];
    int numVertices;
} poligono;

void criaPonto(ponto*, double x, double y);

//retorna TRUE se os pontos forem identicos
int pontoCoincide(ponto P, ponto Q);

void imprimePonto(ponto P);

void criaLinha(linha*l, int numVertices, ponto*vertices);

//verificase a linha poligonal tem interseção com o poligono
int linhaInterceptaPoligono(linha l, poligono P);

//verifica se a linha é simples (sem auto-interseções)
int linhaSimples(linha L);

void criaPoligono (poligono *p, int numVertices, ponto*vertices);

//verifica se o ponto esta no interior do poligono
int pontoEmPoligono(ponto P, poligono Pol);

//verifica se o poligono é simple (sem auto-interseções)
int poligonoSimples (poligono Pol);
