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

using namespace std;

int N, K;
long long A[5];
long long B[5];
long long C[5];
long long M[5];

int main()
{
    int T;
    freopen("D:/temp/kickstart/2018d/B-large-practice.in", "r", stdin);
    freopen("D:/temp/kickstart/2018d/B-large-practice.out", "w", stdout);

    cin >> T;

   
    for (int t = 1; t <= T; t++)
    {

        cin >> N >> K;
        long long res = 0;
        vector<long long> p(N + 1, 0);
        vector<long long> h(N + 1, 0);
        vector<long long> x(K + 1, 0);
        vector<long long> y(K + 1, 0);
        vector<pair<long long, long long>> l(N + 1);
        vector<pair<long long, long long>> lr(1);


        // input
        cin >> p[1] >> p[2] >> A[1] >> B[1] >> C[1] >> M[1];
        cin >> h[1] >> h[2] >> A[2] >> B[2] >> C[2] >> M[2];
        cin >> x[1] >> x[2] >> A[3] >> B[3] >> C[3] >> M[3];
        cin >> y[1] >> y[2] >> A[4] >> B[4] >> C[4] >> M[4];
        for (int i = 3; i <= N; i++)
        {
            p[i] = ((A[1] * p[i - 1] + B[1] * p[i - 2] + C[1]) % M[1]) + 1;
            h[i] = ((A[2] * h[i - 1] + B[2] * h[i - 2] + C[2]) % M[2]) + 1;
        }
        for (int i = 3; i <= K; i++)
        {
            x[i] = ((A[3] * x[i - 1] + B[3] * x[i - 2] + C[3]) % M[3]) + 1;
            y[i] = ((A[4] * y[i - 1] + B[4] * y[i - 2] + C[4]) % M[4]) + 1;
        }

        // solve
        // 要证明一个 Edge 可以被另一个 Edge 完全包括：(如第 i 个被第 j 个完全包括)
        // 1. h[j] + p[j] >= h[i] + p[j]
        // 2. p[j] - h[j] <= p[i] - h[i] -->  h[j] - p[j] >= p[i] - h[i]
        // 这个约束条件对 balloons 同样有效
        for (int i = 1; i <= N; i++)
        {
            l[i].first = h[i] + p[i];
            l[i].second = h[i] - p[i];
        }

        sort(l.begin() + 1, l.end());

        int j = 0;
        for (int i = 1; i <= N; i++)
        {
            while (j && lr[j].second <= l[i].second)
            {
                j--;
                lr.pop_back();
            }
            j++;
            lr.push_back(l[i]);
        }
        N = j;
        for (int i = 1; i <= K; i++)
        {
            int j = lower_bound(lr.begin() + 1, lr.end(), make_pair(y[i] + x[i], y[i] - x[i])) - lr.begin();
            if (j <= N && lr[j].first >= (y[i] + x[i]) && lr[j].second >= (y[i] - x[i])) 
                res++;
        }
      
        // output
        cout << "Case #" << t << ":" << " " << res << endl;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}