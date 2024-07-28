#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	struct node *left, *right;
	int level;
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
};


struct node *make_tree(struct node *root, int a)
{
	if(root == NULL)
		return new node(a);
	
	if(a > root->data)
		root->right = make_tree(root->right, a);
	else
		root->left = make_tree(root->left, a);
	
	return root;
}

void in_order(struct node* root)
{
	if(root == NULL)
		return;
	
	in_order(root->left);
	if(root->left == NULL && root->right == NULL)
		cout<<root->data<<" ";
	in_order(root->right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		struct node *root = new node(a[0]);
		for(int i = 1; i < n; i++)
		{
			root = make_tree(root, a[i]);	
		}	
		
		in_order(root);
		
		cout<<endl;
	}
	

	return 0;
}