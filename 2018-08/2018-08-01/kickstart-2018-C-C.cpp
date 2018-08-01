// kickstart-c-b.cpp : Defines the entry point for the console application.
// references: https://blog.csdn.net/iceteaset/article/details/80472573

#include "stdafx.h"

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

const int MAXN = 1e6 + 5;
const int MOD = 1000000007;
long long x[MAXN];
long long y[MAXN];
int K, F;

int powll(int base, int n)
{
    if (n == 0) return 1;
    if (n == 1) return base;
    long long temp = powll(base, n / 2);
    temp = (temp * temp) % MOD;
    if (n % 2 == 1) temp = (temp * base) % MOD;
    return (int)temp;
}

long long compute(long long c, long long xx,long long e, long long d, long long yy)
{
    return (c * xx + d * yy + e) % F;
}

long long computeA(long long xx, long long yy)
{
    return (xx + yy) % F;
}

long long computeMe(vector<long long>& arr/* valid index: 1-n*/) /* for small data */
{
    long long sum = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            for (int now = i; now <= j; now++)
            {
                for (int exp = 1; exp <= K; exp++)
                {
                    sum += arr[now] * powll(now - i + 1, exp);
                    sum %= MOD;
                }
            }
        }
    }
    return sum;
}

int geoSum(int base, int n)
{
    if (n == 1) return base;
    long long temp = geoSum(base, n / 2);
    temp = (temp + temp * powll(base, n / 2)) % MOD;
    if (n % 2 == 1) temp = (temp + powll(base, n)) % MOD;
    return (int)temp;
}

int main()
{
    int T;
    freopen("D:/temp/kickstart/2018c/C-large-practice.in", "r", stdin);
    freopen("D:/temp/kickstart/2018c/C-large-practice.out", "w", stdout);

    cin >> T;

    long long N, x1, y1, C, D, E1, E2;
    for (int t = 1; t <= T; t++)
    {
        cin >> N >> K >> x[1] >> y[1] >> C >> D >> E1 >> E2 >> F;

        vector<long long> arr(N + 1, 0);  arr[1] = computeA(x[1], y[1]);
        for (int i = 2; i <= N; i++)
        {
            x[i] = compute(C, x[i - 1], E1, D, y[i - 1]);
            y[i] = compute(D, x[i - 1], E2, C, y[i - 1]);
            arr[i] = computeA(x[i], y[i]);
        }

        vector<long long> sum(N + 1);
        sum[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            sum[i] = (sum[i - 1] + geoSum(i, K)) % MOD;
        }

        long long ans = 0;
        for (int i = 1; i <= N; i++)
        {
            ans = (ans + (((N - i + 1) * arr[i]) % MOD) * sum[i]) % MOD;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

