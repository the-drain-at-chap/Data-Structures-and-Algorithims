/* Implements all private variables, public variables, default constructor, and destructor needed for a Queue based on
   doubly linked lists. Descriptions of function are in Queue.h
*/
#include "Queue.h"
#include "DLList.h"
#include <stdexcept>


template <typename E>
class DLLQueue : public Queue<E>{
private:
  DLList<E>* queue;
  int size = 0;
public:
  DLLQueue();
  ~DLLQueue();
  void clear();
  void enqueue(const E& item);
  E dequeue();
  E frontValue();
  int length();
  bool isEmpty();
  E findItemInQueue(int index);
  void printQueue();
};

template <typename E>
DLLQueue<E>::DLLQueue(){
  queue = new DLList<E>();
}

template <typename E>
DLLQueue<E>::~DLLQueue(){
  delete queue;
}

template <typename E>
void DLLQueue<E>::clear(){
  queue = new DLList<E>();
  size = 0;
}

template <typename E>
void DLLQueue<E>::enqueue(const E& item){
  queue->insertBack(item);
  size++;
}

template <typename E>
E DLLQueue<E>::dequeue(){
  if(isEmpty()){
    throw std::invalid_argument("Queue is empty!");
  }
  else{
    E item = frontValue();
    queue->removeFront();
    size--;
    return item;
  }
}

template <typename E>
E DLLQueue<E>::frontValue(){
  if(isEmpty()){
    throw std::invalid_argument("Queue is empty!");
  }
  else{
    return queue->peekFront();
  }
}

template <typename E>
int DLLQueue<E>::length(){
  return size;
}

template <typename E>
bool DLLQueue<E>::isEmpty(){
  return queue->isEmpty();
}

template <typename E>
void DLLQueue<E>::printQueue(){
  queue->printList();
}

template <typename E>
E DLLQueue<E>::findItemInQueue(int index){
  return queue->findItem(index);
}
