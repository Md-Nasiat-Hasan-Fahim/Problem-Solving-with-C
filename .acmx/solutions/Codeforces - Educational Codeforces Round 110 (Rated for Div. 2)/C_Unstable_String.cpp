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

struct segment_tree{
    vector<int>tree;
    int size;
    void memory(int n)
    {
        tree.assign(4*n+2,0LL);
        size = n;
    }
    void init(vector<int>&vec)
    {
        init(1,1,size,vec);
    }
    void init(int node, int s, int e, vector<int>&vec)
    {
        if(s==e)
        {
            tree[node]=vec[s];
            return;
        }
        int mid = ((s+e)/2);
        init(2*node,s,mid,vec);
        init(2*node+1,mid+1,e,vec);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    int query(int l, int r)
    {
        return query(1,size,1,l,r);
    }
    int query(int s, int e, int node, int l, int r)
    {
        if(s>r||l>e) return 0;
        if(s>=l&&r>=e) return tree[node];
        int mid = (s+e)/2;
        //cout<<s<<" "<<e<<endl;
        return query(s,mid,2*node,l,r)+query(mid+1,e,2*node+1,l,r);
    }
    void update(int i, int v)
    {
        update(1,size,1,i,v);
    }
    
    void update(int s, int e, int node, int i, int v)
    {
        if(i<s||i>e) return;
        if(s==e) {tree[node] = v;return;}
        int mid = (s+e)/2;
        update(s,mid,2*node,i,v);
        update(mid+1,e,2*node+1,i,v);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
};

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    //FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>vec(n+1);
        for(int i=1;i<=n;i++) cin>>vec[i];
        segment_tree st;
        st.memory(n);
        st.init(vec);
        while(m--)
        {
            int x,a,b;
            cin>>x>>a>>b;
            if(x==1)
            {
                st.update(a+1,b);
            }
            else
            {
                cout<<st.query(a+1,b)<<endl;
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
