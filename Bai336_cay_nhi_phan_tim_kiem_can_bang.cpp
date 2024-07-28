#include<bits/stdc++.h>
using namespace std;


// Cài đặt cây AVL.

struct node{
	int data;
	int height;
	struct node *left, *right;
	node(int val)
	{
		data = val;
		height = 1;
		left = right = NULL;	
	}
};

int height(struct node *root)
{
	if(root == NULL)
		return 0;
	return root->height;
}

int getbalance(struct node *root)
{
	if(root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

struct node *rightRotate(struct node *root)
{
	struct node *x = root->left;
	struct node *y = x->right;

	x->right = root;
	root->left = y;
	
	// cập nhật lại độ cao của các node.
	root->height = max(height(root->left), height(root->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	
	return x;
}

struct node *leftRotate(struct node *root)
{
	struct node *x = root->right;
	struct node *y = x->left;
	
	x->left = root;
	root->right = y;
	
	// cập nhật lại độ cao các node.
	root->height = max(height(root->left), height(root->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	
	return x;
}

struct node *make_tree(struct node *root, int val)
{
	if(root == NULL){
		return new node(val);
	}
	
	if(val > root->data)
		root->right = make_tree(root->right,val);
	else
		root->left = make_tree(root->left,val);
	
	// cập nhật lại độ cao.
	root->height = max(height(root->left), height(root->right))+1;
	
	int balance = getbalance(root);
	
	// TH1: cây lệch Left left.
	if(balance > 1 && val < root->left->data)
		return rightRotate(root);
	
	// TH2: cây lệch right right.
	if(balance < -1 && val > root->right->data)
		return leftRotate(root);
	
	// TH3: cây lệch left right.
	if(balance > 1 && val > root->left->data)
	{
		root->left = leftRotate(root->left);
		return  rightRotate(root);
	}
	
	// TH3: cây lệch right left.
	if(balance < -1 && val < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}

void pre_order(struct node *root)
{
	if(root == NULL)
		return;
	
	cout<<root->data<<" ";
	pre_order(root->left);
	pre_order(root->right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		cin>>x;
		struct node *root = new node(x);
		n--;
		
		while(n--)
		{
			cin>>x;
			root = make_tree(root,x);
		}
		cout<<root->data;
			
		cout<<endl;
	}

 
	return 0;
}
