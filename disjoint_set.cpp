#include <bits/stdc++.h>

using namespace std;

class DisjointSet{
	//0 .. n - 1
	public:
		DisjointSet() : arr(NULL), count(NULL), size(0) {}
		DisjointSet(int x) : arr(new int[x]), count(new int[x]), size(x) {
			for(int i = 0; i < x; i++) 
				arr[i] = i, count[i] = 0;
		}
		bool isSameSet(int x, int y);
		int findSet(int x);
		void unionSet(int x, int y);
	private:
		int *arr;
		int *count;
		int size;
};

bool DisjointSet::isSameSet(int x, int y){
	return findSet(x) == findSet(y);
}

int DisjointSet::findSet(int x){
	if(arr[x] == x) return arr[x];
	return arr[x] = findSet(arr[x]);
}

void DisjointSet::unionSet(int x, int y){
	arr[findSet(x)] = findSet(y);
}

int main(){

	return 0;
}