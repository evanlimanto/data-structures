#include <bits/stdc++.h>

using namespace std;

class Heap{
    public:
        Heap() : arr(new int[0]), size(0), capacity(0) {}
        Heap(int x) : arr(new int[x]), size(0), capacity(x) {}
        void push(int x);
        void pop();
        int top();
        bool empty();
        int getSize();
        void updateSize(int x);
        void bubbleUp(int idx);
        void bubbleDown(int idx);
    private:
        int *arr;
        int size;
        int capacity;
};

void Heap::push(int x){
    int sz = this->getSize();
    if(capacity == sz) assert(0);
    arr[sz] = x;
    bubbleUp(sz);
    this->updateSize(sz + 1);
}

void Heap::pop(){
    int sz = this->getSize();
    if(sz == 0) assert(0);
    swap(arr[0], arr[sz - 1]);
    this->updateSize(sz - 1);
    bubbleDown(0);
}

int Heap::top(){
    int sz = this->getSize();
    if(sz == 0) assert(0);
    return arr[0];
}

bool Heap::empty(){
    return (this->getSize() == 0);
}

int Heap::getSize(){
    return size;
}

void Heap::updateSize(int x){
    size = x;
}

void Heap::bubbleUp(int idx){
    if(idx == 0) return;
    if(arr[idx] > arr[idx>>1]) swap(arr[idx], arr[idx>>1]);
    bubbleUp(idx >> 1);
}

void Heap::bubbleDown(int idx){
    int sz = this->getSize();
    int left = (idx << 1) + 1;
    int right = (idx << 1) + 2;
    int largestidx = idx;
    
    if(left < sz && arr[largestidx] < arr[left]){
        largestidx = left;
    }
    if(right < sz && arr[largestidx] < arr[right]){
        largestidx = right;
    }

    if(largestidx != idx){
        swap(arr[idx], arr[largestidx]);
        bubbleDown(largestidx);
    }
}

int main(){
    Heap pq(1000000);
    pq.push(1);
    printf("%d\n",pq.top());
    pq.push(5);
    printf("%d\n",pq.top());
    pq.push(30);
    printf("%d\n",pq.top());
    pq.push(1);
    printf("%d\n",pq.top());
    pq.push(25);
    printf("%d\n",pq.top());
    pq.push(35);
    printf("%d\n",pq.top());
    pq.pop();
    printf("%d\n",pq.top());
    pq.pop();
    printf("%d\n",pq.top());
    pq.pop();
    printf("%d\n",pq.top());
    pq.pop();
    printf("%d\n",pq.top());
    pq.pop();
    printf("%d\n",pq.top());
    
    return 0;
}