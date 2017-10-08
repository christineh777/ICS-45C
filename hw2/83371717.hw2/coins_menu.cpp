#include "Coins.h"
int main()
{
Coins myCoins(0,0,0,0);
int select;
while (select != 4){
cout<<"\n1) deposit change\n2) extract change\n3) print the balance\n4) exit\nEnter the number: ";
cin >> select;
if(select==1)
{
int a;int b;int c;int d;
cout<<"Enter the quarters: ";
cin>>a;
cout<<"Enter the dimes: ";
cin>>b;
cout<<"Enter the nickels: ";
cin>>c;
cout<<"Enter the pennies: ";
cin>>d;
Coins deposit(a,b,c,d);
myCoins.deposit_coins(deposit);
}
if(select==2)
{
int extract;
cout<<"Money you want to extract: ";
cin>>extract;
if(myCoins.has_exact_change_for_cents(extract))
{
myCoins.extract_exact_change(extract);
}
else
{
cout<<"Extraction is not valid."<<endl;
}
}
if(select==3)
{
cout<<"Money you have: "<<myCoins;
}
}
}