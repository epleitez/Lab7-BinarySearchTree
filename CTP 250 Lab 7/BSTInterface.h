//
// Created by Emely Pleitez on 10/27/22.
//

#ifndef CTP_250_LAB_7_BSTINTERFACE_H
#define CTP_250_LAB_7_BSTINTERFACE_H


template <class T>
class BSTInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual bool add(const T& newItem) = 0;
    virtual void removeItem(const T& delItem) = 0;
    virtual void clearTree() = 0;
    virtual bool contains(const T& findItem) const = 0;


    //TODO traversals
    virtual void inorderTraverse() const = 0;   //void visit(T&)
    virtual void preOrderTravers() const = 0;
    virtual void postOrderTraverse() const = 0;

private:

};


#endif //CTP_250_LAB_7_BSTINTERFACE_H
