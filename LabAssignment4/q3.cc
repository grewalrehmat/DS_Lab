#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, x;

    cout << "Enter even number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    int half = n / 2;
    queue<int> first;

    for (int i = 0; i < half; i++) {
        first.push(q.front());
        q.pop();
    }

    cout << "Interleaved queue: ";
    while (!first.empty()) {
        cout << first.front() << " ";
        first.pop();

        cout << q.front() << " ";
        q.pop();
    }
}
