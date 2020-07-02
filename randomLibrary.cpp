#include <iostream>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 using namespace std;

 void println(string words){
 cout << words << endl;
 }

 void println(int words){
 cout << words << endl;
}

string isprime(int num){
int isprime = 0;
for(int i = 3; i <= sqrt(num); i+=2){
  isprime += num % i;
  isprime -= num == i;
}
if(isprime == 0){
  return "true";
} else return "false";
}

void gimmeSpace(int howmuch){
  for(int i = 0; i < howmuch; i++ ){
    cout << endl;
  }
}

int random(int start,int end){
  int result = rand() % (end - start) + start;
  return result;
}

void askQuestion(string question){
  println(question);
}

vector<string> generateCardDeck(){
vector<string> tempCardDeck;
string suit = "hearts";
tempCardDeck.push_back("ace of  " + suit);
tempCardDeck.push_back("two of " + suit);
tempCardDeck.push_back("three of " + suit);
tempCardDeck.push_back("four of " + suit);
tempCardDeck.push_back("five of " + suit);
tempCardDeck.push_back("six of " + suit);
tempCardDeck.push_back("seven of " + suit);
tempCardDeck.push_back("eight of " + suit);
tempCardDeck.push_back("nine of " + suit);
tempCardDeck.push_back("ten of " + suit);
tempCardDeck.push_back("jack of " + suit);
tempCardDeck.push_back("queen of " + suit);
tempCardDeck.push_back("king of " + suit);
suit = "diamonds";
tempCardDeck.push_back("ace of " + suit);
tempCardDeck.push_back("two of " + suit);
tempCardDeck.push_back("three of " + suit);
tempCardDeck.push_back("four of " + suit);
tempCardDeck.push_back("five of " + suit);
tempCardDeck.push_back("six of " + suit);
tempCardDeck.push_back("seven of " + suit);
tempCardDeck.push_back("eight of " + suit);
tempCardDeck.push_back("nine of " + suit);
tempCardDeck.push_back("ten of " + suit);
tempCardDeck.push_back("jack of " + suit);
tempCardDeck.push_back("queen of " + suit);
tempCardDeck.push_back("king of " + suit);
suit = "spades";
tempCardDeck.push_back("ace of " + suit);
tempCardDeck.push_back("two of " + suit);
tempCardDeck.push_back("three of " + suit);
tempCardDeck.push_back("four of " + suit);
tempCardDeck.push_back("five of " + suit);
tempCardDeck.push_back("six of " + suit);
tempCardDeck.push_back("seven of " + suit);
tempCardDeck.push_back("eight of " + suit);
tempCardDeck.push_back("nine of " + suit);
tempCardDeck.push_back("ten of " + suit);
tempCardDeck.push_back("jack of " + suit);
tempCardDeck.push_back("queen of " + suit);
tempCardDeck.push_back("king of " + suit);
suit = "clubs";
tempCardDeck.push_back("ace of " + suit);
tempCardDeck.push_back("two of " + suit);
tempCardDeck.push_back("three of " + suit);
tempCardDeck.push_back("four of " + suit);
tempCardDeck.push_back("five of " + suit);
tempCardDeck.push_back("six of " + suit);
tempCardDeck.push_back("seven of " + suit);
tempCardDeck.push_back("eight of " + suit);
tempCardDeck.push_back("nine of " + suit);
tempCardDeck.push_back("ten of " + suit);
tempCardDeck.push_back("jack of " + suit);
tempCardDeck.push_back("queen of " + suit);
tempCardDeck.push_back("king of " + suit);
random_shuffle(&tempCardDeck[0],&tempCardDeck[51]);
return tempCardDeck;
}

int iteratedaddition(int start, int end){
  int sum = 0;
for(int i = start; i <= end; i++){
  sum += i;
}
return sum;
}

int whatsTheTime(){
  int currentTime = time(NULL);
  return currentTime;
}

vector<int> generateRandomSet(int end){
  vector<int> randomSet;
  for(int i = 0;i < end; i++){
    randomSet.push_back(random(0,100));
  }
return randomSet;
}

string scramble(string word){
  int randomiser = random(0,10);
for(int i = 0; i < randomiser; i++){
  //int letter = word[word.length() - 1];
//  insert(word)
  random_shuffle(&word[0],&word[word.length() - 1]);
}
  return word;
}
