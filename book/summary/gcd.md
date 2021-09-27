## 辗转相除法

求最大公约数的算法。

`a / b = k ... r`, 则 `gcd(a, b) = gcd(b, r)`。

大概的证明过程：

1. 设d是a和b的公因数，则d|a且d|b。于是d|(a−bq)。也就是说d|r, 因为r=a−bq. ==》d是b,r的公因数
2. 设d是b和r的公因数，则d|r且d|b。于是d|(bq+r)。所以d|a ==》所以d是a,b的公因数。

综上，a,b的所有公因数和b,r的所有公因数是一样的。那么，d是a，b的最大公因数，当且仅当d是b和r的最大公因数。