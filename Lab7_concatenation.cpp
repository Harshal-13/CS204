#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(string a,string b)
{
  ll len=min(a.length(),b.length());
  for(int i=0;i<len;i++)
  {
    if(a[i]>b[i])return true;
    if(a[i]<b[i])return false;
  }
  if(a.length()==b.length())return true;
  else
  {
    if(len==a.length())compare(a,b.substr(len));
    else compare(a.substr(len),b);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s,s+n,compare);
    for(int i=0;i<n;i++)cout<<s[i];
    cout<<endl;
  }
  return 0;
}
