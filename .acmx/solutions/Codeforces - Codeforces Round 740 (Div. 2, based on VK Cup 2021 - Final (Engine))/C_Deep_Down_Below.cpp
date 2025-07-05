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

bool abc(int x, vector<vector<int>> &vec, vector<int> &vc)
{
    //cout<<q.size()<<endl;
    for(int k=0;k<vc.size();k++)
    {
        int i = vc[k];
        for(int j=0;j<vec[i].size();j++)
        {
            if(x>vec[i][j])
            {
                x++;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

struct node{
    int a,b,c;
};

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
        vector<vector<int>>vec(n,vector<int>());
        vector<node>pq;
        for(int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            int x = INT_MIN;
            for(int j=0;j<k;j++)
            {
                int a;
                cin>>a;
                x = max(a-j,x);
                vec[i].push_back(a);
            }
            pq.pb({x,i,k});
        }
        sort(all(pq),[&](node p, node q){
            if(p.a!=q.a) return p.a<q.a;
            else return p.c>q.c;
        });
        vector<int>q;
        for(int i=0;i<n;i++)
        {
            q.pb(pq[i].b);
        }
        int hi=INT_MAX, lo = 0;
        while(hi-lo>1)
        {
            int mid = lo+(hi-lo)/2;
            if(abc(mid,vec,q)) hi = mid;
            else lo = mid;
        }
        if(abc(lo,vec,q)) cout<<lo<<endl;
        else cout<<hi<<endl;
        // while(!q.empty())
        // {
        //     cout<<q.front()<<" ";
        //     q.pop();
        // }
        // cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
