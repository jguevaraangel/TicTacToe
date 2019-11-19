#ifndef __tree__hpp
#define __tree__hpp
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Tree {
private:
	struct Node {
		char situacion[3][3] = {{'X', 'O', '_'},
								{'O', 'X', '_'},
								{'X', 'O', '_'},
		};
		Node* padre;
		vector<Node*> hijos;
		int puntaje = 0;
	};

	Node* root;
	void destroyRecursive(Node* &p);
	void insertNode(Node* &p, Node* &ptr, int num_hijos);
	void display(Node* &n);
	void obtenerSituacion(Node* &p);
	void posibilidades(array<array<char,3>,3> situacion);
	array<array<char, 3>, 3> ponerX(array<array<char, 3>, 3> myMatrix, int x, int y, bool turno);

public:
	Tree(); //Crea todas las posibles situaciones del juego
	~Tree();
	void display();
};

array<array<char,3>, 3> Tree::ponerX(array<array<char,3>, 3> myMatrix, int x, int y){
	char jugador = turno ? 'X' : 'O';
    myMatrix[x][y] = jugador;
    return myMatrix;
}

void Tree::posibilidades(array<array<char,3>,3> situacion, bool turno) {
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
            }
        }
    }
}


void Tree::obtenerSituacion(Node* &p) {
	for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
					cout << p->situacion[i][j] << "\t";
			}
			cout << endl;
	}
}

Tree::Tree() {
  root = nullptr;
  Node* p = nullptr;
  insertNode(p, root, 3);
}

void Tree::destroyRecursive(Node* &p) {
  if (p != nullptr) {
    for (unsigned int i = 0; i < p->hijos.size(); i++) {
        destroyRecursive(p->hijos[i]);
    }
    delete p;
  }
}

Tree::~Tree() {
  destroyRecursive(root);
}

void Tree::insertNode(Node* &p, Node* &ptr, int num_hijos) {
	if (num_hijos > 0) {
		ptr = new Node;
    ptr->padre = p;
    for (unsigned int i = 0; i < num_hijos; i++) {
        ptr->hijos.push_back(nullptr);
    }
    for (unsigned int i = 0; i < num_hijos; i++) {
        insertNode(ptr, ptr->hijos[i], num_hijos - 1);
    }
  }
}

void Tree::display(Node* &n) {
    if(n != nullptr) {
        cout << "Numero de hijos: " << n->hijos.size() << endl;
				obtenerSituacion(n);
        cout << endl;
        for (unsigned int i = 0; i < n->hijos.size(); i++) {
            display(n->hijos[i]);
        }
    }
}

void Tree::display() {
    display(root);
}

#endif
