#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

//{{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{2,-1}}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        map<string,int>mp;
        int n;
        cin>>n;
        vector<int>graph[n];
        vector<int>vis(200005);
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            graph[i].pb(a);
            for(int j=0;j<a;j++)
            {
                int x;
                cin>>x;
                vis[x]++;
                graph[i].pb(x);
            }
        }
        bool ans = false;
        for(int i=0;i<n;i++)
        {
            bool tem = true;
            for(int j = 1;j<=graph[i][0];j++)
            {
                if(vis[graph[i][j]]-1==0)
                {
                    tem=false;
                    break;
                }
            }
            if(tem)
            {
                ans = true;
                break;
            }
        }
        if(ans) YES;
        else NO;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}