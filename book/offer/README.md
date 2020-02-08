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