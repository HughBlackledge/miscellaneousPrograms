#include <iostream>
#include <vector>
#include <fstream>
#include <map>

/*
This game is the sole intellectual property of Hugh Blackledge.

You must not:

- Republish material from this game
- Sell, rent or sub-license material from this game
- Reproduce, duplicate or copy material from
- Redistribute content from this game.

*/

 using namespace std;
//Colour codes
 #define RESET   "\033[0m"
 #define BLACK   "\033[30m"      /* Black */
 #define RED     "\033[31m"      /* Red */
 #define GREEN   "\033[32m"      /* Green */
 #define YELLOW  "\033[33m"      /* Yellow */
 #define BLUE    "\033[34m"      /* Blue */
 #define MAGENTA "\033[35m"      /* Magenta */
 #define CYAN    "\033[36m"      /* Cyan */
 #define WHITE   "\033[37m"      /* White */
 #define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
 #define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
 #define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
 #define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
 #define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
 #define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
 #define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
 #define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

string fileDirectory = "dungeonGame";

int roomSize = 10;
char room[10][10];
int wallNum = 14;
int difficulty = 1;
int score = 0;
char inventoryDisplay[9];
string inventory[9];
int inventoryStats[18];
string action = "";
bool alive = true;
int posX = roomSize/2;
int posY = 8;

int hp = 10;
int maxHP = 10;
int mp = 100;
int xp = 0;
int level = 1;
int gold = 0;

string deathCause = "";
vector<string> loot;
vector<int> lootStats;
vector<char> lootDisplay;

bool nextRoom = true;
int lootItemNum = 13;
int lootMaterialNum = 25;
int lootModifierNum = 36;

void loadSettings();
void generateRoom();
void generateWalls();
void generateLoot();
void breakWalls();
void OpenDoor();
void spawnMonsters();
void generateInventory();
void turn();
void openInventory();
void moveRoom();
void setLoot();
void levelUp();
void colouredText();

void drawRoom(){
  for(int y = 0; y < roomSize; y++){
    cout << "\t\t\t\t";
    for(int x = 0; x < roomSize; x++){
        cout << room[x][y] << " ";
    }
    cout << endl;
  }
  for(int i = 0; i < 3; i++){
    cout << endl;
  }
}

void startUp(){
  //loadSettings();
  srand(time(NULL));
generateInventory();
cout << endl;
setLoot();
}

void saving(){

}

int random(int start, int end){
  return rand() % (end - start) + start;
}

 int main() {
   startUp();
   generateRoom();
   colouredText();
   room[roomSize/2][9] = ' ';
   room[roomSize/2][8] = 'P';
   room[roomSize/2][7] = ' ';
   generateLoot();
while(alive == true){
  while(nextRoom == false){
    drawRoom();
    cout << "\t" <<endl;
    turn();
    if(hp < 1){
      alive = false;
      break;
    }
  }
  generateRoom();
  moveRoom();
  generateLoot();
  nextRoom = false;
}
cout << "You have been killed by a " << deathCause << "." << endl;
if(deathCause == "Wall"){
  cout << "You clumsy idiot you got killed by a wall, a wall of all things." << endl << "What is wrong with you?" << endl;
}
}

void generateRoom(){
  nextRoom = false;
  for(int y = 0; y < roomSize; y++){
    for(int x = 0; x < roomSize; x++){
      if(x % (roomSize - 1) == 0 || y % (roomSize - 1) == 0){
        room[x][y] = 'w';
      } else room[x][y] = ' ';
    }
  }
  generateWalls();
  breakWalls();
  OpenDoor();
  spawnMonsters();
}

