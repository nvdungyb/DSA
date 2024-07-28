#include<bits/stdc++.h>
using namespace std;
 
int n, check;
int b[15], visited[15];

void display()
{
	for(int i = 1; i <= n; i++)
		cout<<b[i];
	cout<<endl;	
}

void Try(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(!visited[j])
		{
			if(abs(j-b[i-1]) > 1 || i == 1)
			{
				b[i] = j;
				visited[j] = true;
				if(i == n)
					display();
				
				else
					Try(i+1);
				visited[j] = false;
			}
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
		cin>>n;
		memset(b, 0, sizeof(b));
		memset(visited, false, sizeof(visited));
		Try(1);
	
	}	
  
	
	return 0;
}