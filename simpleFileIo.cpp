#include <iostream>
#include <fstream>

 using namespace std;

void saveString(vector<string> data, string fileLocation){
ofstream output (fileLocation);
for(int i = 0; i < data.size(); i++){
  output << data[i] << endl;
}
output.close();
}
void saveIntegar(vector<int> data, string fileLocation){
ofstream output (fileLocation);
for(int i = 0; i < data.size(); i++){
  output << data[i] << endl;
}
output.close();
}

vector<string> loadString(string fileLocation){
ifstream input (fileLocation);
vector<string> data;
string line;
int i = 0;
     if (input.is_open())
     {

       while ( getline (input,line) )
       {
         data.push_back(line);
         i++;

       }
       input.close();


}
return data;
}
