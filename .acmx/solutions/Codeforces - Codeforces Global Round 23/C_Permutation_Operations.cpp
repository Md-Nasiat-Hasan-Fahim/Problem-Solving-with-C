#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        int mx = 0;
        int j=1;int cnt = 0;int k =0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a+cnt<mx)
            {
                while(a+cnt<mx){cnt+=j;cout<<i+1<<" ";k++;j++;}
            }
            mx = max(mx,a+cnt);
        }
        n-=k;
        while(n>0)
        {
            cout<<"1 ";
            n--;
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
