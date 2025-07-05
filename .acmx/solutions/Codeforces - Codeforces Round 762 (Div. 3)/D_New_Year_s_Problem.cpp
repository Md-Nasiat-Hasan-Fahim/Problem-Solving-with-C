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

bool abc(int x,vector<int> &ab, vector<vector<int>> &vec)
{
    int pq = ab[x];
    set<int>st;
    int m = vec.size(),n = vec[0].size();
    int ara[m]={0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vec[i][j]>=pq)
            {
                ara[i]++;
                st.insert(j);
            }
        }
    }
    if(st.size()==n)
    for(int i=0;i<m;i++)
    if(ara[i]>1) return true;
    return false;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int m,n;
        cin>>m>>n;
        vector<vector<int>>vec(m+1,vector<int>(n));
        set<int>st;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>vec[i][j];
                st.insert(vec[i][j]);
            }
        }
        vector<int>ab;
        while(!st.empty()) ab.pb(*st.begin()),st.erase(st.begin());
        sort(all(ab));
        ab.pb(ab.back()+1);
        int lo = 0,hi = ab.size()-1;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid,ab,vec)) lo = mid;
            else hi = mid;
        }
        if(abc(hi,ab,vec)) cout<<ab[hi]<<endl;
        else cout<<ab[lo]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
