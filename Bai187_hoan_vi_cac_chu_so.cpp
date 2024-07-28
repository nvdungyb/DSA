#include<bits/stdc++.h>
using namespace std;



int a[10], 
	ok, n, k;
void init()
{
	for(int i = 1; i <= k; i++)
		a[i] = i;
}

void display()
{
	for(int i = 1; i <= k; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void genNext()
{
	int i = k-1;
	while(a[i] > a[i+1])
	{
		i--;
	}
	if(i == 0)
		ok = 1;
	else{
		int j = k;
		while(a[j] < a[i])
		{
			j--;
		}
		swap(a[i],a[j]);
		
		int l = i+1, r = k;
		while(l < r)
		{
			swap(a[l],a[r]);
			l++, r--;
		}
	}
}

long long min_num(vector<string> vt)
{
	long long Min = INT_MAX, Max = INT_MIN;
	for(string s:vt)
	{
		string ss = "";
		for(int i = 1; i <= k; i++)
		{
			ss+=s[a[i]-1];
		}
		
		long long ans = stol(ss);
		Min = min(Min,ans);
		Max = max(Max,ans);
	}
	
	return Max-Min;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k;
	string s;
	vector<string> vt;
	for(int i = 1; i <= n; i++)
	{
		cin>>s;
		vt.push_back(s);
	}
	
	init();
	int result = INT_MAX;
	while(!ok)
	{
		result = min(result,min_num(vt));
		genNext();
	}
	
	cout<<result;


	return 0;
}
