#include <vector>;

class PriorityQueue {
private:
  vector<int> heap;
  
public:
  PriorityQueue(){
  }
  int size(){ return this->heap.size(); }
  bool isEmpty(){ return (this->heap.size()==0); }
  int peek(){ return this->heap[0]; }
  void push(){}
  int pop(){}
}
