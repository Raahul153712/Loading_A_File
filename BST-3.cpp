#include "BST.h"

void BST::inorder(Node *n, ostream &os)
{
    if (!n) return;
    // because of the way c++ works, !n is equivalent to n == nullptr
    inorder(n->left,os);
    os << n->data << std::endl;
    inorder(n->right,os);
}
void BST::preorder(Node *n, ostream &os)
{
    if (!n) return;
    os << n->data << std::endl;
    preorder(n->left,os);
    preorder(n->right,os);
}

void BST::postorder(Node *n, ostream &os)
{
    if (!n) return;
    postorder(n->left, os);
    postorder(n->right,os);
    os << n->data << std::endl;
}

// altered the postorder traversal to handle my cleanup for the
// BST. This guarantees I delete each node after I am done using it
// to get to other nodes in the tree
void BST::destroy(Node *&n)
{
    if (!n) return;
    destroy(n->left);
    destroy(n->right);
    delete n;
    n = nullptr;
}

bool BST::insert(Node *&n, const string &val)
{ bool flag = false; // save the success of the insert
    if (!n)
    {
        n = new Node(val);
        return true;
    }
    if (val < n->data) flag = insert(n->left,val);
    else
        if (val > n->data) flag =  insert(n->right,val);
    return flag;
}
bool BST::remove(Node *&n, const string &val)
{
    bool flag = false; // save the success of the remove
    if (!n) return false;
    if (val < n->data) flag = remove(n->left,val);
    else
        if (val > n->data) flag = remove(n->right,val);
        else
        {
            // we need to determine what degree the deletion is
            // and which child to use when finishing the deletion
            
            Node *child = nullptr; // this is the child we will use: default to nullptr
            int deg = 0; // this is the degree of the node: default to 0
            // to save some lines of code, we test for the existence of a
            // right child first. If there is one, we increment degree by one
            // and set child = to the right child
            if (n->right)
            {
                deg++;
                child = n->right;
            }
            // now we test for the existence of a left child
            // If there is one, we increment degree by one and set
            // child = to the left child
            if (n->left)
            {
                deg++;
                child = n->left;
            }
            // at this point, degree will either be 0, 1, or 2.
            // if degree is 0 then the child is nullptr
            // if degree is 1, then the child will either be
            // left child or right child
            // if degree is 2, then the child will be the left child
            switch(deg)
            {
                    // handles degree 0 and degree 1 since they all involve the same
                    // basic steps after running the above code
                    // delete the node
                    // set it to the located child
                case 0:
                case 1:
                    delete n;
                    n = child;
                    break;
                    // handles the degree 2 deletion
                    // we have already set child to left
                    // so we just traverse right until there is no
                    // right child, then we copy the data in that child
                    // to the original node and call delete again from the
                    // left child of the node to complete the removal.
                case 2:
                    while (child->right)
                    {
                        child = child->right;
                    }
                    n->data = child->data;
                    flag = remove(n->left, child->data); // this approach inspired by code from GeeksForGeeks.org
                    //https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
                    break;
            }
            flag = true;
        }
    return flag;
}


bool BST::search(Node *n, const string &val)
{
    if (!n) return false;
    if (val < n->data) return search(n->left,val);
    if (val > n->data) return search(n->right,val);
    return true;
}

void BST::DeleteTree()
{
    rDeleteTree(root);
}

void BST::rDeleteTree(Node *&n)
{
    if(root == nullptr)
    {
        return;
    }
    rDeleteTree(n -> left);
    rDeleteTree(n -> right);
    delete root;
}

