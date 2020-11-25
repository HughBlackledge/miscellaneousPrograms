
void drawPossibilities(){
  for(int x = 0; x < 9; x++){
    for(int y = 0; y < 9; y++){
     for(int i = 0; i < 9;i++){
       fill(140);
       if(possibilities[x][y][i] == true && numbers[x][y] == 0){
         text(i+1,x*boxSize+i*5,y * boxSize+10);
       }
       
     }
    }
  }
}

boolean fillInPossibilities(int x,int y){
  int index = -1;
  for(int i = 0; i < 9;i++){
    //if more than one number could be in the particular square it just skips filling in the square
    if(possibilities[x][y][i] == true){
      if(index != -1){
        return false;
      }
      index = i;
    }
  }
  if(index != -1){
    numbers[x][y] = index+1;
  }
  return true;
}

//this is unnecessary currently

/*
boolean fillInBoxes(){
  boolean[] boxPossibilities = new boolean[9];
  for(int box_X = 0; box_X < 3; box_X ++){
    for(int box_Y = 0; box_Y < 3; box_Y ++){
    for(int x = 0; x < 3; x++){
      for(int y = 0; y < 3; y++){
          if(numbers[box_X+x][box_Y+y] != 0){
            boxPossibilities[numbers[box_X+x][box_Y+y]] = false;
          }
        }
      }
    }
  }
  int index = -1;
  for(int i = 0; i < 9;i++){
    if(boxPossibilities[i] == true){
      if(index != -1){
        return false;
      }
      index = i;
    }
  }
  
  return true;
}

*/
