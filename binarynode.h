#ifndef BINARYNODE_H
#define BINARYNODE_H

//template <class T>
class BinarySearchTree
{

private:

    struct Node
    {
        int key;
        Node* left;
        Node* right;
    };

    Node* root;
    void AddLeafPrivate(int key, Node* Ptr);
    Node* CreateLeaf(int key);
    Node* ReturnNode(int key);
    void PrintInOrderPrivate(Node* Ptr);
    void PrintInPreOrderPrivate(Node* Ptr);
    Node* ReturnNodePrivate(int key, Node* Ptr);
    int FindSmallestPrivate(Node* Ptr);
    void RemoveNodePrivate(int key, Node* parent);
    void RemoveRootMatch();
    void RemoveMatch(Node* parent, Node* match, bool left);
    void RemoveSubtree(Node* Ptr);

public:

    BinarySearchTree();
    ~BinarySearchTree();
    void AddLeaf(int key);
    void PrintInOrder();
    void PrintPreOrder();
    int ReturnRootKey();
    void PrintChildren(int key);
    int FindSmallest();
    void RemoveNode(int key);


};


#endif // BINARYNODE_H
