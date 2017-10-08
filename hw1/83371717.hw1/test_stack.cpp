#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
Stack a;
for(string str;str !="^D";)
{
getline(cin, str);
if(str!="^D")
{
for(int i=0;i<str.size();i++)
a.push(str[i]);
for(int i=0;i<str.size();i++)
cout<<a.pop();
cout<<endl;
}
}
}
