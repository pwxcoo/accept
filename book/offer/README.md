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

时间复杂度：$$O(n)$$