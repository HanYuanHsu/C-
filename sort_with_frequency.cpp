#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

struct freq {
    int n;
    int freq;
};

bool operator< (const freq& a, const freq& b)  {
    return a.freq < b.freq || (a.freq == b.freq && a.n < b.n);
}

vector<int> sort_by_freq(const vector<int>& arr) {
    unordered_map<int, int> count;
    for (int i=0; i<arr.size(); ++i) {
        if (count.find(arr[i]) == count.end()) {
            count[arr[i]] = 0;
        } else {
            ++count[arr[i]];
        }
    }

    vector<freq> arr_with_freq;
    for (auto num : arr) {
        arr_with_freq.push_back({num, count[num]});
    }

    sort(arr_with_freq.begin(), arr_with_freq.end());
    
    vector<int> result;
    for (auto& f : arr_with_freq) {
        result.push_back(f.n);
    }

    return result;
}

int main() {
    vector<int> v = {1, 1, 2, 2, 3, 5};
    for (auto n : sort_by_freq(v)) {
        cout << n << " ";
    }
}
