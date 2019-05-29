class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k + 1);
        front = 0;
        rear = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if ((rear + 1) % data.size() == front) return false;

        data[rear] = value;
        rear = (rear + 1) % data.size();
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (front == rear) return false;

        front = (front + 1) % data.size();
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (front == rear) return -1;

        return data[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (front == rear) return -1;

        return data[(rear + data.size() - 1) % data.size()];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == rear;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear + 1) % data.size() == front;
    }
private:
    vector<int> data;
    int front;
    int rear;
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