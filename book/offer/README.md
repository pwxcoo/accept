# Introduction

《剑指offer》题解。

## [二维数组中的查找](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

从左下角为起点开始 search，这样每次都能排除掉一列或者一行。(当然以右上角为起点也是可以的)。

```cpp
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0) {
            return false;
        }

        int n = array.size(), m = array[0].size();
        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (array[i][j] == target) return true;
            else if (array[i][j] > target) i--;
            else if (array[i][j] < target) j++;
        }

        return false;
    }
};
```

时间复杂度：$$O(n+m)$$

## [替换空格](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

正着来替换的话，需要开辟新的字符数组来保存一个中间结果。可以反着来，算出新数组长度后，倒着更新就好了。

如果是 `%20` 替换成空格话，直接正着来就好了。

```cpp
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int spaceCount = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') spaceCount++;
        }

        int newLength = length + 2 * spaceCount;
        for (int i = length - 1, newi = newLength - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                str[newi--] = '0';
                str[newi--] = '2';
                str[newi--] = '%';
            } else {
                str[newi--] =  str[i];
            }
        }
	}
};
```

时间复杂度：$$O(length + 2 * spaceCount)$$

## [从尾到头打印链表](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

一边遍历一边保存结果。然后把结果倒一下。（感觉想考察栈？不过直接用数组完全可以实现）

```cpp
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;

        ListNode* cur = head;
        while (cur != NULL) {
            res.push_back(cur->val);
            cur = cur->next;
        }

        // reverse(res.begin(), res.end());
        int n = res.size();
        for (int i = 0; i < n / 2; i++) {
            int tmp = res[i];
            res[i] = res[n - 1 - i];
            res[n - 1 - i] = tmp;
        }

        return res;
    }
};
```

时间复杂度：$$O(n)$$

## [重建二叉树](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

根据前序遍历和中序遍历重建二叉树。

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* buildBinaryTree(vector<int>& pre,vector<int>& vin, int ps, int vs, int size) {
        if (size == 0) return NULL;

        TreeNode* root = new TreeNode(pre[ps]);
        int leftSize = 0;
        while (vin[vs + leftSize] != pre[ps]) {
            leftSize++;
        }

        root->left = buildBinaryTree(pre, vin, ps + 1, vs, leftSize);
        root->right = buildBinaryTree(pre, vin, ps + 1 + leftSize, vs + leftSize + 1,  size - leftSize - 1);

        return root;
    }
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0 || vin.size() == 0) return NULL;

        return buildBinaryTree(pre, vin, 0, 0, pre.size());
    }
};
```

时间复杂度：$$O(nlogn)$$，最坏应该是 $$O(n^2)$$。时间复杂度是 $$T(n)=O(n)+2T(n/2)$$，是一个 $$O(n)$$ 的复杂度，加上两个子问题的复杂度，算出来平均应该是 $$O(nlogn)$$。

## [用两个栈实现队列](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

1. `push()` 放到 stack1 里
2. `pop()` 的时候，看 stack2 是不是空的，如果是空的得把 stack1 里元素倒到 stack2 里，然后直接 pop stack2 中的元素就好了。

```cpp
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int t = stack1.top(); stack1.pop();
                stack2.push(t);
            }
        }
        
        int res = stack2.top(); stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

时间复杂度：$$O(1)$$

## [旋转数组的最小数字](https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba)

我是按照**严格递增**的话来写的。取中间元素和最后一个元素比较，然后每次都排除掉非“分割线”所在的那个区间（正常的递增区间）。（**PS：之所以用最后一个元素，是因为如果只有两个元素的话，mid 每次都是 L 元素，而不是 R 元素，会有点问题。**）

如果是**非递减**的话，感觉只能 $$O(n)$$ 的写法了。因为没办法区分 `[1, 0, 1, 1, 1]` 和 `[1, 1, 1, 0, 1]`。

```cpp
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) {
            return 0;
        }
        
        int L = 0, R = rotateArray.size() - 1;
        
        while (L < R) {
            int mid = L + (R - L) / 2;
            if (rotateArray[mid] > rotateArray[R]) {
                L = mid + 1;
            } else {
                R = mid;
            }
        }
        
        return rotateArray[L];
    }
};
```

时间复杂度：$$O(logn)$$

## [斐波那契数列](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

用一个数组记录一下结果。避免重复的计算。

```cpp
class Solution {
private:
    int fib[50];
public:
    int Fibonacci(int n) {
       if (n <= 1) {
           return n;
       }
        
        return fib[n] ? fib[n] : fib[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};
```

时间复杂度：$$O(n)$$

## [跳台阶](https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

和上一题一样。

