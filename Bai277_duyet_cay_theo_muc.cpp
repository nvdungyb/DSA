#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	struct node* left, *right;
	node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

struct node* make_tree(struct node* root, int par, int val, int edge)
{
	if(root == NULL)
		return root;
	
	if(root->data == par)
	{
		struct node* ans = new node(val);
		if(edge == 'L'){
			root->left = ans;
		}else{
			root->right = ans;
		}
	}
	
	root->right = make_tree(root->right,par,val,edge);
	root->left = make_tree(root->left,par,val,edge);
	
	return root;
}


void levelOrder(struct node* root)
{
	queue<struct node*> que;
	que.push(root);
	while(!que.empty())
	{
		struct node* ans = que.front();
		que.pop();
		cout<<ans->data<<" ";
		
		if(ans->left != NULL)
			que.push(ans->left);
		if(ans->right != NULL)
			que.push(ans->right);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, par, val;
	char edge;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>par>>val>>edge;
		struct node* root = new node(par);
		make_tree(root,par,val,edge);
		
		for(int i = 1; i < n; i++)
		{
			cin>>par>>val>>edge;
			make_tree(root,par,val,edge);
		}
		
		levelOrder(root);
		
		cout<<endl;
	}


	return 0;
}

// That tree may be not a bst.
