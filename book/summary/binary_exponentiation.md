## Binary Exponentiation

二分幂，快速幂，矩阵快速幂在计算大指数次方的时候比较高效，因为相当于二分了，就从传统求次方的 `O(n)` 变成了 `O(logn)` 。

其实二分幂就是快速幂，二分幂是快速幂递归写法，而通常意义上说的快速幂指的是非递归写法，然后矩阵快速幂就是用矩阵乘法替换一下就好了。

### 二分幂 (快速幂的递归写法)

就是把求解 $$a^{n}$$ 的问题变成求解 $$a^{\frac{n}{2}} \cdot a^{\frac{n}{2}}$$ 或者 $$a^{\frac{n}{2}} \cdot a^{\frac{n}{2}} \cdot a$$  (根据 n 的奇偶确定转话成哪个) 的问题。

```c++
long long pow(int base,int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return base;
    long long ans = pow(base,n/2);
    ans *= ans;
    if (n % 2 == 1)
        ans *= base;
    return ans;
}
```

### 快速幂

就是把写法写成非递归的，可以用位运算，其实不用也没关系，可能是写起来比较好看吧。

举个例子，相当于
$$
A=a^{6}=a^{110}=(a^{2^{2}} \cdot 1) \cdot (a^{2^{1}} \cdot 1) \cdot (a^{2^{0}} \cdot 0)
$$

```c++
long long int fun( int a, int b )
{
    long long int r = 1;
    int base = a;
    while ( b != 0 )
    {
        if(b & 1)
        {
            r *= base;
        }
        base *= base;
        b >>= 1;
    }
    return r;
}
```

#### 快速乘

突然联想到快速乘，顺便提一下。。。因为 $$a\cdot b$$ 有可能在取模之前就溢出，所以可以这种类似快速幂的办法来解决，借助二进制的思想。

```c++
long long fastMultiplication(long long a,long long b)
{
    long long ans = 0;
    while(b)
    {
        if(b % 2 == 1)
        {
            b--;
            ans = ans + a;
            ans %= mod;
        }
        else
        {
            b /= 2;
            a = a + a;
            a %= mod;
        }
    }
    return ans;
}
```

### 矩阵快速幂

就是把乘法换成矩阵的乘法。

矩阵快速幂可以用在很多递推式的中，比如 $$f(n)=a\cdot f(n-1) + b\cdot f(n-2)$$ ，可以用矩阵运算快速求出若干项的结果。

最简单就是用在 Fibonacci 中了。

```c++
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
```

### References

- [kickstart-2018-RoundC-C](https://github.com/pwxcoo/ac-game/blob/master/2018-08/2018-08-01/kickstart-2018-C-C.cpp) 快速幂 + 求需要取模的等比数列和的类快速幂算法
- [poj3070](https://github.com/pwxcoo/ac-game/blob/master/2018-08/2018-08-01/poj3070.cpp) 矩阵快速幂
