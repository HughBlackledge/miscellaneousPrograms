#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
//Blank space
//Why?
 using namespace std;
 int num =
186
;
int incrementer=
17
;
 string code[
88
 ];
//Nice
 int main() {
   string line;
     ifstream input ("/Users/hugh/codingStuff/c++/programs/metaProgramming/metaProgram.cpp");
     ofstream output;
//Why?
int i = 0;
     if (input.is_open())
     {
//Blank space
       while ( getline (input,line) )
       {
         code[i] = line;
         if(i == 8){
           string s = line;
           stringstream eight(s);
           int incremented = 0;
           eight >> incremented;
           incremented += incrementer;
           code[8] = to_string(incremented);
         }
         if(i == 11){
           string s = line;
           stringstream eleven(s);
           int incremented = 0;
           eleven >> incremented;
           incremented ++;
           code[11] = to_string(incremented);
         }
//Nice
         if(line.length() == 0){
           switch(rand() % 5){
             case 0:
             code[i] = "//Lol";
             break;
             case 1:
             code[i] = "//Nice";
             break;
             case 2:
             code[i] = "//Blank space";
             break;
             case 3:
             code[i] = "//Why?";
             break;
             case 4:
             code[i] = "//What does it even mean?";
             break;
           }
//Nice
         }
         i++;
//Blank space
       }
       input.close();
//What does it even mean?
     }
//Lol
     else cout << "Unable to open file";
//Nice
     output.open ("/Users/hugh/codingStuff/c++/programs/metaProgramming/metaProgram.cpp");
     int size = i;
     for(i = 0; i < size; i++){
//Blank space
       if(i == 14){
         output << size << endl;
       } else output << code[i] << endl;
     }
    // output << endl;
     output.close();
     cout << "The number is: " << num << endl;
     system("g++ /Users/hugh/codingStuff/c++/programs/metaProgramming/metaProgram.cpp -o /Users/hugh/codingStuff/c++/programs/metaProgramming/metaProgram");
}
