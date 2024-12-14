#include <iostream>
using namespace std;

class queue {
    private:
        int size;
        string* q;
        int* ages;
        int front;
        int rear;

    public:
        queue(int size) {
            size = size;
            q = new string[size];
            ages = new int[size];
            front = -1;
            rear = -1;
        }

        bool isEmpty() {
            return front == -1 ;
        }

        bool isFull() {
            return (rear+1)%size == front;
        }

        void Equeue(string x, int age) {
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
                ages[rear] = age;
            }
        }

        string dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty. Cannot remove elements." << endl;
                return "0";
            }
            int max = front;
            for (int i = front+1; i <= rear; i++) {
                if (ages[i] > ages[max]) {
                    max= i;
                }
            }
            string data = q[max];
            
            for (int i = max; i < rear; i++) {
                q[i] = q[i+1];
                ages[i] = ages[i+1];
            }
            rear--;
            if (front > rear) {
                front = -1;
                rear = -1;
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
            cout << "\nEnter your order: ";
            string ord;
            cin >> ord;
            cout << "\nEnter your age: ";
            int age;
            cin >> age;
            order.Equeue(ord, age);
        } else if (choice == 2) {
            string ord = order.dequeue();
            if (ord != "0") {
                cout << "\nOrder: " << ord << endl;
            }
        }
    } while (choice != 3);

    return 0;
}

