#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll,ll>
#define MP make_pair
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll find(ll rank[],ll x)
{
  if(rank[x]==x)return x;
  else return rank[x]=find(rank,rank[x]);
}

void un(ll rank[], ll size[], ll x, ll y)
{
  x=find(rank,x);
  y=find(rank,y);

  if(x==y)return;
  if(size[x]>size[y])swap(x,y);
  rank[x]=y;
  size[y]+=size[x];
}

int main()
{
    io
    ll n,m,k;
    cin>>n>>m>>k;
    map<pll,ll>val;
    ll rank[k],size[k],x[k],y[k];
    for(ll i=0;i<k;i++)
    {
      cin>>x[i]>>y[i];
      rank[i]=i;
      size[i]=1;
      val[MP(x[i],y[i])]=i;
    }
    for(ll i=0;i<k;i++)
    {
      if(val.count(MP(x[i]-1,y[i])) !=0)un(rank, size, i, val[MP(x[i]-1,y[i])]);
      if(val.count(MP(x[i],y[i]+1)) !=0)un(rank, size, i, val[MP(x[i],y[i]+1)]);
      if(val.count(MP(x[i],y[i]-1)) !=0)un(rank, size, i, val[MP(x[i],y[i]-1)]);
      if(val.count(MP(x[i]+1,y[i])) !=0)un(rank, size, i, val[MP(x[i]+1,y[i])]);
    }
    ll ans=0;
    for(ll i=0;i<k;i++)ans=max(ans,size[i]);
    cout<<ans<<endl;
    return 0;
}
