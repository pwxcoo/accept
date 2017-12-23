class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<Integer>();
        for(int i = 0; i < asteroids.length; i++)
        {
            if(stack.empty() || asteroids[i] > 0)
            {
                stack.push(asteroids[i]);
                continue;
            }
            
            while(true)
            {
                int pre = stack.peek();
                if(pre < 0)
                {
                    stack.push(asteroids[i]);
                    break;
                }
                else if(pre == -asteroids[i])
                {
                    stack.pop();
                    break;
                }
                else if(pre > -asteroids[i])
                {
                    break;
                }
                else   // pre < -asteroids[i]
                {
                    stack.pop();
                    if(stack.isEmpty()){  
                        stack.push(asteroids[i]);  
                        break;  
                    }  
                }
            }
        }
        int[] res = new int[stack.size()];
        int i = stack.size()-1;
        while(!stack.empty())
        {
            res[i--] = stack.pop();
        }
        return res;
    }
}