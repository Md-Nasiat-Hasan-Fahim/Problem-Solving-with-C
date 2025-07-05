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
vector<pair<int,int>>pr;
int cnt,n;

int chk(int x,int y,int flag)
{
    for(int i=0;i<n;i++)
    {
        if(((1<<i)&flag))
        {
            if(pr[i].first==x||pr[i].second==y) return true;
        }
    }
    return false;
}

int abc(int j,int flag)
{
    if(((1<<n)-1)==flag) return 0;
    if(j==n) return INT_MAX;
    int ct = INT_MAX;
    for(int i=j;i<n;i++)
    {
        if(!((1<<i)&flag))
        {
            int cpt = 1-chk(pr[i].first,pr[i].second,flag);
            ct = min(ct,cpt+abc(i+1,(flag|((1<<i)))));
            if(j==0) cout<<i<<" "<<cpt<<" "<<ct<<endl;
        }
    }
    return ct;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        cnt = LONG_LONG_MAX;
        pr.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            pr.pb({a,b});
        }
        cout<<abc(0,0)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
