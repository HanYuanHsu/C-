#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int B;
    vector<int> h;
    make_heap(h.begin(), h.end()); // heapsort
    cin >> N >> B;
    
    int H; // height
    for (int i=0; i<N; ++i) {
        cin >> H;
        h.push_back(H);
    }

    sort_heap(h.begin(), h.end());

    int sum = 0;
    int i;
    for (i=0; i<N; ++i) {
        sum += h[i];
        if (sum >= B) {
            cout << i << endl;
            return 0;
        }
    }

    return -1;
}

