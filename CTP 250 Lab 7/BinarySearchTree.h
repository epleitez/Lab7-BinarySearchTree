//
// Created by Emely Pleitez on 10/27/22.
//

#ifndef CTP_250_LAB_7_BINARYSEARCHTREE_H
#define CTP_250_LAB_7_BINARYSEARCHTREE_H

#include "Node.h"
#include "BSTInterface.h"
#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& orig);
    virtual ~BinarySearchTree();


    //interface methods
    void loadTreeData(const T data[], const int count);
    bool isEmpty() const;
    bool add(const T& newItem);
    void removeItem(const T& deleteItem);
    void clearTree();
    bool contains(const T& findItem) const;
    void inorderTraverse() const;
    void preorderTraverse() const;

    //added----------------------------------------
    void inorderTraverseString(string userInput) const;
    void inorderTraverseInteger(int userInput) const;
    void displayInorderTraverse() const;
    void displayAvgNumPassengersTraverse() const;
    void displayAvgNumFlightsTraverse() const;
    void maxNumPassengersTraverse() const;
    void maxFreightTraverse() const;
    void maxNumFlightsTraverse() const;
    void minNumPassengersTraverse() const;
    void minFreightTraverse() const;
    void minNumFlightsTraverse() const;
    void changeNumPassengersTraverse(string userInput);
    void changeFreightTraverse(string userInput);
    void changeNumFlightsTraverse(string userInput);


    void postorderTraverse() const;

    //---------------------------------------------


    void print2D();





private:

    Node<T>* root;

    //recursive methods
    void destroyTree(Node<T>* currRoot);

    Node<T>* deleteNode(Node<T>* currRoot, const T& deleteItem);

    Node<T>* minValueNode(Node<T>* node);
    Node<T>* maxValueNode(Node<T>* node);
    Node<T>* copyTree(const Node<T>* currRoot) const;
    Node<T>* placeNode(Node<T>* currRoot, Node<T>* newNode);
    bool findNode(Node<T>* currRoot, const T& item) const; //TODO
    void inorder(Node<T>* currRoot) const;
    void preorder(Node<T>* currRoot) const;
    void print2DUtil(Node<T>* root, int space);

    //added----------------------------------------
    void inorderString(Node<T>* currRoot, string userInput) const;
    void inorderInteger(Node<T>* currRoot, int userInput) const;
    void displayInorder(Node<T>* currRoot) const;
    void displayAvgNumPassengers(Node<T>* currRoot) const;
    void displayAvgNumFlights(Node<T>* currRoot) const;
    void maxNumPassengers(Node<T>* currRoot) const;
    void maxFreight(Node<T>* currRoot) const;
    void maxNumFlights(Node<T>* currRoot) const;
    void minNumPassengers(Node<T>* currRoot) const;
    void minFreight(Node<T>* currRoot) const;
    void minNumFlights(Node<T>* currRoot) const;
    void changeNumPassengers(Node<T>* currRoot, string userInput);
    void changeFreight(Node<T>* currRoot, string userInput);
    void changeNumFlights(Node<T>* currRoot, string userInput);


    void postorder(Node<T>* currRoot) const;



};




template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}




template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& orig) {

    root = this->copyTree(orig.root);
}




template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    clearTree();
}



template <class T>
void BinarySearchTree<T>::loadTreeData(const T data[], const int count)
{
    for (int i = 0; i < count; i++) {
        add(data[i]);
    }
}



//interface methods
template <class T>
bool BinarySearchTree<T>::isEmpty() const {
    return root = nullptr;
}




template <class T>
bool BinarySearchTree<T>::add(const T& newItem) {
    Node<T>* newNode = new Node<T>(newItem);
    root = placeNode(root, newNode);
    return true;
}




template <class T>
Node<T>* BinarySearchTree<T>::placeNode(Node<T>* currRoot, Node<T>* newNode) {
    if (currRoot == nullptr){
        //cout << "added " << newNode->getItem() << endl;
        return newNode;
    }//end if
    else {
        if (newNode->getItem() < currRoot->getItem()) {
            //cout << "Going left" << endl;
            Node<T>* tempPtr = placeNode(currRoot->left, newNode);
            currRoot->left = tempPtr;
        } else {
            //cout << "Going right" << endl;
            currRoot->right = placeNode(currRoot->right, newNode);
        }
        return currRoot;
    }
}


