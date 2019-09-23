#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int partition(ll arr[], int l, int r, int k);
ll findMedian(ll arr[], int n);
ll median(ll arr[], int l, int r, int k);
void swap(ll *a, ll *b);

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    ll d[n];
    for(int i=0;i<n;i++){
      ll a,b;
      cin>>a>>b;
      d[i]=a*a+b*b;
    }
    ll radius = median(d,0,n-1,(n+1)/2);
    cout<<sqrt(radius)<<endl;
  }
  return 0;
}

int partition(ll d[], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (d[i] == x)
           break;
    swap(&d[i], &d[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (d[j] <= x)
        {
            swap(&d[i], &d[j]);
            i++;
        }
    }
    swap(&d[i], &d[r]);
    return i;
}

void swap(ll *a, ll *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

ll findMedian(ll d[], int n)
{
    sort(d, d+n);
    return d[n/2];
}

ll median(ll d[], int l, int r, int k)
{
  int n = r-l+1;
  int i;
  ll med[(n+4)/5];
  for (i=0; i<n/5; i++)
      med[i] = findMedian(d+l+i*5, 5);
  if (i*5 < n)
  {
      med[i] = findMedian(d+l+i*5, n%5);
      i++;
  }
  ll medOfMed = (i == 1)? med[i-1]:
                           median(med, 0, i-1, i/2);

  int pos = partition(d, l, r, medOfMed);

  if (pos-l == k-1)
      return d[pos];
  if (pos-l > k-1)
      return median(d, l, pos-1, k);

  return median(d, pos+1, r, k-pos+l-1);
}
