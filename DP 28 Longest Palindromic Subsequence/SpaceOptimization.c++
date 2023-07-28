#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<int> prev(m+1,0), curr(m+1,0);
    for(int i=0;i<=n;i++){
        prev[0] = 0;
    }
    for(int i=0;i<=m;i++){
        prev[i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                curr[ind2] = 1 + prev[ind2-1];
            else
                curr[ind2] = 0 + max(prev[ind2],curr[ind2-1]);
        }
        prev = curr;
    }
    
    return curr[m];
}

int longestPalindromeSubsequence(string s){
    string t = s;
    reverse(s.begin(),s.end());
    return lcs(s,t);
}

int main() {

  string s= "bbabcbcab";
                                 
  cout<<"The Length of Longest Palindromic Subsequence is "<<
  longestPalindromeSubsequence(s);
}