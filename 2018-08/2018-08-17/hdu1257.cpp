#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    int num;
    
    while (scanf("%d", &n) != EOF)
    {
        vector<int> dp = vector<int>();

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);

            auto temp = upper_bound(dp.begin(), dp.end(), num) - dp.begin();
            if (temp < dp.size())
            {
                dp[temp] = num;
            }
            else
            {
                dp.push_back(num);
            }     
        }
        printf("%d\n", dp.size());
    }
    return 0;
}
