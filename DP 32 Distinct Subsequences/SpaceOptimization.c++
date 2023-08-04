#include <bits/stdc++.h>
using namespace std;

int distinctSubsequences(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0);
    
    for (int i = 0; i <= n; i++) {
        prev[0] = 1; // One subsequence for any s1[i] when s2 is empty
    }
    for (int j = 1; j <= m; j++) {
        prev[j] = 0; // No subsequence for any s2[j] when s1 is empty
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                prev[j] = prev[j - 1] + prev[j];
            } else {
                prev[j] = prev[j];
            }
        }
    }
    return prev[m];
}

int main()
{

    string s1 = "babgbag";
    string s2 = "bag";

    cout << "The Count of Distinct Subsequences is "
         << distinctSubsequences(s1, s2);
}