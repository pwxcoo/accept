#include<cstdio>
#include<vector>
#include<unordered_map>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

typedef long long ll;
// copy n times starting at (x, y)  
void ncopy(const vector<int> &nums, int n, int m, ll &x, int &y) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)nums.size(); ++j) {
			if (y == m)
				y = 0, ++x;
			++y;
			if (y + nums[j] > m)
				y = 0, ++x;
			y += nums[j];
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> words;
	string str;
	while (cin >> str)
		words.push_back(str.size());

	// record nth copy starting at (x, y) => dict[y] = make_pair(n, x)  
	unordered_map<int, pair<int, ll>> dict;//c++ 11里面的  
	ll x = 1;
	int y = -1;
	for (int i = 1; i <= n; ++i) {
		ncopy(words, 1, m, x, y);
		if (dict.find(y) != dict.end()) { // find the repetend  
										  // fast forward to skip the repetend  
			ll remain = (n - i) % (i - dict[y].first);
			// add x by repetend's rows  
			x += (n - i) / (i - dict[y].first)*(x - dict[y].second);
			// copy the reset times  
			ncopy(words, remain, m, x, y);
			break;
		}
		// record ith copy starting at (x, y)  
		dict.emplace(y, make_pair(i, x));
	}
	printf("%lld %d\n", x, y);
	return 0;
}