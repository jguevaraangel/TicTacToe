#include <iostream>
#include <array>
using namespace std;
#include <vector>

array<array<char,3>, 3> ponerX(array<array<char,3>, 3> myMatrix, int x, int y, bool turno){
	char jugador = turno ? 'X' : 'O';
    myMatrix[x][y] = jugador;
    return myMatrix;
}

void posibilidades(array<array<char,3>,3> situacion, bool turno, vector<int> &v) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (situacion[i][j] == '_') {
                array<array<char, 3>, 3> temp = ponerX(situacion, i, j, turno);
                for (int m = 0; m < 3; ++m) {
                    for (int n = 0; n < 3; ++n) {
                        cout << temp[m][n] << " ";
                    }
                    cout << endl;
                }
                cout << "\n\n";
                v.push_back(1);
                posibilidades(temp, !turno, v);

            }
        }
    }
}

int main(){
    vector<int> v;
    array<array<char,3>, 3> situacion;
    for(int x = 0; x < 3; x++){
        for(int a = 0; a < 3; a++){
            situacion[x][a] = '_';
        }
    }
    bool turno = true;

    posibilidades(situacion, turno, v);
    cout << v.size() << endl;
}
