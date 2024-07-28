#include<bits/stdc++.h>
using namespace std;

int n, w, ok;
int sum, fopt;
int b[100], parent[100];

void genNext()
{
	int i = n;
	while(b[i] == 1)
	{
		b[i] = 0;
		i--;
	}
	if(i == 0)
		ok = 1;
	else
		b[i] = 1;
}

bool check(pair<int,int> a[])
{
	int weight = 0;
	for(int i = 1; i <= n; i++)
	{
		weight += a[i].second*b[i];
	}
	if(weight > w)
		return false;
	return true;
}

void tong(pair<int,int> a[])
{
	for(int i = 1; i <= n; i++)
		sum += a[i].first*b[i];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>w;
	pair<int,int> a[n+5];
	for(int i = 1; i <= n; i++)
		cin>>a[i].first;
	
	for(int i = 1; i <= n; i++)
		cin>>a[i].second;
	
	fopt = 0, ok = 0;
	while(!ok)
	{
		sum = 0;
		if(check(a)){
			tong(a);
			if(sum > fopt){
				fopt = sum;
				for(int i = 1; i <= n; i++)
					parent[i] = b[i];
			}
		}
		genNext();
	}
	
	cout<<fopt<<endl;
	for(int i = 1; i <= n; i++)
		cout<<parent[i]<<" ";

	return 0;
}
