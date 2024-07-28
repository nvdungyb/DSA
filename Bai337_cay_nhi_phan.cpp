#include<bits/stdc++.h>
using namespace std;


// xây dựng cây nhị phân từ mảng.

struct node{
	int data;
	struct node *left, *right;
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

struct node *make_tree(node *root, int a[], int l, int r)
{
	if(l > r)
		return NULL;
	
	int mid = (l+r)/2;
	root = new node(a[mid]);
	root->left = make_tree(root->left,a,l,mid-1);
	root->right = make_tree(root->right,a,mid+1,r);
	
	return root;
}

int cnt;
void pre_order(node *root)
{
	if(root == NULL)
		return;
	
	if(root->left == NULL && root->right == NULL){
		cnt++;
	}
	pre_order(root->left);
	pre_order(root->right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+1];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		sort(a,a+n);
		
		node *root = make_tree(root,a,0,n-1);
		
		cnt = 0;
		pre_order(root);
		cout<<cnt;
		
		cout<<endl;
	}


	return 0;
}
