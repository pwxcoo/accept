/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    归并排序
 */

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int l = m - 1, r = n - 1, pos = m + n - 1;
        while(pos >= 0)
        {
            if(l >= 0 && r >= 0)
                nums1[pos--] = nums1[l] > nums2[r] ? nums1[l--] : nums2[r--];
            else if(l < 0 && r >= 0)
                nums1[pos--] = nums2[r--];
            else break;
        }
    }
}