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
        int n;string s;
        cin>>n>>s;
        if(n%2)
        {
            cout<<"-1\n";
            continue;
        }
        int ara[27]={0},ct[27]={0};
        for(int i=0;i<n/2;i++)
        {
            if(s[i]==s[n-i-1])
            {
                ara[s[i]-'a']++;
                //cout<<s[i]<<" "<<ara[s[i]-'a']<<endl;
            }
        }
        int cnt = 0;
        queue<int>q;
        sort(ara,ara+26);
        //reverse(ara,ara+26);
        for(int i=0;i<26;i++)
        if(ara[i])q.push(ara[i]);
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            ct[s[i]-'a']++;
            if(ct[s[i]-'a']>(n/2)) flag = false;
        }
        if(!flag)
        {
            cout<<"-1\n";
            continue;
        }
        while(q.size()>1)
        {
            int a = q.front();
            q.pop();
            while(!q.empty())
            {
                //cout<<a<<" ";
                int x = q.front();
                if(q.front()<a)
                {
                    a-=q.front();
                    cnt+=q.front();
                    q.pop();
                }
                else if(a==q.front())
                {
                    //YES;
                    a=0;
                    cnt+=q.front();
                    q.pop();
                    break;
                }
                else
                {
                    x-=a;
                    q.pop();
                    q.push(x);
                    cnt+=a;
                    a=0;
                    break;
                }
            }
            if(a)q.push(a);
            //cout<<endl;
        }
        if(q.size()) cnt+=q.front();
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
