// hdu1728.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int MAXN = 0x7fffffff;
int t, m, n;
char mg[105][105];
int visit[105][105][4];
bool in[105][105][4];
int k, startx, starty, targetx, targety;
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };

struct now
{
	int x;
	int y;

	int direction;
	now(int _x, int _y, int _direction) : x(_x), y(_y), direction(_direction) {};
};

bool bfs()
{
	queue<now> q;
	
	for (int i = 0; i < 4; i++)
	{
		q.push(now(startx, starty, i));
		visit[startx][starty][i] = 0;
		in[startx][starty][i] = true;
	}
		
	
	while (!q.empty())
	{
		now t = q.front(); q.pop(); in[t.x][t.y][t.direction] = false;
		
		if (t.x == targetx && t.y == targety) 
			return true;
		for (int i = 0; i < 4; i++)
		{
			int nextx = t.x + dir[i][0];
			int nexty = t.y + dir[i][1];
			int nexttime = visit[t.x][t.y][t.direction] + ((i == t.direction) ? 0 : 1);
			if (nextx <= 0 || nextx > m || nexty <= 0 || nexty > n || mg[nextx][nexty] != '.' || nexttime > k || nexttime >= visit[nextx][nexty][i]) continue;

			visit[nextx][nexty][i] = nexttime;
			if (!in[nextx][nexty][i])
			{
				q.push(now(nextx, nexty, i));
				in[nextx][nexty][i] = true;
			}
		}
		
	}
	return false;
}


int main()
{
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d %d", &m, &n);
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf(" %c", &mg[i][j]);
				for (int k = 0; k < 4; k++)
				{
					visit[i][j][k] = MAXN;
					in[i][j][k] = 0;
				}
			}
				
		scanf("%d %d %d %d %d", &k, &starty, &startx, &targety, &targetx);
		
		bfs() ? printf("yes\n") : printf("no\n");
	}

    return 0;
}

