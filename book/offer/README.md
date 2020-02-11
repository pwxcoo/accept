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