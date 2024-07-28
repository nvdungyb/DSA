#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	struct node *left, *right;
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
};


struct node *make_tree(struct node *root, int b)
{
	if(root == NULL)
		return new node(b);
	
	if(b > root->data)
		root->right = make_tree(root->right, b);
	else{
		root->left = make_tree(root->left, b);
	}
	
	return root;
}

void in_order(struct node *root)
{
	if(root == NULL)
		return;
	
	in_order(root->left);
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
		int a, b; 
		char c;
		
		n--;
		cin>>a>>b>>c;
		struct node *root = new node(a);
		root = make_tree(root,b);
		
		while(n)
		{
			cin>>a>>b>>c;
			root = make_tree(root,b);
			n--;
		}
		
		in_order(root);
		
		cout<<endl;
	}


	return 0;
}
