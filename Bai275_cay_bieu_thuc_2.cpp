#include<bits/stdc++.h>
using namespace std;


int n;
struct node{
	string data;
	node *left, *right;
	node(string val)
	{
		data = val;
		left = right = NULL;
	}
};

bool check(string s)
{
	if(s == "+" || s == "-" || s == "*" || s == "/")
		return true;
	return false;
}

// vì đây là cây biểu thức => nỗi node trung gian đều có 2 node con => cây nhị phân đầy đủ (full binary tree).
// vì các node trung gian đại diện cho toán tử và các node lá đại diện cho toán hạng
//	nên ta chỉ xây dựng cây con trái và phải cho toán tử.

node *make_tree(node *root, string a[], int index)
{
	if(index < n)
	{
		node *ans = new node(a[index]);
		root = ans;
		if(check(a[index]))
		{
			root->left = make_tree(root->left, a, 2*index+1);
			root->right = make_tree(root->right, a, 2*index+2);
		}
	}
	
	return root;
}

long long math(long long a, long long b, string s)
{
	if(s == "+")
		return a+b;
	if(s == "-")
		return a-b;
	if(s == "*")
		return a*b;
	if(s == "/")
		return a/b;
	
	return 0;
}

stack<long long> st;

// sử dụng pos_order để thực hiện, tính giá trị của cây biểu thức.
void pos_order(node *root)
{
	if(root == NULL)
		return;
	
	pos_order(root->left);
	pos_order(root->right);
	if(check(root->data))
	{
		long long ans1 = st.top(); st.pop();
		long long ans2 = st.top(); st.pop();
		long long ans = math(ans2,ans1,root->data);
		st.push(ans);
	}else{
		st.push(stoi(root->data));
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		string a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		node *root = make_tree(root, a, 0);
		pos_order(root);
	 
	 	cout<<st.top();
	 	
	 	while(!st.empty())
	 		st.pop();
	 	
		cout<<endl;
	}


	return 0;
}
