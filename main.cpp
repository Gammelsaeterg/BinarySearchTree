#include <iostream>
#include "binarynode.h"
#include "binarysimple.h"

using namespace std;

int main()
{
    //The binary search tree
//    int input{};
//    int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

//    BinarySearchTree<int> MyTree{};



//    cout << "Printing the tree in order\nBefore adding numbers\n";

//    MyTree.PrintInOrder();

//    for(int i = 0; i < 16; i++)
//    {
//        MyTree.AddLeaf(TreeKeys[i]);
//    }

//    cout << "Printing the tree in order\nAfter adding numbers\n";

//    MyTree.PrintInOrder();
//    cout << "Hello World!" << endl;

//    MyTree.PrintChildren(MyTree.ReturnRootKey());


//    cout << "The smallest value in the tree is: " << MyTree.FindSmallest() << "\n";

//    cout << "Enter a key value to delete. Enter -1 to stop the process\n";
//    while(input != -1)
//    {
//        cout << "Delete node: ";
//        cin >> input;
//        {
//            if(input != -1)
//            {
//                cout << endl;
//                MyTree.RemoveNode(input);
//                MyTree.PrintInOrder();
//                cout << endl;
//            }
//        }
//    }



    //The binary tree

    cout << "Adding nodes from the bottom: \n";
    BinaryTree MyBottomUpTree(10);

    MyBottomUpTree.PrintInOrder();

    return 0;
}
