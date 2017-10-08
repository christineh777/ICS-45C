#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;
int main()
{
    map<string,int> m1;
    set<string> s1;
    ifstream f1("sample_doc.txt");
    ifstream f2("stopwords.txt");
    for_each(istream_iterator<string>(f2),istream_iterator<string>(),[&s1](string s){s1.insert(s);});
    for_each(istream_iterator<string>(f1),istream_iterator<string>(),[&s1,&m1](string s)
    {
        string s2(s);
        transform(begin(s),end(s),begin(s2),::tolower);
        if(s1.find(s2)==end(s1))
        {
            m1[s2]+=1;
        }
    });
    ofstream f3;
    f3.open("frequency.txt");
    for_each(begin(m1),end(m1),[&m1,&f3](map<string,int>::const_reference i){f3<<i.first<<" "<<i.second<<endl;});
    f3.close();
    return 0;
    
}
