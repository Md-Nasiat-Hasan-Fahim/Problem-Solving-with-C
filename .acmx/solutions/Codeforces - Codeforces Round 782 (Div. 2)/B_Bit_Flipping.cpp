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

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>vec(n);
        vector<int>flip(n+1);
        int cnt = 0;
        for(int i=0;i<n&&k>0;i++)
        {
            if(k%2==0)
            {
                if(cnt%2==0)
                {
                    if(s[i]=='0')
                    {
                        cnt++;
                        k--;
                        flip[0]++;
                        flip[i]--;
                        if(i+1<n)
                        {
                            flip[i+1]++;
                            flip[n]--;
                        }
                        vec[i]++;
                    }
                }
                else
                {
                    if(s[i]=='1')
                    {
                        cnt++;
                        k--;
                        vec[i]++;
                        flip[0]++;
                        flip[i]--;
                        if(i+1<n)
                        {
                            flip[i+1]++;
                            flip[n]--;
                        }
                    }
                }
            }
            else
            {
                if(cnt%2==0)
                {
                    if(s[i]=='1')
                    {
                        cnt++;
                        k--;
                        vec[i]++;
                        flip[0]++;
                        flip[i]--;
                        if(i+1<n)
                        {
                            flip[i+1]++;
                            flip[n]--;
                        }
                    }
                }
                else
                {
                    if(s[i]=='0')
                    {
                        cnt++;
                        k--;
                        vec[i]++;
                        flip[0]++;
                        flip[i]--;
                        if(i+1<n)
                        {
                            flip[i+1]++;
                            flip[n]--;
                        }
                    }
                }
            }
        }
        if(k>0)
        {
            vec[n-1]+=k;
            flip[0]+=k;
            flip[n-1]-=k;
        }
        for(int i=1;i<=n;i++)
        flip[i]+=flip[i-1];
        for(int i=0;i<n;i++)
        {
            if(flip[i]%2==0)
            cout<<s[i];
            else
            {
                if(s[i]=='1') cout<<'0';
                else cout<<'1';
            }
        }
        cout<<endl;
        for(int x:vec)
        cout<<x<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
