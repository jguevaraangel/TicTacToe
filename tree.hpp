#ifndef __tree__hpp
#define __tree__hpp
#include <iostream>
#include <vector>
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
	char hayGanador(char** situacion);
	void obtenerSituacion(Node* &p);
	void posibilidades(Node* &p, bool turno);

public:
	Tree(); //Crea todas las posibles situaciones del juego
	~Tree();
	void display();
	void posibilidades();
};

void Tree::posibilidades(Node* &p, bool turno) {
	if (p->hijos[0] != nullptr) {
		char jugador = turno ? 'X' : 'O';
		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (p->situacion[i][j] == '_') {
					p->situacion[i][j] = jugador;
					goto salto;
				}
			}
		}
		salto:*/
		turno = !turno;

		for (unsigned int k = 0; k < p->hijos.size(); k++) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p->hijos[k]->situacion[i][j] = p->situacion[i][j];
				}
			}
		}

		for (unsigned int k = 0; k < p->hijos.size(); k++) {
			posibilidades(p->hijos[k], turno);
		}
	}
}

void Tree::posibilidades() {
		posibilidades(root, true);
}

void Tree::obtenerSituacion(Node* &p) {
	for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
					cout << p->situacion[i][j] << "\t";
			}
			cout << endl;
	}
}

char Tree::hayGanador(char** situacion) {
	//Validacion horizontal
	for (int i = 0; i < 3; i++) {
			if (situacion[i][0] != '_' && situacion[i][0] == situacion[i][1] && situacion[i][1] == situacion[i][2]) {
					return situacion[i][0];
			}
	}
	//Validacion vertical
	for (int i = 0; i < 3; i++) {
			if (situacion[0][i] != '_' && situacion[0][i] == situacion[1][i] && situacion[1][i] == situacion[2][i]) {
					return situacion[0][i];
			}
	}
	//Validacion diagonal izquierda a derecha
	if (situacion[0][0] != '_' && situacion[0][0] == situacion[1][1] && situacion[1][1] == situacion[2][2])
			return situacion[0][0];

	//Validacion diagonal derecha a izquierda
	if (situacion[0][2] != '_' && situacion[0][2] == situacion[1][1] && situacion[1][1] == situacion[2][0])
			return situacion[0][2];

return '_';
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
