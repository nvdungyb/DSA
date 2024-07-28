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

int ok;

struct node *make_tree(struct node *root, int a, int b, int c)
{
	if(root == NULL)
		return NULL;
	
	if(root->data == a)
	{
		if(c == 'L'){
			root->left = new node(b);
		}
		else{
			root->right = new node(b);
		}
			
		ok = 1;
	}else{
		root->left = make_tree(root->left, a, b, c);
		if(!ok)
			root->right = make_tree(root->right, a, b, c);
	}
	
	return root;
}

int identical(struct node* root1, struct node *root2)
{
	if(root1 == NULL && root2 == NULL)
		return 1;
	if(root1 && root2)
	{
		if(identical(root1->left, root2->left) && root1->data == root2->data && identical(root1->right, root2->right))
			return 1;
				
		return 0;
	}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m;
	cin>>t;
	while(t--)
	{
		int a, b;
		char c;
		cin>>n;
		n--;
		cin>>a>>b>>c;
		
		struct node *root1 = new node(a);
		root1 = make_tree(root1,a,b,c);
		
		while(n)
		{
			ok = 0;
			cin>>a>>b>>c;
			root1 = make_tree(root1, a, b, c);
			n--;
		}
		
		cin>>m;
		cin>>a>>b>>c;
		
		struct node *root2 = new node(a);
		root2 = make_tree(root2,a,b,c);
		m--;
		
		while(m)
		{
		    ok = 0;
			cin>>a>>b>>c;
			root2 = make_tree(root2, a, b, c);
			m--;
		}
	 	
	 	cout<<identical(root1,root2);
		
		cout<<endl;
	}
	

	return 0;
}