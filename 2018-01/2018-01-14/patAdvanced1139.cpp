#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//1. 解法暴力
//2. 因为有 0000， -0000 这样的数据，所以用字符串处理
//3. 同性的时候，遍历好朋友时会直接遍历到对方，这个时候应该continue


int n, m;
unordered_map<string, unordered_set<string>> relations;

bool is_same_gender(string id1, string id2)
{
	if ((id1[0] == '-' && id2[0] == '-') || (id1[0] != '-' && id2[0] != '-')) return true;
	return false;
}

struct result
{
	string id1;
	string id2;
	result(string _x, string _y)
	{
		if (_x[0] == '-') id1 = _x.substr(1);
		else id1 = _x;
		if (_y[0] == '-') id2 = _y.substr(1);
		else id2 = _y;
	}
	void print()
	{
		cout << id1 << " " << id2 << endl;
	}
	bool operator<(const result&r)const
	{
		return id1 == r.id1 ? id2 < r.id2: id1 < r.id1 ;
	}
};

int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		char id1[6], id2[6];

		relations.clear();
		while (m--)
		{
			scanf("%s %s", id1, id2);
			relations[id1].insert(id2);
			relations[id2].insert(id1);
		}

		int q;
		scanf("%d", &q);
		while (q--)
		{
			vector<result> res; res.clear();
			scanf("%s %s", id1, id2);
			for (unordered_set<string>::iterator i = relations[id1].begin(); i != relations[id1].end(); i++)
			{
				if (!is_same_gender(id1, (*i)) || (*i) == string(id2)) continue;
				for (unordered_set<string>::iterator j = relations[id2].begin(); j != relations[id2].end(); j++)
				{
					if (!is_same_gender(id2, (*j)) || (*j) == string(id1)) continue;
					if (relations[(*i)].find(*j) != relations[(*i)].end())
					{
						res.push_back(result((*i), (*j)));
					}
				}
			}
			 
			sort(res.begin(), res.end());
			printf("%d\n", res.size());
			for (int i = 0; i < res.size(); i++)
				res[i].print();
		}
	}

    return 0;
}
