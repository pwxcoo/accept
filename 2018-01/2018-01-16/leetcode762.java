class Solution {
    public int countPrimeSetBits(int L, int R) { 
        int res = 0;
        for(int i = L; i <= R; i++) 
        {

            int temp = i;
            int count = 0;
            // count = Integer.bitCount(temp)
            while(temp > 0)
            {
                count += temp & 1;
                temp = temp >> 1;
            }
            if(isPrime(count)) res += 1;
        }
        return res;
    }
    
    public boolean isPrime(int x) {
        return (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19);
    }
}