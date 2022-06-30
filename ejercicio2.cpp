/* 2- Dado un valor n (<=25), ingresar por filas una matriz cuadrada de n filas y columnas.
Desarrollar un algoritmo que determine e imprima los elementos de la diagonal principal o
secundaria según de cuál resulte mayor la sumatoria de elementos.
 */

#include <iostream>

using namespace std;

const int cantF = 25, cantC = 25;

void inicializarMatriz(int matriz[][cantC], int m, int n);
void cargarPorFila(int matriz[][cantC], int m, int n);
void mostrarPorFila(int matriz[][cantC], int m, int n);
void imprimirDiagonal(int matriz[][cantC], int n);
void recorrerDiagonalPrincipal(int matriz[][cantC], int n, int filas, int columnas, int sumaDiagonal);
void recorrerDiagonalSecundaria(int matriz[][cantC], int n, int filas, int columnas, int sumaDiagonal);

int main()
{
  int n, n2;

  do
  {
    cout << "Ingrese un valor menor o igual a 25: ";
    cin >> n;
    n2 = n;
  } while (n > cantF);

  int matriz[cantF][cantC];

  inicializarMatriz(matriz, cantF, cantC);
  cargarPorFila(matriz, n, n2);
  mostrarPorFila(matriz, cantF, cantC);
  imprimirDiagonal(matriz, n);

  return 0;
}

void inicializarMatriz(int matriz[][cantC], int m, int n)
{
  for (int c = 0; c < n; c++)
    for (int f = 0; f < m; f++)
      matriz[f][c] = 0;
}

void cargarPorFila(int matriz[][cantC], int m, int n)
{
  for (int f = 0; f < m; f++)
    for (int c = 0; c < n; c++)
    {
      int num;
      cout << "Fila " << f << " columna " << c << endl;
      cin >> num;
      matriz[f][c] = num;
    }
}

void mostrarPorFila(int matriz[][cantC], int m, int n)
{
  cout << "Matriz:" << endl;
  for (int f = 0; f < m; f++)
  {
    for (int c = 0; c < n; c++)
      cout << matriz[f][c] << "   ";
    cout << endl;
  }
}

void imprimirDiagonal(int matriz[][cantC], int n)
{
  int sumaDiagP = 0, sumaDiagS = 0, contFilas = 0, contColumnas = 0;

  for (contColumnas; contColumnas < n; contColumnas++)
  {
    sumaDiagP += matriz[contFilas][contColumnas];
    contFilas++;
  }

  contFilas = 0;

  for (contColumnas = n - 1; contColumnas >= 0; contColumnas--)
  {
    sumaDiagS += matriz[contFilas][contColumnas];
    contFilas++;
  }

  if (sumaDiagP > sumaDiagS)
    recorrerDiagonalPrincipal(matriz, n, contFilas, contColumnas, sumaDiagP);
  else
  {
    if (sumaDiagP == sumaDiagS)
    {
      recorrerDiagonalPrincipal(matriz, n, contFilas, contColumnas, sumaDiagP);
      recorrerDiagonalSecundaria(matriz, n, contFilas, contColumnas, sumaDiagS);
    }
    else
      recorrerDiagonalSecundaria(matriz, n, contFilas, contColumnas, sumaDiagS);
  }
}

void recorrerDiagonalPrincipal(int matriz[][cantC], int n, int filas, int columnas, int sumaDiagonal)
{
  filas = 0;
  for (columnas = 0; columnas < n; columnas++)
  {
    cout << "Elementos de la diagonal principal: " << matriz[filas][columnas] << "  " << endl;
    filas++;
  }
  cout << "Los elementos de la diagonal principal suman: " << sumaDiagonal << endl;
}

void recorrerDiagonalSecundaria(int matriz[][cantC], int n, int filas, int columnas, int sumaDiagonal)
{
  filas = 0;
  for (columnas = n - 1; columnas >= 0; columnas--)
  {
    cout << "Elementos de la diagonal secundaria: " << matriz[filas][columnas] << "  " << endl;
    filas++;
  }
  cout << "Los elementos de la diagonal secundaria suman: " << sumaDiagonal;
}
