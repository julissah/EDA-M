
#ifndef AVL_H_
#define AVL_H_

#include "Nodo.h"
#include <iostream>
#include <fstream>
#include <stack>

using std::cout;
using std::endl;

template<class T>
class Tree {
    public:
        Tree() : root(0) {}
        bool find(T value, Node<T> **&p);
 //       void add(T value);
        int insert(T value, Node<T> *&p);
        void insertar(T value);
        void printDot(char*);
    private:
        void rs(Node<T> *&p, bool);
        void rd(Node<T> *&p, bool);
        void printDot(Node<T>*, std::ostream&);
        Node<T> *root;
};

template<class T>
void Tree<T>::rs(Node<T> *&p, bool b) {
    Node<T> *q = p->childs[b];
    p->childs[b] = q->childs[!b];
    q->childs[!b] = p;

    p->factor = q->factor = 0;

    p = q;
}


//left rotate right rotate
template<class T>
void Tree<T>::rd(Node<T> *&p, bool b) {
    Node<T> *q = p->childs[b];
    Node<T> *r = q->childs[!b];

    p->childs[b] = r->childs[!b];
    q->childs[!b] = r->childs[b];

    r->childs[!b] = p;
    r->childs[b] = q;

    if (r->factor == 0)
        p->factor = q->factor = 0;
    else if (r->factor == 1) {
        r->childs[b]->factor = 0;
        r->childs[!b]->factor = -1;
    } else {
        r->childs[b]->factor = -1;
        r->childs[!b]->factor = 0;
    }

    p = r;
}

template<class T>
void Tree<T>::printDot(char* name) {
    std::ofstream out(name);
    out << "digraph G {" << endl;
    printDot(root, out);
    out << "}";
}

template<class T>
void Tree<T>::printDot(Node<T> *node, std::ostream &out) {
    if (!node) return;
    if (node->childs[0])
        out << node->value << "->" << node->childs[0]->value << endl;
    if (node->childs[1])
        out << node->value << "->" << node->childs[1]->value << endl;
    printDot(node->childs[0], out);
    printDot(node->childs[1], out);
}

template<class T>
void Tree<T>::insertar(T value) {
	insert(value, root);
}

template<class T>
int Tree<T>::insert(T value, Node<T> *&p) {
	if (!p) {
		p = new Node<T>(value);
		return 1;
	}

	if (p->value == value) return 0;

	int f = insert(value, p->childs[p->value < value]);
	if (!f) return 0;

	if (p->value < value) p->factor++;
	else p->factor--;

	switch (p->factor) {
	case 0: return 0;
	case -2:
		if (p->childs[0]->factor < 0) rs(p, 0);

		else rd(p, 0); return 0;
	case 2:
		if (p->childs[1]->factor > 0) rs(p, 1);

		else rd(p, 1); return 0;
	}
}



#endif /* AVL_H_ */
