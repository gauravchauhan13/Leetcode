class MyCircularDeque {
private:
    vector<int> dq;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) {
        dq.resize(k);
        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        dq[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        dq[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        if (size == 1) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (size == 1) {
            front = 0;
            rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : dq[front];
    }

    int getRear() {
        return isEmpty() ? -1 : dq[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};