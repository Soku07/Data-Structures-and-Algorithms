typedef struct Tree_Node
{
    char data;
    Tree_Node* left;
    Tree_Node* right;
};
typedef struct Node
{
    Tree_Node* data;
    Node* next;
};