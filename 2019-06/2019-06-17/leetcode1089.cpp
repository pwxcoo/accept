class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        int n = arr.size();
        if (n == 0) return;

        bool zero = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) zero = true;

            if (!q.empty()) {
                q.push(arr[i]);
                arr[i] = q.front();
                q.pop();
            }

            if (zero) {
                q.push(0);
                zero = false;
            }
        }
    }
};