void generateWalls(){
  //Create the level structure
  int walls = 0;
  while(walls < wallNum){
    if(rand() % 2 == 0){
      int y = random(0,roomSize);
      int length = random(2,5);
      int x = random(length,roomSize)-length;
      int end = x + length;

      for(x = random(length,roomSize)-length; x < end; x++){
        room[x][y] = 'w';
      }
    } else{
      int x = random(0,roomSize);
      int length = random(3,7);
      int y = random(length,roomSize)-length;
      int end = y + length;
      for(y = random(length,roomSize)-length; y < end; y++){
        room[x][y] = 'w';
    }
  }
  walls ++;
  }


}

void breakWalls(){
  //Adds irregularity by breaking walls randomly
  for(int y = 1; y < roomSize - 1; y++){
    int walls = 0;
    for(int x = 1; x < roomSize - 1; x++){
      if(room[x][y] == 'w'){
        walls ++;
      }
    }
    if(walls > 5){
      int x = random(1,roomSize-2);
      while(room[x][y] != ' '){
        room[x][y] = ' ';
        x = random(1,roomSize-2);
      }
    }
  }
  for(int x = 1; x < roomSize - 1; x++){
    int walls = 0;
    for(int y = 1; y < roomSize - 1; y++){
      if(room[x][y] == 'w'){
        walls ++;
      }
    }
    if(walls > 5){
      int y = random(1,roomSize-2);
      while(room[x][y] != ' '){
        room[x][y] = ' ';
        y = random(1,roomSize-2);
      }
    }
  }
  for(int i = 0; i < 5; i++){
    room[random(1,roomSize-2)][random(1,roomSize-2)] = ' ';
  }
}

void OpenDoor(){
  int door1 = 0;
  int door2 = 0;
  int door3 = 0;
  int door4 = 0;
  //randomly chooses whether the doors are open or closed
  door1 += rand() % 2 * (door1 == 0);
  door2 += rand() % 2 * (door2 == 0);
  door3 += rand() % 2 * (door3 == 0);
  door4 += rand() % 2 * (door4 == 0);
 if(door1 == 1){
   room[roomSize/2][0] = ' ';
   room[roomSize/2][1] = ' ';
 }
 if(door2 == 1){
   room[9][roomSize/2] = ' ';
   room[8][roomSize/2] = ' ';
 }
 if(door3 == 1){
   room[roomSize/2][9] = ' ';
   room[roomSize/2][8] = ' ';
 }
 if(door4 == 1){
   room[0][roomSize/2] = ' ';
   room[1][roomSize/2] = ' ';
 }
while(door1 + door2 + door3 + door4 < 2){
   door1 += rand() % 2 * (door1 == 0);
   door2 += rand() % 2 * (door2 == 0);
   door3 += rand() % 2 * (door3 == 0);
   door4 += rand() % 2 * (door4 == 0);
  if(door1 == 1){
    room[roomSize/2][0] = ' ';
    room[roomSize/2][1] = ' ';
  }
  if(door2 == 1){
    room[9][roomSize/2] = ' ';
    room[8][roomSize/2] = ' ';
  }
  if(door3 == 1){
    room[roomSize/2][9] = ' ';
    room[roomSize/2][8] = ' ';
  }
  if(door4 == 1){
    room[0][roomSize/2] = ' ';
    room[1][roomSize/2] = ' ';
  }
}
}
//spawns the monsters
void spawnMonsters(){
  for(int i = 0; i < difficulty * 5; i++){
    int x = random(1,roomSize-2);
    int y = random(1,roomSize-2);
      if(room[x][y] == ' '){
        room[x][y] = 'M';
      } else i --;
  }
int x = random(1,roomSize-2);
int y = random(1,roomSize-2);

while(room[x][y] != ' '){
  x = random(1,roomSize-2);
  y = random(1,roomSize-2);
}
room[x][y] = 'B';
}

void generateInventory(){
  for(int i = 0; i < 9; i++){
    inventoryDisplay[i] = '*';
  }
}

