#include <iostream>
#include <cmath>
#include <vector>
 using namespace std;

int num = 99991;

vector<int> primeFact(int n){
  vector<int> primeFactors;
  for(int i = 2; i <= ceil(sqrt(n)); i++){
    if(n % i == 0){
      primeFactors.push_back(i);
      n /= i;
    }
    while(n % i == 0 && n != 1){
      n /= i;
    }
  }
  if(n != 1){
    primeFactors.push_back(n);
  }
 return primeFactors;
}

void printVector(vector<int> vector,int vectorSize){
  for(int i = 0; i < vectorSize; i ++){
    cout << vector[i] << ", ";
  }
  cout << endl;
}

 int main() {
   cout << num << " has prime factors: " << endl;
printVector(primeFact(num),primeFact(num).size());
}
