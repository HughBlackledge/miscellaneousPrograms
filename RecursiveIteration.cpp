#include <iostream>
#include <map>
 using namespace std;
int repeat = 100;
void infiniteRegress();
void end();
void (*f[2])() = {end, infiniteRegress};;

void end(){

}

 void infiniteRegress(){
   repeat --;
   int n = (repeat > 0);
   cout << "hi" << endl;
   (*f[n])();
 }

 int main() {
infiniteRegress();
}
