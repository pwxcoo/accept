class Solution {
public:
    string reverse(long long n)
    {
        string res = "";
        while(n)
        {
            res += '0' + n % 10;
            n /= 10;
        }
        return res;
    }
    
    bool is_palindrome(long long n)
    {
        vector<int> p;
        while(n)
        {
            p.push_back(n%10);
            n /= 10;
        }
        int left = 0, right = p.size() - 1;
        while(left < right)
        {
            if (p[left++] != p[right--]) return false;
        }
        return true;
    }
    
    long long concat(long long a, string b)
    {
        long long res = a;
        
        for (int i = 0; i < b.length(); i++)
        {
            a = a * 10 + (b[i] - '0');
        }
        return a;
    }
    
    int superpalindromesInRange(string L, string R) {
        long long l = stoll(L);
        long long r = stoll(R);
        
        queue<long long> q;
        for (int i = 1; i <= 9; i++)
            q.push(i);
        int res = 0;
        while(!q.empty())
        {
            long long t = q.front(); q.pop();
            
            long long one = concat(t, reverse(t/10));
            one = one * one;
            if (one > r) break;
            if (one >= l && is_palindrome(one)) res++;
            
            long long two = concat(t, reverse(t));
            two = two * two;
            if (two >= l && two <= r && is_palindrome(two)) res++;
            
            for (int i = 0; i <= 9; i++)
                q.push(t * 10 + i);
        }
        return res;
    }
};