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
        int n;
        cin>>n;
        vector<int>vec[n+1];
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec[a].pb(i+1);
        }
        int ara[n+1]={0}, vis[n+1]={0};
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(vec[i].size())
            {
                int xy = -1;
                for(int j=0;j<vec[i].size();j++)
                {
                    if(vec[vec[i][j]].size()==0)
                    {
                        xy = vec[i][j];
                        break;
                    }
                }
                if(xy!=-1) ara[xy]=i;
                else ara[vec[i][0]]=i;
                vis[i]=1;
                cnt++;
            }
        }
        vector<int>pq,both;
        int xy=0;
        for(int i=1,j=0;i<=n;i++)
        {
            if(!vis[i]&&!ara[i]) {both.push_back(j);pq.push_back(i);j++;}
            else if(!vis[i]){pq.push_back(i);xy = j;j++;}
        }
        for(int i=0;i<both.size();i++)
        {
            swap(pq[xy],pq[both[i]]);
        }
        for(int i=1,j=0;i<=n;i++)
        {
            if(!ara[i])
            {
                ara[i] = pq[j];
                j++;
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<ara[i]<<" ";
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
