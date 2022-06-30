/* 4- Una fábrica de calzados elabora 7 modelos en 5 colores diferentes. Se ingresan los datos de las
ventas, para finalizar se ingresa nro. de modelo 0

Nro. modelo (1..7) Color (1..5) Cantidad vendida

Se pide emitir un listado que informe:
a) Totales de cada uno de los modelos y por cada uno de los colores
b) Totales por cada modelo
c) Totales por cada color
d) Total general */

// Matriz con columnas (modelos) y filas (colores), y el valor es la cantidad vendida

#include <iostream>

using namespace std;

const int modelos = 7, colores = 5;

void inicializarMatriz(int mt[][modelos], int m, int n);
void ingresoDeDatos(int mt[][modelos], int m, int n);

int main()
{
  int mCalzados[colores][modelos];

  inicializarMatriz(mCalzados, colores, modelos);
  ingresoDeDatos(mCalzados, colores, modelos);

  return 0;
}

void inicializarMatriz(int mt[][modelos], int m, int n)
{
  for (int f = 0; f < m; f++)
    for (int c = 0; c < n; c++)
      mt[f][c] = 0;
}

// void ingresoDeDatos(int mt[][modelos], int m, int n)
// {
//   // for (int f = 0; f < m; f++)
//   //   for (int c = 0; c < n; c++)
//   //   {
//   //     cout << "Ingrese la cantidad de calzados vendidos del color " << f + 1 << " y modelo " << c + 1 << endl;
//   //     cin >> mt[f][c];
//   //   }
// }
