
#include "String.h"

int String::allocations=0;

void test_constructor_and_print()
{
    String s("Hello World");
    cout << "\n===testing constructor and print===\n" << s << endl;
}
void test_read()
{
    String s;
    cout<< "\n===testing read===\n"  << "Please Enter:";
    cin >> s;
    cout << s << endl;
}
void test_assignment()
{
    String s;
    s = "Hello World Again";
    cout<< "\n===testing assignment===\n";
    cout << s << endl;
}
void test_operators()
{
    String a("abc");
    String b("def");
    String c("abcdef");
    String d("12345");
    String e("abcde");
    cout<< "\n===testing operators===\n";
    cout << "abc > def is " << (a>b) << endl;
    cout << "abc < def is " << (a<b) << endl;
    cout << "abcdef > abcde is " << (c>e) << endl;
    cout << "abcdef >= abcde is " << (c>=e) << endl;
    cout << "abcdef <= abcde is " << (c<=e) << endl;
    cout << "abc == abc is " << (a==a) << endl;
    String f = a+b;
    cout<<"abc + def is "<<f<<endl;
    f+="abc";
    cout<<"abcdef += abc is "<< f<<endl;
    cout<<"a is \"abc\" then a[1] is "<< a[1]<<endl;
}
void test_reverse(){
    String a("abcd");
    String b = a.reverse();
    cout<< "\n===testing reverse===\n";
    cout << "abcd reverse is " << b << endl;
}
void test_indexOf(){
    String a("abcd");
    cout<<"\n===testing indexOf===\n";
    cout<<"the index of 'c' in \"abcd\" is "<<a.indexOf('c')<<endl;
    cout<<"the index of \"bc\" in \"abcd\" is "<<a.indexOf("bc")<<endl;
    cout<<"the index of \"bd\" in \"abcd\" is "<<a.indexOf("bd")<<endl;
}

int main()
{
    test_constructor_and_print();
    test_read();
    test_assignment();
    test_operators();
    test_reverse();
    test_indexOf();
    String::final_report_on_allocations();
    cout<<"Number of new allocations minus number of delete deallocations is "<<String::allocations<<endl;
    return 0;
}
