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
set<int> st;

struct node *make_tree(struct node *root, int a, int b, int c)
{
	if(root == NULL)
		return NULL;
	
	if(root->data == a)
	{
		if(c == 'L')
			root->left = new node(b);
		else
			root->right = new node(b);
		ok = 1;
	}else{
		root->left = make_tree(root->left, a, b, c);
		if(!ok)
			root->right = make_tree(root->right, a, b, c);
	}
	
	return root;
}

void in_order(struct node* root)
{
	if(root == NULL)
		return;
	
	in_order(root->left);
	cout<<root->data<<" ";
	in_order(root->right);
}

void level_order(struct node *root)
{
	int cnt = 1;
	root->level = cnt;
	queue<struct node*> que;
	que.push(root);
	while(!que.empty())
	{
		struct node *ans = que.front();	
		que.pop();
	
		if(ans->left != NULL || ans->right != NULL)
		{
			if(ans->left != NULL){
				ans->left->level = ans->level+1;
				que.push(ans->left);
			}
			if(ans->right != NULL)
			{
				ans->right->level = ans->level+1;
				que.push(ans->right);
			}
			
		}else{
			st.insert(ans->level);
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
		int a, b;
		char c;
		cin>>n;
		n--;
		cin>>a>>b>>c;
		
		struct node *root = new node(a);
		root = make_tree(root,a,b,c);
		
		while(n)
		{
			ok = 0;
			cin>>a>>b>>c;
			root = make_tree(root, a, b, c);
			n--;
		}
		
		st.clear();
		level_order(root);
		
		if(st.size() == 1)
			cout<<"1";
		else
			cout<<"0";
		
		cout<<endl;
	}
	

	return 0;
}
