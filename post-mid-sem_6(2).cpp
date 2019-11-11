#include <bits/stdc++.h>
using namespace std;
#define M 10000007
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define PB push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<string> hash_table[M];

ll hash_value(string s)
{
    ll x, value = 0;
    int p = 53;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] - 'a' < 25) && (s[i] - 'a' >= 0))
            x = s[i] - 'a';
        else
            x = s[i] - 'A' + 25;

        value += ((x + 1) * p) % M;
        p = p * 53;
    }
    return value;
}

bool search(string s)
{
    ll val = hash_value(s);
    for (int i = 0; i < hash_table[val].size(); i++)
    {
        if (s == hash_table[val][i])
            return true;
    }
    return false;
}

int main()
{
    io
    ll n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp, temp1;
        cin >> temp;
        temp1 = temp;
        hash_table[hash_value(temp)].push_back(temp);

        reverse(temp.begin(), temp.end());
        if (temp == temp1)
            continue;
        if (search(temp))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}