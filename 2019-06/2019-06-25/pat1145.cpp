#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 其实感觉题目有问题，search的时候，区间为什么是 [0, MSize]，右侧是闭区间？
 */

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int MSize, N, M;
int m[100005];

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= num / i; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void ha(int num) {
    bool suc = false;

    for (int i = 0; i < MSize; i++) {
        // todo: there is a overflow risk.
        int pos = (num + i * i) % MSize;
        if (m[pos] == 0) {
            m[pos] = num;
            suc = true;
            break;
        }
    }

    if (!suc) printf("%d cannot be inserted.\n", num);
}

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    scanf("%d %d %d", &MSize, &N, &M);
    while (!isPrime(MSize)) MSize++;

    int temp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        ha(temp);
    }

    int res = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &temp);
        for (int j = 0; j <= MSize; j++) {
            res++;

            int pos = (temp + j * j) % MSize;
            if (m[pos] == temp || m[pos] == 0) break;
        }
    }

    printf("%.1f\n", (double)res / M);

    return 0;
}

