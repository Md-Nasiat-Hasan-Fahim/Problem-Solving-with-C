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

int quer(int l, int r, vector<vector<int>> &rmq,int n)
{
    int j=0;
    int x=r-l+1;
    for(int i=0;i<32;i++)
    {
        if((1LL<<i)<=x) j=i;
    }
    //cout<<j<<endl;
    int gc=rmq[l][j];
    //cout<<gc<<endl;
    if(l+(1LL<<j)<n)
    gc = __gcd(rmq[l][j],rmq[r-(1LL<<j)+1][j]);
    return gc;
}

int abc(vector<vector<int>> &rmq, int n)
{
    int lo = 0;
    int hi = 0;
    int cnt = 0;
    int gc = rmq[0][0];
    for(;hi<n;hi++)
    {
        //cout<<lo<<" "<<hi<<" "<<quer(lo,hi,rmq,n)<<endl;
        while(lo<=hi&&quer(lo,hi,rmq,n)==1)
        {
            cout<<lo<<" "<<hi<<endl;
            cnt=max(cnt,hi-lo);
            lo++;
        }
    }
    cnt=max(hi-lo,cnt);
    return cnt;
}

void cons(vector<int> &vec, vector<vector<int>> &rmq, int n)
{
    for(int i=0;i<n;i++) rmq[i][0]=vec[i];
    for(int i=0;i<n-1;i++)
    {
        rmq[i][1]=labs(vec[i]-vec[i+1]);
    }
    rmq[n-1][1]=1;
    for(int j=2;j<32;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(i+(1<<(j-1))<n)
            rmq[i][j]=__gcd(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
            else rmq[i][j]=rmq[i][j-1];
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        vector<vector<int>>rmq(n+1,vector<int>(32));
        cons(vec,rmq,n);
        cout<<abc(rmq,n)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
