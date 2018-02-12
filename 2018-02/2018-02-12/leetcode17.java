/**
 * date: 2018-02-12
 * author: pwxcoo
 * complexity: T = O(n*m), S = O(1)
 * describe:    用队列回溯。offer（）= push（）; element() = front(); poll() = pop()
 */

class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> ans = new LinkedList<String>();
        if(digits.isEmpty()) return ans;
        String[] mapping = new String[] {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.add("");
        for(int i = 0; i < digits.length(); i++){
            int x = Character.getNumericValue(digits.charAt(i));
            while(ans.element().length() == i){
                String t = ans.poll();
                for(char s : mapping[x].toCharArray())
                    ans.offer(t+s);
            }
        }
        return ans;
    }
}