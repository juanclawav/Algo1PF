#include <bits/stdc++.h> // Para importar todas librerias
#define input freopen("ejemplo1.txt", "r", stdin)
using namespace std;

const int n = 9;
bool enFila(int tabla[n][n], int fila, int numero) {
  for (int i = 0; i < n; i++)
    if (tabla[fila][i] == numero)
      return true;
  return false;
}
bool enColumna(int tabla[n][n], int columna, int numero) {
  for (int i = 0; i < n; i++)
    if (tabla[i][columna] == numero)
      return true;
  return false;
}
bool enCuadro(int tabla[n][n], int fila, int columna, int numero) {
  int filaInicio = fila - fila % 3;
  int colInicio = columna - columna % 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (tabla[filaInicio + i][colInicio + j] == numero)
        return true;
  return false;
}
bool buscaLibre(int tabla[n][n], int &row, int &col) {
  for (row = 0; row < n; row++){
    for (col = 0; col < n; col++){
      if (tabla[row][col] == 0){
        return true;}
    }
  }
  return false;
}
bool resolver(int tabla[n][n]) {
  int fila, columna;
  if (!buscaLibre(tabla, fila, columna))
    return true;
  for (int numero = 1; numero <= 9; numero++) {
    if (!enFila(tabla, fila, numero) &&
       !enColumna(tabla, columna, numero) &&
       !enCuadro(tabla, fila, columna, numero)) {
      tabla[fila][columna] = numero;
      if (resolver(tabla))
        return true;
      tabla[fila][columna] = 0;
    }
  }
  return false; 
}
int main() {
    input;
  int tabla[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> tabla[i][j];
    }
  }
  cout << endl;
  if (resolver(tabla) == true) {
    cout << "Solucion: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
        cout << tabla[i][j] << " ";
        }
    cout << endl;
    }
  } else {
    cout << "No hay solucion. " << endl;
  }
  return 0;
}

