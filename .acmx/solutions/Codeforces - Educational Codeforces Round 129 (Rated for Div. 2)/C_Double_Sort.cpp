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

bool is_sorted(vector<int> &vec)
{
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i]<vec[i-1])
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>vec(n), vec2(n);
        vector<int>graph[102];
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            graph[vec[i]].pb(i);
        }
        for(int i=0;i<n;i++) cin>>vec2[i];
        vector<pair<int,int>>pr;
        for(int i=1;i<=100;i++)
        {
            if(graph[i].size())
            {
                for(int j=0;j<graph[i].size();j++)
                {
                    int k = graph[i][j];
                    for(;k>0;k--)
                    {
                        if(vec[k]<vec[k-1])
                        {
                            swap(vec[k],vec[k-1]);
                            swap(vec2[k],vec2[k-1]);
                            pr.push_back({k,k+1});
                        }
                        else if(vec[k]==vec[k-1])
                        {
                            if(vec2[k]<vec2[k-1])
                            {
                                swap(vec[k],vec[k-1]);
                                swap(vec2[k],vec2[k-1]);
                                pr.push_back({k,k+1});
                            }
                        }
                        else break;
                    }
                }
            }
        }
        if(is_sorted(vec)&&is_sorted(vec2))
        {
            cout<<pr.size()<<endl;
            for(auto &i : pr)
            cout<<i.first<<" "<<i.second<<endl;
        }
        else cout<<"-1\n";

    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
