
#include "bin_stack.cpp"
class Bin_Tree 
{
    private:
    Tree_Node* Root;
    Tree_Node* MakeNode();// Creates a leaf Node.
    public:
    Bin_Tree();
    void AddNode();
    void Pre_order();
    // void Inorder();
};
