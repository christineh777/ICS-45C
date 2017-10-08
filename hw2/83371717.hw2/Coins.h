// Coins.h		///  The name of this file.
#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
public:

  Coins( int q, int d, int n, int p ){
quarters = q;
dimes = d;
nickels = n;
pennies = p;
}

  void deposit_coins( Coins & c ){ // note remove the coins from c and put them into this Coins object
quarters += c.quarters;
dimes += c.dimes;
nickels += c.nickels;
pennies += c.pennies;
c.quarters = 0;
c.dimes = 0;
c.nickels = 0;
c.pennies = 0;
}

bool checkrec(int m,int q,int d,int n,int p){
bool result = 0;
if(p>=m) return 1;
if(q !=0 && m>=25)
result = checkrec(m-25, q-1, d, n, p);
if(result==1)return 1;
if(d !=0 && m>=10)
result = checkrec(m-10, q, d-1, n, p);
if(result==1)return 1;
if(n !=0 && m>=5)
result = checkrec(m-5, q, d, n-1, p);
if(result==1)return 1;
return 0;
}
 
  bool has_exact_change_for_cents( int amount_in_cents ){
return checkrec(amount_in_cents,quarters,dimes,nickels,pennies);
}

bool checkrec1(int m,int q,int d,int n,int p,Coins & c){
bool result = 0;
if(p>=m){
c.quarters=quarters-q;
c.dimes=dimes-d;
c.nickels=nickels-n;
c.pennies=m;
quarters=q;
dimes=d;
nickels=n;
pennies-=m;
return 1;
}
if(q !=0 && m>=25)
result=checkrec1(m-25, q-1, d, n, p,c);
if(result==1)return 1;
if(d !=0 && m>=10)
result=checkrec1(m-10, q, d-1, n, p,c);
if(result==1)return 1;
if(n !=0 && m>=5)
result=checkrec1(m-5, q, d, n-1, p,c);
if(result==1)return 1;
return 0;
}

  Coins extract_exact_change( int amount_in_cents ){
Coins c(0,0,0,0);
checkrec1(amount_in_cents,quarters,dimes,nickels,pennies,c);
return c;
}

  int total_value_in_cents(){
return quarters * CENTS_PER_QUARTER + dimes * CENTS_PER_DIME + nickels * CENTS_PER_NICKEL + pennies;
}

  void print( ostream & out ){ // ¡°6 quarters, 2 dimes, ¡­¡±
out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies. "<<endl;
}

private:
  int quarters, dimes, nickels, pennies;
};

ostream & operator << ( ostream & out, Coins c ){
c.print(out);
return out;
}

