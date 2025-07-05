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

void dfs(int x, stack<int> &st,vector<int> &vis, vector<vector<int>> &vec)
{
    vis[x]=1;
    for(auto c:vec[x])
    {
        if(!vis[c]) dfs(c,st,vis,vec);
    }
    st.push(x);
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
        int n;
        cin>>n;
        unordered_map<int,string>mp1;
        unordered_map<string,int>mp2;
        vector<vector<int>>vec(n+5,vector<int>());
        int j = 0;
        for(int i=0;i<n-1;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            int a,b;
            if(mp2.count(s1)!=0) a = mp2[s1];
            else
            {
                j++;
                mp2[s1]=j;
                mp1[j] = s1;
                a = j;
            }
            if(mp2.count(s2)!=0) b = mp2[s2];
            else{
                j++;
                mp2[s2] = j;
                mp1[j] = s2;
                b = j;
            }
            vec[a].pb(b);
        }
        if(tttttttt>1) cout<<endl;
        stack<int>st;vector<int>vis(n+5,0);
        //cout<<j<<endl;
        for(int i=1;i<=j;i++)
        {
            if(!vis[i]) dfs(i,st,vis,vec);
        }
        cout<<"Scenario #"<<tttttttt<<":\n";
        while(!st.empty()) cout<<mp1[st.top()]<<endl,st.pop();
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
