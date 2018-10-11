#ifndef BINARYSIMPLE_H
#define BINARYSIMPLE_H
#include <iostream>
#include <cmath>
#include <vector>

//Binary tree (non-searchable)

using namespace std;

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

    int calculateDepth(int numberOfNodes)
    {
        int binaryDepth{1};
        int NodesTotal{0};
        for (binaryDepth = 1; NodesTotal < numberOfNodes; ++binaryDepth)
        {
            NodesTotal = static_cast<int>(((pow(2, binaryDepth)) - 1));
        }
        return (binaryDepth - 1);
    }


    int calculateNumberOfBottomLeaves(int numberOfNodes)
    {
        int binaryDepth{1};
        int NodesTotal{0};
        for (binaryDepth = 1; NodesTotal < numberOfNodes; ++binaryDepth)
        {
            NodesTotal = static_cast<int>(((pow(2, binaryDepth)) - 1));
        }
        return static_cast<int>((((pow(2, (binaryDepth - 1)))/2)-(NodesTotal - numberOfNodes)));
    }


    int calculateNumberOfEmptyLeaves(int numberOfNodes)
    {
        int binaryDepth{1};
        int NodesTotal{0};
        for (binaryDepth = 1; NodesTotal < numberOfNodes; ++binaryDepth)
        {
            NodesTotal = static_cast<int>(((pow(2, binaryDepth)) - 1));
        }
        return (NodesTotal - numberOfNodes);
    }

    int calculateFullSizeOfTree(int numberOfNodes)
    {
        int binaryDepth{1};
        int NodesTotal{0};
        for (binaryDepth = 1; NodesTotal < numberOfNodes; ++binaryDepth)
        {
            NodesTotal = static_cast<int>(((pow(2, binaryDepth)) - 1));
        }
        return NodesTotal;
    }


    //Input parameter currently not implemented. Function is hard-coded
    void MakeNodes(int numberOfNodes)
    {
        unsigned int numberOfNodesLeft = static_cast<unsigned int>(numberOfNodes);
        unsigned int numberOfLeaves = static_cast<unsigned int>(calculateNumberOfBottomLeaves(numberOfNodes));
        unsigned int sizeOfFullTree = static_cast<unsigned int>(calculateFullSizeOfTree(numberOfNodes));

        //Vector of pointers
        std::vector<Node* > NPtr;
        NPtr.resize(sizeOfFullTree);

//        for (unsigned int i = 0; i < sizeOfFullTree+1; ++i)
//        {
//            NPtr[i] = new Node();
//        }

//        Node**NPtr;
//        NPtr = new Node*[numberOfNodes];

        //Creates all of the bottom leaves //Warning - this code isn't necessary
        while (numberOfLeaves > 0)
        {
            //Debug text for reference
            //cout << "\n check 1" << ",  It is: " << numberOfLeaves << ", nodes left: " << numberOfNodesLeft;

            NPtr[numberOfNodesLeft] = new Node();
            Node* n = NPtr[numberOfNodesLeft];
            n->data = static_cast<int>(numberOfNodesLeft);
            n->vsub = nullptr;
            n->hsub = nullptr;
            --numberOfNodesLeft;
            --numberOfLeaves;
        }


        //Creates the rest of the leaves and/or sub trees
        while (numberOfNodesLeft > 1)
        {
            //Debug text for reference
            //cout << "\n check 1" << ",  It is: " << numberOfLeaves << ", nodes left: " << numberOfNodesLeft;
            NPtr[numberOfNodesLeft] = new Node();
            Node* n = NPtr[numberOfNodesLeft];
            n->data = static_cast<int>(numberOfNodesLeft);

            if (((numberOfNodesLeft*2)+1) <= static_cast<unsigned int>(numberOfNodes))
            {
                    n->hsub = NPtr[((numberOfNodesLeft*2)+1)];                
            }
            if ((numberOfNodesLeft*2) <= static_cast<unsigned int>(numberOfNodes))
            {
                {
                    n->vsub = NPtr[(numberOfNodesLeft*2)];
                }
            }
            --numberOfNodesLeft;
        }

        while (numberOfNodesLeft > 0)
        {
            //Debug text for reference
            //cout << "\n check 1" << ",  It is: " << numberOfLeaves << ", nodes left: " << numberOfNodesLeft;
            NPtr[numberOfNodesLeft] = new Node();
            Node* n = NPtr[numberOfNodesLeft];
            n->data = static_cast<int>(numberOfNodesLeft);
            root = n;

            if (NPtr[((numberOfNodesLeft*2)+1)])
            {
                n->hsub = NPtr[((numberOfNodesLeft*2)+1)];
            }
            if (NPtr[(numberOfNodesLeft*2)])
            {
                n->vsub = NPtr[(numberOfNodesLeft*2)];
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

};

#endif // BINARYSIMPLE_H
