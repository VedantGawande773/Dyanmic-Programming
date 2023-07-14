#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    // step 1 create a dp array
    vector<int> dp(n + 1);

    // step 2 Check base case
    dp[1] = 1;
    dp[0] = 0;

    // step 3 Convert recursive call into dp call
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;

    return 0;
}