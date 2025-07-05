#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int double
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

vector<int>vec;

int abc(int x)
{
    int cnt = INT_MIN;
    for(int i=0;i<vec.size();i++)
    {
        cnt=max(cnt,fabs(vec[i]-x));
    }
    return cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        vec.resize(n);
        for(int i=0;i<n;i++) {cin>>vec[i];}
        int l = -10000 ,r = 10000;
        while(r-l>0.0000001)
        {
            int m1 = (2*l+r)/3;
            int m2 = (l+2*r)/3;
            int x = abc(m1);
            int y = abc(m2);
            if(x>y) l = m1;
            else if(x<y) r = m2;
            else {l = m1; r = m2;}
        }
        if(abc(l)<abc(r)) cout<<setprecision(15)<<abc(l)<<" "<<l<<endl;
        else cout<<setprecision(15)<<abc(r)<<" "<<r<<endl;
        //cout<<abc(2)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
