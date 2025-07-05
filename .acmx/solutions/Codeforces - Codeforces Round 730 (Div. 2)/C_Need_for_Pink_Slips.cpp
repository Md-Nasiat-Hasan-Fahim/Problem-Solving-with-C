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

long double abc(vector<long double> vec, long double v,int c)
{
    if(vec[0]==0.0&&vec[1]==0.0) return c;
    long double cnt=0;
    //cout<<cnt<<endl;
    long double fx = v;
    while(vec[0]>fx)
    {
        if(vec[1]!=0.0) cnt+=(vec[0])*abc({vec[0]-fx,vec[1]+(fx/2.0),vec[2]+(fx/2.0)},v,c+1);
        else cnt+=(vec[0])*abc({vec[0]-fx,vec[1],vec[2]+(fx)},v,c+1);
        fx+=v;
        //cout<<cnt<<endl;
    }
    //cout<<cnt<<endl;
    if(vec[0]!=0.0) 
    {
        if(vec[1]!=0.0) cnt+=(vec[0])*abc({0.0,vec[1]+(vec[0]/2.0),vec[2]+(vec[0]/2.0)},v,c+1);
        else cnt+=(vec[0])*abc({0.0,vec[1],vec[2]+(vec[0])},v,c+1);
    }
    //cout<<cnt<<" "<<c<<endl;
    fx = v;
    //cout<<cnt<<" "<<" YES"<<endl;
    while(vec[1]>fx)
    {
        if(vec[0]!=0.0) cnt+=(vec[1])*abc({vec[0]+(fx/2.0),vec[1]-fx,vec[2]+(fx/2.0)},v,c+1);
        else cnt+=(vec[1])*abc({vec[0],vec[1]-fx,vec[2]+(fx)},v,c+1);
        fx+=v;
    }
    if(vec[1]!=0.0) {
        if(vec[0]!=0.0)
        cnt+=(vec[1])*abc({vec[0]+(vec[1]/2.0),0.0,vec[2]+(vec[1]/2.0)},v,c+1);
        else {cnt+=(vec[1])*abc({vec[0],0.0,vec[2]+(vec[1])},v,c+1);if(c==2)cout<<setprecision(12)<<abc({vec[0],0.0,vec[2]+(vec[1])},v,c+1)<<endl;}
    }
    //cout<<cnt<<" "<<c<<endl;
    cout<<cnt<<" ";
    cnt+=c*vec[2];
    cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<" ";
    cout<<cnt<<" "<<c<<endl;
    return cnt;
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
        long double c,m,p,v;
        cin>>c>>m>>p>>v;
        long double cnt = abc({c,m,p},v,1);
        cout<<setprecision(20)<<cnt<<endl;
        cout<<cnt<<" "<<"DKJSLF"<<endl;
        YES;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