```cpp
class Solution {
private:
    int jump[50];
public:
    int jumpFloor(int number) {
        if (number <= 1) {
            return 1;
        }
        
        return jump[number] ? jump[number]: jump[number] = jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};
```

时间复杂度：$$O(n)$$

## [变态跳台阶](https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

得到递推公式：

$$
F(n) = F(n - 1) + F(n - 2) + \cdots + F(1) + F(0)
$$

处理一下可得：

$$
F(n) = 2^{n - 1}
$$

然后快速幂一下。

```cpp
class Solution {
public:
    int jumpFloorII(int number) {
        return quickPow(number - 1);
    };
    
    int quickPow(int n) {
        int base = 2;
        int r = 1;
        while (n) {
            if (n & 1 == 1) {
                r *= base;
            }
            
            base *= base;
            n >>= 1;
        }
        
        return r;
    }
};
```

时间复杂度：$$O(logn)$$


## [矩形覆盖](https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

考虑横着放和竖着放两种情况。发现还是 `fibonacci`。

```cpp
class Solution {
public:
    int rectCover(int number) {
        if (number <= 1) {
            return number;
        }
        
        int first = 1, second = 1, third = first + second;
        for (int i = 2; i <= number; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        
        return third;
    }
};
```

时间复杂度：$$O(n)$$。不过 `fibonacci` 写成矩阵快速幂复杂度可以变成 $$O(logn)$$

## [二进制中1的个数](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

$$(n - 1) & n$$ 的运算会吞掉最右边的 1。

```cpp
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while (n) {
             count++;
             n = (n - 1) & n;
         }
         return count;
     }
};
```

时间复杂度：$$O(n)$$，取决于 `n` 中 1 的个数。

## [数值的整数次方](https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

快速幂。**注意一下 exponent 是负数的情况**

```cpp
class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1.0;
        bool reciprocal = exponent < 0;
        exponent = abs(exponent);
        
        while (exponent) {
            if (exponent & 1 == 1) {
                res *= base;
            }
            
            base *= base;
            exponent >>= 1;
        }
        
        if (reciprocal) {   
            res = 1.0 / res;
        }
        
        return res;
    }
};
```


时间复杂度：$$O(logn)$$


## [调整数组顺序使奇数位于偶数前面](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

因为得保证稳定性，所以想要时间复杂度是 $$O(n)$$ 的话，只能开辟一块空间来存储。

```cpp
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        stack<int> even;
        
        int cur = 0;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] & 1 == 1) {
                array[cur++] = array[i];
            } else {
                even.push(array[i]);
            }
        }
        
        for (int i = array.size() - 1; i >= cur; i--) {
            int t = even.top(); even.pop();
            array[i] = t;
        }
    }
};
```

时间复杂度：$$O(n)$$

## [链表中倒数第k个结点](https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

担心 `k` 会比总长度要大，所以算出总长度后，就可以直接得到对应的正数的位置。

如果题目保证了 `k` 会比总长度要小，可以用一个 `fast` 和 `slow` 指针来做，常数的优化。

```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int count = 0;
        ListNode* now = pListHead;
        
        while (now != NULL) {
            count++;
            now = now -> next;
        }
        
        if (k > count) {
            return NULL;
        }
        
        int target = count - k;
        ListNode* res = pListHead;
        while (target--) {
            res = res -> next;
        }
        
        return res;
    }
};
```

时间复杂度：$$O(n)$$

## [反转链表](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

反转链表，就改改指针就好了。

```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead -> next == NULL) {
            return pHead;
        }
        
        ListNode* pre = NULL;
        ListNode* now = pHead;
        
        while (now) {
            ListNode* next = now -> next;
            now -> next = pre;
            pre = now;
            now = next;
        }
        
        return pre;
    }
};
```

时间复杂度：$$O(n)$$

## [合并两个排序的链表](https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

直接遍历就好了。

```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* now = dummy;
        
        while (pHead1 != NULL && pHead2 != NULL) {
            if (pHead1 -> val < pHead2 -> val) {
                now -> next = pHead1;
                pHead1 = pHead1 -> next;
            } else {
                now -> next = pHead2;
                pHead2 = pHead2 -> next;
            }
            
            now = now -> next;
        }
        
        now -> next = pHead1 != NULL ? pHead1 : pHead2;
        
        return dummy -> next;
    }
};
```

时间复杂度：$$O(length(pHead1) + length(pHead2))$$

## [树的子结构](https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

1. 看根节点是否一致
2. 然后比对 `Tree2` 中各个节点在 `Tree1` 中都有。

