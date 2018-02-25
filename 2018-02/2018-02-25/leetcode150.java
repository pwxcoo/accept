/**
 * date: 2018-02-25
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    算术运算符的后缀表达式。用栈
 */

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for(String s : tokens)
        {
            if(s.equals("+"))
            {
                int a = st.pop();
                int b = st.pop();
                st.push(a + b);
            }
            else if(s.equals("-"))
            {
                int a = st.pop();
                int b = st.pop();
                st.push(b - a);
            }
            else if(s.equals("*"))
            {
                int a = st.pop();
                int b = st.pop();
                st.push(a * b);
            }
            else if(s.equals("/"))
            {
                int a = st.pop();
                int b = st.pop();
                st.push(b / a);
            }
            else
            {
                st.push(Integer.parseInt(s));
            }
        }
        return st.peek();
    }
}