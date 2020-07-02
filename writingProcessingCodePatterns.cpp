#include <iostream>
#include <vector>
#include <fstream>

 using namespace std;


 int main() {
srand(time(NULL));
ofstream myfile;
myfile.open ("/Users/hugh/codingStuff/Processing/ComputerPatternGenerator/ComputerPatternGenerator.pde");
myfile << "void setup(){" << endl << "size(700,550);" << endl;
for(int incrementor = 0; incrementor < 20; incrementor ++){
  char characters[] = {
  '+','-','*','/','%'//,'('
  };

  char var[] = {
  'x','y'
  };
  vector<char> line;
  vector<char>::iterator it;

  string completeLine;
  int lineLength = 10 + (rand() % 20) * 2 ;
  int brackets[lineLength];
  for(int i = 0; i <lineLength; i++){
    brackets[i] = 0;
  }
  int size = sizeof(characters)/sizeof(characters[0]);
  line.push_back(var[rand() %2]);

  for(int i = 0; i < lineLength/2;i++){
    int pos = rand() % size;
    line.push_back(characters[pos]);
    line.push_back(var[rand() %2]);
  /*if(characters[pos] == '('){
   brackets[i/2] = 1;
   cout << i/2 << endl;
  } */
  }
  /*
  for(int i = 0; i < lineLength; i+= 2){
    if(brackets[i/2] == 1){
      int pos = i/2 + 1 + rand() % (lineLength - (i + 1));
      it = line.begin();
    it = line.insert (it + pos, ')');
    cout << i/2 << endl;
    }
  }
  */
  for(int i = 0; i < line.size(); i++){
  completeLine = completeLine + line[i];
  }
  if(rand()%10 == 3){
    myfile << "for(int x = 1; x < width; x ++){" << endl << "for(int y = 1; y < height; y ++){" << endl << "stroke(" + completeLine +  ");" << endl << "point(x,y);" << endl << "}" << endl << "}" << endl << "saveFrame(\"pattern" << 1+incrementor << ".png\");" << endl << "println(\"Finished\");" << endl;
  } else myfile << "for(int x = 1; x < width; x ++){" << endl << "for(int y = 1; y < height; y ++){" << endl << "stroke((" + completeLine +  ")%255);" << endl << "point(x,y);" << endl << "}" << endl << "}" << endl << "saveFrame(\"pattern" << 1+incrementor << ".png\");" << endl << "println(\"Finished\");" << endl;

//  myfile << "background(0);" << endl;
  cout << completeLine << endl;
}
myfile << "}" << endl;
myfile.close();
}