```cpp
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL) {
            return false;
        }
        
        return pRoot1 -> val == pRoot2 -> val && Tree1HasTree2(pRoot1, pRoot2)
            || HasSubtree(pRoot1->left, pRoot2)
            || HasSubtree(pRoot1->right, pRoot2);
    }
    
    bool Tree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == NULL) return true;
        if (pRoot1 == NULL) return false;
        
        return pRoot1 -> val == pRoot2 -> val
            && Tree1HasTree2(pRoot1 -> left, pRoot2 -> left)
            && Tree1HasTree2(pRoot1 -> right, pRoot2 -> right);
    }
};
```

时间复杂度：$$O(m*n)$$

## [二叉树的镜像](https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

递归一下。

```cpp
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        
        Mirror(pRoot -> left);
        Mirror(pRoot -> right);
        
        swap(pRoot -> left, pRoot -> right);
    }
};
```

时间复杂度：$$O(n)$$

## [顺时针打印矩阵](https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

顺时针打印矩阵。注意拐弯。

```cpp
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int left = 0, right = m - 1, down = n - 1, up = 0;
        vector<int> res;
        int i, j;
        while (true) {
            for(int j = left; j <= right; j++) res.push_back(matrix[up][j]);
            if (++up > down) break;
            
            for (int i= up; i <= down; i++) res.push_back(matrix[i][right]);
            if (--right < left) break;
            
            for(int j = right; j >= left; j--) res.push_back(matrix[down][j]);
            if (--down < up) break;
            
            for (int i = down; i >= up; i--) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        
        return res;
    }
};
```

时间复杂度：$$O(n*m)$$

## [包含min函数的栈](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

多用一个栈用来保存前缀字符里最小的元素。

```cpp
class Solution {
private:
    stack<int> st;
    stack<int> minst;
public:
    void push(int value) {
        st.push(value);
        
        minst.push(minst.empty() || value < minst.top() ? value : minst.top());
    }
    void pop() {
        st.pop();
        minst.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return minst.top();
    }
};
```

时间复杂度：$$O(1)$$


## [栈的压入、弹出序列](https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

模拟栈操作。

```cpp
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        
        int now = 0;
        for (int i = 0; i < popV.size(); i++) {
            while (st.empty() || st.top() != popV[i]) {
                if (now >= pushV.size()) return false;
                
                st.push(pushV[now++]);
            }
            
            st.pop();
        }
        
        return true;
    }
};
``

时间复杂度：$$O(n)$$

## [从上往下打印二叉树](https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

利用队列层次遍历树。

```cpp
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;  
        queue<TreeNode*> q;
        if (root != NULL) q.push(root);
        
        while (!q.empty()) {
            TreeNode* t = q.front(); q.pop();
            
            res.push_back(t -> val);
            if (t -> left) q.push(t -> left);
            if (t -> right) q.push(t -> right);
        }
        
        return res;
    }
};
```


时间复杂度：$$O(n)$$


## [二叉搜索树的后序遍历序列](https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

后序遍历。最右边的是根节点，然后根据 BST 的性质判断一波。

```cpp
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) return false;
        return isLegalPost(sequence, 0, sequence.size() - 1);
    }
    
    bool isLegalPost(vector<int>& s, int L, int R) {
        if (L >= R) return true;
        
        int seg = L;
        while (seg < R && s[seg] < s[R]) {
            seg++;
        }
        
        
        for (int i = seg; i < R; i++) {
            if (s[i] < s[R]) return false;
        }
        
        return isLegalPost(s, L, seg - 1) && isLegalPost(s, seg, R - 1);
    }
};
```

时间复杂度：$$O(n^2)$$

## [二叉树中和为某一值的路径](https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

DFS。

```cpp
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
    vector<int> cur;
    vector<vector<int>> res;
    
    void DFS(TreeNode* root, int number) {
        if (number == 0 && root -> left == NULL && root -> right == NULL) {
            res.push_back(cur);
        }
        
        if (root -> left) {
            cur.push_back(root -> left -> val);
            DFS(root -> left, number - root -> left -> val);
            cur.pop_back();
        }
        
        if (root -> right) {
            cur.push_back(root -> right -> val);
            DFS(root -> right, number - root -> right -> val);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (!root) return res;
        cur.push_back(root -> val);
        DFS(root, expectNumber - root -> val);
        cur.pop_back();
        
        sort(res.begin(), res.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a.size() > b.size();
        });
        return res;
    }
};
```

时间复杂度：$$O(n)$$

## [复杂链表的复制](https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

一种不用辅助空间的时间复杂度为 $$O(n)$$ 的算法。

1. 遍历一遍，把生成的节点放在各自节点后面
2. 在遍历一遍，赋值 random 指针。（这里相当于搞了 map 来映射）
3. 然后分离目标链表和原链表

```cpp
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* res = dummy;
        
        RandomListNode* now = pHead;
        while (now) {
            RandomListNode* next = now -> next;
            
            RandomListNode* node = new RandomListNode(now -> label);
            now -> next = node;
            node -> next = next;
            
            now = next;
        }
        
        now = pHead;
        while (now) {
            RandomListNode* node = now -> next;
            RandomListNode* random = now -> random;
            if (random) {
                node -> random = random -> next;
            }
            
            now = node -> next;
        }
        
        now = pHead;
        while (now) {
            RandomListNode* node = now -> next;
            
            now -> next = node -> next;
            res -> next = node;
            res = res -> next;
            
            now = now -> next;
            
        }
        
        return dummy -> next;
    }
};
```

时间复杂度：$$O(n)$$

## [二叉搜索树与双向链表](https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

中序遍历搞一下。

```cpp
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        stack<TreeNode*> st;
        TreeNode* now = pRootOfTree;
        
        TreeNode* pre;
        TreeNode* res;
        while (!st.empty() || now) {
            while (now) {
                st.push(now);
                now = now -> left;
            }
            
            if (!st.empty()) {
                TreeNode* t = st.top(); st.pop();
                if (pre) {
                    pre -> right = t;
                    t -> left = pre;
                } else {
                    res = t;
                }
                
                pre = t;
                now = t -> right;
            }
        }
        
        return res;
    }
};
```

## [字符串的排列](https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

全排列。

```cpp
class Solution {
private:
    int visit[10];
    set<string> s;
    string cur;
public:
    void dfs(string& str) {
        if (cur.length() == str.length()) {
            s.insert(cur);
            return;
        }
        
        for (int i = 0; i < str.length(); i++) {
            if (visit[i]) continue;
            
            visit[i] = 1;
            cur += str[i];
            dfs(str);
            cur.pop_back();
            visit[i] = 0;
        }
    }
    
