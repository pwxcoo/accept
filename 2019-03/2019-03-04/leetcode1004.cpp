class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();

        int left = 0, right = 0;
        int res = 0;
        while (right < n) {
            if (A[right] == 0) K--;
            right++;

            if (K < 0) {
                while (A[left++]) ;
                K++;
            }
            res = max(res, right - left);
        }

        return res;
    }
};