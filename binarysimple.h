#ifndef BINARYSIMPLE_H
#define BINARYSIMPLE_H
#include <iostream>
#include <cmath>
#include <vector>

//Binary tree (non-searchable) //////////////////

using namespace std;


namespace TheBinaryTree{

class BinaryTree
{
public:

    struct Node
    {
        int data{};
        Node* vsub;
        Node* hsub;
    };
    Node* root{nullptr};

    //Code needed for printing tree with a visual structure, an array containing all the nodes
    int *binaryTreeArray{};

    BinaryTree()
    {
    }


    BinaryTree(int numberOfNodes)
    {
        MakeNodes(numberOfNodes);
    }

    ~BinaryTree()
    {
        //Needs a function to delete the binary tree
    }

    //Code needed for printing tree with a visual structure, stores the tree in an array
    void SaveArray(int numberOfNodes, std::vector<Node* > NPtr)
    {
        int *arrayTemp = new int[numberOfNodes+1];
        for(int i = 0; i < numberOfNodes; ++i)
        {
            arrayTemp[i] = NPtr[static_cast<unsigned int>(i+1)]->data;
        }
        binaryTreeArray = arrayTemp;
    }

    void MakeNodes(int numberOfNodes)
    {
        unsigned int numberOfNodesLeft = static_cast<unsigned int>(numberOfNodes);

        //Vector of pointers
        std::vector<Node* > NPtr;
        NPtr.resize(static_cast<unsigned int>(numberOfNodes+1));

        //Creates nodes from the bottom and upwards
        while (numberOfNodesLeft > 0)
        {
            //Creates the node with the current highest index
            NPtr[numberOfNodesLeft] = new Node();
            Node* n = NPtr[numberOfNodesLeft];

            //Sets the node's value to its index
            n->data = static_cast<int>(numberOfNodesLeft);

            //Connects the node to child nodes if they exist
            if (((numberOfNodesLeft*2)+1) <= static_cast<unsigned int>(numberOfNodes)) //Checks if child node exists
                n->hsub = NPtr[((numberOfNodesLeft*2)+1)];
            if ((numberOfNodesLeft*2) <= static_cast<unsigned int>(numberOfNodes)) //Checks if child node exists
                n->vsub = NPtr[(numberOfNodesLeft*2)];
            if (numberOfNodesLeft <= 1)
            {
                //Creates the root
                root = n;
                SaveArray(numberOfNodes, NPtr); //Code needed for printing tree with a visual structure, stores the tree in an array
            }
            --numberOfNodesLeft;
        }
    }

    void PrintInOrder()
    {
        PrintInOrder(root);
    }

    void PrintInOrder(Node* Ptr)
    {
        if(root != nullptr)
        {
            //In-order traversal
            if (Ptr->vsub != nullptr)
            {
                PrintInOrder(Ptr->vsub);
            }

            std::cout << Ptr->data << ", ";

            if (Ptr->hsub != nullptr)
            {
                PrintInOrder(Ptr->hsub);
            }
        }
        else
        {
            std::cout << "The tree is empty \n";
        }
    }


    //Borrowed and edited code 1: https://stackoverflow.com/a/18725868
    void PrintSpace(int count){
        for (int x = 0; x<count; x++) {
            cout<<"-";
        }
    }
    void PrintHeap(int heap[], int size){
        cout<<endl;
        int height = static_cast<int>(ceil(log(size)+1)); //+1 handle the last leaves
        int width = static_cast<int>(pow(2, height)*height);
        int index = 0;
        for (int x = 0; x <= height; x++)
        { //for each level of the tree
            for (int z = 0; z < pow(2, x); z++)
            { // for each node on that tree level
                int digitWidth = 1;
                if(heap[index] != 0) digitWidth = static_cast<int>(floor(log10(abs(heap[index]))) + 1);
                PrintSpace(static_cast<int>(width/(pow(2,x))-digitWidth));
                if(index<size)cout<<heap[index++];
                else cout<<"-";
                PrintSpace(static_cast<int>(width/(pow(2,x))));
            }
            cout<<endl;
        }
    }
    //End of borrowed code 1



    //Borrowed and edited code 2: https://stackoverflow.com/a/50650932
    void PrintTree(Node* root)
    {
            if (root == nullptr)
            {
                    return;
            }

            cout << root->data << endl;
            PrintSubtree(root, "");
            cout << endl;
    }


    void PrintSubtree(Node* root, const string& prefix)
    {
            if (root == nullptr)
            {
                    return;
            }

            bool hasLeft = (root->vsub != nullptr);
            bool hasRight = (root->hsub != nullptr);

            if (!hasLeft && !hasRight)
            {
                    return;
            }

            cout << prefix;
            cout << ((hasLeft  && hasRight) ? "├── " : "");
            cout << ((!hasLeft && hasRight) ? "└── " : "");

            if (hasRight)
            {
                    bool printStrand = (hasLeft && hasRight && (root->hsub->hsub != nullptr || root->hsub->vsub != nullptr));
                    string newPrefix = prefix + (printStrand ? "│   " : "    ");
                    cout << root->hsub->data << endl;
                    PrintSubtree(root->hsub, newPrefix);
            }

            if (hasLeft)
            {
                    cout << (hasRight ? prefix : "") << "└── " << root->vsub->data << endl;
                    PrintSubtree(root->vsub, prefix + "    ");
            }
    }
    //End of borrowed code 2




};
}

#endif // BINARYSIMPLE_H