void attack(){
 char atk = ' ';
 cin >> atk;
 switch(atk){
   case 'u':
   if(posY - 1 > -1){
     if(room[posX][posY-1] == 'M' || room[posX][posY-1] == 'B'){
       room[posX][posY-1] = ' ';
       hp -= 2 * difficulty * (1 + (room[posX][posY-1] == 'B'));
       gold += random(3,7) * difficulty * (1+(room[posX][posY-1] == 'B'));
       xp += random(11,19) * difficulty * (1+(room[posX][posY-1] == 'B'));
      deathCause = "Monster";
     }
   }
   break;
   case 'd':
   if(posY + 1 < roomSize - 1){
     if(room[posX][posY+1] == 'M' || room[posX][posY+1] == 'B'){
       room[posX][posY+1] = ' ';
       hp -= 2 * difficulty * (1 + (room[posX][posY+1] == 'B'));
       gold += random(3,7) * difficulty * (1+(room[posX][posY-1] == 'B'));
       xp += random(11,19) * difficulty * (1+(room[posX][posY-1] == 'B'));
       deathCause = "Monster";
     }
   }
   break;
   case 'r':
   if(posX + 1 < roomSize - 1){
     if(room[posX+1][posY] == 'M' || room[posX+1][posY] == 'B'){
       room[posX+1][posY] = ' ';
       hp -= 2 * difficulty * (1 + (room[posX+1][posY] == 'B'));
       gold += random(3,7) * difficulty * (1+(room[posX][posY-1] == 'B'));
       xp += random(11,19) * difficulty * (1+(room[posX][posY-1] == 'B'));
       deathCause = "Monster";
     }
   }
   break;
   case 'l':
   if(posX - 1 > -1){
     if(room[posX-1][posY] == 'M' || room[posX-1][posY] == 'B'){
       room[posX-1][posY] = ' ';
       hp -= 2 * difficulty * (1 + (room[posX-1][posY] == 'B'));
       gold += random(3,7) * difficulty * (1+(room[posX][posY-1] == 'B'));
       xp += random(11,19) * difficulty * (1+(room[posX][posY-1] == 'B'));
       deathCause = "Monster";
     }
   }
   break;
 }
}

void spell(){
//sp = spell
char sp = ' ';
cin >> sp;
switch(sp){
case 't':
{
  int locX = posX;
  int locY = posY;
  cin >> locX;
  cin >> locY;
  if(mp > 10 && room[locX][locY] == ' '){
    room[posX][posY] = ' ';
   posX = locX;
   posY = locY;
   room[posX][posY] = 'P';
   mp -= 10;
 } else{
   cout << "Teleporting into walls hurts, ouch." << endl;
   mp -= 15;
   hp -= 5;
 }
  break;
}


case 'f':
{
  cout << "Choose your target: (x,y)" << endl;
  int targetX = 0;
  int targetY = 0;
  cin >> targetX >> targetY;
  switch(room[targetX][targetY]){
    case 'w':
    cout << "You hit a wall with a fireball." << endl;
    break;
}
break;
}

case 'h':
{
  if(mp > 20 && hp <= maxHP){
    hp += maxHP - hp;
    mp -= 20;
  }
}
break;
}
}

void walk(){
//Walking...
char direction = ' ';
cin >> direction;
room[posX][posY] = ' ';
//string direction2 = " ";
//cin >> direction2;
//switch
switch(direction){
  case 'u':
  if(posY - 1 > -1){
    if(room[posX][posY-1] == ' '){
      posY --;
    } else if(room[posX][posY-1] == 'w'){
      int damage = random(1,3);
      hp -= damage;
      cout << "You run into a wall and lose " << damage << " health.";
      deathCause = "Wall";
    }
  }
  break;
  case 'd':
  if(posY + 1 < roomSize){
    if(room[posX][posY+1] == ' '){
      posY ++;
    } else if(room[posX][posY-1] == 'w'){
      int damage = random(1,3);
      hp -= damage;
      cout << "You run into a wall and lose " << damage << " health.";
      deathCause = "Wall";
    }
  }
  break;
  case 'r':
  if(posX + 1 < roomSize){
    if(room[posX+1][posY] == ' '){
      posX ++;
    } else if(room[posX][posY-1] == 'w'){
      int damage = random(1,3);
      hp -= damage;
      cout << "You run into a wall and lose " << damage << " health.";
      deathCause = "Wall";
    }
  }
  break;
  case 'l':
  if(posX - 1 > -1){
    if(room[posX-1][posY] == ' '){
      posX --;
    } else if(room[posX][posY-1] == 'w'){
      int damage = random(1,3);
      hp -= damage;
      cout << "You run into a wall and lose " << damage << " health.";
      deathCause = "Wall";
    }
  }
  break;
}
room[posX][posY] = 'P';
}

