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
        bool neg=false,pos=false;
        int tn = 0, tp = 0;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a<0)
            {
                if(tp) vec.pb(tp);
                neg=true;
                tp=0;
                tn+=a;
            }
            else
            {
                if(tn) vec.pb(tn);
                pos=true;
                tn=0;
                tp+=a;
            }
        }
        if(tn) vec.pb(tn);
        if(tp) vec.pb(tp);
        if(!neg||!pos)
        {
            cout<<"0\n";
            continue;
        }
        int cnt = 0;
        int tr=0;
        tp = 0;
        //for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
        //cout<<endl;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]<0)
            {
                tr++;
                cnt+=tp;
            }
            tp+=max(0LL,vec[i]);
        }
        cnt=cnt/tr;
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}