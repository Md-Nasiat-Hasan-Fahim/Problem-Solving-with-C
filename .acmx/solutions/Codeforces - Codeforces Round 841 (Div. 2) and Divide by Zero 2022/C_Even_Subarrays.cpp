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

bool abc(int x)
{
    for(int i=2;i*i<=x&&x>1;i++)
    {
        int cnt = 0;
        while(x%i==0) {cnt++;x/=i;}
        if(cnt%2) return true;
    }
    return x>1;
}

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
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        vec.pb(3);
        int cnt = 0;
        bool even = false;
        int lo=-1;
        for(int i=0;i<n+1;i++)
        {
            if(abc(vec[i]))
            {
                if(lo==-1) lo = i;
                else 
                {
                    cnt+=(lo+1)+max(i-lo-1,0LL)+max(0LL,(i-lo-1)*lo);
                    lo = i;
                }
                cout<<cnt<<endl;
            }
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
