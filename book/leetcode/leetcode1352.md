## Intuition

后缀积。

----

用前缀积来做。特别注意 `0` 的情况，一旦有 `0`，就不关心前面的数字，所以在处理零的时候，清空 `vector`。

PS：有一种做法是在 `vector` 里放一个 `1` 方便计算。

## Solution

```cpp
class ProductOfNumbers {
private:
    vector<int> nums;
public:
    ProductOfNumbers() {
        nums.clear();
    }
    
    void add(int num) {
        if (num == 0) {
            nums.clear();
            return;
        }
        
        nums.push_back(nums.empty() ? num : nums[nums.size() - 1] * num);
    }
    
    int getProduct(int k) {
        if (k > nums.size()) return 0;
        return nums[nums.size() - 1] / (nums.size() == k ? 1 : nums[nums.size() - 1 - k]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
```

时间复杂度：都是 $$O(1)$$