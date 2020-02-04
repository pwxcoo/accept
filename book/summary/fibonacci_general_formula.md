## Fibonacci General Formula

求 fibonacci 数列的第 n 项，用快速幂已经可以达到 `O(logn)` 的时间复杂度了。

当然 fibonacci 数列是可以推导出其通项公式的。下面利用矩阵推导一次。

### 推导

存在矩阵 $$M$$ 使得：

$$
\begin{pmatrix}F_n\\F_{n+1}\end{pmatrix}=M\begin{pmatrix}F_{n-1}\\F_{n}\end{pmatrix}\Rightarrow\begin{pmatrix}F_n\\F_{n+1}\end{pmatrix}=M^n\begin{pmatrix}F_{0}\\F_{1}\end{pmatrix}
$$

处理一下右式，需要求 $$M$$ 的 `n` 次方，尝试把 $$M$$ 矩阵对角化：

$$
\begin{pmatrix}F_n\\F_{n+1}\end{pmatrix}=M^n\begin{pmatrix}F_{0}\\F_{1}\end{pmatrix}\Rightarrow\begin{pmatrix}F_n\\F_{n+1}\end{pmatrix}=PD^nP^{-1}\begin{pmatrix}0\\1\end{pmatrix}
$$


先解出 $$M$$ 的值 $$M=\begin{pmatrix}0&1\\1&1\end{pmatrix}$$，求矩阵 $$M$$ 的特征值和特征向量，解特征方程 $$\det(M-\lambda I)=0$$ 得到 $$M$$ 的特征值 $$\lambda=\frac{1\pm\displaystyle\sqrt{5}}{2}$$，然后得到两个特征向量：

$$
\begin{pmatrix}1\\\\\displaystyle\frac{1\pm\sqrt 5}{2}\end{pmatrix}
$$

然后求 $$P^{-1}$$，代入公式 $$A^{-1}=\frac{A^*}{|A|}$$：

$$
\begin{aligned}P^{-1}&=\begin{vmatrix}1&1\\\\\displaystyle\frac{1+\sqrt 5}{2}&\displaystyle\frac{1-\sqrt 5}{2}\end{vmatrix}^{-1}\begin{pmatrix}\displaystyle\frac{1-\sqrt 5}{2}&-\displaystyle\frac{1+\sqrt 5}{2}\\\\-1&1\end{pmatrix}^{\rm T}\\&=\begin{pmatrix}\displaystyle\frac{\sqrt 5-1}{2\sqrt 5}&\displaystyle\frac{1}{\sqrt 5}\\\\\displaystyle\frac{\sqrt 5 + 1}{2\sqrt 5}&\displaystyle-\frac{1}{\sqrt 5}\end{pmatrix}\end{aligned}
$$

然后求解 $$F_{n}$$：

$$
\begin{aligned}F_n&=\begin{pmatrix}1&0\end{pmatrix}\begin{pmatrix}1&1\\\\\displaystyle\frac{1+\sqrt 5}{2}&\displaystyle\frac{1-\sqrt 5}{2}\end{pmatrix}\begin{pmatrix}\displaystyle\left(\frac{1+\sqrt 5}{2}\right)^{n}&0\\0&\displaystyle\left(\frac{1-\sqrt 5}{2}\right)^n\end{pmatrix}\begin{pmatrix}\displaystyle\frac{\sqrt 5-1}{2\sqrt 5}&\displaystyle\frac{1}{\sqrt 5}\\\\\displaystyle\frac{\sqrt 5 + 1}{2\sqrt 5}&\displaystyle-\frac{1}{\sqrt 5}\end{pmatrix}\begin{pmatrix}0\\1\end{pmatrix}\\&=\begin{pmatrix}1&0\end{pmatrix}\begin{pmatrix}1&1\\\\\displaystyle\frac{1+\sqrt 5}{2}&\displaystyle\frac{1-\sqrt 5}{2}\end{pmatrix}\begin{pmatrix}\displaystyle\left(\frac{1+\sqrt 5}{2}\right)^{n}&0\\0&\displaystyle\left(\frac{1-\sqrt 5}{2}\right)^n\end{pmatrix}\begin{pmatrix}\displaystyle\frac{1}{\sqrt{5}}\\\\\displaystyle-\frac{1}{\sqrt{5}}\end{pmatrix}\\&=\frac{2^{-n}}{\sqrt 5}\begin{pmatrix}1&0\end{pmatrix}\begin{pmatrix}1&1\\\\\displaystyle\frac{1+\sqrt 5}{2}&\displaystyle\frac{1-\sqrt 5}{2}\end{pmatrix}\begin{pmatrix}\displaystyle\left(1+\sqrt 5\right)^n\\-\displaystyle\left(1-\sqrt 5\right)^n\end{pmatrix}\\&=\frac{\displaystyle\left(\frac{1+\displaystyle\sqrt{5}}{2}\right)^n-\displaystyle\left(\frac{1-\displaystyle\sqrt{5}}{2}\right)^n}{\displaystyle\sqrt{5}}\end{aligned}
$$

可得 fibonacci 第 n 项的通项公式为：

$$
F_n=\frac{\displaystyle\left(\frac{1+\displaystyle\sqrt{5}}{2}\right)^n-\displaystyle\left(\frac{1-\displaystyle\sqrt{5}}{2}\right)^n}{\displaystyle\sqrt{5}}
$$