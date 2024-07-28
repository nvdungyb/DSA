#include<bits/stdc++.h>
using namespace std;

int n, k;
string ss;
int visited[20];

void Try(int i)
{
	for(int j = 0; j < n; j++)
	{
		if(i == 1 || j > visited[i-1])
		{
			ss+=char('A'+j);
			visited[i] = j;
			
			if(i == k)
				cout<<ss<<" "<<endl;
			else if(i < k)
				Try(i+1);	
				
			ss.erase(ss.length()-1);
		}
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
		cin>>n>>k;
		ss = "";
	 
		Try(1);	
		
	}
		

	return 0;
}

// Giang hồ đồn đại vẫn có cách nhanh hơn, đó là cách sinh tổ hợp.
