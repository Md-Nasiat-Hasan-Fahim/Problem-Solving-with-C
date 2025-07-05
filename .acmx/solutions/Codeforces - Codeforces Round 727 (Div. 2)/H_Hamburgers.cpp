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

string s;
int cb,cc,cs,kb,kc,ks,pcb,pcc,pcs,r;

bool abc(int x)
{
    int tem = r;
    int bx = max(0LL,x*cb-kb);
    int cx = max(0LL,x*cc-kc);
    int sx = max(0LL,x*cs-ks);
    //cout<<bx<<" "<<cx<<" "<<sx<<endl;
    int y = min(r/pcb,bx);
    bx-=y;r-=y*pcb;
    y = min(r/pcc,cx);
    cx-=y;r-=y*pcc;
    y = min(r/pcs,sx);
    sx-=y;r-=y*pcs;
    r=tem;
    return (bx==0&&cx==0&&sx==0);
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
        cin>>s;
        cin>>kb>>ks>>kc>>pcb>>pcs>>pcc>>r;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='B') cb++;
            else if(s[i]=='S')cs++;
            else cc++;
        }
        //cout<<kb<<" "<<ks<<" "<<kc<<endl;
        int lo = 0, hi = 1;
        while(abc(hi)) hi*=2;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) lo = mid;
            else hi = mid-1;
        }
        if(abc(hi)) cout<<hi<<endl;
        else cout<<lo<<endl;
        //cout<<abc(2)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
