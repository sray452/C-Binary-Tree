/*
Programmer: Ray, Stephen

Course: CSC161

Submission Date: [12/06/2021]

Function definitions used in the C19_Main program.

*/

#include "C19_Header.h"

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

//The insert() function accepts an integer as an argument and adds this number to the binary tree
void binaryTreeType::insert(int d)
{
    nodeType* trailCurrent = new nodeType;
    nodeType* parent;

    trailCurrent->info = d;
    trailCurrent->lLink = NULL;
    trailCurrent->rLink = NULL;
    parent = NULL;

  //Check if tree is empty
  if(isEmpty())
  {
      root = trailCurrent;
  }

  else
  {
    nodeType* current;
    current = root;

    //-------------------------------------
    // Link the correct node to parent node
    //-------------------------------------

    while(current)
    {
        parent = current;

        if(trailCurrent->info > current->info)
        {
            current = current->rLink;
        }

        else
        {
            current = current->lLink;
        }

    }

    if(trailCurrent->info < parent->info)
    {
        parent->lLink = trailCurrent;
    }

    else
    {
        parent->rLink = trailCurrent;
    }

  }
}

//The deletion() function accepts an integer as an argument, locates this integer in the binary tree if possible and removes that node
void binaryTreeType::deletion(int d)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout << "The tree is empty." << endl;
        return;
    }

    nodeType* current;
    nodeType* parent;
    current = root;

    while(current != NULL)
    {
         if(current->info == d)
         {
            found = true;
            break;
         }

         else
         {
             parent = current;
             if(d>current->info) current = current->rLink;
             else current = current->lLink;
         }
    }

    //If the item to be deleted is not found, display message to user
    if(!found)
    {
        cout << "The number you entered is not in the current binary tree." << endl;
        return;
    }


    //Handling node with single child node
    if((current->lLink == NULL && current->rLink != NULL) || (current->lLink != NULL && current->rLink == NULL))
    {
       if(current->lLink == NULL && current->rLink != NULL)
       {
           if(parent->lLink == current)
           {
             parent->lLink = current->rLink;
             delete current;
           }
           else
           {
             parent->rLink = current->rLink;
             delete current;
           }
       }


       else
       {
          if(parent->lLink == current)
           {
             parent->lLink = current->lLink;
             delete current;
           }
           else
           {
             parent->rLink = current->lLink;
             delete current;
           }
       }

     return;

    }

		 //Check leaf nodes
		 if( current->lLink == NULL && current->rLink == NULL)
         {
             if(parent->lLink == current)
             {
                 parent->lLink = NULL;
             }

            else
            {
                 parent->rLink = NULL;
            }

            delete current;
            return;
         }


    //---------------------------------------------------
    //Number to be deleted is in a node with two children
    //---------------------------------------------------

    if (current->lLink != NULL && current->rLink != NULL)
    {
        nodeType* check;
        check = current->rLink;

        if((check->lLink == NULL) && (check->rLink == NULL))
        {
            current = check;
            delete check;
            current->rLink = NULL;
        }

        else
        {
            if((current->rLink)->lLink != NULL)
            {
                nodeType* lcurrent;
                nodeType* lcurrentp;
                lcurrentp = current->rLink;
                lcurrent = (current->rLink)->lLink;

                while(lcurrent->lLink != NULL)
                {
                   lcurrentp = lcurrent;
                   lcurrent = lcurrent->lLink;
                }

                current->info = lcurrent->info;
                delete lcurrent;
                lcurrentp->lLink = NULL;
           }

           else
           {
               nodeType* tmp;
               tmp = current->rLink;
               current->info = tmp->info;
		 	   current->rLink = tmp->rLink;
               delete tmp;
           }

        }
		 return;
    }

}

//The inorder() function calls the inorder() function to display the current binary tree
void binaryTreeType::displayResults()
{
  inorder(root);
}

//The inorder() function accepts a nodeType pointer as an argument and cycles through the nodes, leftnode, rightnode to display the list of numbers in the binary tree
void binaryTreeType::inorder(nodeType* p)
{
    if(p != NULL)
    {
        if(p->lLink)
        {
            inorder(p->lLink);
        }

        cout << " " << p->info << " ";

        if(p->rLink)
        {
            inorder(p->rLink);
        }
    }
    else
        return;
}

//The nodeCount() function accepts an integer as a parameter and alters the numNodes private variable
void binaryTreeType::nodeCount(int e)
{
    int node;

    if (e == 1)
    {
        node = numNodes + 1;
    }

    else if (e == -1)
    {
        node = numNodes - 1;
    }

    numNodes = node;
}

//Getter function returns the numNodes private member variable
int binaryTreeType::getNodeCount()
{
    return numNodes;
}

//Constructor
binaryTreeType::binaryTreeType()
{
    root = nullptr;
    numNodes = 0;
}




