#ifndef C19_HEADER_H
#define C19_HEADER_H

//binaryTreeType class
class binaryTreeType
{
    //private member variables of the binaryTreeType class
    private:
        int numNodes;
        struct nodeType
        {
            int info;
            nodeType* lLink;
            nodeType* rLink;
        };

        nodeType* root;

    //Public member functions of the binaryTreeType class
    public:

        bool isEmpty() const { return root==nullptr; }

        void displayResults();
        void inorder(nodeType*);

        void insert(int);
        void deletion(int);

        void nodeCount(int e);
        int getNodeCount();

        binaryTreeType();

};


#endif // C19_HEADER_H
