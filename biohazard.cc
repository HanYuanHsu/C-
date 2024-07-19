#include <vector>
#include <unordered_map>
#include <deque>
#include <set>
#include <iostream>
using namespace std;

int num_valid_intervals(int n, int m, int allergic[], int poisonous[]) {
    // n: bacteria 1 ~ n
    // m: length of allergic[] and poisonous[]
    // note: the index of each bacteria is 1-indexed

    unordered_map<int, int> die; // die[i] is the rightmost bacterium to the left of i
                                 // that cannot coexist with i

    for (int i=0; i<m; ++i) {
        die[poisonous[i]] = max(die[poisonous[i]], allergic[i]);        
    }

    int res = 0;
    int cur_die = 0;
    for (int r=1; r<=n; ++r) { // group the intervals by the right end r
        if (die.find(r) != die.end()) {
            cur_die = die[r];
        }
        res += (r - cur_die);
    }

    return res;
}

int main() {
    int n = 4, m = 2;
    int allergic[]  = {1, 2};
    int poisonous[] = {3, 4};

    cout << num_valid_intervals(n, m, allergic, poisonous) << endl;
    return 0;
}
