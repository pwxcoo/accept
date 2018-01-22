#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;
//temp


int visit[101];
int cnt[10000001];

int main()
{
	int n, m;
	string text;
	cin >> n >> m;
	getchar();
	getline(cin, text);

	int time = 0, len = text.length(), offset = 0, row = 0;
	int now = 0;
	memset(visit, 0, sizeof(visit));
	while (1) {
		int next = now + m - offset;	//next表示下一行从那个字符开始

		//如果下一行已经超出了text的长度，表示这一次结束了
		if (next >= len) {
			offset = len - now + 1;
			now = 0;
			cnt[time++] = row;
			continue;
		}
		

		if (text[next] != ' ' && text[next - 1] != ' ') {
			while (next - 1 >= 0 && text[next - 1] != ' ') {
				next--;
			}
		}

		row++;
		offset = 0;
		if (visit[next] == 1) {
			break;
		}
		else {
			visit[next] = 1;
		}

		now = next;
	}

	int res = 0;
	res += (n / time) * row;
	res += cnt[n % time];
	printf("%d\n", res);

    return 0;
}

