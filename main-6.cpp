//  main.cpp
//  Semester Project: Implementing an AVL
//
//  Created by Raahul Pathak on 23-Oct-2019
//  Copyright © 2019 Raahul Pathak. All rights reserved.


#include <iostream>
#include <fstream>
#include <string>
#include "AVL.h"
#include "BST.h"

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;
using std::ostream;
using std::ofstream;

int main()
{
    
    AVL *myAVL = new AVL();
    
    string x;
    string str;
    int sx = 10;
    string filename;
    ofstream file;
    while(sx != 0)
    {
    cout<<"Please enter '1' to create an empty AVL."<<endl;
    cout<<"Please enter '2' to insert a string into the current AVL."<<endl;
    cout<<"Please enter '3' to search for a string in the current AVL."<<endl;
    cout<<"Please enter '4' to remove a string from the current AVL."<<endl;
    cout<<"Please enter '5' to output the In-Order Traversal of the current AVL."<<endl;
    cout<<"Please enter '6' to output the Pre-Order Traversal of the current AVL."<<endl;
    cout<<"Please enter '7' to output the Post-Order Traversal of the current AVL."<<endl;
    cout<<"Please enter '8' to save the Post-Order Traversal of the current AVL to a user specified filename."<<endl;
        cout<<"Please enter '9' to load a file."<<endl;
    cout<<"Please enter '0' to exit the program."<<endl;
    
    getline(cin, x);
    try
    {
        sx = stoi(x, nullptr);
    }
    catch(...)
    {
        
    }
    
    switch(sx)
    {
        case 1: //Create an empty AVL. This should warn the user that they are deleting the existing AVL and ask them if they wish to proceed. Remind the user that they can save the contents of their existing AVL to a file.
            
            myAVL = new AVL();
            break;
            
        case 2: //Insert a string into the current AVL.
            
            cout<<"Please enter something."<<endl;
            getline(cin, str);
            myAVL -> insert(str);
            break;
        
        case 3: //Search for a string in the current AVL.
            
            cout<<"Please enter the phrase that you want to search for."<<endl;
            getline(cin, str);
            if (myAVL -> search(str) == true)
            {
                cout<<"The phrase was found." <<endl;
            }
            else
                cout<<"The phrase was not found."<<endl;
                
            break;
        case 4: //Remove a string from the current AVL.
            
            cout<<"Please enter the phrase you wish to remove."<<endl;
            getline(cin, str);
            myAVL -> remove(str);
            break;
            
        case 5: //Output the In-Order Traversal of the current AVL.
            
            myAVL -> inorder(cout);
            break;
            
        case 6: //Output the Pre-Order Traversal of the current AVL.
            
            myAVL -> preorder(cout);
            break;
            
        case 7: //Output the Post-Order Traversal of the current AVL.
            
            myAVL -> postorder(cout);
            break;
            
        case 8: //Save the Post-Order Traversal of the current AVL to a user specified filename.
            
            cout<<"Please enter a filename." <<endl; //creates the file
            getline(cin, filename);
            filename = "/Users/Raahul/"+filename +".txt";
            file.open (filename);
            
            myAVL -> postorder(file); //Write contents of Post-Order Traversal to file
            
            file.close(); //Close the file
            
            break;
            
        case 9: //Load the file
            
            myAVL = new AVL();
            cout<<"Please enter a filename." <<endl; //creates the file
            getline(cin, filename);
            filename = "/Users/Raahul/"+filename +".txt";
            myAVL -> LoadFile(filename);
            break;
            
        case 0: //Exit the program
            break;
            
        default: //code to be execulted if n doesn't match any cases
        {
            cout<<"This was not a valid option. Please try again"<<endl;
            break;
        }
    }
     
    }
    
    return 0;
}
