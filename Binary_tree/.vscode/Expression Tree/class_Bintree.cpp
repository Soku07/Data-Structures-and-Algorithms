
#include "bin_stack.cpp"
class Bin_Tree 
{
    private:
    Tree_Node* Root;
    
    public:
    Tree_Node* MakeNode(char);// Creates a leaf Node.
    Bin_Tree();
    void AddNode(int, char);//pass 1 to add left child, pass 2 to add right child
    void Pre_order();
    void Inorder();
    void Postorder(Tree_Node*);
    void change_Root(Tree_Node*);
    // void Inorder();
};
