#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<string.h>

using namespace std;

const int MAXN = 2;
const int MOD = 1e4;

struct Matrix 
{
    int edges[MAXN][MAXN];
    Matrix() {}
    Matrix operator*(Matrix const &b)const
    {
        Matrix res;
        memset(res.edges, 0, sizeof(res));
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                for (int k = 0; k < MAXN; k++)
                    res.edges[i][j] = (res.edges[i][j] + this->edges[i][k] * b.edges[k][j]) % MOD;
        return res;
    }
};

Matrix fastpow(Matrix base, int n)
{
    Matrix res;
    memset(res.edges, 0, sizeof(res.edges));
    for (int i = 0; i < MAXN; i++)
        res.edges[i][i] = 1;
    while (n > 0)
    {
        if (n & 1) res = res * base;
        base = base * base;
        n >>= 1;
    }
    return res;
}



int main()
{
    int n;
    Matrix init;
    init.edges[0][0] = 1; init.edges[0][1] = 1; init.edges[1][0] = 1; init.edges[1][1] = 0;
    while (~scanf("%d", &n) && n != -1)
        printf("%d\n", fastpow(init, n).edges[0][1]);


    return 0;
}