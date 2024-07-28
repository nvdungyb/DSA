#include<bits/stdc++.h>
using namespace std;

int n;
string s;

bool check()		// Cách kiểm tra số lớn dạng xâu có chia hết cho n hay không nhé!
{
	int ans = 0;
	for(int i = 0; i < s.length(); i++)
	{
		ans = ans*10+(s[i]-'0');
		ans %= n;
	}
	if(ans == 0)
		return true;
	return false;
}

void genNext()
{
	int i = s.length()-1;
	while(s[i]=='9' && i >= 0)
	{
		s[i]='0';
		i--;
	}
	if(i == -1)			// Tức nghĩa là s là full 9 sau while s full 0 => số nhỏ nhất lớn hơn s là 9 + full 0 đó.
		s = "9"+s;
	else
		s[i] = '9';		// else sinh số nhỏ nhất lớn hơn nó.
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
		s="9";
		while(!check())
		{
			genNext();
		}
		cout<<s<<endl;
	}

	return 0;
}

// Cách làm nhanh hơn và hiệu quả hơn là dùng queue: tương tự như duyệt BFS.

//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int t, n;
//	cin>>t;
//	while(t--)
//	{
//		cin>>n;
//		
//		queue<long long> que;
//		que.push(9);
//		while(!que.empty())
//		{
//			long long ans = que.front(); 
//			que.pop();
//			if(ans%n == 0){
//				cout<<ans<<endl;
//				break;
//			}else{
//				que.push(ans*10);
//				que.push(ans*10+9);
//			}
//		}
//	}
//
//
//	return 0;
//}
