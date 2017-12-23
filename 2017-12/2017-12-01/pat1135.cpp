#include<cstdio>
#include<cstring>

using namespace std;

int tree[62];
int n;
bool flag;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : left(NULL), right(NULL), val(x) {}
};

int abs(int x)
{
	return x > 0 ? x : -x;
}

void insert(TreeNode* &now, int val)
{
	if (!val) flag = false;   //(1)
	if (!now)
	{
		now = new TreeNode(val);
		return;
	}
	abs(now->val) > abs(val) ? insert(now->left, val) : insert(now->right, val);
}

int check(TreeNode* root)		
{
	if (!root) return 0;
	if (root->val < 0 && ((root->right && root->right->val < 0) || (root->left && root->left->val < 0)))
		flag = false;   //(3) (4)
	int left = check(root->left);
	int right = check(root->right);
	if (left != right) 
		flag = false;			//(5)
	return root->val > 0 ? left + 1 : left;
	
}

int main()
{
	int k, temp;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		//init
		scanf("%d", &n);
		memset(tree, 0, sizeof(tree));
		TreeNode* root = NULL;
		flag = true;

		// generate
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &temp);
			insert(root, temp);
		}

		if (root->val < 0) flag = false;   //(2)
		check(root);
		flag ? printf("Yes\n") : printf("No\n");
	}
	
    return 0;
}
