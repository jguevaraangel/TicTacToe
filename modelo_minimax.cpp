#include <iostream>
#include <cstdlib>
using namespace std;

bool turnoDeX = false; //Jugador 'O' marca primero

char tablero[][3] = {{'_', '_', '_'},
                     {'_', '_', '_'}, //Tablero vacio
                     {'_', '_', '_'},
};

//Retorna 'X' o 'O' o '_'
char hayGanador() {
    //Validacion horizontal
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] != '_' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return tablero[i][0];
        }
    }
    //Validacion vertical
    for (int i = 0; i < 3; i++) {
        if (tablero[0][i] != '_' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return tablero[0][i];
        }
    }
    //Validacion diagonal izquierda a derecha
    if (tablero[0][0] != '_' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        return tablero[0][0];

    //Validacion diagonal derecha a izquierda
    if (tablero[0][2] != '_' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        return tablero[0][2];

	return '_';
}

bool hayEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '_') {
                return false;
            }
        }
    }
    return true;
}

//Algoritmo Minimax
bool finPartida() {
  return hayEmpate() || hayGanador() != '_';
}

//foward declaration
int min();

int max() {
  if (finPartida()) {
    if (hayGanador() != '_') return -1;
    else return 0;
  }
  int min_value = -1;
  int aux;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tablero[i][j] == '_') {
        tablero[i][j] = 'X';
        aux = min();
        if (aux > min_value) min_value = aux;
        tablero[i][j] = '_';
      }
    }
  }
  return min_value;
}

int min() {
  if (finPartida()) {
    if (hayGanador() != '_') return 1;
    else return 0;
  }
  int max_value = 1;
  int aux;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tablero[i][j] == '_') {
        tablero[i][j] = 'O';
        aux = max();
        if (aux < max_value) max_value = aux;
        tablero[i][j] = '_';
      }
    }
  }
  return max_value;
}

void DecisionIA() {
  if (!finPartida()) {
    int f = 0, c = 0;
    int min_value = -1;
    int aux;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (tablero[i][j] == '_') {
          tablero[i][j] = 'X';
          aux = min();
          if (aux > min_value) {
            min_value = aux;
            f = i;
            c = j;
          }
          tablero[i][j] = '_';
        }
      }
    }
    tablero[f][c] = 'X';
  }
}

void mostrarTablero() {
    char jugador = turnoDeX ? 'X' : 'O';
    int fila = 0;
    int columna = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << "\t";
        }
        cout << endl;
    }
	  cout << endl;

    cout << "Turno de " << jugador << endl;

    if (turnoDeX == false) {
      cout << "En que fila desea jugar: ";
      cin >> fila;
      fila--;
      cout << "En que columna desea jugar: ";
      cin >> columna;
      columna--;
      cout << endl;
      if (tablero[fila][columna] == '_') {
        tablero[fila][columna] = jugador;
      }
      else {
        int f = fila;
        int c = columna;
        while (tablero[f][c] != '_') {
          cout << "¡No puede jugar en esa casilla!" << endl;
          cout << "En que fila desea jugar: ";
          cin >> fila;
          fila--;
          cout << "En que columna desea jugar: ";
          cin >> columna;
          columna--;
          cout << endl;
          f = fila;
          c = columna;
        }
        tablero[f][c] = jugador;
      }
    }

    else {
      DecisionIA();
    }
    char ganador = hayGanador();
    if (ganador != '_') {
        cout << "Ha ganado " << ganador << endl;
        exit(0);
    }
    if (hayEmpate()) {
        cout << "Hay un empate " << endl;
        exit(0);
    }
    turnoDeX = !turnoDeX;
}

int main() {
  while(true) {
      mostrarTablero();
  }
  return 0;
}
