#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

int POW(int x)
{
    if(x==0) return 1;
    int res = POW(x/2);
    res = (res*res);
    if(x%2==1) res*=2;
    return res;
}

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ara[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>ara[i];
            cout<<POW(log2(ara[i]))<<" ";
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
