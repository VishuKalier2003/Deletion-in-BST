// Implementation of Deletion in Binary Tree
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    public:
    Node (int value)
    {
        data = value;
        left = NULL; right = NULL;
    }
};
class BinaryTree
{
    public:
    Node* root;
    Node* parent;
    BinaryTree ()
    {
        root = NULL;
        parent = NULL;
    }
    public:
    Node* InsertNodeInTree(Node* root, int value)
    {
        if(root == NULL)
            return new Node(value);
        if(value <= root -> data)
        {
            root -> left = InsertNodeInTree(root -> left, value);
            parent = root -> left;
        }
        if(value > root -> data)
        {
            root -> right = InsertNodeInTree(root -> right, value);
            parent = root -> right;
        }
        return root;
    }
    public:
    void PrintTree(Node* root)
    {
        if(root == NULL)
            return;
        PrintTree(root -> left);
        cout << "Node : " << endl;
        if(root -> left != NULL)
            cout << "\t" << root -> data << " ----> "<< root -> left -> data << "\t Left(Occupied)" << endl;
        else
            cout << "\t" << root -> data << "\t\t Left (Empty)" << endl;
        if(root -> right != NULL)
            cout << "\t" << root -> data << " ----> "<< root -> right -> data << "\t Left(Occupied)" << endl;
        else
            cout << "\t" << root -> data << "\t\t Left (Empty)" << endl;
        PrintTree(root -> right);
    }
    public:
    Node* FindNodeToDelete(Node* root, int val)
    {
        if(root -> data == val)
            return root;
        if(val <= root -> data)
            root -> left = FindNodeToDelete(root -> left, val);
        if(val > root -> data)
            root -> right = FindNodeToDelete(root -> right, val);
        return root;
    }
    public:
    Node* Predecessor(Node* root)
    {
        Node* t = root;
        while(t -> left != NULL)
        {
            t = t -> left;
            if(t -> right != NULL)
            {
                while(t -> right != NULL)
                {
                    t = t -> right;
                    return t;
                }
            }
        }
        return t;
    }
    public:
    void DeleteNode(Node* root, int val)
    {
        Node* temp = root -> left -> left;
        if(temp -> left == NULL && temp -> right == NULL)
            delete temp;
        else if(temp -> left != NULL && temp -> right != NULL)
        {
            while(temp -> left != NULL && temp -> right != NULL)
            {
                Node* pred = Predecessor(temp);
                int t1 = temp -> data;
                temp -> data = pred -> data;
                pred -> data = t1;
            }
            delete temp;
        }
        else
        {
            if(temp -> left != NULL)
            {
                while(temp -> left != NULL)
                {
                    int t1 = temp -> data;
                    temp -> data = parent -> data;
                    parent -> data = t1;
                }
                delete temp;
            }
            else if(temp -> right != NULL)
            {
                while(temp -> right != NULL)
                {
                    int t1 = temp -> data;
                    temp -> data = parent -> data;
                    parent -> data = t1;
                }
                delete temp;
            }
        }
    }
};
int main()
{
    Node* root = NULL;
    BinaryTree binarytree;
    int x, s;
    cout << "Enter root Node value : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);
    cout << "Enter number of Nodes to Insert : ";
    cin >> s;
    for(int i = 0; i < s; i++)
    {
        cout << "Enter Node value to be Inserted in the Tree : ";
        cin >> x;
        root = binarytree.InsertNodeInTree(root, x);
    }
    binarytree.PrintTree(root);
    cout << "Enter Node value to be deleted : ";
    cin >> x;
    binarytree.DeleteNode(root, x);
    binarytree.PrintTree(root);
    return 0;
}