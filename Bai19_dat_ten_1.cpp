#include<bits/stdc++.h>
using namespace std;

int n, k;
int ans;
int visited[35];
string ss;
set<string>resul;

void Try(string a[], int i)
{
	for(int j = 1; j <= ans; j++)
	{
		if(j > visited[i-1] || i == 1)
		{
			if(i == 1)
				ss+=a[j];
			else
				ss = ss+" "+a[j];
				
			visited[i] = j; 	// lưu index từ thứ i trong mảng a[].
			
			if(i == k)
				resul.insert(ss);
			else if(i < k)
				Try(a,i+1);
			
			int m = a[j].length();
			if(i != 1)
				ss.erase(ss.length()-m-1);
			else
				ss="";
		}
	}	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	set<string> st;
	cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		cin>>s;
		st.insert(s);
	}
	
	int m = st.size();
	string a[m+5];
	ans = 0;
	for(string x:st)
	{
		a[++ans] = x;
	}
	
//	for(int i = 1; i <= ans; i++)
//		cout<<a[i]<<" ";
//	cout<<endl;	

	ss = "";
	Try(a,1);
	for(string x:resul)
		cout<<x<<endl;

	return 0;
}

// vẫn có cách làm nhanh và hay hơn.

