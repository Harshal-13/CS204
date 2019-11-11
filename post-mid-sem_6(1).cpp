#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define PB push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    io
    ll n;
    cin>>n;

    string s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    
    sort(s,s+n);

    for(int i=0 ; i<n;i++)
    {
        string temp = s[i];
        reverse(temp.begin(),temp.end()); 
        if(temp == s[i]) continue;

        if(binary_search(s,s+n,temp))
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
