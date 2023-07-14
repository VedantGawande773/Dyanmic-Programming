#include<bits/stdc++.h>
using namespace std;

int solve(int day, int last, vector<vector<int>> &points) {
  // Base case
  if (day == 0) {
    int n = points[0].size();
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      if (i != last) {
        maxi = max(maxi, points[0][i]);
      }
    }
    return maxi;
  }

  int maxi = 0;
  for (int i = 0; i < 3; i++) {  // Iterate from 0 to 2 (inclusive)
    if (i != last) {
      int activity = points[day][i] + solve(day - 1, i, points);
      maxi = max(activity, maxi);
    }
  }
  return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
  return solve(n - 1, 3, points);
}

int main() {
  vector < vector < int > > points = {{10,40,70},
                                      {20,50,80},
                                      {30,60,90}};
  int n = points.size();
  cout << ninjaTraining(n, points);
}