template <class T>
bool BinarySearchTree<T>::contains(const T& findItem) const {
    //call findNode using root
    findNode(root, findItem);
    return false;
}


template <class T>
void  BinarySearchTree<T>::removeItem(const T& delItem) {

    root = deleteNode(root, delItem);

}


/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
template <class T>
Node<T>* BinarySearchTree<T>::minValueNode(Node<T>* node)
{
    //cout << "minValueNode(" << node->getItem() << "): Begin..." << endl;
    Node<T>* current = node;

    /* loop to find the leftmost leaf */
    while (current && current->left != nullptr) {
        current = current->left;
    }

    //cout << "minValueNode(" << node->getItem() << "): End: current = " << current << endl;
    return current;
}


template <class T>
Node<T>* BinarySearchTree<T>::maxValueNode(Node<T>* node)
{
    //cout << "minValueNode(" << node->getItem() << "): Begin..." << endl;
    Node<T>* current = node;

    /* loop to find the leftmost leaf */
    while (current && current->right != nullptr) {
        current = current->right;
    }

    //cout << "minValueNode(" << node->getItem() << "): End: current = " << current << endl;
    return current;
}


/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
template <class T>
Node<T>* BinarySearchTree<T>::deleteNode(Node<T>* currRoot, const T& deleteItem)
{

    // base case
    if (currRoot == nullptr) {

        return nullptr;
    }

    // If the item to be deleted is < than the root's item then look in the left subtree

    if (deleteItem < currRoot->getItem()) {

        currRoot->left = deleteNode(currRoot->left, deleteItem);
    }

        // If the item to be deleted is > than the root's item then look in right subtree
    else if (deleteItem > currRoot->getItem()) {

        currRoot->right = deleteNode(currRoot->right, deleteItem);
    }

    else {
        // The deleteItem is same as root's item.
        // Deleting the root node.
        if (currRoot->left == nullptr && currRoot->right == nullptr) {
            return nullptr;
        }

            // node with only one child or no child
        else if (currRoot->left == nullptr) {

            Node<T>* temp = currRoot->right;
            delete(currRoot);

            return temp;
        }
        else if (currRoot->right == nullptr) {

            Node<T>* temp = currRoot->left;
            delete(currRoot);

            return temp;
        }

        // node with two children: Get the largest in the left subtree (or smallest in the right subtree)
        Node<T>* temp = maxValueNode(currRoot->left);   //could also use Node<T>* temp = minValueNode(currRoot->right);
        //Node<T>* temp = minValueNode(currRoot->right) ;



        // Copy the inorder successor's content to this node
        currRoot->setItem(temp->getItem());


        currRoot->left = deleteNode(currRoot->left, temp->getItem());
        //currRoot->right = deleteNode(currRoo->right, temp-gettItem());
    }


    return currRoot;
}


template <class T>
void BinarySearchTree<T>::clearTree() {
    //call destroyTree with root
    destroyTree(root);
    root = nullptr;

}


//recursive methods
template <class T>
Node<T>* BinarySearchTree<T>::copyTree(const Node<T>* currRoot) const {
    //preorder traversal
    Node<T>* newTree = nullptr;
    if (currRoot != nullptr) {
        newTree = new Node<T>(currRoot->getItem(), nullptr, nullptr);
        newTree->left = copyTree(currRoot->left);
        newTree->right =copyTree(currRoot->right);
    }
    return newTree;
}


template <class T>
bool BinarySearchTree<T>::findNode(Node<T>* currRoot, const T& item) const {

    /* if (base case)
    *  return some value
    * else
    *  recursive call with root of new subtree
    */


    if(currRoot != nullptr){
        if(item == currRoot->item){
            return currRoot;
        }
        else if (item < currRoot->item){
            return findNode(currRoot->left, item);
        }
        else{
            return findNode(currRoot->right, item);
        }
    }

    return false;

}


