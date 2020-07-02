#include <iostream>
#include <cmath>
#include <fstream>
 using namespace std;

void prime2();

void prime(){
  ofstream output;
  output.open ("/Users/hugh/codingStuff/c++/programs/prime/mersennePrimes.txt");
  long double num = 2;
  int incrementor = 0;
  double limit = pow(10,25);
  while(num < limit) {
   for(int i = 3; i <= sqrt(num - 1); i+=2) {
     if(fmod((num - 1),i) == 0) {
       num*=2;
       i = 1;
     }
   }
   incrementor ++;
   if(num != 0){
     output << fixed << incrementor << ". " << num -1 << endl;
     num*=2;
   }
 }
 output.close();
}

 int main() {
prime();
}

void prime2(){
  ofstream output;
  output.open ("/Users/hugh/codingStuff/c++/programs/prime/mersennePrime2.txt");
  //long long num = 10000000000000000000;
  //   output << fmod(pow(2,10000000000000000000) -2),10000000000000000000) << endl;
 output.close();
}
