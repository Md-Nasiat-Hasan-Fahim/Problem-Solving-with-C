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

struct tr{
    vector<int>tree;
    void init(int n)
    {
        tree.assign(4*n,0);
    }
    int update(int idx, int s, int e, int node)
    {
        if(idx<s||idx>e) return tree[node];
        if(s==e)
        {
            tree[node]++;
            return tree[node];
        }
        int mid = (s+e)/2;
        tree[node] = update(idx,s,mid,2*node) + update(idx,mid+1,e,2*node+1);
        return tree[node];
    }

    int sum(int i, int j, int s, int e, int node)
    {
        if(s>=i&&e<=j) return tree[node];
        if(s>j||e<i) return 0;
        int mid = (s+e)/2;
        return sum(i,j,s,mid,2*node) + sum(i,j,mid+1,e,2*node+1);
    }
};

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    // cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        tr tree;
        vector<int>pos(n+3,-1),sm(n+1,-1);
        tree.init(2*n+3);
        for(int i=1;i<=2*n;i++)
        {
            int a;
            cin>>a;
            if(pos[a]==-1)
            {
                pos[a] = i;
            }
            else
            {
                sm[a]=tree.sum(pos[a],i,1,2*n,1);
                tree.update(pos[a],1,2*n,1);
            }
        }
        for(int i=1;i<=n;i++) cout<<sm[i]<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
