#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<stdio.h>
#include<stdlib.h>
 
using namespace std;
 
int main()
{
    long int i, count,len;
    char expression[3055],ch;
    while(gets(expression))
    {
        stack<char> mystack;
        len=strlen(expression);
            if(len==0)
            {
                printf("Yes\n");
                continue;
            }
        count=0;
        for(i=0;i<len;i++)
        {
           if(expression[i]=='('||expression[i]=='{'||expression[i]=='['||expression[i]=='<'||(expression[i-1]=='('&&expression[i]=='*'))
            {
                mystack.push(expression[i]);
                if(expression[i]!='*')
                    count+=1;
            }
            else if((expression[i]==')'||expression[i]=='}'||expression[i]==']'||expression[i]=='>'||(expression[i]=='*'&&expression[i+1]==')')))
            {
                if(mystack.empty() &&expression[i]=='*')
                {
                    count+=1;
                    break;
                }
                else if(mystack.empty() &&(expression[i]==')'||expression[i]=='}'||expression[i]==']'||expression[i]=='>'))
                {
                    count+=1;
                    break;
                }
                else if(mystack.top()=='*'&&expression[i]=='*' )
                {
                    mystack.pop();
                    mystack.pop();
                    count+=1;
                    i+=1;
                }
 
                else if(!mystack.empty() &&((mystack.top()=='('&&expression[i]==')')||(mystack.top()=='{'&&expression[i]=='}')||(mystack.top()=='['&&expression[i]==']')||(mystack.top()=='<'&&expression[i]=='>')))
                {
                    mystack.pop();
                    count+=1;
                }
                else
                {
                    count+=1;
                    break;
                }
            }
            else
                count+=1;
        }
        if(mystack.empty() && len==i)
            printf("YES\n");
        else if(!mystack.empty() && len==i)
            printf("NO %ld\n",count+1);
        else
            printf("NO %ld\n",count);
    }
    return 0;
}