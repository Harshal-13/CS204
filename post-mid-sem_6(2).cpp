#include <bits/stdc++.h>
using namespace std;
#define M 10000007
#define ll long long
#define PB push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

static bool hash_table[4][M];
static ll pr[4]={53,2311,13331,123457};

ll choice(char c)
{
    if(c>='a'&&c<='z')
    {
        return (ll)(c-'a'+1);
    }
    else
        return (ll)(c-'A'+27);
}

ll func(string &s,ll p)
{
    ll n=s.size();
    ll r=1;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ans+=(r*choice(s[i]))%M;
        ans%=M;
        r*=p;
        r%=M;
    }
    return ans;
}

int main()
{
    io
    ll n;
    cin>>n;
    vector<string> v;
    while(n--)
    {
        string s;
        cin>>s;
        string t=s;
        reverse(t.begin(),t.end());
        if(s!=t)
        {
            v.PB(s);
            for(int j=0;j<4;j++)
            {
                hash_table[j][func(t,pr[j])]=true;
            }
        }
    }
    for(auto s:v)
    {
        bool flag=true;
        for(int j=0;j<4;j++)
        {
            if(hash_table[j][func(s,pr[j])]==false) flag=false;
        }
        if(flag==true)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}
