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

vector<vector<int>>val;
vector<int>term;
string tar;
int sz;
queue<string>que;
bool ans;

void dfs2(int root,string &s)
{
  if(term[root]) que.push(s),cout<<s<<endl;
  for(int i=0;i<26;i++)
  {
    if(val[root][i]!=-1)
    {
      s.pb(i+'a');
      // cout<<(char)(i+'a')<<endl;
      dfs2(val[root][i],s);
      s.pop_back();
    }
  }
}

void dfs1(int root, int pos)
{
  if(pos==sz)
  {
    if(term[root]) cout<<sz<<endl,ans=true;
    for(int i=0;i<26;i++)
    {
      if(val[root][i]!=-1)
      {
        string s = "";
        s.pb(i+'a');
        cout<<(char)(i+'a')<<endl;
        dfs2(val[root][i],s);
        s.pop_back();
      }
      while(!que.empty()) cout<<tar<<que.front()<<endl,que.pop(),ans=true;
    }
    return;
  }
  if(!val[root][tar[pos]-'a']!=-1) dfs1(val[root][tar[pos]-'a'],pos+1);
}


signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    // FastIO;
    int Master0fTheSEA=1;
    // cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int n;
      cin>>n;
      int aloc = 0;
      val.pb(vector<int>(30,-1));
      for(int i=0;i<n;i++)
      {
        string s;
        cin>>s;
        int root = 0;
        for(int i=0;i<s.size();i++)
        {
          if(val[root][s[i]-'a']==-1)
          {
            aloc++;
            val[root][s[i]-'a']=aloc;
            val.pb(vector<int>(30,-1));
            term.pb(0);
          }
          root = val[root][s[i]-'a'];
        }
        cout<<root<<endl;
        term[root]=1;
      }
      int q;
      cin>>q;
      for(int i=1;i<=q;i++)
      {
        string s;
        cin>>s;
        ans = false;
        tar=s;
        sz = s.size();
        dfs1(0,0);
        if(!ans) cout<<"No match\n";
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
