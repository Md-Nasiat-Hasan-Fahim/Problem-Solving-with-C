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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        stack<pair<int,int>>st;
        int a;
        cin>>a;
        queue<int>q;
        q.push(1);
        st.push({a,1});
        int cnt = 1;
        for(int i=0;i<n-1;i++)
        {
            int b;
            cin>>b;
            if(!st.size())
            {
                q.push(1);
                st.push({b,1});
                continue;
            }
            else if(st.top().first==b)
            {
                //if(i==5) cout<<cnt<<" ";
                cnt-=st.top().second;
                auto [x,ctx]= st.top();
                //if(i==5) cout<<x<<" "<<ctx<<" "<<cnt<<endl;
                st.pop();
                ctx++;
                bool flag = ctx>=x;
                ctx%=x;
                q.push(ctx+cnt);
                if(ctx){st.push({x,ctx});}
                if(flag&&!st.empty()) cnt-=st.top().second;;
            }
            else
            {
                //if(i==8) cout<<"        YES "<<st.top().first<<endl;
                st.push({b,1});
                q.push(cnt+1);
            }
            if(!st.empty()) cnt+=st.top().second;
            //cout<<cnt<<endl;
        }
        while(!q.empty())
        {
            cout<<q.front()<<endl;
            q.pop();
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
