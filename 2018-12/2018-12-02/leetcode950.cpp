class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        
        vector<int> res;
        res.push_back(deck[0]);
        for (int i = 1; i < deck.size(); i++) {
            int a = res.back(); res.pop_back();
            
            res.insert(res.begin(), a);
            res.insert(res.begin(), deck[i]);
        }
        return res;
    }
};