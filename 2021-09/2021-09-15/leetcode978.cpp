class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        if (len <= 1) {
            return len;
        }
        
        vector<int> dp(len);
        dp[0] = 1;
        dp[1] = arr[0] == arr[1] ? 1 : 2; 
        int res = max(dp[0], dp[1]);
        for (int i = 2; i < len; i++) {
            if (arr[i - 2] > arr[i - 1] && arr[i] > arr[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else if (arr[i - 2] < arr[i - 1] && arr[i] < arr[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = arr[i] == arr[i - 1] ? 1 : 2;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};