#include<bits/stdc++.h>
using namespace std;

int n, k, OK;
int a[35]={0};
string b[35];
set<string> resul;

void genNext()
{
	int i = k;
	while(a[i] == n-k+i)
	{
		i--;
	}
	if(i == 0)
		OK = 1;
	else{
		a[i]++;
		for(int j = i+1; j <= k; j++)
			a[j] = a[j-1]+1;
	}
}

void insert()
{
	string ss="";
	ss+=b[a[1]];
	for(int i = 2; i <= k; i++)
		ss = ss+" "+b[a[i]];
	resul.insert(ss);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k;
	set<string> st;
	string s;
	for(int i = 0; i < n; i++)
	{
		cin>>s;
		st.insert(s);
	}
	
	n = st.size();
	
	int ans = 0;
	for(string x:st)
		b[++ans] = x;
	
	for(int i = 1; i <= k; i++)		// Khởi tạo mảng giá trị a[] để sinh kế tiếp.
		a[i] = i;
	
	OK = 0;
	while(!OK)
	{
		insert();
		genNext();
	}
	
	for(string x:resul)
		cout<<x<<endl;
	

	return 0;
}

// Đây là lấy k trong n xâu xắp xếp theo thứ tự tăng dần bằng sinh kế tiếp.
// Dùng quay lui thì đó là bài 19.