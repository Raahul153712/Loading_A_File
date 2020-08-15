#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using std::ostream;
using std::string;
using std::vector;
using std::stack;



// class description for a node of strings
class Node
{
public:
    string data; // string stored in node: defaults to ""
    int height; // height of node: defaults to 1
    Node *right; // right child: defaults to nullptr
    Node *left; // left child: defaults to nullptr
    
    Node():data(""),height(1),right(nullptr),left(nullptr){}
    Node(string data):data(data),height(1),right(nullptr),left(nullptr){}
};


//class description for a BST
class BST
{
private:
    
    // private methods to handle recursion
    void inorder(Node *n, ostream &os);
    void preorder(Node *n, ostream &os);
    void postorder(Node *n, ostream &os);
    bool insert(Node *&n, const string &val);
    bool remove(Node *&n, const string &val);
    bool search(Node *n, const string &val);
    void rDeleteTree(Node *&n);
protected:
    
    void destroy(Node *&n);
    Node *root;  // root: defaults to nullptr
    
public:
    BST(): root(nullptr){}
    ~BST() {destroy(root);}
    
    // public methods to forward the requests to the private methods
    void inorder(ostream &os) {inorder(root,os);}
    void preorder(ostream &os) {preorder(root,os);}
    void postorder(ostream &os) {postorder(root,os);}
    bool insert(const string &val) { return insert(root,val);}
    bool remove(const string &val) { return remove(root,val);}
    bool search(const string &val) { return search(root,val);}
    void DeleteTree();
    
};

