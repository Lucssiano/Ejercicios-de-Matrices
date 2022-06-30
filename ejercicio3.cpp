/* 3- Hacer una función que dada una matriz cuadrada calcule y devuelva la sumatoria del triángulo
superior con respecto a la diagonal principal. */

#include <iostream>

using namespace std;

const int cantF = 20, cantC = 20;

void cargarPorFila(int matriz[][cantC], int m, int n);
void mostrarPorFila(int matriz[][cantC], int m, int n);
// void recorrerDiagonalPrincipal(int matriz[][cantC], int n, int columnas, int sumaDiagonal);

int main()
{

  int n, n2;

  do
  {
    cout << "Ingrese un valor mayor o igual a 2 y menor o igual a 20: ";
    cin >> n;
    n2 = n;
  } while (n < 2 && n > 20);

  int matriz[cantF][cantC];

  cargarPorFila(matriz, n, n2);
  mostrarPorFila(matriz, n, n2);

  return 0;
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

void recorrerDiagonalPrincipal(int matriz[][cantC], int n, int columnas, int sumaDiagonal)
{
  for (columnas = 0; columnas < n; columnas++)
    cout << "Elementos de la diagonal principal: " << matriz[columnas][columnas] << "  " << endl;
  cout << "Los elementos de la diagonal principal suman: " << sumaDiagonal << endl;
}