    vector<string> Permutation(string str) {
        if (str.length() == 0) return vector<string>();
        
        cur = "";
        dfs(str);
        vector<string> res(s.begin(), s.end());
        
        return res;
    }
};
```

用 `STL` 里的 `next_permutation()` 也可以做。

```cpp
class Solution {
public:
    vector<string> Permutation(string str) {
      vector<string> result;
      if(str == "") return result;
      do {
        result.push_back(str);
      } while (next_permutation(str.begin(), str.end()));
       
      return result;
    }

```

时间复杂度：$$O(n!)$$


## [数组中出现次数超过一半的数字](https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)


[多数投票算法 Boyer–Moore majority vote algorithm](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)。

```cpp
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 0;
        int lastNumber = 0;
        
        for (int i = 0; i < numbers.size(); i++) {
            if (count == 0) {
                count = 1;
                lastNumber = numbers[i];
            } else {
                count = lastNumber == numbers[i] ? count + 1: count - 1;
            }
        }
        
        count = 0;
        for (int i = 0; i< numbers.size(); i++) {
            if (numbers[i] == lastNumber) count++;
        }
        if (count <= numbers.size() / 2) lastNumber = 0;
        
        return lastNumber;
    }
};
```

时间复杂度：$$O(n)$$
空间复杂度：$$O(1)$$


## [最小的K个数](https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

用堆来实现。

```cpp
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> q;
        
        for (int i = 0; i < input.size(); i++) {
            if (q.size() < k) {
                q.push(input[i]);
            } else {
                if (!q.empty() && q.top() > input[i]) {
                    q.pop();
                    q.push(input[i]);
                }
            }
        }
        
        vector<int> res;
        if (q.size() == k) {
            while (!q.empty()) {
                res.push_back(q.top()); q.pop();
            }
        }
        
        return res;
    }
};
```

时间复杂度：$$O(nlogk)$$

另外可以用快排的思路做。时间复杂度可以是 $$O(n)$$


## [连续子数组的最大和](https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

写出 dp 方程就好了。可以写成以 `i` 为结尾的数组，最大的连续子数组的和就是当前前缀和减去最小的前缀和。

```cpp
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int minPrefixSum = 0;
        int prefixSum = 0;
        int res;
        
        for (int i = 0; i < array.size(); i++) {
            prefixSum += array[i];
            res = i == 0 ? prefixSum - minPrefixSum : max(res, prefixSum - minPrefixSum);
            minPrefixSum = min(minPrefixSum, prefixSum);
        }
        
        return res;
    }
};
```

时间复杂度：$$O(n)$$

## [整数中1出现的次数](https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

找规律。一个位数一个位数做。

举例 $$12345$$，看百分位 $$3$$，$$3$$ 的 `left` 是 $$12$$，`right` 是 $$45$$。

让百分位取 $$1$$。

1. `left` 取 $$0-11$$ 是完全没问题的，随便取。这块有 $$12*100=1200$$ 种取法。
2. `left` 取 $$12$$，发现当前位 `x` 是 $$3$$，所以对 `right` 是没有限制的，`right` 有 $$100$$ 种取法。

而步骤 2 里取法，是对当前位数有要求的，必须是当前位 `x` 大于 $$1$$ 才行。如果当前位等于 $$1$$，比如数字是 $$12145$$ 算百分位，对 `right` 就有限制了，`right` 只能取到 $$0-45$$，有 $$46$$ 种取法。如果当前位等于 $$0$$，那 `right` 没办法取，自然只有 $$0$$ 种取法。


```cpp
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i *= 10) {
            res += n / (i * 10) * i;
            int x = (n / i) % 10;
            res += x > 1 ? i : (n % i + 1) * x;
        }
        return res;
    }
};
```

时间复杂度：$$O(logn)$$

**PS:看别人写法还有用数位 DP 来做的**

## [把数组排成最小的数](https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

搞成字符串排序。其实就相当于字段序排序。

```cpp
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> sn;
        for (int i = 0; i < numbers.size(); i++) {
            sn.push_back(to_string(numbers[i]));
        }
        
        sort(sn.begin(), sn.end(), [](const string& a, const string& b) -> bool {
            return a + b < b + a;
        });

        string res;
        for (const auto &piece : sn) res += piece;
        return res;
    }
};
```

时间复杂度：$$O(nlogn)$$

## [丑数](https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

可以直到下一个丑数一定是当前丑数集合中，乘上 $$2$$ 或 $$3$$ 或 $$5$$ 得到的。

维护一个 `t2`, `t3`, `t5`，`t2` 当前丑数中乘上 $$2$$ 就比当前最大丑数要大的丑数位置。

```cpp
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> uglyNumber;
        uglyNumber.push_back(1);
        
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < index; i++) {
            uglyNumber.push_back(min(uglyNumber[t2] *2, min(uglyNumber[t3] * 3, uglyNumber[t5] * 5)));
            
            while (uglyNumber[i] >= uglyNumber[t2] * 2) t2++;
            while (uglyNumber[i] >= uglyNumber[t3] * 3) t3++;
            while (uglyNumber[i] >= uglyNumber[t5] * 5) t5++;
        }
        
        return uglyNumber[index - 1];
    }
};
```

时间复杂度：$$O(n)$$

## [第一个只出现一次的字符](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

开个 `map` 记一下。


```cpp
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> m;
        
        for (const auto &c : str) m[c]++;
        
        for (int i = 0; i < str.length(); i++) {
            if (m[str[i]] == 1) return i;
        }
        
        return -1;
    }
};
```

时间复杂度：$$O(n)$$

## [数组中的逆序对](https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

利用归并排序的方法做到 $$O(nlogn)$$ 的复杂度。

举例：归并的 `left` 是 `[3, 4]`，`right` 是 `[1, 2]`。

归并的时候，`leftpointer` 在 `3` 处，`rightpointer` 在 `1` 处，`3 > 1` 可以得到 `3` 及 `3` 后面的数都会和 `1` 组成逆序对。所以逆序对 `+2`。

```cpp
class Solution {
private:
    const long long mod = 1000000007LL;
public:
    long long GetFromMerge(vector<int>& data, int left, int right) {
        if (left == right) return 0LL;
        
        int mid = left + (right - left) / 2;
        long long leftCount = GetFromMerge(data, left, mid);
        long long rightCount = GetFromMerge(data, mid + 1, right);
        long long mergeCount = 0;
        
        vector<int> merge;
        int pl = left, pr = mid + 1;
        while (pl <= mid || pr <= right) {
            if (pl <= mid && pr <= right) {
                if (data[pl] > data[pr]) {
                    mergeCount = (mergeCount + mid - pl + 1) % mod;
                    merge.push_back(data[pr++]);
                } else {
                    merge.push_back(data[pl++]);
                }
            } else {
                if (pl <= mid) {
                    merge.push_back(data[pl++]);
                } else {
                    merge.push_back(data[pr++]);
                }
            }
        }
        
        for (int i = left; i <= right; i++) {
            data[i] = merge[i - left];
        }
        
        return ((leftCount + rightCount) % mod + mergeCount) % mod;
    }
    
