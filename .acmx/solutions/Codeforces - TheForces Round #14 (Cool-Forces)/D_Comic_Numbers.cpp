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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}
int l,r;
int cq(int x)
{
    return 1LL*x*x*x;
}

int ct(int i)
{
    int p = cq(i)-1;
    int q = cq(i+1)-1;
    return (q/i)-(p/i);
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    const int x = 1e6+10;
    vector<int>vec(x);
    for(int i=1;i<x;i++)
    {
        
        vec[i]=ct(i);
        vec[i]+=vec[i-1];
    }
    for(int z=1;z<=t;z++)
    {
        cin>>l>>r;
        int x = cbrtl(l);
        int y = cbrtl(r);
        int cnt = 0 , cnt1 = 0, cnt2 = 0;
        int p = max(l-1,cq(x)-1);
        int q = min(r,cq(x+1)-1);
        cnt1 = (q/x)-(p/x);
        if(y-x==0)
        {
            cout<<cnt1<<endl;
            continue;
        }
        p = max(l-1,cq(y)-1);
        q = min(r,cq(y+1)-1);
        cnt2 = (q/y)-(p/y);
        x++;y--;
        if(x<=y) cnt = vec[y]-vec[x-1];
        cout<<cnt+cnt1+cnt2<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
