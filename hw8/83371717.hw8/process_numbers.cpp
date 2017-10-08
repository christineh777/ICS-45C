#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    vector<int> v1;
    ifstream f1("rand_numbers.txt");
    for_each(istream_iterator<int>(f1), istream_iterator<int>(), [&v1](int i){v1.push_back(i);});
    sort(begin(v1),end(v1));
    ofstream f2("odd.txt");
    ofstream f3("even.txt");
    for_each(begin(v1),end(v1),[&f2,&f3](int i)
    {
        if(i%2!=0)
            f2<<i<<" ";
        else
            f3<<i<<endl;
    });
    f2.close();
    f3.close();
    return 0;
}
