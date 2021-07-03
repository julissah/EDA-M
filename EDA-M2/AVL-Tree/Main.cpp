/*
 * Main.cpp
 *
 *  Created on: 6 de jun. de 2016
 *      Author: romario
 */

#include "AVL.h"
#include "Nodo.h"
#include <cstdlib>
#include <fstream>


int main(void) {
    Tree<int> tree;
    tree.insertar(2);
    tree.insertar(8);
    tree.insertar(40);
    tree.insertar(49);
    tree.insertar(69);
    tree.insertar(1);
    tree.insertar(3);
    tree.insertar(5);
    tree.insertar(10);
//    tree.insertar(19);
 //   tree.insertar(22);
 //   tree.insertar(12);
 //   tree.insertar(84);
 //   tree.insertar(17);

    //****Prueba****
 //   for (int i = 0; i < 3; i++)
 //       tree.insert(i);

    tree.printDot("avl.dot");
    system("dot -Tpng avl.dot -o avl.png");
}


