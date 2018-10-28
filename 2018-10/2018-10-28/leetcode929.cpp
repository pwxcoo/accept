class Solution {
public:
    string getlocal(string s)
    {
        int len = s.length();
        string res = "";
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '+') break;
            else if (s[i] == '.') continue;
            else res += s[i];
        }
        return res;
    }
    string filter(string s)
    {
        int len = s.length();
        int deli = s.find('@');
        string local = getlocal(s.substr(0, deli));
        string domain = s.substr(deli + 1, len - deli + 1);
        return local + "@" + domain;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (auto email: emails)
        {
            s.insert(filter(email));
        }
        return (int)s.size();
    }
};