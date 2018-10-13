//Binary tree
#include <iostream>
#include "binarynode.h"
#include "binarysimple.h"

#include "windows.h" //Included to make certain UTF-8 symbols appear on Windows


using namespace std;
using namespace TheBinaryTree;

int main()
{
    //Included to make certain UTF-8 symbols appear on Windows
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);





    //The binary tree
    cout << "Adding nodes from the bottom and upwards... \n\n";

    int numberOfNodes{10};
    BinaryTree MyBottomUpTree(numberOfNodes);

    cout << "In-order traversal of the binary-tree: ";
    MyBottomUpTree.PrintInOrder();

    cout << endl << endl << "Visual structure: \n";
    //MyBottomUpTree.PrintHeap(MyBottomUpTree.binaryTreeArray, numberOfNodes); ////Uncomment this if the print function below does not work
    MyBottomUpTree.PrintTree(MyBottomUpTree.root);






    //The binary search tree
    int input{};
    int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

    BinarySearchTree<int> MyTree{};



    cout << "Printing the tree in order\nBefore adding numbers\n";

    MyTree.PrintInOrder();

    for(int i = 0; i < 16; i++)
    {
        MyTree.AddLeaf(TreeKeys[i]);
    }

    cout << "Printing the tree in order\nAfter adding numbers\n";

    MyTree.PrintInOrder();
    cout << "Hello World!" << endl;

    MyTree.PrintChildren(MyTree.ReturnRootKey());


    cout << "The smallest value in the tree is: " << MyTree.FindSmallest() << "\n";

    cout << "Enter a key value to delete. Enter -1 to stop the process\n";
    while(input != -1)
    {
        cout << "Delete node: ";
        cin >> input;
        {
            if(input != -1)
            {
                cout << endl;
                MyTree.RemoveNode(input);
                MyTree.PrintInOrder();
                cout << endl;
            }
        }
    }


    return 0;
}
