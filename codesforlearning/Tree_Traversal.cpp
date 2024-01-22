#include<iostream>
#include<queue>
class Tree{
    public:
    struct Tnode{
        int data;
        Tnode *left;
        Tnode *right;
        Tnode(int value):data(value),left(nullptr),right(nullptr){}

    };
   
    public:
     Tree(int data) {
        root= new Tnode(data);}

    void Trees(int data,Tnode * &root){
        if(root==nullptr){
            root=new Tnode(data);
        }
        else if (root->data>data){
        Trees(data,root->left);}
        else if (root->data<data){
        Trees(data,root->right);}
    }
    void Trees(int data){
        Trees(data,root);
    }
    void InOrder(Tnode *root){
        if (root==nullptr)
        return;
        else{
            InOrder(root->left);
            std::cout<<root->data<<" ";
            InOrder(root->right);

        }
       
    }
    void PreOrder(Tnode * root){
        if (root==nullptr)
        return;
        else{
            std::cout<<root->data<<" ";
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
    void PostOrder(Tnode * root){
        if(root==nullptr)
        {return;}
        else{
            PostOrder(root->left);
            PostOrder(root->right);
            std::cout<<root->data<<" ";
        }
    }
    void InOrder(){
        InOrder(root);
    }
    void PreOrder(){
        PreOrder(root);
    }
    void PostOrder(){
        PostOrder(root);

    }
    void LevelT(Tnode * root);
    
Tnode *root;

};
std::queue<Tree::Tnode *>myQueue;
void Tree::LevelT(Tnode *root){
    if (root==nullptr){
        return;
    }
    myQueue.push(root);
    Tnode * temp=nullptr;
    while(!myQueue.empty()){
    Tnode* temp = myQueue.front();
    myQueue.pop();
    if(temp->left!=nullptr){
    myQueue.push(temp->left);}
    if(temp->right!=nullptr){
    myQueue.push(temp->right);}
    std::cout<<temp->data<< " ";
    }

}

int main() {
    Tree myTree(50);
    myTree.Trees(30);
    myTree.Trees(70);
    myTree.Trees(20);
    myTree.Trees(40);

    // Print the tree elements in-order
    std::cout << "In-Order Traversal: ";
    myTree.InOrder();
    std::cout<<std::endl<<"Pre-Order ";
    myTree.PreOrder();
    std::cout<<std::endl<<"Post-Order ";
    myTree.PostOrder();
    std::cout << std::endl << "Level-Order: ";
    myTree.LevelT(myTree.root);

    return 0;
}