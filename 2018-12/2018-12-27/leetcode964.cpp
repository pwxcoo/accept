class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pos = (target % x) * 2, neg = (x - target % x) * 2;
        target /= x;
        
        int k = 1;
        for (; target > 0; target /= x, k++) {
            int cur = target % x;
            int pos2 = min(pos + cur * k, neg + (cur + 1) * k);
            int neg2 = min(pos + (x - cur) * k, neg + (x - cur - 1) * k);
            pos = pos2, neg = neg2;
        }
        
        return min(pos, k + neg) - 1;
    }
};