#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool match(string s1, string s2) {
    if (s1.length() > s2.length()) {
        return false;
    }

    for (int i=0; i<s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    return 0;
}
