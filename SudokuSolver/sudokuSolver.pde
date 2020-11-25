


int boxSize;

int[][] numbers;

//Holds the values of what each individual square can be
boolean[][][] possibilities;

int iterations = 0;

int solvedSquares = 0;

String[] solution;

void setup(){
  size(600,600);
  boxSize = width/9;
  numbers = new int[width/boxSize][height/boxSize];
  possibilities = new boolean[9][9][9];
  {
  String[] file;
   file = loadStrings("numbers.txt");
    for(int x = 0; x < 9; x++){
    for(int y = 0; y < 9; y++){
      numbers[x][y] = int(file[x].charAt(y))-48;
     for(int i = 0; i < 9;i++){
        possibilities[x][y][i] = true;
      }
    }
  }
  }
  stroke(0);
  fill(255);
  background(0);
  for(int x = 0; x < 9; x++){
    for(int y = 0; y < 9; y++){
      fill(255);
      square(x*boxSize,y*boxSize,boxSize);
      if(numbers[x][y] != 0){
        fill(0);
      text(numbers[x][y],x*boxSize+boxSize/2,y*boxSize+boxSize/2);
      } 
    }
  }
  checkPossibilities();
  drawPossibilities();
  solution = new String[9];
  for(int i = 0; i < 9; i++){
    solution[i] = "";
  }
}

void draw(){
  solvedSquares = 0;
  iterations ++;
    background(0);
    for(int i = 0; i < 5; i++){
      for(int x = 0; x < 9; x++){
      for(int y = 0; y < 9; y++){
      fill(255);
      square(x*boxSize,y*boxSize,boxSize);
      //Doesn't put zero in the empty boxes
      if(numbers[x][y] != 0){
        fill(0);
      text(numbers[x][y],x*boxSize+boxSize/2,y*boxSize+boxSize/2);
      } 
    }
  }
    }
    for(int x = 0; x < 9; x++){
      for(int y = 0; y < 9; y++){
        
        if(numbers[x][y] == 0){
          fillInPossibilities(x,y); 
        } else{
          solvedSquares ++;
        }
      }
    }
  checkPossibilities();
  drawPossibilities();
if(solvedSquares == 81){
  for(int x = 0; x < 9; x++){
      for(int y = 0; y < 9; y++){
   solution[x] += str(numbers[x][y]);  
      }
  }
  saveStrings("solution.txt",solution);
  exit();
  }
}

void mousePressed(){
}
