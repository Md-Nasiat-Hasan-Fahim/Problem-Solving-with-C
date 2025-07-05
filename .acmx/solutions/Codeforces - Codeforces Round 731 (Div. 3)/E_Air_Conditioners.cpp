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

int abc(pair<int,int> &a, pair<int,int> &b)
{
    int x = a.second+abs(a.first-b.first);
    int y = 
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
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> vec(n);
        for(int i=0;i<k;i++) cin>>vec[i].first;
        for(int i=0;i<k;i++) cin>>vec[i].second;
        queue<pair<int,int>>q;
        stack<pair<int,int>>st;
        int i=0;
        while(i<k)
        {
            q.push(vec[i]);
            st.push(vec[i]);
            i++;
        }
        vector<int>ara(n+1,INT_MAX),bra(n+1,INT_MAX);
        while(q.size()>1)
        {
            pair<int,int> a = q.front(); q.pop();
            pair<int,int> b = q.front();
            int x = abc(a,b);
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
