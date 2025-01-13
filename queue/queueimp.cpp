#include<iostream>
using namespace std;

class Queue {
    public:
        int size;
        int f;
        int r;
        int* arr;

        Queue(int size) {
            this->size = size;
            this->f = this->r = -1;  // Initialize front and rear to -1
            this->arr = new int[size];
        }

        // Check if the queue is empty
        bool isEmpty() {
            return f == -1;  // Queue is empty if front is -1
        }

        // Check if the queue is full
        bool isFull() {
            return (r + 1) % size == f;  // Full when (rear+1) % size == front
        }

        // Enqueue an element
        void enqueue(int val) {
            if (isFull()) {
                cout << "This Queue is full" << endl;
            } else {
                if (f == -1) { // If queue was empty before enqueue
                    f = 0;  // Set front to 0
                }
                r = (r + 1) % size;  // Circular increment for rear
                arr[r] = val;
                cout << "Enqueued element: " << val << endl;
            }
        }

        // Dequeue an element
        int dequeue() {
            int a = -1;
            if (isEmpty()) {
                cout << "This Queue is empty" << endl;
            } else {
                a = arr[f];
                if (f == r) { // If there is only one element left
                    f = r = -1; // Reset to indicate the queue is empty
                } else {
                    f = (f + 1) % size;  // Circular increment for front
                }
            }
            return a;
        }

        // Destructor to release allocated memory
        ~Queue() {
            delete[] arr;
        }
};

int main() {
    Queue q(4);

    // Enqueue a few elements
    q.enqueue(12);
    q.enqueue(15);
    q.enqueue(1);
q.enqueue(2);
q.enqueue(10);
    // Dequeue elements
    cout << "Dequeuing element " << q.dequeue() << endl;
    cout << "Dequeuing element " << q.dequeue() << endl;
    cout << "Dequeuing element " << q.dequeue() << endl;

    // Enqueue more elements
    q.enqueue(45);
    q.enqueue(100);
    q.enqueue(200); // This will not enqueue as the queue is full
    q.enqueue(300);
    // Check if the queue is empty or full
    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    if (q.isFull()) {
        cout << "Queue is full" << endl;
    }
    cout<<"\nfront element:"<<q.arr[q.f];
    return 0;
}