    int InversePairs(vector<int> data) {
        return (int)GetFromMerge(data, 0, data.size() - 1);
    }
};
```

时间复杂度：$$O(nlogn)$$

## [两个链表的第一个公共结点](https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

求出两个链表长度，求出差值 `x`，长的那个先走 `x` 步。

```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int l1 = 0, l2 = 0;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        
        while (p1) {
            l1++;
            p1 = p1 -> next;
        }
        while (p2) {
            l2++;
            p2 = p2 -> next;
        }
        
        p1 = pHead1; p2 = pHead2;
        int diff = abs(l1 - l2);
        if (l1 > l2) {
            while (diff--) {
                p1 = p1 -> next;
            }
        } else {
            while (diff--) {
                p2 = p2 -> next;
            }
        }
        
        while (p1 != p2) {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        return p1;
    }
};
```


时间复杂度：$$O(n)$$

## [数字在排序数组中出现的次数](https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

相当于 `upper_bound() - lower_bound()`。

```cpp
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        // return upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k);
        
        int left = 0, right = data.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (data[mid] <= k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int upper = left;
        
        left = 0, right = data.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (data[mid] < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int lower = left;
        
        return upper - lower;
    }
};
```

时间复杂度：$$O(logn)$$

## [二叉树的深度](https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

递归一下。

```cpp
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot) return 0;
        int left = 0, right = 0;
        
        if (pRoot -> left) left = TreeDepth(pRoot -> left);
        if (pRoot -> right) right = TreeDepth(pRoot -> right);
        
        return max(left, right) + 1;
    }
};
```

时间复杂度：$$O(n)$$

## [平衡二叉树](https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

平衡二叉树俩性质：

- 子树是平衡二叉树
- 左右子树高度差小于等于 1

俩都是相同形式的递归，如果重复写的话复杂度会达到 $$O(n^2)$$。剪枝一下，算高度的时候，用 `-1` 来表示该子树不是平衡二叉树了，避免重复计算。

```cpp
class Solution {
public:
    int height(TreeNode* pRoot) {
        if (!pRoot) return 0;
        int left = height(pRoot -> left);
        int right = height(pRoot -> right);
        
        return left != -1 && right != -1 && abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return height(pRoot) != -1;
    }
};
```

时间复杂度：$$O(n)$$

## [数组中只出现一次的数字](https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

先求出总的异或值。

`x & (-x)` 会得到 `x` 二进制里最右边的的 1，其他位都置为 0，记为 `seg`。

于是根据根据 `seg` 按位与，可以将原数组分成两组，两个数字会分到两个组里。很妙的解法。


```cpp
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int x = 0;
        for (const auto& d : data) x ^= d;
        
        int seg = x & (-x);
        *num1 = 0, *num2 = 0;
        for (const auto& d : data) {
            d & seg ? *num1 ^= d : *num2 ^= d;
        }
    }
};
```

时间复杂度：$$O(n)$$

## [和为S的连续正数序列](https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

用一个窗口来做。


```cpp
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int const largest = (sum + 1) / 2;
        int left = 1, right = 2;
        
        vector<vector<int>> res;
        while (right <= largest) {
            // 有溢出风险
            int now = (left + right) * (right - left + 1) / 2;
            
            if (now == sum) {
                vector<int> match;
                for (int i = left; i <= right; i++) match.push_back(i);
                res.push_back(match);
                left++;
            } else if (now < sum) {
                right++;
            } else {
                left++;
            }
        }
        
        return res;
    }
};
```

时间复杂度：$$O(n)$$

看到别人有种 $$O(sqrt{n})$$ 的方法，根据通项公式确定序列长度的最大值，然后一边遍历一边根据长度的奇偶确定是否符合条件。


## [和为S的两个数字](https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

搞个哈希表存一下。

```cpp
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        
        unordered_set<int> s;
        for (const int& num : array) {
            if (s.find(sum - num) != s.end()) {
                if (!res.empty() && res[0] * res[1] > (sum - num) * num) {
                    res.clear();
                }
                
                res.push_back(sum - num);
                res.push_back(num);
            }
            
            s.insert(num);
        }
        
        return res;
    }
};
```

时间复杂度：$$O(n)$$

## [左旋转字符串](https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

没啥好讲的。。

```cpp
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length(); 
        if (len == 0) return str;
        
        n %= len;
        return str.substr(n, len - n) + str.substr(0, n);
    }
};
```

时间复杂度：$$O(n % len)$$

## [翻转单词顺序列](https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

整体反转再局部反转。

```cpp
class Solution {
private:
    void reverse(string& str, int left, int right) {
        while (left < right) {
            swap(str[left++], str[right--]);
        }
    }
    
public:
    string ReverseSentence(string str) {
        reverse(str, 0, str.length() - 1);
        
        int now = 0;
        while (now < str.length()) {
            while (now < str.length() && str[now] == ' ') now++;
            
            int end = now;
            while (end < str.length() && str[end] != ' ') end++;
            reverse(str, now, end - 1);
            now = end + 1;
        }
        
        return str;
    }
};
```

时间复杂度：$$O(n)$$

## [扑克牌顺子](https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

一开始直接模拟做了。

```cpp
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() == 0) return false;
        sort(numbers.begin(), numbers.end());
        
        int any = 0;
        bool continuous = true;
        bool begin = true;
        int last;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == 0) any++;
            else {
                if (begin) {
                    begin = false;
                } else {
                    while (numbers[i] != last + 1 && any) {
                        any--; last++;
                    }
                    
                    if (numbers[i] != last + 1){
                        continuous = false;
                        break;
                    }
                }
                
                last = numbers[i];
            }
        }
        
        return continuous;
    }
};
```

看了下别人的解答。其实要满足两个条件就可以了：

- 除 0 之外没有重复的数
- 除 0 之外，`max - min = 5`

```cpp
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5) return false;
        
        int mx = -1, mn = 14;
        int flag = 0;
        for (const auto& num : numbers) {
            if (num == 0) continue;
            if (flag & (1 << num)) return false;
            
            flag = flag | (1 << num);
            mx = max(mx, num);
            mn = min(mn, num);
        }
        
        return mx - mn < 5;
    }
};
```


时间复杂度：$$O(n)$$

## [孩子们的游戏(圆圈中最后剩下的数)](https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

[约瑟夫环](https://pwxcoo.gitbook.io/algorithm/summary/josephus_circle)。

```cpp
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0) return -1;
        
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = (res + m) % i;
        }
        return res;
    }
};
```

时间复杂度：$$O(n)$$

## [求1+2+3+...+n](https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=3)

利用短路运算符。（但是我感觉这个题目没什么意义= =）

```cpp
class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};
```

时间复杂度：$$O(logn)$$

## [不用加减乘除做加法](https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

`a + b = (a ^ b) + ((a & b) << 1)`。左边表示运算后的结果，右边表示进位。

```cpp
class Solution {
public:
    int Add(int num1, int num2)
    {
        // a + b = (a ^ b) + ((a & b) << 1);
        while (num2) {
            int result = num1 ^ num2;
            int extra = (num1 & num2) << 1;
            
            num1 = result;
            num2 = extra;
        }
        
        return num1;
    }
};
```

时间复杂度：$$O(logn)$$

## [把字符串转换成整数](https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

字符串转整型，学问多着呢。。测试用例也只考虑了：

- 正负号
- 超出 `int32` 范围
- 非法字符

```cpp
class Solution {
public:
    int StrToInt(string str) {
        int n = str.size(), s = 1;
        long long res = 0;
        if(!n) return 0;
        if(str[0] == '-') s = -1;
        for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0; i < n; ++i){
            if(!('0' <= str[i] && str[i] <= '9')) return 0;
            res = res * 10 + str[i] - '0';
        } 
        
