
void checkPossibilities(){
  for(int x = 0; x < 9; x++){
    for(int y = 0; y < 9; y++){
      if(numbers[x][y] == 0){
        checkRows(x,y);
        checkCols(x,y);
        checkBoxes(x,y);
      } 
    }
  }
}

void checkRows(int x,int y){
  for(int i = 0; i < 9; i++){
    if(x != i && numbers[i][y] != 0){
      possibilities[x][y][numbers[i][y]-1] = false;
    }
  }
}

void checkCols(int x,int y){
  for(int j = 0; j < 9; j++){
    if(y != j && numbers[x][j] != 0){
      possibilities[x][y][numbers[x][j]-1] = false;
    }
  }
}

void checkBoxes(int trueX,int trueY){
  //Sets the x value to the upper right corner of each box
  int x = trueX - trueX % 3;
  int y = trueY - trueY % 3;
  for(int i = 0; i < 3;i++){
    for(int j = 0; j < 3;j++){
    if((x == i && y == j)==false && numbers[x+i][y+j] != 0){
      possibilities[trueX][trueY][numbers[x+i][y+j]-1] = false;
    }
    }
  }
}
