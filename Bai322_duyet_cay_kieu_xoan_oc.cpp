#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	node *left, *right;
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

node *make_tree(node *root, int a, int b, char c)
{
	if(root == NULL)
		return NULL;
	
	if(root->data == a)
	{
		if(c == 'L')
			root->left = new node(b);
		else	
			root->right = new node(b);
	}else{
		root->right = make_tree(root->right,a,b,c);
		root->left = make_tree(root->left,a,b,c);
	}
	
	return root;
}

void spiral_order(node *root)
{
//	if(root == NULL)
//		return;
	stack<node *> st1,			// duyet tu phai sang trai.
				 st2;			// duyet tu trai sang phai.
	st1.push(root);
	while(!st1.empty() || !st2.empty())
	{
		node *ans;
		while(!st1.empty())
		{
			ans = st1.top(); st1.pop();
			cout<<ans->data<<" ";
			if(ans->right)
				st2.push(ans->right);
			if(ans->left)
				st2.push(ans->left);
		}
		
		while(!st2.empty())
		{
			ans = st2.top(); st2.pop();
			cout<<ans->data<<" ";
			if(ans->left)
				st1.push(ans->left);
			if(ans->right)
				st1.push(ans->right);
		}	
	}
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
		int a, b; char c;
		cin>>a>>b>>c;
		
		node *root = new node(a);
		root = make_tree(root,a,b,c);
		
		for(int i = 1; i < n; i++)
		{
			cin>>a>>b>>c;
			root = make_tree(root,a,b,c);
		}
		
		spiral_order(root);
		
		cout<<endl;
	}
	

	return 0;
}
