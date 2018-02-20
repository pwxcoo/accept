/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    用栈模拟操作。
 */

class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int res = 0, cnt = 0;
        for(int i = 0; i < heights.length; i++)
        {
            if(st.empty() || heights[i] >= st.peek())
            {
                st.push(heights[i]);
            }
            else 
            {
                cnt = 0;
                while(!st.empty() && heights[i] < st.peek())
                {
                    res = Math.max(res, ++cnt * st.pop());
                }
                while(cnt-- >= 0) st.push(heights[i]);
            }
        }
        cnt = 0;
        while(!st.empty())
        {
            res = Math.max(res, ++cnt * st.pop());
        }
        return res;
    }
}