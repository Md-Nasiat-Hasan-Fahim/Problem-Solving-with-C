#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        //cin.ignore();
        string s;
        vector<string>k;
        getline(cin,s);
        while(s.size()==0) getline(cin,s);
        string str="";
        for(int i=0;i<s.length();i++)
        {
           if(s[i]==' ')
            {
                k.push_back(str);
                str="";
            }
            else
                str+=s[i];
        }
        k.push_back(str);
        for(int i=0;i<k.size();i++)
        {
           reverse(k[i].begin(),k[i].end());
        }
        for(int i=0;i<k.size();i++)
        {
           cout<<k[i]<<" ";
        }
        cout<<endl;
    }
}