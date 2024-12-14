#include <iostream>
using namespace std;

class queue {
private:
    int size;
    string* q;
    int front;
    int rear;

public:
    queue(int size) {
        this->size = size;
        q = new string[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueueFront(string x) {
        if (isFull()) {
            cout << "Queue is full. Cannot add element." << endl;
        } else {
            if (isEmpty()) {
                front = 0;
                rear = 0;
            } else {
                front = (front - 1 + size) % size;
            }
            q[front] = x;
        }
    }

    void enqueueRear(string x) {
        if (isFull()) {
            cout << "Queue is full. Cannot add element." << endl;
        } else {
            if (isEmpty()) {
                front = 0;
                rear = 0;
            } else {
                rear = (rear + 1) % size;
            }
            q[rear] = x;
        }
    }

    string dequeueFront() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove elements." << endl;
            return "";
        }
        string data = q[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return data;
    }

    string dequeueRear() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove elements." << endl;
            return "";
        }
        string data = q[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
        return data;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    queue q(size);

    int choice;
    string value;

    while (true) {
        cout << "Enter your choice:\n1. Enqueue from front\n2. Enqueue from rear\n3. Dequeue from front\n4. Dequeue from rear\n5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue from front: ";
                cin >> value;
                q.enqueueFront(value);
                break;
            case 2:
                cout << "Enter value to enqueue from rear: ";
                cin >> value;
                q.enqueueRear(value);
                break;
            case 3:
                value = q.dequeueFront();
                if (value != "") {
                    cout << "Dequeued from front: " << value << endl;
                }
                break;
            case 4:
                value = q.dequeueRear();
                if (value != "") {
                    cout << "Dequeued from rear: " << value << endl;
                }
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}


