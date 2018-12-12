class Solution {
public:
    bool compare(string a, string b, vector<int>& rank) {
        int i = 0, j = 0;
        while (i < a.length() || j < b.length()) {
            if (i >= a.length()) return true;
            if (j >= b.length()) return false;
            
            if (rank[a[i] - 'a'] > rank[b[j] - 'a']) return false;
            else if (rank[a[i] - 'a'] < rank[b[j] - 'a']) return true;
            i++, j++;
        }
        return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26, 0);
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;    
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compare(words[i], words[i + 1], rank)) {
                return false;
            }
        }
        return true;
    }
};