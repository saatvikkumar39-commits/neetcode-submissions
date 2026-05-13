class MyCircularQueue {
public:
    vector<int> arr;
    int front;
    int back;
    int size;
    int capacity;
    MyCircularQueue(int k) {
        size=0;
        capacity=k;
        arr.resize(capacity,0);
        front=-1;back=-1;
    }
    
    bool enQueue(int value) {
        if(front==-1 && back==-1){
            front=0;back=0;
            arr[back]=value;
            size++;
            return true;
        }
        if(size>=capacity) return false;
        back=(back+1)%capacity;
        arr[back]=value;
        size++;
        return true;

    }
    
    bool deQueue() {
        if(size==0) return false;
        front=(front+1)%capacity;
        size--;
        if(size==0){
            front=-1;back=-1;
        }
        return true;
    }
    
    int Front() {
        return front==-1? -1:arr[front];
    }
    
    int Rear() {
        return back==-1? -1:arr[back];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size>=capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */