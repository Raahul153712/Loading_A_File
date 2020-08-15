#pragma once
#include "BST.h"


class AVL : public BST
{
    
private:
    int height(Node *n);
    int BF(Node *n);
    void rightRotate(Node *&n);
    void leftRotate(Node *&n);
    void balance(Node *&n);
    void UpdateHeight(Node *&n);
    
protected:
    bool insert(Node *&n, const string &val);
    bool remove(Node *&n, const string &val);
    
public:
    AVL():BST() {}
    ~AVL() { BST::destroy(root);}
    
    bool insert(const string &val)
    {
        return insert(root,val);
        
    }
    bool remove(const string &val)
    {
        return remove(root,val);
        
    }
    void LoadFile(string userfile);
    
};

