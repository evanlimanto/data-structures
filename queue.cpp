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

class Queue{
    public:
        Queue() : head(NULL), tail(NULL), size(0) {}
        void print();
        void push(int x);
        void pop();
        bool empty();
        int getSize();
        int front();
        int back();
        void updateSize(int x);
    private:
        Node *head;
        Node *tail;
        int size;
};
void Queue::print(){
    Node *cur = head;
    bool middle = false;
    printf("size : %d, front : %d, back : %d\n",this->getSize(),this->front(),this->back());
    while(cur != NULL){
        if(middle) printf(" - ");
        middle = true;
        printf("%d",cur->getVal());
        cur = cur->getNext();
    }
    puts("");
}
void Queue::push(int x){
    if(head == NULL && tail == NULL){
        head = new Node(x);
        tail = head;
    }
    else{
        tail->setNext(new Node(x));
        tail = tail->getNext();
    }
    this->updateSize(this->getSize() + 1);   
}
void Queue::pop(){
    Node *tmp = head;
    head = head->getNext();
    delete tmp;
    tmp = NULL;
    this->updateSize(this->getSize() - 1);
}
bool Queue::empty(){
    return (this->getSize() == 0);
}
int Queue::getSize(){
    return size;
}
void Queue::updateSize(int x){
    size = x;
}
int Queue::front(){
    return head->getVal();
}
int Queue::back(){
    return tail->getVal();
}
int main(){
    Queue q;
    q.push(1);
    q.print();
    q.push(2);
    q.print();
    q.push(3);
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();

    return 0;
}