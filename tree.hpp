#ifndef __tree__hpp
#define __tree__hpp
#include <iostream>
#include <vector>
using namespace std;

class Tree {
private:
	struct Node {
		char situacion[3][3] = {{'_', '_', '_'},
								{'_', '_', '_'},
								{'_', '_', '_'},
		};
		Node* padre;
		vector<Node*> hijos;
		int puntaje = 0;
	};

	Node* root;
	void destroyRecursive(Node* &p);
	void insertNode(Node* &p, Node* &ptr, int num_hijos);
	void display(Node* &n);

public:
	Tree(); //Crea todas las posibles situaciones del juego
	~Tree();
	void display();
};

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
