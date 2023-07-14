#include <bits/stdc++.h> 
using namespace std;

int solve(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    //base case
    if(j<0 || j>= matrix[0].size()) return -1e8;
    if(i == 0) return matrix[0][j];

    if(dp[i][j] != -1)
        return dp[i][j];

     int u = matrix[i][j] + solve(i-1,j,matrix,dp);
     int ld = matrix[i][j] + solve(i-1,j-1,matrix,dp);
     int rd = matrix[i][j] + solve(i-1,j+1,matrix,dp);

     return max(u,max(ld,rd));


}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int maxi = -1e8;
    for(int j=0;j<m;j++){
        maxi = max(maxi,solve(n-1,j,matrix,dp));
    }
    return maxi;
}

int main() {

  vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
  cout<<getMaxPathSum(matrix);
}