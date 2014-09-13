#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        Node(int x) : next(NULL), prev(NULL), val(x) {}
        Node() : next(NULL), prev(NULL), val(0) {}
        void setVal(int x);
        void setPrev(Node *x);
        void setNext(Node *x);
        int getVal();
        Node *getNext();
        Node *getPrev();
    private:
        Node *next;
        Node *prev;
        int val;
};

void Node::setVal(int x){
    if(this == NULL) return;
    val = x;
}
void Node::setPrev(Node *x){
    if(this == NULL) return;
    prev = x;
}
void Node::setNext(Node *x){
    if(this == NULL) return;
    next = x;
}
int Node::getVal(){
    if(this == NULL) return 0;
    return val;
}
Node* Node::getNext(){
    if(this == NULL) return NULL;
    return next;
}
Node* Node::getPrev(){
    if(this == NULL) return NULL;
    return prev;
}

class LinkedList{
    public:
        LinkedList() : head(NULL), tail(NULL), size(0) {}
        void addNode(int x);
        void print();
        void remove(int x);
        void insert(int pos, int x);
        int getSize();
        void modifySize(int x);
    private:
        Node* head;
        Node* tail;
        int size;
};
void LinkedList::addNode(int x){
    if(head == NULL){
        head = new Node(x);
        tail = head;
    }
    else{
        tail->setNext(new Node(x));
        tail->getNext()->setPrev(tail);
        tail = tail->getNext();
    }
    this->modifySize(this->getSize() + 1);
}
void LinkedList::print(){
    Node *cur = head;
    bool middle = false;
    printf("Size: %d\n",this->getSize());
    while(cur != NULL){
        if(middle) printf(" -> ");
        middle = true;
        printf("%d",cur->getVal());
        cur = cur->getNext();
    }
    puts("");
}
void LinkedList::remove(int x){
    Node *cur = head;
    int counter = 0;
    while(cur != NULL){
        ++counter;
        if(cur->getVal() == x){
            if(counter == 1){
                head = cur->getNext();
                head->setPrev(NULL);
                delete cur;
                cur = NULL;
                this->modifySize(this->getSize() - 1);
                break;
            }
            else if(counter == this->getSize()){
                tail = cur->getPrev();
                tail->setNext(NULL);
                delete cur;
                cur = NULL;
                this->modifySize(this->getSize() - 1);
                break;
            }
            else{
                cur->getPrev()->setNext(cur->getNext());
                cur->getNext()->setPrev(cur->getPrev());
                delete cur;
                cur = NULL;
                this->modifySize(this->getSize() - 1);
                break;
            }
        }
        cur = cur->getNext();
    }
}
void LinkedList::insert(int pos, int x){
    //inserts a new node with value x after pos-th node
    assert(pos <= this->getSize());

    if(pos == 0){
        if(this->getSize() == 0) this->addNode(x);
        else{
            Node *tmp = new Node(x);
            head->setPrev(tmp);
            tmp->setNext(head);
            head = tmp;
        }
        this->modifySize(this->getSize() + 1);
        return;
    }
    
    Node *cur = head;
    int counter = 1;
    while(counter < pos){
        cur = cur->getNext();
        ++counter;
    }
    Node *tmp = new Node(x);
    tmp->setNext(cur->getNext());
    cur->getNext()->setPrev(tmp);
    tmp->setPrev(cur);
    cur->setNext(tmp);

    this->modifySize(this->getSize() + 1);
}
int LinkedList::getSize(){
    return size;
}
void LinkedList::modifySize(int x){
    size = x;
}

int main(){
    LinkedList list;
    list.addNode(1);
    list.print();
    list.addNode(3);
    list.print();
    list.insert(0,0);
    list.print();
    list.insert(2,2);
    list.print();
    list.insert(4,4);
    list.print();
    list.remove(0);
    list.print();
    list.remove(4);
    list.print();
    list.remove(2);
    list.print();
    list.remove(1);
    list.print();
    list.remove(3);
    list.print();
    list.addNode(1);
    list.print();
    list.addNode(3);
    list.print();
    list.insert(0,0);
    list.print();
    list.insert(2,2);
    list.print();
    list.insert(4,4);
    list.print();
    list.remove(0);
    list.print();
    list.remove(4);
    list.print();
    list.remove(2);
    list.print();
    list.remove(1);
    list.print();
    list.remove(3);
    list.print();
    return 0;    
}
