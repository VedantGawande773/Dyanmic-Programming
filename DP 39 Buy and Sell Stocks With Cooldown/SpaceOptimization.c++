    #include <bits/stdc++.h>
    using namespace std;

    int stockProfit(vector<int> &prices){
        int n = prices.size();

    vector<int> cur(2,0);
    vector<int> front1(2,0);
    vector<int> front2(2,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
            int profit;

                if (buy == 0) {
                    profit = max(-prices[ind] + front1[1], 0 + front1[0]);                
                } 
                
                if(buy == 1){
                    profit = max(prices[ind] + front2[0],  0 + front1[1]);
                }

                 cur[buy] = profit;                
            }
            front2 = front1;
            front1 = cur;
        }

        return cur[0];
    }


    int main() {

    vector<int> prices {4,9,0,4,10};
                                    
    cout<<"The maximum profit that can be generated is "<<stockProfit(prices);
    }