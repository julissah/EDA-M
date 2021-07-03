
#ifndef NODO_H_
#define NODO_H_

#include <iostream>

template<class T>
class Node {
    public:
        Node(T value) : value(value), factor(0) { childs[0] = childs[1] = 0; }
        T value;
        int factor;
        Node *childs[2];
};




#endif /* NODO_H_ */
