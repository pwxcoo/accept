#include<cstdio>
#include<stack>
using namespace std;

int res[1000005];

int main()
{
	int n;

	while(scanf("%d", &n) != EOF){
		stack<int> st;
		int now = n, temp, pos = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			if (temp == now) {
				res[pos++] = temp;
				now--;
			}
			else {
				st.push(temp);
			}
		}
		while (!st.empty()) {
			int temp = st.top();
			res[pos++] = temp;
			st.pop();
		}

		for (int i = 0; i < n; i++) {
			i == n - 1 ? printf("%d\n", res[i]) : printf("%d ", res[i]);
		}
	}
    return 0;
}