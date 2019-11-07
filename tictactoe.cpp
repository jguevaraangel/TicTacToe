#include "tree.hpp"
#include <cstdlib>

bool turnoDeX = false; //Jugador "O" marca primero

char tablero[][3] = {{'_', '_', '_'},
                     {'_', '_', '_'}, //Tablero vac�o
                     {'_', '_', '_'},
};

//Retorna "X" o "O"
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
    cout << "En que fila desea jugar: ";
    cin >> fila;
    fila--;
    cout << "En que columna desea jugar: ";
    cin >> columna;
    columna--;
	cout << endl;
    tablero[fila][columna] = jugador;
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
    /*while(true) {
        mostrarTablero();
    }*/
	Tree t;
  t.posibilidades();
	t.display();
    return 0;
}
