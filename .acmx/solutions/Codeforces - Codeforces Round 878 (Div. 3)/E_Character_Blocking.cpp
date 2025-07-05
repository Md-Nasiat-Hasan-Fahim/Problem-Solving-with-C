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
        string s1,s2;
        cin>>s1>>s2;
        s1 = "#" + s1;
        s2 = "#" + s2;
        int tme,q;
        cin>>tme>>q;
        set<int>st;
        set<pair<int,int>>rst;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i]) st.insert(i);
        }
        int run = 0;
        while(q--)
        {
            run++;
            while(!rst.empty()&&rst.begin()->first<=run)
            {
                int index = rst.begin()->second;
                rst.erase(rst.begin());
                if(s1[index]!=s2[index])st.insert(index);
            }
            int a;
            cin>>a;
            if(a==1)
            {
                int pos;
                cin>>pos;
                //cout<<st.size()<<" "<<;
                if(st.count(pos)) st.erase(pos);
                //cout<<st.size()<<" ";
                rst.insert({run+tme,pos});
            }
            else if(a==2)
            {
                int ft,sc,pos1,pos2;
                cin>>ft>>pos1>>sc>>pos2;
                if(st.count(pos1)) st.erase(pos1);
                if(st.count(pos2)) st.erase(pos2);
                if(ft==1&&sc==2||ft==2&&sc==1)
                {
                    swap(s1[pos1],s2[pos2]);
                    if(s1[pos1]!=s2[pos1]) st.insert(pos1);
                    if(s1[pos2]!=s2[pos2]) st.insert(pos2);
                }
                else if(sc==1)
                {
                    swap(s1[pos1],s1[pos2]);
                    if(s1[pos1]!=s2[pos1]) st.insert(pos1);
                    if(s1[pos2]!=s2[pos2]) st.insert(pos2);
                }
                else
                {
                    swap(s2[pos1],s2[pos2]);
                    if(s1[pos1]!=s2[pos1]) st.insert(pos1);
                    if(s1[pos2]!=s2[pos2]) st.insert(pos2);
                }
            }
            else
            {
                //cout<<st.size()<<endl;
                if(st.empty()) YES;
                else NO;
            }
            //cout<<q<<" "<<st.size()<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
