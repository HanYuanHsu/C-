#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int visited[1001];
    for (int i=1; i<=n-1; ++i) {
        visited[i] = 0;
    }

    int current;
    int prev = 0;
    for (int i=0; i < n; ++i) {
        cin >> current;
        int abs_diff = abs(current - prev);
        if (abs_diff >= n || abs_diff <= 0) {
            cout << "Not jolly" << endl;
            return 0;
        }

        if (visited[abs_diff] == 1) {
            cout << "Not jolly" << endl;
            return 0;
        }

        visited[abs_diff] = 1;

        prev = current;
    }

    cout << "Jolly" << endl;
    return 0;
}
