typedef struct Tree_Node
{
    int data;
    Tree_Node* left;
    Tree_Node* right;
};
typedef struct Node
{
    Tree_Node* data;
    Node* next;
    Node* back;
};