#ifndef BINARYSIMPLE_H
#define BINARYSIMPLE_H
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class BinaryTree
{
public:

    struct Node
    {
        int data{-1};
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

    }

    int calculateDepth(int numberOfNodes)
    {
        int binaryDepth{1};
        int NodesTotal{0};
        for (binaryDepth = 1; NodesTotal < numberOfNodes; ++binaryDepth)
        {
            NodesTotal = ((pow(2, binaryDepth)) - 1);
        }
        return (binaryDepth - 1);
    }


    int calculateNumberOfLeaves(int numberOfNodes)
    {
        int binaryDepth{1};
        int NodesTotal{0};
        for (binaryDepth = 1; NodesTotal < numberOfNodes; ++binaryDepth)
        {
            NodesTotal = ((pow(2, binaryDepth)) - 1);
        }
        return (((pow(2, (binaryDepth - 1)))/2)-(NodesTotal - numberOfNodes));
    }


    int calculateNumberOfEmptyLeaves(int numberOfNodes)
    {
        int binaryDepth{1};
        int NodesTotal{0};
        for (binaryDepth = 1; NodesTotal < numberOfNodes; ++binaryDepth)
        {
            NodesTotal = ((pow(2, binaryDepth)) - 1);
        }
        return (NodesTotal - numberOfNodes);
    }

    int calculateFullSizeOfTree(int numberOfNodes)
    {
        int binaryDepth{1};
        int NodesTotal{0};
        for (binaryDepth = 1; NodesTotal < numberOfNodes; ++binaryDepth)
        {
            NodesTotal = ((pow(2, binaryDepth)) - 1);
        }
        return NodesTotal;
    }


    //Input parameter currently not implemented. Function is hard-coded
    void MakeNodes(int numberOfNodes)
    {
        int numberOfNodesLeft = numberOfNodes;
        int binaryDepth = calculateDepth(numberOfNodes);
        int numberOfLeaves = calculateNumberOfLeaves(numberOfNodes);
        int sizeOfFullTree = calculateFullSizeOfTree(numberOfNodes);

        std::vector<Node* > NPtr;
        NPtr.resize(sizeOfFullTree);
        for (int i = 0; i < sizeOfFullTree; ++i)
        {
            NPtr[i] = new Node();
        }

//        Node**NPtr;
//        NPtr = new Node*[numberOfNodes];

        //Creates all of the bottom leaves
        while (numberOfLeaves > 0)
        {
            //Debug text for reference
            //cout << "\n check 1" << ",  It is: " << numberOfLeaves << ", nodes left: " << numberOfNodesLeft;
            Node* n = NPtr[numberOfNodesLeft];
            n->data = numberOfNodesLeft;
            n->vsub = nullptr;
            n->hsub = nullptr;
            --numberOfNodesLeft;
            --numberOfLeaves;
        }


        //Creates the rest of the leaves
        while (numberOfNodesLeft > 1)
        {
            //Debug text for reference
            //cout << "\n check 1" << ",  It is: " << numberOfLeaves << ", nodes left: " << numberOfNodesLeft;
            Node* n = NPtr[numberOfNodesLeft];
            n->data = numberOfNodesLeft;

            if (NPtr[((numberOfNodesLeft*2)+1)])
            {
                if (NPtr[((numberOfNodesLeft*2)+1)]->data != -1)
                {
                    n->hsub = NPtr[((numberOfNodesLeft*2)+1)];
                }

            }
            if (NPtr[(numberOfNodesLeft*2)])
            {
                if (NPtr[(numberOfNodesLeft*2)]->data != -1)
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
            Node* n = NPtr[numberOfNodesLeft];
            n->data = numberOfNodesLeft;
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
