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
    int ttt=400;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n=z,k=1;
        //cout<<n<<" ";
        cin>>n>>k;
        string s = to_string(n);
        set<int>st;
        int m = n;
        while(m)
        {
            st.insert(m%10);
            m/=10;
        }
        if(st.size()==k)
        {
            cout<<n<<endl;
            continue;
        }
        if(k==1)
        {
            int ct;
            if(s[0]=='9')
            {
                if(st.size()>1)
                {
                    ct = 9;
                }
                else
                {
                    ct = 1;
                    cout<<ct;
                }
            }
            else
            {
                int x = s[0]-'0';
                if(st.upper_bound(x)==st.end())
                {
                    //cout<<" y ";
                    ct = x;
                }
                else
                {
                    ct = x+1;
                }
            }
            for(int i=0;i<s.size();i++)
            {
                cout<<ct;
            }
            cout<<endl;
            continue;
        }
        if(st.size()==1)
        {
            if(s.size()==1)
            {
                cout<<"10"<<endl;
                continue;
            }
            cout<<n+1<<endl;
        }
        else
        {
            int i=1;
            for(;i<s.size();i++)
            {
                if(s[i-1]!=s[i]) break;
            }
            int ai = i;
            for(;i<s.size()-1;i++)
            {
                if(s[i]!=s[i+1]) break;
            }
            for(int j=i+1;j<s.size();j++)
            {
                if(s[i]!=s[j])
                {
                    if(s[i]<s[j])
                    {
                        if(s[i]=='9')
                        {
                            s[i-1]++;
                            s[ai]=0;
                        }
                        else
                        {
                            s[ai]++;
                        }
                    }
                    break;
                }
            }
            for(int j = 0;j<i-2;j++)
            {
                s[j]=s[i-1];
            }
            for(int j=ai+1;j<s.size();j++)
            {
                if(s[ai]!=s[0])
                s[j]=min(s[ai],s[0]);
                else s[j]='0';
            }
            cout<<s<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