void checkInventorySlot(int slotNum){
  //Check what item is in each slot
  if(inventoryDisplay[slotNum-1] == '*'){
    cout << "That slot is empty." << endl;
  } else{
    switch(inventory[slotNum - 1][0]){
      case 'a':
      cout << "That slot contains an " << inventory[slotNum - 1] << endl;
      break;
      case 'i':
      cout << "That slot contains an " << inventory[slotNum - 1] << endl;
      break;

      case 'o':
      cout << "That slot contains an " << inventory[slotNum - 1] << endl;
      break;

      case 'u':
      cout << "That slot contains an " << inventory[slotNum - 1] << endl;
      break;
      case 'e':
      cout << "That slot contains an " << inventory[slotNum - 1] << endl;
      break;
      default:
      cout << "That slot contains a " << inventory[slotNum - 1] << endl;
      break;
    }
  }
}

void openInventory(){
  //Inventory actions
  cout << '|';
for(int i = 0; i < 9; i++){
  cout << inventoryDisplay[i] << '|';
}
cout << endl;
//n = no don't close inventory
char inventoryAction = 'n';
while(inventoryAction != 'y'){
  cout << "Do you want to close your inventory (y/n) or check a specific slot (slot number)?" << endl;
  cin >> inventoryAction;
  switch(inventoryAction){
    case '1':
    checkInventorySlot(1);
    break;
    case '2':
    checkInventorySlot(2);
    break;
    case '3':
    checkInventorySlot(3);
    break;
    case '4':
    checkInventorySlot(4);
    break;
    case '5':
    checkInventorySlot(5);
    break;
    case '6':
    checkInventorySlot(6);
    break;
    case '7':
    checkInventorySlot(7);
    break;
    case '8':
    checkInventorySlot(8);
    break;
    case '9':
    checkInventorySlot(8);
    break;
    default:
    if(inventoryAction != 'y'){
      inventoryAction = 'n';
    }
    break;
  }

}
}

