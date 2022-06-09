/*
Programmer: Ray, Stephen

Course: CSC161

Submission Date: [11/09/2021]

Function definitions used in the C19_Main program.

*/

#include <iostream>

// Include header file C18_Header.h

#include "C19_Header.h"


using namespace std;


 int main()
{
    //Display initial message
    cout << "Create a binary tree and count how many nodes are in the tree.\n" << endl;


    //Instantiate object userTree of the binaryTreeType class
    binaryTreeType userTree;

    //Declare local variables
    int userChoice;
    int temp;
    int removal;

    while(1)
    {
       cout << "Create and edit your binary tree. "<<endl;
       cout << "Enter 1 to insert a number into the tree\n";
       cout << "Enter 2 to print the current tree list.\n";
       cout << "Enter 3 to remove a number from the list.\n";
       cout << "Enter 4 to count the number of nodes currently in the list.\n";
       cout << "Enter 5 to quit.\n";

       cin >> userChoice;

       switch(userChoice)
       {
           case 1 : cout << "Enter a number to insert into the tree: ";
                    cin >> temp;
                    userTree.insert(temp);
                    break;

           case 2 : cout << "\nContents of binary tree." << endl;
                    userTree.displayResults();
                    userTree.nodeCount(1);
                    userTree.getNodeCount();
                    cout << endl;
                    break;

           case 3 : cout<<" Enter info to be deleted : ";
                    cin>>removal;
                    userTree.deletion(removal);
                    userTree.nodeCount(-1);
                    userTree.getNodeCount();
                    cout << endl;
                    break;

           case 4:  cout << userTree.getNodeCount() << "\n\n";
                    cout << endl;
                    break;

           case 5 : return 0;
                    break;
       }
    }
}
