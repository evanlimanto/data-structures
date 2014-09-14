#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        Node() : val(0), left(NULL), right(NULL) {}
        Node(int x) : val(x), left(NULL), right(NULL) {}
        int getVal();
        void setVal(int x);
        Node* getLeft();
        Node* getRight();
        void setLeft(Node *x);
        void setRight(Node *x);
    private:
        int val;
        Node *left;
        Node *right;
};

int Node::getVal(){
    return val;
}
void Node::setVal(int x){
    val = x;
}
Node* Node::getLeft(){
    if(this == NULL) return NULL;
    return left;
}
Node* Node::getRight(){
    if(this == NULL) return NULL;
    return right;
}
void Node::setLeft(Node *x){
    left = x;
}
void Node::setRight(Node *x){
    right = x;
}

class BST{
    public:
        BST() : root(NULL) {}
        void insert(int x);
        Node *insert(Node *cur, int x);
        void remove(int x);
        Node *remove(Node *cur, int x);
        bool find(int x);
        bool find(Node *cur, int x);
        void inorder(Node *cur);
        void inorder();
        Node *getNextLargest(Node *cur);
    private:
        Node *root;
};

void BST::insert(int x){
    root = insert(root, x);
}
bool BST::find(int x){
    return find(root, x);
}
Node* BST::insert(Node *cur, int x){
    if(cur == NULL) return new Node(x);
    
    int curval = cur->getVal();
    if(x < curval)
        cur->setLeft(insert(cur->getLeft(), x));
    else if(x > curval)
        cur->setRight(insert(cur->getRight(), x));
        
    return cur;
}
Node* BST::getNextLargest(Node *cur){
    cur = cur->getRight();
    while(cur->getLeft() != NULL){
        cur = cur->getLeft();
    }
    return cur;
}
void BST::remove(int x){
    root = remove(root, x);
}
Node* BST::remove(Node *cur, int x){
    if(cur == NULL) return NULL;

    int curval = cur->getVal();
    if(x < curval) 
        cur->setLeft(remove(cur->getLeft(), x));
    else if(x > curval) 
        cur->setRight(remove(cur->getRight(), x));
    else{
        if(cur->getLeft() == NULL || cur->getRight() == NULL){
            Node *tmp = (cur->getLeft()) ? cur->getLeft() : cur->getRight();
            if(tmp == NULL){
                tmp = cur;
                cur = NULL;
            }
            else{
                cur = tmp;
            }
            delete tmp;
        }
        else{
            Node* tmp = getNextLargest(cur);
            cur->setVal(tmp->getVal());
            cur->setRight(remove(cur->getRight(), tmp->getVal()));
        }
    }
    return cur;
}
bool BST::find(Node *cur, int x){
    if(cur == NULL) return false;

    int curval = cur->getVal();
    if(x < curval) return find(cur->getLeft(), x);
    else if(x > curval) return find(cur->getRight(), x);
    
    return true;
}
void BST::inorder(Node *cur){
    if(cur != NULL){
        inorder(cur->getLeft());
        printf("%d ",cur->getVal());
        inorder(cur->getRight());
    }
}
void BST::inorder(){
    inorder(root);
    puts("");
}
int main(){
    BST tree;
    tree.insert(18);
    tree.insert(223);
    tree.insert(100);
    tree.insert(2);
    tree.insert(23);
    tree.insert(45);
    tree.insert(1000);
    tree.insert(43);
    tree.inorder();
    tree.remove(2);
    tree.inorder();
    tree.remove(999);
    tree.remove(1000);
    tree.inorder();
    printf("Find %d: %d\n",18,tree.find(18));
    printf("Find %d: %d\n",19,tree.find(19));
    return 0;
}