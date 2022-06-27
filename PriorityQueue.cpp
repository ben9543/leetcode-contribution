#include <vector>;
#include <algorithm>; // std::swap
using namespace std;

class PriorityQueue {
private:
  vector<int> heap;
  int parent(int index){ return floor((index-1)/2); }
  int left(int index){ return (index*2 + 1); }
  int right(int index){ return (index*2 + 2); }
  void swap(int i, int j){
    swap(this->heap[i], this->heap[j]);
  }
  
public:
  PriorityQueue(){
  }
  int size(){ return this->heap.size(); }
  bool isEmpty(){ return (this->heap.size()==0); }
  int peek(){ return this->heap[0]; }
  void push(){}
  int pop(){}
}
