#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

long long N, O, D;
long long A, B, C, M, L;

int main()
{
    int T;
    freopen("D:/temp/kickstart/2018d/A-large-practice.in", "r", stdin);
    freopen("D:/temp/kickstart/2018d/A-large-practice.out", "w", stdout);

    cin >> T;


    for (int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);
        cin >> N >> O >> D;
        vector<long long> X(N + 1, 0);
        vector<long long> S(N + 1, 0);
        vector<long long> b(N + 1, 0);

        cin >> X[1] >> X[2] >> A >> B >> C >> M >> L;
        S[1] = X[1] + L;
        S[2] = X[2] + L;

        b[1] = S[1]; b[2] = S[2] + S[1];

        for (int i = 3; i <= N; i++)
        {
            X[i] = (A * X[i - 1] + B * X[i - 2] + C) % M;
            S[i] = X[i] + L;
            b[i] = b[i - 1] + S[i];
        }
        
        multiset<long long> s;
        multiset<long long>::iterator it;
        long long ans = -(1LL << 60);
        s.insert(0);
        
        for (int i = 1, j = 1, k = 0; i <= N; i++)
        {
            
            if (j >= i)
            {
                it = s.find(b[i - 1]);
                if (it != s.end()) s.erase(it);
                k -= S[i - 1] & 1;
            }
            else j = i;

            for (; j <= N; j++)
            {
                k += S[j] & 1;
                if (k > O)
                {
                    k -= S[j] & 1;
                    break;
                }
                s.insert(b[j]);
            }
            it = s.upper_bound(D + b[i - 1]);
            if (it != s.begin())
            {
                it--;
                ans = max(ans, *it - b[i - 1]);
            }
        }
        if (ans == -(1LL << 60)) printf("IMPOSSIBLE\n");
        else cout << ans << endl;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}