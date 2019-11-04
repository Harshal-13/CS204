#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define PB push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll v, e;
vll id, nodes, edges;
vector<pair<ld, pair<ll, ll> > >points;

ll find(ll x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void uni(ll x, ll y)
{
    ll p = find(x);
    ll q = find(y);
    id[p] = id[q];
}

ll Max_Spamming_Tree(vector<pair<ld, pair<ll, ll> > >p)
{
    ll x, y, cost, maxcost = 1;
    for(ll i = 0;i < e;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(find(x) != find(y))
        {
            maxcost *= cost;
            uni(x, y);
        }    
        maxcost = maxcost%M;
    }
    return maxcost;
}

bool compare(pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b)
{
	return a.first>b.first;
}

int main()
{
	ll x, y, w, maxcost;
	cin>>v>>e;
    id.resize(v);
    nodes.resize(v);
    edges.resize(e);
    points.resize(e);
	for(ll i = 0;i < v;++i) id[i] = i;

	for(ll l = 0; l<e; ++l)
	{
		cin >> x >> y >> w;
		points[l] = make_pair(w, make_pair(x,y));
	}
	sort(points.begin(), points.end(), compare);
	maxcost = Max_Spamming_Tree(points);
	cout << maxcost << endl;
	return 0;
}