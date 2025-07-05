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

struct node
{
    string s;
    int a;
    int b;
};

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    freopen("traffic.in","r+",stdin);
    freopen("traffic.out","w+",stdout);
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        vector<node>vec;
        int ss;
        bool is_ss = false;
        for(int i=0;i<n;i++)
        {
            string s; int a,b;
            cin>>s>>a>>b;
            vec.pb({s,a,b});
        }
        for(int i=n-1;i>-1;i--)
        {
            if(vec[i].s=="none")
            {
                ss=i;
                break;
            }
        }
        int st = vec[ss].a, ed = vec[ss].b;
        for(int i=ss-1;i>-1;i--)
        {
            if(vec[i].s=="off")
            {
                st+=vec[i].b;
                ed+=vec[i].a;
            }
            else if(vec[i].s=="on")
            {
                st-=vec[i].a;
                ed-=vec[i].b;
            }
            else 
            {
                st=max(st,vec[i].a);
                ed = min(ed,vec[i].b);
            }
        }
        cout<<st<<" "<<ed<<endl;;
        for(int i=0;i<n;i++)
        {
            if(vec[i].s=="none")
            {
                ss = i;
                break;
            }
        }
        st = vec[ss].a, ed = vec[ss].b;
        for(int i=ss+1;i<n;i++)
        {
            if(vec[i].s=="off")
            {
                st-=vec[i].b;
                ed-=vec[i].a;
            }
            else if(vec[i].s=="on")
            {
                st+=vec[i].a;
                ed+=vec[i].b;
            }
            else 
            {
                st=max(st,vec[i].a);
                ed = min(ed,vec[i].b);
            }
        }
        cout<<st<<" "<<ed<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
