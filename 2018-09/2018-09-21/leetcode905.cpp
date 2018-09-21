class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int pos = 0, len = A.size();
        
        for (int i = 0; i < len; i++)
        {
            if (~A[i] & 1)
            {
                swap(A[i], A[pos++]);
            }
        }
        return A;
    }
};