#include<bits/stdc++.h>
using namespace std;


struct node{
	char data;
	struct node *left, *right;
	node(char s){
		data = s;
		left = right = NULL;
	}
};

bool check(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/')
		return true;
	return false;
}

string ss;

void in_order(struct node *root)
{
	if(root == NULL)
		return;
	
	in_order(root->left);
	ss += root->data;
	in_order(root->right);
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
		string s;
		cin>>s;
		
		stack<struct node*> st;
		for(int i = 0; i < s.length(); i++)
		{
			struct node *newnode = new node(s[i]);
			if(check(s[i]))
			{
				struct node *node1 = st.top(); st.pop();
				struct node *node2 = st.top(); st.pop();
				
				newnode->left = node2;
				newnode->right = node1;
			}	
			st.push(newnode);
		}
		
		ss = "";
		struct node *root = st.top();
		in_order(root);
		cout<<ss<<endl;
		
	}


	return 0;
}

// Bài tương tự bài biến đổi từ hậu tố sang trung tố sử dụng stack, khác biệt mỗi là thay vì tính luôn kết quả để push vào stack thì ta liên kết các node lại với nhau.
// Với bài biểu diễn cây biểu thức này thì các node lá là các toán hạng, các node trung gian là các toán tử.