#include<cstdio>
#include<cstring>
using namespace std;
//除零

int n;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		int number;
		int num[12];
		while (n--)
		{
			scanf("%d", &number);
			int temp = number, num1 = 0, num2 = 0;
			int len = 0;
			while (temp)
			{			
				num[len++] = temp % 10 + '0';
				temp /= 10;
			}
			num[len] = '\0';
			for (int i = len - 1; i >= len/2; i--)
			{
				num1 = num1 * 10 + (num[i] - '0');
				num2 = num2 * 10 + (num[i - len/2] - '0');
			}

			if (num1 == 0 || number % num1) printf("No\n");
			else {
				temp = number / num1;
				if (num2 == 0 || temp % num2) printf("No\n");
				else printf("Yes\n");
			}
		}
	}
    return 0;
}

