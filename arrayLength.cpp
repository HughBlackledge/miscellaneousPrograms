#include <iostream>
 using namespace std;

 struct arr{
   int size;
   int *data;
   void createArray(int len){
     delete data;
     data = new int[len];
     size = len;
   }
   void printArray(){
     for(int i = 0; i < size;i++){
       cout << data[i] << endl;
     }
   }
   void setTo(int number){
     for(int i = 0; i < size;i++){
       data[i] = number;
     }
   }
   void clear(){
     setTo(0);
   }
   float getMean(){
     float sum = 0;
     for(int i = 0; i < size;i++){
       sum += data[i];
     }
     float avg = sum /size;
     return avg;
   }
 };

 arr num;

 int main() {
   num.createArray(10);
   for(int i = 0; i < num.size;i++){
     num.data[i] = i;
   }
   //num.setTo(3);
   cout << num.size << endl;
   cout << num.getMean() << endl;
}
