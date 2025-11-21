#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2*i + 1, right = 2*i + 2, largest = i;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return -1;
        }
        return heap[0];
    }

    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty() {
        return heap.size() == 0;
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(40);
    pq.push(10);
    pq.push(50);
    pq.push(30);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Top: " << pq.top() << endl;

    pq.pop();
    cout << "After pop: ";
    pq.display();

    return 0;
}