void chestLoot(){
  //Randomises the loot
  char chosenInventorySlot = '0';
  cout << "What slot would you like to put the loot into?" << endl;
  cin >> chosenInventorySlot;
  int selectedLoot = random(0,loot.size());
  switch(chosenInventorySlot){
    case '1':
    inventory[0] = loot[selectedLoot];
    inventoryDisplay[0] = lootDisplay[selectedLoot];
    loot.erase(loot.begin() + selectedLoot - 1);
    lootDisplay.erase(lootDisplay.begin() + selectedLoot - 1);
    break;
    case '2':
    inventory[1] = loot[selectedLoot];
    inventoryDisplay[1] = lootDisplay[selectedLoot];
    loot.erase(loot.begin() + selectedLoot - 1);
    lootDisplay.erase(lootDisplay.begin() + selectedLoot - 1);
    break;
    case '3':
    inventory[2] = loot[selectedLoot];
    inventoryDisplay[2] = lootDisplay[selectedLoot];
    loot.erase(loot.begin() + selectedLoot - 1);
    lootDisplay.erase(lootDisplay.begin() + selectedLoot - 1);
    break;
    case '4':
    inventory[3] = loot[selectedLoot];
    inventoryDisplay[3] = lootDisplay[selectedLoot];
    loot.erase(loot.begin() + selectedLoot - 1);
    lootDisplay.erase(lootDisplay.begin() + selectedLoot - 1);
    break;
    case '5':
    inventory[4] = loot[selectedLoot];
    inventoryDisplay[4] = lootDisplay[selectedLoot];
    loot.erase(loot.begin() + selectedLoot - 1);
    lootDisplay.erase(lootDisplay.begin() + selectedLoot - 1);
    break;
    case '6':
    inventory[5] = loot[selectedLoot];
    inventoryDisplay[5] = lootDisplay[selectedLoot];
    loot.erase(loot.begin() + selectedLoot - 1);
    lootDisplay.erase(lootDisplay.begin() + selectedLoot - 1);
    break;
    case '7':
    inventory[6] = loot[selectedLoot];
    inventoryDisplay[6] = lootDisplay[selectedLoot];
    loot.erase(loot.begin() + selectedLoot - 1);
    lootDisplay.erase(lootDisplay.begin() + selectedLoot - 1);
    break;
    case '8':
    inventory[7] = loot[selectedLoot];
    inventoryDisplay[7] = lootDisplay[selectedLoot];
    loot.erase(loot.begin() + selectedLoot - 1);
    lootDisplay.erase(lootDisplay.begin() + selectedLoot - 1);
    break;
    case '9':
    inventory[8] = loot[selectedLoot];
    inventoryDisplay[8] = lootDisplay[selectedLoot];
    loot.erase(loot.begin() + selectedLoot - 1);
    lootDisplay.erase(lootDisplay.begin() + selectedLoot - 1);
    break;
  }
  gold += random(20,100);
}

void openChest(){
  //Manages the open of a chest and runs chest loot function
  char direction = ' ';
  cin >> direction;
  switch(direction){
    case 'u':
    if(posY - 1 > -1){
      if(room[posX][posY-1] == 'L'){
        chestLoot();
        room[posX][posY-1] = ' ';
      }
    }
    break;
    case 'd':
    if(posY + 1 < roomSize){
      if(room[posX][posY+1] == 'L'){
        chestLoot();
        room[posX][posY+1] = ' ';
      }
    }
    break;
    case 'r':
    if(posX + 1 < roomSize){
      if(room[posX+1][posY] == 'L'){
        chestLoot();
        room[posX+1][posY] = ' ';
      }
    }
    break;
    case 'l':
    if(posX - 1 > -1){
      if(room[posX-1][posY] == 'L'){
        chestLoot();
        room[posX-1][posY] = ' ';
      }
    }
    break;
  }
  room[posX][posY] = 'P';
}

void turn(){
//Every player action
levelUp();
cout << "You have " << hp << "hp" << endl;
cout << "You have " << mp << "mp" << endl;
cout << "You have " << gold << " gold" << endl;
cout << "You have " << xp << "xp" << endl;
cout << "You are level " << level << endl;
cout <<"Choose an action: attack (atk), spell (sp),walk(w) - (up-u,down-d,right-r,left-l),openInventory(inv)..." << endl;
cin >> action;
if(action == "atk"){
  attack();
} else if(action == "sp"){
  spell();
} else if(action == "w"){
  walk();
} else if(action == "inv"){
  openInventory();
} else if(action == "loot"){
  openChest();
}
for(int i = 0; i < 3; i++){
  cout << endl;
}
if(posX % 9 == 0 || posY % 9 ==0){
  nextRoom = true;
}
}

void moveRoom(){
  //This runs when the player goes through a door and makes sure there is a door there
  if(room[posX][posY] == 'P'){
    room[posX][posY] = ' ';
  }
  posX = abs(posX - 8) * (posX != roomSize/2) + posX * (posX == roomSize/2);
  posY = abs(posY - 8) * (posY != roomSize/2) + posY * (posY == roomSize/2);
  room[posX][posY] = 'P';
  if(room[posX - (posX < 1) * 1 + (posX < 9) * 1][posY - (posY < 1) * 1 + (posY < 9) * 1] == 'w'){
    room[posX - (posX < 1) * 1 + (posX < 9) * 1][posY - (posY < 1) * 1 + (posY < 9) * 1] = ' ';
  }
  if(room[posX - (posX < 1) * 2 + (posX < 9) * 2][posY - (posY < 1) * 2 + (posY < 9) * 2] == 'w'){
    room[posX - (posX < 1) * 2 + (posX < 9) * 2][posY - (posY < 1) * 2 + (posY < 9) * 2] = ' ';
  }
}

