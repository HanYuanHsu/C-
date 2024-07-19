#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> genParen(int n, vector<vector<string>> &dp)
    {
        // dp[i] is the collection of strings of well-formed, i pairs of parentheses 
        if (n == 0)
        {
            return {""};
        }

        if (n == 1) {
            vector<string> result = {"()"};
            dp.push_back(result);
            return result;
        }

        if (dp[n].size() > 0)
        {
            return dp[n];
        }

        for (int a = 0; a <= n-1; ++a)
        {
            vector<string> A = genParen(a, dp);
            vector<string> B = genParen(n-1 - a, dp);
            for (const string &s : A)
            {
                for (const string &t : B)
                {
                    string combined = "(" + s + ")" + t;
                    dp[n].push_back(combined);
                }
            }
        }

        return dp[n];
    }

    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+10, vector<string>());
        return genParen(n, dp);
    }
};

int main()
{
    // to do: test this
    // https://www.geeksforgeeks.org/dynamic-programming/
    Solution sol;
    for (auto &s : sol.generateParenthesis(3))
    {
        cout << s << endl;
    }

    /*
    terminate called after throwing an instance of 'std::bad_array_new_length'
  what():  std::bad_array_new_length
    */
}

// does the dynamic programming really work???
// search how recursive functions work in computer architecture
