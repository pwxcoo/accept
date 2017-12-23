class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cnt(10001, 0);
        for(int i : nums)
            cnt[i]++;
        
        int dp[10002];
        dp[1] = cnt[1];
        dp[2] = max(cnt[1], cnt[2]*2);
        for(int i = 3; i <= 10000; i++)
        {
            dp[i] = max(dp[i-2] + cnt[i]*i, dp[i-1]);            
        }
        
        return dp[10000];
    }
};