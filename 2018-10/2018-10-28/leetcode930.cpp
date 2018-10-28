class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> m;
        m[0] = 1;
        int n = A.size();
        vector<int> sum(n + 1, 0);
        
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + A[i - 1];
            res += m[sum[i] - S];
            m[sum[i]]++;
        }
        return res;
    }
};