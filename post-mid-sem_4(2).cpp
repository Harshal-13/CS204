#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define PB push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<vll> arr;
ll color[1000001];
ll f=0;
void DFS(ll n, ll c)
{
  if(color[n]!=c && color[n]!=0)
  {
    f=1;
    return;
  }
  else if(color[n]==c)return;

  color[n]=c;
  if(c==1)c=2;
  else c=1;

  for(auto x : arr[n])
  {
    DFS(x,c);
  }
}

int main()
{
  string n;
  ll m;
  cin>>n>>m;

  map<ll,ll>mp;
  ll t1=0;
  for(ll i=0;i<m;i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    if(mp.find(a)==mp.end())
    {
      vll temp;
      arr.PB(temp);
      mp[a]=t1;
      t1++;
    }
    if(mp.find(b)==mp.end())
    {
      vll temp;
      arr.PB(temp);
      mp[b]=t1;
      t1++;
    }

    if(c%2)
    {
      arr[mp[a]].PB(mp[b]);
      arr[mp[b]].PB(mp[a]);
    }
    else
    {
      vll temp;
      arr.PB(temp);

      arr[mp[a]].PB(t1);
      arr[t1].PB(mp[a]);
      arr[mp[b]].PB(t1);
      arr[t1].PB(mp[b]);
      t1++;
    }
  }

  for(ll i=0;i<t1;i++)
  {
    if(color[i])continue;
    DFS(i,1);
    if(f)
    {
      cout<<"YES"<<endl;
      return 0;
    }
  }

  cout<<"NO"<<endl;
  return 0;
}
