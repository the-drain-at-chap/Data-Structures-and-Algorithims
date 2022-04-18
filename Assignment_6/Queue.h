//abstract Queue class
template <typename E>
class Queue{
public:
  Queue(){}
  virtual ~Queue(){}
  //reinitialize the queue
  virtual void clear() = 0;
  //place item at end of queue
  virtual void enqueue(const E& item) = 0;
  //remove and return element at the front of Queue
  virtual E dequeue() = 0;
  //return: a copy of the front element
  virtual E frontValue() = 0;
  //return: number of elements in the Queue
  virtual int length() = 0;
  //return: true if queue is empty, false if not
  virtual bool isEmpty() = 0;
  //prints queue
  virtual void printQueue() = 0;
  //finds item in queue and returns it
  virtual E findItemInQueue(int index) = 0;
};