template <typename T>
void BinarySearchTree<T>::destroyTree(Node<T>* currRoot) {
    //post order traversal
    if(currRoot != nullptr){

        destroyTree(currRoot->left);
        destroyTree(currRoot->right);
        delete currRoot;
        currRoot = nullptr;
    }//end if
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//-----------In order traversal for Airport Code and Airport State -----------------------------------
/* In order traverses the Binary Search tree <Airport> airports
 * Specifically searches for either the Airport code or Airport State
 * @param string UserInput is the input done by the user for what they are searching for.
 */
template <typename T>
void BinarySearchTree<T>::inorderTraverseString(string userInput) const { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    inorderString(root, userInput);//, visit);

}

template <typename T>
void BinarySearchTree<T>::inorderString(Node<T>* currRoot, string userInput) const {//, void visit(T& item)) const {
    if(currRoot != nullptr){
        inorderString(currRoot->left, userInput);             //, visit);

        T item = currRoot->getItem();
        if(item.getCode() == userInput) {
            cout << item << "  ";
        }
        else if(item.getState() == userInput){
            cout << item << "  ";
        }
        //visit()
        inorderString(currRoot->right, userInput);             //, visit);
    }

}
//-----------In order traversal for Min num of Passengers --------------------------------------------
/* In order traverses the Binary Search tree <Airport> airports
 * Specifically searches for the minimum number of Passengers in Airport Object
 * @param int UserInput is the input done by the user for the min number of Passengers they are searching for.
 */
template <typename T>
void BinarySearchTree<T>::inorderTraverseInteger(int userInput) const { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    inorderInteger(root, userInput);//, visit);

}

template <typename T>
void BinarySearchTree<T>::inorderInteger(Node<T>* currRoot, int userInput) const {//, void visit(T& item)) const {
    //bool found = false;

    if(currRoot != nullptr){
        inorderInteger(currRoot->left, userInput);             //, visit);

        T item = currRoot->getItem();
        if(item.getNumPassengers() >= userInput) {
            cout << item << "  ";
            //found = true;
        }

        //visit()
        inorderInteger(currRoot->right, userInput);             //, visit);
    }

    /*
    if(!found){
        cout << "No Airports have the minimum number of passengers that has been searched..." << endl;
    }
    */

}
//-----------In order traversal to display --------------------------------------------
/* In order traverses the Binary Search tree <Airport> airports
 * Displays each Airport Object in a formatted table
 */
template <typename T>
void BinarySearchTree<T>::displayInorderTraverse() const{
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    displayInorder(root);//, visit);
}
template <typename T>
void BinarySearchTree<T>::displayInorder(Node<T>* currRoot) const{
    int width = 20;

    if(currRoot != nullptr){
        displayInorder(currRoot->left);             //, visit);

        T item = currRoot->getItem();
        //DISPLAY
        cout << left << setw(65) <<  item.getName() <<
        left << setw(10) <<  item.getState() <<
        left << setw(25) << item.getCity() <<
        left << setw(width) << item.getCode() <<
        left << setw(width) << item.getNumPassengers() <<
        left << setw(width) << item.getNumFlights() <<
        left << setw(width) << item.getFreight() << endl;


        displayInorder(currRoot->right);             //, visit);
    }

}
/* In order traverses the Binary Search tree <Airport> airports
 * Displays each Airport Object in a formatted table
 * Specifically displays the Average Number of Passengers of the Airport in one year (365 days)
 */
template <typename T>
void BinarySearchTree<T>::displayAvgNumPassengersTraverse() const{
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    displayAvgNumPassengers(root);//, visit);
}
template <typename T>
void BinarySearchTree<T>::displayAvgNumPassengers(Node<T> *currRoot) const {
    int width = 20;

    if(currRoot != nullptr){
        displayAvgNumPassengers(currRoot->left);             //, visit);

        T item = currRoot->getItem();
        //DISPLAY
        cout << left << setw(65) <<  item.getName() <<
             left << setw(10) <<  item.getState() <<
             left << setw(25) << item.getCity() <<
             left << setw(width) << item.getCode() <<
             left << setw(width) <<  fixed << setprecision(0) << ( item.getNumPassengers() / 365.0) << endl;


        displayAvgNumPassengers(currRoot->right);             //, visit);
    }
}

/* In order traverses the Binary Search tree <Airport> airports
 * Displays each Airport Object in a formatted table
 * Specifically displays the Average Number of Flights of the Airport in one year (365 days)
 */
template <typename T>
void BinarySearchTree<T>::displayAvgNumFlightsTraverse() const{
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    displayAvgNumFlights(root);//, visit);
}
template <typename T>
void BinarySearchTree<T>::displayAvgNumFlights(Node<T> *currRoot) const {
    int width = 20;

    if(currRoot != nullptr){
        displayAvgNumFlights(currRoot->left);             //, visit);

        T item = currRoot->getItem();
        //DISPLAY
        cout << left << setw(65) <<  item.getName() <<
             left << setw(10) <<  item.getState() <<
             left << setw(25) << item.getCity() <<
             left << setw(width) << item.getCode() <<
             left << setw(width) << fixed << setprecision(0) << ( item.getNumFlights() / 365.0) << endl;


        displayAvgNumFlights(currRoot->right);             //, visit);
    }
}

/* In order traverses the Binary Search tree <Airport> airports
 * Displays the Airport Object with Max number of Passengers in a formatted table
 * Specifically displays the Airport name, code, and number of Passengers
 */
template <typename T>
void BinarySearchTree<T>::maxNumPassengersTraverse() const{
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    maxNumPassengers(root);//, visit);
}
template <typename T>
void BinarySearchTree<T>::maxNumPassengers(Node<T> *currRoot) const {
    int width = 20;
    T item = currRoot->getItem();

    if (currRoot->right == nullptr) {
        cout << left << setw(65) <<  item.getName() <<
             left << setw(width) << item.getCode() <<
             left << setw(width) << fixed << setprecision(0) << item.getNumPassengers() << endl;
    }
    else {
        maxNumPassengers(currRoot->right);             //, visit);
    }

} //end maxNumPassengers()

/* In order traverses the Binary Search tree <Airport> airports
 * Displays the Airport Object with Max number of freight in a formatted table
 * Specifically displays the Airport name, code, and number of freight
 */
template <typename T>
void BinarySearchTree<T>::maxFreightTraverse() const{
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    maxFreight(root);//, visit);
}
template <typename T>
void BinarySearchTree<T>::maxFreight(Node<T> *currRoot) const {
    int width = 20;
    T item = currRoot->getItem();

    if (currRoot->right == nullptr) {
        cout << left << setw(65) <<  item.getName() <<
             left << setw(width) << item.getCode() <<
             left << setw(width) << fixed << setprecision(0) << item.getFreight() << endl;
    }
    else {
        maxFreight(currRoot->right);             //, visit);
    }

} //end maxFreight()

/* In order traverses the Binary Search tree <Airport> airports
 * Displays the Airport Object with Max number of Flights in a formatted table
 * Specifically displays the Airport name, code, and number of Flights
 */
template <typename T>
void BinarySearchTree<T>::maxNumFlightsTraverse() const{
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    maxNumFlights(root);//, visit);
}
template <typename T>
void BinarySearchTree<T>::maxNumFlights(Node<T> *currRoot) const {
    int width = 20;
    T item = currRoot->getItem();

    if (currRoot->right == nullptr) {
        cout << left << setw(65) <<  item.getName() <<
             left << setw(width) << item.getCode() <<
             left << setw(width) << fixed << setprecision(0) << item.getNumFlights() << endl;
    }
    else {
        maxNumFlights(currRoot->right);             //, visit);
    }
} //end maxNumFlights()

/* In order traverses the Binary Search tree <Airport> airports
 * Displays the Airport Object with Min number of Passengers in a formatted table
 * Specifically displays the Airport name, code, and number of Passengers
 */
template <typename T>
void BinarySearchTree<T>::minNumPassengersTraverse() const{
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    minNumPassengers(root);//, visit);
}
template <typename T>
void BinarySearchTree<T>::minNumPassengers(Node<T> *currRoot) const {
    int width = 20;
    T item = currRoot->getItem();

    if (currRoot->left == nullptr) {
        cout << left << setw(65) <<  item.getName() <<
             left << setw(width) << item.getCode() <<
             left << setw(width) << fixed << setprecision(0) << item.getNumPassengers() << endl;
    }
    else {
        minNumPassengers(currRoot->left);             //, visit);
    }

} //end minNumPassengers()

/* In order traverses the Binary Search tree <Airport> airports
 * Displays the Airport Object with Min number of freight in a formatted table
 * Specifically displays the Airport name, code, and number of freight
 */
template <typename T>
void BinarySearchTree<T>::minFreightTraverse() const{
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    minFreight(root);//, visit);
}
template <typename T>
void BinarySearchTree<T>::minFreight(Node<T> *currRoot) const {
    int width = 20;
    T item = currRoot->getItem();

    if (currRoot->left == nullptr) {
        cout << left << setw(65) <<  item.getName() <<
             left << setw(width) << item.getCode() <<
             left << setw(width) << fixed << setprecision(0) << item.getFreight() << endl;
    }
    else {
        minFreight(currRoot->left);             //, visit);
    }

} //end minFreight()

/* In order traverses the Binary Search tree <Airport> airports
 * Displays the Airport Object with Min number of Flights in a formatted table
 * Specifically displays the Airport name, code, and number of Flights
 */
template <typename T>
void BinarySearchTree<T>::minNumFlightsTraverse() const{
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    minNumFlights(root);//, visit);
}
template <typename T>
void BinarySearchTree<T>::minNumFlights(Node<T> *currRoot) const {
    int width = 20;
    T item = currRoot->getItem();

    if (currRoot->left == nullptr) {
        cout << left << setw(65) <<  item.getName() <<
             left << setw(width) << item.getCode() <<
             left << setw(width) << fixed << setprecision(0) << item.getNumFlights() << endl;
    }
    else {
        minNumFlights(currRoot->left);             //, visit);
    }

} //end minNumFlights()

/* In order traverses the Binary Search tree <Airport> airports
 * Specifically searches for the Airport code that matches user input
 * Finds the Airport object and changes and displays the old and new num passengers.
 * @param string UserInput is the input done by the user for what they are searching for.
 */
template <typename T>
void BinarySearchTree<T>::changeNumPassengersTraverse(string userInput) { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    changeNumPassengers(root, userInput);//, visit);

}

template <typename T>
void BinarySearchTree<T>::changeNumPassengers(Node<T>* currRoot, string userInput) {//, void visit(T& item)) const {
    if(currRoot != nullptr){
        changeNumPassengers(currRoot->left, userInput);             //, visit);

        T item = currRoot->getItem();
        int newNumPassengers = 0;
        if(item.getCode() == userInput) {
            cout << "\nOld Airport information:" << endl;
            cout << item << "  ";
            cout << "\nEnter new number of Passengers: ";
            cin >> newNumPassengers;
            while (newNumPassengers < 0){
                cout << "\nInvalid...Entry cannot be negative..." << endl;
                cout << "Enter new number of Passengers: ";
                cin >> newNumPassengers;
            }
            item.setNumPassengers(newNumPassengers);
            cout << "\nNew Airport information:" << endl;
            cout << item << "  ";
        }
        //visit()
        changeNumPassengers(currRoot->right, userInput);             //, visit);
    }

} //end changeNumPassengers()

/* In order traverses the Binary Search tree <Airport> airports
 * Specifically searches for the Airport code that matches user input
 * Finds the Airport object and changes and displays the old and new amount of freight
 * @param string UserInput is the input done by the user for what they are searching for.
 */
template <typename T>
void BinarySearchTree<T>::changeFreightTraverse(string userInput) { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    changeFreight(root, userInput);//, visit);

}

template <typename T>
void BinarySearchTree<T>::changeFreight(Node<T>* currRoot, string userInput) {//, void visit(T& item)) const {
    if(currRoot != nullptr){
        changeFreight(currRoot->left, userInput);             //, visit);

        T item = currRoot->getItem();
        int newFreight = 0;
        if(item.getCode() == userInput) {
            cout << "\nOld Airport information:" << endl;
            cout << item << "  ";
            cout << "\nEnter new amount of Freight: ";
            cin >> newFreight;
            while (newFreight < 0){
                cout << "\nInvalid...Entry cannot be negative..." << endl;
                cout << "\nEnter new amount of Freight: ";
                cin >> newFreight;
            }
            item.setFreight(newFreight);
            cout << "\nNew Airport information:" << endl;
            cout << item << "  ";
        }
        //visit()
        changeFreight(currRoot->right, userInput);             //, visit);
    }

}//end changeFreight()


/* In order traverses the Binary Search tree <Airport> airports
 * Specifically searches for the Airport code that matches user input
 * Finds the Airport object and changes and displays the old and new num flights.
 * @param string UserInput is the input done by the user for what they are searching for.
 */
template <typename T>
void BinarySearchTree<T>::changeNumFlightsTraverse(string userInput) { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    changeNumFlights(root, userInput);//, visit);

}

template <typename T>
void BinarySearchTree<T>::changeNumFlights(Node<T>* currRoot, string userInput) {//, void visit(T& item)) const {
    if(currRoot != nullptr){
        changeNumFlights(currRoot->left, userInput);             //, visit);

        T item = currRoot->getItem();
        int newNumFlights = 0;
        if(item.getCode() == userInput) {
            cout << "\nOld Airport information:" << endl;
            cout << item << "  ";
            cout << "\nEnter new number of Flights: ";
            cin >> newNumFlights;
            while (newNumFlights < 0){
                cout << "\nInvalid...Entry cannot be negative..." << endl;
                cout << "Enter new number of Flights: ";
                cin >> newNumFlights;
            }
            item.setNumFlights(newNumFlights);
            cout << "\nNew Airport information:" << endl;
            cout << item << "  ";
        }
        //visit()
        changeNumFlights(currRoot->right, userInput);             //, visit);
    }

} //end changeNumFlights()







//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------







//traversal
template <typename T>
void BinarySearchTree<T>::inorderTraverse() const { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    inorder(root);//, visit);
}


template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* currRoot) const {//, void visit(T& item)) const {
    if(currRoot != nullptr){
        inorder(currRoot->left);             //, visit);

        T item = currRoot->getItem();
        cout << item << "  ";
        //visit()
        inorder(currRoot->right);             //, visit);
    }

}


