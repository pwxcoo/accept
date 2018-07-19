class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
  		int n = A.size();
  		vector<pair<int, int>> vb;
  		for (int i = 0; i < n; i++) vb.push_back(make_pair(B[i], i));
  		sort(A.begin(), A.end());
  		sort(vb.begin(), vb.end());
  		vector<int> ans(n, 0);
  		int i1 = 0, i2 = n-1;
  		int m = n, j = 0;
  		while (j < m){
  			if (A[i1] > vb[j].first){
  				ans[vb[j].second] = A[i1];
  				i1++;
  				j++;
  			}
  			else {
  				ans[vb[i2].second] = A[i1];
  				i2--;
  				i1++;
  				m--;
  			}
  		}     
  		return ans;
    }
};