void generateLoot(){
  //Put the loot chests into the room
  for(int i = 0; i < difficulty; i++){
    int ChestX = random(1,9);
    int ChestY = random(1,9);
    if(room[ChestX][ChestY] == ' '){
      room[ChestX][ChestY] = 'L';
    } else  i --;
  }
}

void setLoot(){
  ifstream items ("/Users/hugh/codingStuff/c++/programs/dungeonGame/loot.txt");
  ifstream materials ("/Users/hugh/codingStuff/c++/programs/dungeonGame/material.txt");
  ifstream modifiers ("/Users/hugh/codingStuff/c++/programs/dungeonGame/modifier.txt");

  vector<string> item;
  vector<string> itemStat;
  vector<string> material;
  vector<string> materialStat;
  vector<string> modifier;
  vector<string> modifierStat;

//Get info from files
       if (items.is_open())
       {
         string line = "";
         int i = 0;
         while ( getline (items,line) )
         {
           if(i % 3 == 0){
             //item[i/3] = line;
             item.push_back(line);
           } else{
             itemStat.push_back(line);
           }

           i++;

         }
         items.close();
  }
  if (materials.is_open())
  {
    string line = "";
    int i = 0;
    while ( getline (materials,line) )
    {
      if(i % 3 == 0){
      material.push_back(line);
    } else{
      materialStat.push_back(line);
    }
      i++;

    }
    materials.close();
  }
  if (modifiers.is_open())
  {
    string line = "";
    int i = 0;
    while ( getline (modifiers,line) )
    {
      if(i % 3 == 0){
        modifier.push_back(line);
      } else{
        modifierStat.push_back(line);
      }
      i++;

    }
    modifiers.close();
  }
  for(int i = 0; i < 100; i++){
    //positions in arrays
    int posItem = random(0,lootItemNum);
    int posMod = random(0,lootModifierNum);
    if(item[posItem][0] == 'c'){
      int posMat = random(0,lootMaterialNum);
      //Need to change to take into account the stats of materials,modifiers and item type
      int posItemStats = 0;
      loot.push_back(modifier[posMod] + " " + material[posMat] + " " + item[posItem]);
    } else {
      int posMat = random(0,lootMaterialNum - 9);
            //Need to change to take into account the stats of materials,modifiers and item type
      int posItemStats = 0;
      if(item[posItem][0] != 'g' && item[posItem] != "boots"){
        loot.push_back(modifier[posMod] + " " + material[posMat] + " " + item[posItem]);
      } else loot.push_back("pair of " + modifier[posMod] + " " + material[posMat] + " " + item[posItem]);
    }
    //cout << loot[i] << endl;
    lootDisplay.push_back(item[posItem][0]);
  }
}

void levelUp(){
  if(xp > level * 100 * ((level - level % 10)/10+1)){
    xp -= level * 100 * ((level - level % 10)/10+1);
    level ++;
    cout << "You have leveled up from " << level - 1 << " to level "<< level << endl;
  }
}

void loadSettings(){
/*  ifstream dungeonGameSettings ("dungeonGameSettings.txt");
  if (dungeonGameSettings.is_open())
  {
    string line = "";
    int i = 0;
    while ( getline (dungeonGameSettings,line) )
    {
      fileDirectory = line;
      i++;

    }
    dungeonGameSettings.close();
  } */
}

void colouredText(){
  cout << RED << "Hi" << endl;
  cout << RESET;
}