//traversal
template <typename T>
void BinarySearchTree<T>::preorderTraverse() const { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    preorder(root);//, visit);
}


template <typename T>
void BinarySearchTree<T>::preorder(Node<T>* currRoot) const {//, void visit(T& item)) const {
    if(currRoot != nullptr){

        //visit()
        T item = currRoot->getItem();
        cout << item << "  ";

        preorder(currRoot->left);             //, visit);

        preorder(currRoot->right);             //, visit);
    }

}//end preorder

template <typename T>
void BinarySearchTree<T>::postorderTraverse() const { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    postorder(root);//, visit);

}

template <typename T>
void BinarySearchTree<T>::postorder(Node<T>* currRoot) const {

    if(currRoot != nullptr){

        postorder(currRoot ->left);

        postorder(currRoot ->right);

        T item = currRoot->getItem();
        cout << item << "  ";

    }
}




const int COUNT = 10;

// Function to print binary tree in 2D
// It does reverse inorder traversal
//
//  From:  https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
template <typename T>
void BinarySearchTree<T>::print2DUtil(Node<T>* currRoot, int space)
{
    // Base case
    if (currRoot == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(currRoot->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << currRoot->getItem() << "\n";

    // Process left child
    print2DUtil(currRoot->left, space);
}




// Wrapper over print2DUtil()
//  From:  https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
template <typename T>
void BinarySearchTree<T>::print2D()
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}


#endif //CTP_250_LAB_7_BINARYSEARCHTREE_H
