# Fermat Little Theorem

## Prerequisites

### modular arithmetic

[模运算](https://en.wikipedia.org/wiki/Modular_arithmetic)，相同的模（Congruent modulo）可以写出一个等式，叫同余式：

$$
{\displaystyle a\equiv b{\pmod {n}}}
$$

同余式完全兼容加减乘，**除法的话，当 modulo 是除数的倍数时，需要把 modulo 也除以除数**。

---

## Theorem

费马小定理（Fermat Little Theorem），下面是 [wikipedia](https://en.wikipedia.org/wiki/Fermat's_little_theorem) 的解释：

if $$p$$ is a prime number, then for any integer $$a$$, the number $$a^{p} − a$$ is an integer multiple of $$p$$. In the notation of **modular arithmetic**, this is expressed as:

$$
a^p \equiv a \pmod p
$$

If $$a$$ is not divisible by $$p$$, Fermat's little theorem is equivalent to the statement that $$a{p − 1} − 1$$ is an integer multiple of $$p$$, or in symbols:

$$
a^{p-1} \equiv 1 \pmod p
$$

---



## Improvement

数学归纳法+二项式定理。

1. 当 a = 1 时，$$1^{p} \equiv 1 \pmod p$$ 显然成立
2. 设 a = k 时，$$k^{p} \equiv k \pmod p$$ 成立，
    - 则 $$(k+1)^{p}=k^{p} + p \cdot k^{p-1} + \frac{p(p-1)}{2} \cdot k^{p-2} + ... + p \cdot k + 1$$
    - 则 $$(k+1)^{p} \equiv k^{p} + 1 \pmod p$$
    - 则 $$(k+1)^{p} \equiv k + 1 \pmod p$$ 成立

**由 `1 和 2` 得，对任何自然数 $$a$$，$$a^{p} \equiv a \pmod p$$ 都成立**。


## Practice

1. 素数判定的必要非充分条件
2. 快速求模
3. ...

## References

- [费马小定理（Fermat's Little Theorem） - 知乎](https://zhuanlan.zhihu.com/p/87611586)
- [第五种运算](https://mp.weixin.qq.com/s/PksS-rR8-bQ5mjhHE7jNAw)
- [费马小定理](https://mp.weixin.qq.com/s/yyy3T1BhFLyeegPcYB_goA)
- [费马小定理之素数判定](https://mp.weixin.qq.com/s/c0oxozRQ_mk0CTUgXgn_Bg)