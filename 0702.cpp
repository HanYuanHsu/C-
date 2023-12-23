#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    if (n < k) {
        cout << "NO RESULT";
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    set<int> kinds;

    int num;
    for (int i=0; i<n; ++i) {
        cin >> num;
        if (kinds.find(num) == kinds.end()) {
            minHeap.push(num);
        }
    }

    for (int i=0; i < k-1; ++i) {
        minHeap.pop();
    }
    cout << minHeap.top();

    return 0;
}
