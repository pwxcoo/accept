#include<cstdio>

using namespace std;

int T, N;
const int MAXN = 1e5 + 5;
int num[MAXN];

int main()
{
    scanf("%d", &T);

    for (int tt = 1; tt <= T; tt++)
    {
        scanf("%d", &N);
        printf("Case %d:\n", tt);

        int res = 0x80000000, start = 1, now = 0, r_start, r_end;


        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &num[i]);

            now += num[i];

            if (now > res)
            {
                res = now;
                r_start = start;
                r_end = i;
            }

            if (now < 0)
            {
                now = 0;
                start = i + 1;
            }
        }

        printf("%d %d %d\n", res, r_start, r_end);
        if (tt != T) printf("\n");
    }

    return 0;
}
