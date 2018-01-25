class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int len = arr.size();
        
        int cut = 0;
        int res = 0;
        for(int i = 0; i < len; i++)
        {
            if(arr[i] > cut) cut = arr[i];
            if(i == cut) res += 1;
        }
        return res;
    }
};