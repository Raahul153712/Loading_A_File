#include "AVL.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using std::string;
using std::vector;
using std::stack;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

int MAX(int x, int y) { return (x < y) ? y : x;}


int AVL::height(Node *n)
{
    if (!n) return 0;
    return n->height;
}
int AVL::BF(Node *n)
{
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

void AVL::rightRotate(Node *&n)
{
    // rotate n, n->left to the right
    Node *left = n->left;
    Node *hold = left->right;
    
    left->right = n;
    n->left = hold;
    
    n->height = MAX(height(n->left),height(n->right))+1;
    left->height = MAX(height(left->left),height(left->right))+1;
    
    n = left;
}
void AVL::leftRotate(Node *&n)
{
    // rotate n, n->right to the left
    Node *right = n->right;
    Node *hold = right->left;
    
    right->left = n;
    n->right = hold;
    
    n->height = MAX(height(n->left),height(n->right))+1;
    right->height = MAX(height(right->left),height(right->right))+1;
    
    n = right;
}

void AVL::balance(Node *&n)
{
    int balance = BF(n);
    
    if (balance > 1)
    {
        if (BF(n->left) < 0) leftRotate(n->left);
        rightRotate(n);
    }
    
    if (balance < -1)
    {
        if (BF(n->right) > 0) rightRotate(n->right);
        leftRotate(n);
    }
}
bool AVL::insert(Node *&n, const string &val)
{
    bool flag = false;
    if (!n)
    {
        n = new Node(val);
        return true;
    }
    if (val < n->data)
    {
        flag = insert(n->left,val);
    }
    
    else if (val > n->data)
    {
        flag = insert(n->right,val);
    }
    
    else return false;
    
    n->height = MAX(height(n->left),height(n->right)) + 1;
    balance (n);
    return flag;
}
bool AVL::remove(Node *&n, const string &val)
{
    bool flag = false;
    if (!n) return false;
    if (val < n->data)
    {
        flag = remove(n->left,val);
    }
    else if (val > n->data)
    {
        flag = remove(n->right,val);
    }
    else {
        Node *child = nullptr;
        int deg = 0;
        if (n->right)
        {
            deg++;
            child = n->right;
        }
        if (n->left)
        {
            deg++;
            child = n->left;
        }
        switch(deg)
        {
            case 0:
            case 1:
                delete n;
                n = child;
                break;
            case 2:
                while (child->right)
                {
                    child = child->right;
                }
                n->data = child->data;
                flag = remove(n->left,child->data);
                break;
        }
        flag = true;
    }
    
    if (!n) return flag;
    n->height = MAX(height(n->left),height(n->right)) + 1;
    balance(n);
    
    
    return flag;
}
void AVL::LoadFile(string file)
{
    vector <string> AVLData;
    //declare an ifstream here
    // open the file .open(file)
    // check to see if it is open .is_open()
    // if failed to open ... .close() and return
    
    ifstream fileinput; fileinput.open(file);
    if(!fileinput.is_open())
    {
        fileinput.close();
        return;
    }
    while(getline(fileinput, file))// read from the ifstream not from the console
    {
        AVLData.push_back(file);
    }
    string value;
    stack<Node *> s;
    vector <string>::reverse_iterator rev_iter;//create the reverse iterator
    rev_iter = AVLData.rbegin();
    root = new Node (*rev_iter); //keep in mind that the stack back function
    s.push(root);
    for(++rev_iter; rev_iter!= AVLData.rend(); ++rev_iter)
    {
        Node *current = new Node(*rev_iter);
        Node *temp = nullptr;
        Node *top = nullptr;
        while(!s.empty())
        {
            top = s.top();
            if(current -> data >= top -> data)
            {
                break;
            }
            temp = top;
            s.pop();
        }
        if(temp)
        {
            temp -> left = current;
        }
        else
        {
            top = s.top();
            top -> right = current;
        }
        s.push(current);
        
    }
    fileinput.close();
    
   UpdateHeight(root);
}

void AVL::UpdateHeight(Node *&root)
{
    if(!root)
    {
        return;
    }
    UpdateHeight(root -> left);
    UpdateHeight(root -> right);
    root->height = MAX(height(root->left),height(root->right))+1;
}
