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


## []