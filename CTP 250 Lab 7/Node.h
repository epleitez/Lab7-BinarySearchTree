//
// Created by Emely Pleitez on 10/27/22.
//

#ifndef CTP_250_LAB_7_NODE_H
#define CTP_250_LAB_7_NODE_H


#include <iostream>

template <typename T>
class Node {
public:
    Node();
    Node(const T& newItem,
         Node<T>* left = nullptr,
         Node<T>* right = nullptr);
    Node(const Node& orig);
    virtual ~Node();

    T getItem() const;
    void setItem(const T& newItem);

    bool isLeaf() const;


    T item;
    Node<T>* left;
    Node<T>* right;
};




template <typename T>
Node<T>::Node()  {
    left = nullptr;
    right = nullptr;

}
template <typename T>
Node<T>::Node(const T& newItem, Node<T>* left, Node<T>* right) {
    item = newItem;
    this->left = left;
    this->right = right;

}



template <typename T>
Node<T>::Node(const Node& orig) {
    item = orig.item;
    left = orig.left;
    right = orig.right;
}




template <typename T>
Node<T>::~Node() {
//    cout << " node destroyed" << endl;
}





template <typename T>
T Node<T>::getItem() const {
    return item;
}





template <typename T>
void Node<T>::setItem(const T& newItem) {
    item = newItem;
}





template <typename T>
bool Node<T>::isLeaf() const {
    return (left == nullptr && right == nullptr);
}



#endif //CTP_250_LAB_7_NODE_H