        res *= s;
        return res > (int)0x7fffffff || res < (int)0x80000000 ? 0 : res;
        // return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};
```

时间复杂度：$$O(length(str))$$

## [数组中重复的数字](https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

尝试把每个数字归位，要是有重复的时候归位的时候就会碰到。

```cpp
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i = 0; i < length;) {
            if(numbers[i] == i) { 
                i++;
                continue;
            }
            
            if(numbers[numbers[i]] == numbers[i]) {
                (*duplication) = numbers[i];
                return true;
            } else {
                swap(numbers[numbers[i]], numbers[i]);
            }
        }
        return false;
    }
};
```

时间复杂度：$$O(n)$$
空间复杂度：$$O(1)$$

## [构建乘积数组](https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

前缀积和后缀积。

```cpp
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> L(n);
        vector<int> R(n);
        vector<int> res(n);
        
        L[0] = A[0];
        for (int i = 1; i < n; i++) {
            L[i] = L[i - 1] * A[i];
        }
        
        R[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            R[i] = R[i + 1] * A[i];
        }
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                res[i] = R[1];
            } else if (i == n - 1) {
                res[i] = L[n - 2];
            } else {
                res[i] = L[i - 1] * R[i + 1];
            }
        }
        
        return res;
    }
};
```

时间复杂度：$$O(n)$$

## [正则表达式匹配](https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

以前用 dp 搞了一波，好像有别的写法。暂时懒得写。。下次再补。。

```cpp

