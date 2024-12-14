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
            return front == -1 ;
        }

        bool isFull() {
            return (rear+1)%size == front;
        }

        void Equeue(string x) {
            if (isFull()) {
                cout << "Queue is full. Cannot add element." << endl;
            } else {
                if (isEmpty()) {
                    front = 0;
                    rear = 0;
                } else {
                    rear = (rear+1)%size;
                }
                q[rear] = x;
            }
        }

        string dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty. Cannot remove elements." << endl;
                return "0";
            }
            string data = q[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front+1)%size;
            }
            return data;
        }
};

int main() {
    cout << "Enter the capacity to deliver order: ";
    int capacity;
    cin >> capacity;
    queue order(capacity);

    int choice;
    do {
        cout << "Press 1 to order" << endl;
        cout << "Press 2 to deliver order" << endl;
        cout << "Press 3 to exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter your order: ";
            string ord;
            cin >> ord;
            order.Equeue(ord);
        } else if (choice == 2) {
            string ord = order.dequeue();
            if (ord != "0") {
                cout << "Order: " << ord << endl;
            }
        }
    } while (choice != 3);

    return 0;
}

