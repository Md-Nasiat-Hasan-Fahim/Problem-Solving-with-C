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
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,a,b;
        cin>>n>>a>>b;
        vector<pair<int,int>>vec;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            vec.pb({x,i});
        }
        sort(vec.rbegin(),vec.rend());
        int ta=a;
        int tb=b;
        queue<int>aq,bq;
        for(int i=0;i<n;i++)
        {
            if(((aq.size()+1)*a)<((bq.size()+1)*b))
            {
                aq.push(vec[i].second);
            }
            else bq.push(vec[i].second);
        }
        cout<<aq.size()<<" ";
        while(!aq.empty()){cout<<aq.front()<<" ";aq.pop();}
        cout<<endl;
        cout<<bq.size()<<" ";
        while(!bq.empty()){cout<<bq.front()<<" ";bq.pop();}
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