```

时间复杂度：$$$$

## [表示数值的字符串](https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```cpp

```

时间复杂度：$$$$

## [字符流中第一个不重复的字符](https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

一个 map，一个 queue。

map 用来记录有多少个字符，如果是第一次出现的，就插到 queue 里。后续重复插入后，在返回的时候懒删除就好了。

```cpp

```

时间复杂度：$$O(1)$$

## [链表中环的入口结点](https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

1、设置快慢指针，假如有环，他们最后一定相遇。
2、两个指针分别从链表头和相遇点继续出发，每次走一步，最后一定相遇与环入口。

[之前在 gist 贴过推导。](https://gist.github.com/pwxcoo/b676c2053716930570b39ea730791e75)

```cpp

```

时间复杂度：$$O(n)$$

## [删除链表中重复的结点](https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)


```cpp

```

时间复杂度：$$$$

## [二叉树的下一个结点](https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

1. 如果有右节点，返回右节点最左边的那个节点。
2. 如果没有右节点，该节点不能是根节点（是根的话就没有下一个了）。找到父节点：
    - 该节点是父节点的左孩子，返回父节点。
    - 该节点是父节点的右孩子，继续找父节点重复步骤二

```cpp

```

时间复杂度：$$$$

## [对称的二叉树](https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

递归，一左一右。

```cpp

