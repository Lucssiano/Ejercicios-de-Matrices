/* 1- Dados dos valores, m (<=30) y n (<=25), ingresar por filas todos los componentes de una matriz de
m filas y n columnas. Desarrollar un programa que:
✓ Imprima la matriz por columna.
✓ Calcule e imprima el valor promedio de los componentes de la matriz.
✓ Genere e imprima un vector donde cada componente sea la suma de columna homóloga.
✓ Genere e imprima un vector donde cada componente sea el valor máximo de cada fila */

// m (<=30) y n (<=25)

#include <iostream>

using namespace std;

const int cantF = 25, cantC = 30;

void cargarPorColumna(int matriz[][cantC], int m, int n);
void mostrarPorColumna(int matriz[][cantC], int m, int n);
float promComponentes(int matriz[][cantC], int m, int n);
void sumaColumHomologa(int matriz[][cantC], int m, int n);
void valorMaxFila(int matriz[][cantC], int m, int n);

int main()
{
  int m, n;

  do
  {
    cout << "Ingrese un valor menor o igual a 30: ";
    cin >> m;
    cout << "Ingrese un valor menor o igual a 25: ";
    cin >> n;
  } while (m > cantC || n > cantF);

  int matriz[cantF][cantC];

  cargarPorColumna(matriz, m, n);
  mostrarPorColumna(matriz, m, n);
  cout << "El valor promedio de los componentes de la matriz es: " << promComponentes(matriz, m, n) << endl;
  sumaColumHomologa(matriz, m, n);
  valorMaxFila(matriz, m, n);

  return 0;
}

void cargarPorColumna(int matriz[][cantC], int m, int n)
{
  for (int c = 0; c < n; c++)
    for (int f = 0; f < m; f++)
    {
      cout << "Fila " << f << " columna " << c << endl;
      cin >> matriz[f][c];
    }
}

void mostrarPorColumna(int matriz[][cantC], int m, int n)
{
  cout << "Matriz:" << endl;
  for (int c = 0; c < n; c++)
  {
    for (int f = 0; f < m; f++)
      cout << matriz[f][c] << "   ";
    cout << endl;
  }
}

float promComponentes(int matriz[][cantC], int m, int n)
{
  int suma = 0;
  float prom = 0;

  for (int c = 0; c < n; c++)
    for (int f = 0; f < m; f++)
      suma += matriz[f][c];

  prom = (float)suma / (m * n);
  return prom;
}

void sumaColumHomologa(int matriz[][cantC], int m, int n)
{
  int vecColum[n];
  for (int c = 0; c < n; c++)
  {
    int sumaColum = 0;
    for (int f = 0; f < m; f++)
      sumaColum += matriz[f][c];
    vecColum[c] = sumaColum;
  }

  for (int i = 0; i < n; i++)
    cout << "La suma de la columna homologa " << i + 1 << " es: " << vecColum[i] << endl;
}

void valorMaxFila(int matriz[][cantC], int m, int n)
{
  int vecMaxFila[m];
  for (int i = 0; i < m; i++)
  {
    int valorMax = matriz[i][0];
    for (int j = 0; j < n; j++)
      if (matriz[i][j] > valorMax)
        valorMax = matriz[i][j];
    vecMaxFila[i] = valorMax;
  }

  for (int i = 0; i < m; i++)
    cout << "El valor maximo de la fila " << i + 1 << " es: " << vecMaxFila[i] << endl;
}