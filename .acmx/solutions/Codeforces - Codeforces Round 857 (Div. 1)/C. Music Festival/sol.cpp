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

void abc(vector<int> &vec1, vector<int> &vec2)
{
    for(int i=0;i<vec1.size();i++)
    {
        auto it = lower_bound(all(vec2),vec1[i]);
        if(it==vec2.end()) vec2.pb(vec1[i]);
        else vec2[it-vec2.begin()]=vec1[i];
    }
}

struct node{
    int x,y,z;
};

int pqr(int x, int y, vector<int> &vec)
{
    auto it1 = lower_bound(all(vec),x);
    auto it2 = upper_bound(all(vec),y);
    return it2-it1;
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
        vector<int>album[n],lis[n];
        vector<node>vec;
        for(int i=0;i<n;i++)
        {
            int m;
            cin>>m;
            int mx = LONG_LONG_MIN;
            int mn = LONG_LONG_MAX;
            for(int j=0;j<m;j++)
            {
                int a;
                cin>>a;
                album[i].pb(a);
                mx = max(mx,a);
                mn = min(mn,a);
            }
            abc(album[i],lis[i]);
            vec.pb({mn,mx,i});
        }
        sort(all(vec),[](node &a, node &b){
            if(a.x!=b.x) return a.x<b.x;
            else return a.y<b.y;
        });
        vec.pb({LONG_LONG_MAX,LONG_LONG_MAX,-1});
        int cur=-1,a,b;
        int cnt = 0;
        for(int i=0;i<n+1;i++)
        {
            if(cur==-1)
            {
                cur = i;
                a = vec[i].x;
                b = vec[i].y;
                continue;
            }
            if(vec[i].x>b)///equal
            {
                cnt+=pqr(a,b,lis[cur]);
                cur = vec[i].z;
                a = vec[i].x;
                b = vec[i].y;
            }
            else
            {
                if(vec[i].y>b)
                {
                    int tx = pqr(max(a,vec[i].x),b,lis[cur]);
                    int ty = pqr(max(vec[i].x,a),b,lis[vec[i].z]);
                    cnt+=max(tx,ty);
                    a=b+1;
                    b=vec[i].y;
                    cur = vec[i].z;
                }
                else if(vec[i].y==b)
                {
                    int tx = pqr(max(a,vec[i].x),b,lis[cur]);
                    int ty = pqr(max(a,vec[i].x),b,lis[vec[i].z]);
                    cnt+=max(tx,ty);
                    cur=-1;
                }
                else
                {
                    int tx = pqr(max(a,vec[i].x),vec[i].y,lis[cur]);
                    int ty = pqr(max(a,vec[i].x),vec[i].y,lis[vec[i].z]);
                    cnt+=max(tx,ty);
                    a = vec[i].y+1;
                }
            }
            cout<<vec[i].x<<" "<<vec[i].y<<" "<<cnt<<endl;
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
