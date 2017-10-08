#include "Coins.h"
int main()
{
Coins pocket(5,3,6,8);
Coins piggyBank(50,50,50,50);
pocket.extract_exact_change(68);
cout<<"After buying the chips.\n"<<pocket;
Coins trans = piggyBank.extract_exact_change(205);
pocket.deposit_coins(trans);
cout<<"After depositting.\n"<<"pocket:"<<pocket<<"piggyBank:"<<piggyBank;
Coins change(10,10,10,10);
piggyBank.deposit_coins(change);
double saving = (double)piggyBank.total_value_in_cents()/100.00;
cout<<"Money in piggyBank after change: $"<<saving<<endl;
return 0;
}