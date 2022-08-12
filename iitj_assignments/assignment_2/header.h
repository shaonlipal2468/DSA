template<typename T>
class Stack
{
    T *arr;
    int capacity,top;
  public:
    Stack();
    void push(T);
    T pop();
    bool isFull();
    bool isEmpty();
    void show_stack();
    int show_top();
};

template<typename T>
class Queue
{
    T *arr;
    int capacity,front,rear,size;
  public:
    Queue();
    void enQueue(T);
    T deQueue();
    bool isFull();
    bool isEmpty();
    void show_queue();
    int size_();
};
