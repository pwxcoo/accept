class Solution {
    public int findLength(int[] A, int[] B) {
        int[][] dp = new int[B.length + 1][A.length + 1];
        int res = 0;
        for(int i = 0; i <= B.length; i++)
        {
            for(int j = 0; j <= A.length; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                    continue;
                }
                
                if(A[j - 1] == B[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = Math.max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
}