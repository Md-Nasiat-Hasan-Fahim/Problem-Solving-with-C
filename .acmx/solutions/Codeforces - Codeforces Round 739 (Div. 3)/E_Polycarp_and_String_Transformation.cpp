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
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        string s;
        cin>>s;
        vector<int>pos(27,-1),cnt(27,0);
        set<char>st;
        for(int i=0;i<s.size();i++)
        {
            pos[s[i]-'a']=max(pos[s[i]-'a'],i);
            cnt[s[i]-'a']++;
            st.insert(s[i]);
        }
        priority_queue<pair<int,int>>pr;
        for(int i=0;i<26;i++)
        {
            if(cnt[i])
            pr.push({pos[i],i});
        }
        int op = st.size();
        vector<char>stc;
        bool ans = true;
        int j = 0;
        //cout<<st.size()<<" "<<pr.size()<<endl;
        while(!pr.empty())
        {
            int i = pr.top().second;
            pr.pop();
            if(cnt[i]%(st.size()-j)) ans = false;
            cnt[i]/=(st.size()-j);
            j++;
            stc.pb(i+'a');
        }
        reverse(all(stc));
        vector<char>str;
        for(int i=0;i<s.size();i++)
        {
            if(cnt[s[i]-'a'])
            {
                cnt[s[i]-'a']--;
                str.pb(s[i]);
            }
            else break;
        }
        for(int i=0;i<26;i++)
        {
            if(cnt[i]) ans = false;
        }
        vector<int>vis(26,0);
        //cout<<ans<<endl;
        int k=0;
        for(int i=0;i<stc.size();i++)
        {
            //cout<<i<<" "<<stc[i]<<" "<<ans<<endl;
            int j = 0;
            for(;j<str.size()&&k<s.size();k++,j++)
            {
                while(j<str.size()&&vis[str[j]-'a']) j++;
                if(j==str.size()) break;
                if(str[j]!=s[k])
                {
                    //cout<<"83"<<endl;
                    ans = false;
                    break;
                }
            }
            while(j<str.size()&&vis[str[j]-'a']) j++;
            if(j!=str.size())
            {
                //cout<<"91"<<endl;
                ans = false;
            }
            if(!ans) break;
            vis[stc[i]-'a']=1;
        }
        //cout<<ans<<endl;
        if(k!=s.size()) ans=false;
        if(!ans)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=0;i<str.size();i++) cout<<str[i];
        cout<<" ";
        for(int i=0;i<stc.size();i++) cout<<stc[i];
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
