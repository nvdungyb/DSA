#include<bits/stdc++.h>
using namespace std;

int n, k, ok;
int a[20];

void genNext()
{
	int i = k;
	while(a[i] == n-k+i)
	{
		i--;
	}
	if(i == 0)
		ok = 1;
	else{
		a[i]++;
		for(int j = i+1; j <= k; j++)
			a[j] = a[j-1]+1;
	}
}

void display()
{
	for(int i = 1; i <= k; i++)
		cout<<char('A'+a[i]-1);
	cout<<endl;
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
		for(int i = 1; i <= k; i++)
			a[i] = i;
	 	
	 	ok = 0;
	 	while(!ok)
	 	{
	 		display();
	 		genNext();
		}
		
	}
		

	return 0;
}
