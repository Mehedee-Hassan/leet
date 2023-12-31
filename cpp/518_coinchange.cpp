class Solution {
public:
    int change(int amount, vector<int>& coins) {
     
        // mark all target ways as 0 
        vector<int>dp(amount+1,0);
        
        // 0 target can be made using no coin which is 1 way
        dp[0] = 1;
        
        // for each coin check their contribution from c to target
        for(int coin : coins)
        {
            for(int i=coin;i<=amount;i++)
            {
                // if we can make current value x more ways which is making complement value in x ways
                // if complement value is not made yet then it will have 0 
                // and also current target will get 0 ways for current coin
                dp[i] += dp[i-coin];
            }
        }
        
        return dp[amount];
    }
};
