/* 1- Dados dos valores, m (<=5) y n (<=3), ingresar por filas todos los componentes de una matriz de
m filas y n columnas. Desarrollar un programa que:
✓ Imprima la matriz por columna.
✓ Calcule e imprima el valor promedio de los componentes de la matriz.
✓ Genere e imprima un vector donde cada componente sea la suma de la columna homóloga.
✓ Genere e imprima un vector donde cada componente sea el valor máximo de cada fila */

// m (<=30) y n (<=25)

#include <iostream>

using namespace std;

void cargarPorColumna(int matriz[][3], int m, int n);
void mostrarPorColumna(int matriz[][3], int m, int n);
float promComponentes(int matriz[][3], int m, int n);
void sumaColumHomologa(int matriz[][3], int m, int n);
void valorMaxFila(int matriz[][3], int m, int n);

int main()
{
  int m, n;

  // do
  // {
  //    cout << "Ingrese un valor menor o igual a 5: ";
  //   cin >> m;
  //   cout << "Ingrese un valor menor o igual a 3: ";
  //   cin >> n;
  // } while (m > 5 || n > 3);

  int matriz[2][3];

  cargarPorColumna(matriz, 2, 3);
  mostrarPorColumna(matriz, 2, 3);
  cout << "El valor promedio de los componentes de la matriz es: " << promComponentes(matriz, 2, 3) << endl;
  sumaColumHomologa(matriz, 2, 3);
  valorMaxFila(matriz, 2, 3);

  return 0;
}

void cargarPorColumna(int matriz[][3], int m, int n)
{
  for (int c = 0; c < n; c++)
    for (int f = 0; f < m; f++)
    {
      cout << "Fila " << f << " columna " << c << endl;
      cin >> matriz[f][c];
    }
}

void mostrarPorColumna(int matriz[][3], int m, int n)
{
  cout << "Matriz:" << endl;
  for (int c = 0; c < n; c++)
  {
    for (int f = 0; f < m; f++)
      cout << matriz[f][c] << "   ";
    cout << endl;
  }
}

float promComponentes(int matriz[][3], int m, int n)
{
  int suma = 0;
  float prom = 0;

  for (int c = 0; c < n; c++)
    for (int f = 0; f < m; f++)
      suma += matriz[f][c];

  prom = (float)suma / (m * n);
  return prom;
}

void sumaColumHomologa(int matriz[][3], int m, int n)
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

void valorMaxFila(int matriz[][3], int m, int n)
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