```

时间复杂度：$$$$

## [按之字形顺序打印二叉树](https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

可以用两个栈。

```cpp

```

时间复杂度：$$$$

## [把二叉树打印成多行](https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=11213&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

层次遍历。不过要区分开哪个是那一层的节点，可以维护俩变量，一个表示当前层节点数，一个表示下一层节点数。

```cpp

```

时间复杂度：$$$$

## [序列化二叉树](https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

这个题目的测试用例有点憨= =。其实 leetcode 上那种就是比较好的序列化方法。

```cpp

```

时间复杂度：$$$$

## [二叉搜索树的第k个结点](https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

中序遍历的第 k 个节点。

```cpp

```

时间复杂度：$$$$

## [数据流中的中位数](https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

数据分成两半。小的放左边的大顶堆，大的放右边的小顶堆。

- 为了保证数据均匀分配。根据奇偶来选择插哪个堆
- 为了保证左边永远小于右边，每次插的时候，根据两边的堆顶值来调整一下。

```cpp
class Solution {
private:
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int> > R;
   
public:
    void Insert(int num) {
        if((L.size() + R.size()) % 2 == 1) {
            num > L.top() ? (R.push(num)) : (R.push(L.top()), L.pop(), L.push(num));
        } else {
            R.empty() || num < R.top() ? (L.push(num)) : (L.push(R.top()), R.pop(), R.push(num));
        }
    }
 
    double GetMedian() {
        return (L.size() + R.size()) % 2 == 1 ?
            1.0 * L.top() :
            1.0 * (L.top() + R.top()) / 2.0;
    }

};
```

时间复杂度：插入：$$O(logn)$$，查询：$$O(1)$$


## [滑动窗口的最大值](https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

单调队列（Monotonic Queue）。只关心窗口里的最大值。


```cpp
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        
        deque<int> dq;
        for (int i = 0; i < num.size(); i++) {
            if (!dq.empty() && dq.front() == i - size) dq.pop_front();
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= size - 1) res.push_back(num[dq.front()]);
        }
        
        return res;
    }
};
```

时间复杂度：$$O(n)$$

## [矩阵中的路径](https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

dfs。

```cpp

```

时间复杂度：

## [机器人的运动范围](https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

dfs。

```cpp

```

时间复杂度：

## [剪绳子](https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8?tpId=13&tqId=33257&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

找规律的题，很精妙。

贴一下别人的分析在注释里：

```cpp
/**
 * 题目分析：
 * 先举几个例子，可以看出规律来。
 * 4 ： 2*2
 * 5 ： 2*3
 * 6 ： 3*3
 * 7 ： 2*2*3 或者4*3
 * 8 ： 2*3*3
 * 9 ： 3*3*3
 * 10：2*2*3*3 或者4*3*3
 * 11：2*3*3*3
 * 12：3*3*3*3
 * 13：2*2*3*3*3 或者4*3*3*3
 *
 * 下面是分析：
 * 首先判断k[0]到k[m]可能有哪些数字，实际上只可能是2或者3。
 * 当然也可能有4，但是4=2*2，我们就简单些不考虑了。
 * 5<2*3,6<3*3,比6更大的数字我们就更不用考虑了，肯定要继续分。
 * 其次看2和3的数量，2的数量肯定小于3个，为什么呢？因为2*2*2<3*3，那么题目就简单了。
 * 直接用n除以3，根据得到的余数判断是一个2还是两个2还是没有2就行了。
 * 由于题目规定m>1，所以2只能是1*1，3只能是2*1，这两个特殊情况直接返回就行了。
 *
 * 乘方运算的复杂度为：O(log n)，用动态规划来做会耗时比较多。
 */

class Solution {
public:
    int cutRope(int number) {
        if (number == 2) return 1;
        if (number == 3) return 2;
        
        int x = number % 3;
        int y = number / 3;
        
        if (x == 0) {
            return pow(3, y);
        } else if (x == 1) {
            return 2 * 2 * pow(3, y - 1);
        } else {
            return x * pow(3, y);
        }
    }
};
```

时间复杂度：$$logn$$