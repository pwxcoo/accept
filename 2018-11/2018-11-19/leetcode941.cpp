class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3 || A[0] >= A[1]) return false;
        bool up = true;
        for (int i = 2; i < n; i++) {
            if (A[i - 1] < A[i]) {
                if (!up) return false;
            } else if (A[i - 1] > A[i]) {
                if (up) up = false;
            } else return false;
        }
        return !up;
    }
};