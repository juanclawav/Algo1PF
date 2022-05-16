#include <bits/stdc++.h> // Para importar todas librerias
#define input freopen("in.txt", "r", stdin)
#define input1 freopen("ejemplo1.txt", "r", stdin)
#define input2 freopen("ejemplo2.txt", "r", stdin)
#define input3 freopen("ejemplo3.txt", "r", stdin)
#define input4 freopen("ejemplo4.txt", "r", stdin)
#define input5 freopen("ejemplo5.txt", "r", stdin)
#define input6 freopen("ejemplo6.txt", "r", stdin)

#define output freopen("out.txt", "w", stdout)
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
void menu(){
    int c;
        cout<<"1 ejecutar Ejemplos =======" << endl;
        cout<<"0 Salir del programa" << endl;
        cin>>c;
        if(c == 1) {
             cout<<"Mostrar el ejemplo 1"<<endl;
            cout<<"Mostrar el ejemplo 2"<<endl;
            cout<<"Mostrar el ejemplo 3"<<endl;
            cout<<"Mostrar el ejemplo 4"<<endl;
            cout<<"Mostrar el ejemplo 5"<<endl;
            cout<<"Mostrar el ejemplo 6"<<endl;
            
        cout<<"7. ejecuta tu propio caso de entrada (leer archivo instruccion.txt) =======" << endl;
        }
        else if(c==0){
            cout<<"Saliendo"<<endl;
        }
    int op;
    cin>>op;
    switch(op) {
                     case 1:
                     input1;
                    break;
                      case 2:
                     input2;
                    break;
                     case 3:
                     input3;
                    break;
                     case 4:
                     input4;
                    break;
                     case 5:
                     input5;
                    break;
                     case 6:
                     input6;
                    break;
                    case 7:
                    input;
                    break;
                    default:
                    break;
                    }
}
int main() {
    menu();
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

