#include <iostream>
#include <tgmath.h>
#include <ctime>
using namespace std;
int height = 9, width = 9, minecount, minecountperm = 10, choicex, choicey, mines = 0, tiempo, difficulty;
bool win = true, gamecontinue = false, zero =false;
string output = "", loss = "";
char replay;
char letters[] = {'Q','W','E','R','T','Y','U','I','O'};


int main() {

  //start screen with roolz and difficulty selector
  cout << "  __  __ _             ____\n |  \\/  (_)_ __   ___ / ___| _     "
          "_\n | |\\/| | | '_ \\ / _ \\ |   _| |_ _| |_\n | |  | | | | | |  "
          "__/ |__|_   _|_   _|\n |_|  |_|_|_| |_|\\___|\\____||_|   |_|\n";
  cout << "By Eden Harvey, Thushar Reppale, and Tracy Sheng\n";
  cout << "Enter column number first, then enter row number"
          "\n";
  //comes back to the start so they can replay and choose a different difficulty if desired;
  REPLAY:
  cout << "ENTER NUMBER FOR DIFFICULTY\n1 for beginner\n2 for intermediate\n3 for expert\n4 for custom\n";
  cin >> difficulty;
  if(difficulty == 1){
    height=9;
    width=9;
    minecount=10;
  }
  if(difficulty == 2){
    height=16;
    width=16;
    minecount=40;
  }
  if(difficulty == 3){
    height=16;
    width=30;
    minecount=99;
  }
  if(difficulty == 4){
    cout << "enter board height:\n";
    cin >> height;
    cout << "enter board width:\n";
    cin >> width;
    cout << "enter number of mines:\n";
    cin >> minecount;
  }
  
  // creates the griddy first
  // randomization for mine placement
  // divides mines left to place by squares left to check to rng
  srand(time(NULL));
  minecount = minecount;
  char griddy[height][width];
  for (int i = 0; i < width * height; i++) {
    if (rand() % 10000 < (10000 * minecount / (width * height - i))) {
      griddy[int(floor((i) / width))][int((i)-width * (floor((i) / width)))] =
          'X';
      minecount--;
    } else {
      griddy[int(floor((i) / width))][int((i)-width * (floor((i) / width)))] =
          'O';
    }
  }

  //deterines the number of mines surrunding a square
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      if (griddy[h][w] != 'X') {
        mines = 0;
        if (griddy[h - 1][w - 1] == 'X' && h != 0 && w != 0) {
          mines++;
        }
        if (griddy[h - 1][w] == 'X' && h != 0) {
          mines++;
        }
        if (griddy[h - 1][w + 1] == 'X' && h != 0 && w != width - 1) {
          mines++;
        }
        if (griddy[h][w - 1] == 'X' && w != 0) {
          mines++;
        }
        if (griddy[h][w + 1] == 'X' && w != width - 1) {
          mines++;
        }
        if (griddy[h + 1][w - 1] == 'X' && h != height - 1 && w != 0) {
          mines++;
        }
        if (griddy[h + 1][w] == 'X' && h != height - 1) {
          mines++;
        }
        if (griddy[h + 1][w + 1] == 'X' && h != height - 1 && w != width - 1) {
          mines++;
        }
        griddy[h][w] = '0' + mines;
      }
    }
  }

  loss = "";
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      loss+= string(1,griddy[h][w])+ " ";
    }
    loss+= "\n";
  }
  tiempo = time(NULL);

  
  while(win){

    //dont worry about this while loop
    //its not ver good
    while(zero){
      CERO:
      zero = false;
      if (griddy[choicey - 1][choicex - 1] == '0' && choicey != 0 && choicex != 0) {
        zero = true;
        choicey--;
        choicex--;
        if(true){
          if(griddy[choicey][choicex]=='0'){griddy[choicey][choicex]='Q';}
          if(griddy[choicey][choicex]=='1'){griddy[choicey][choicex]='W';}
          if(griddy[choicey][choicex]=='2'){griddy[choicey][choicex]='E';}
          if(griddy[choicey][choicex]=='3'){griddy[choicey][choicex]='R';}
          if(griddy[choicey][choicex]=='4'){griddy[choicey][choicex]='T';}
          if(griddy[choicey][choicex]=='5'){griddy[choicey][choicex]='Y';}
          if(griddy[choicey][choicex]=='6'){griddy[choicey][choicex]='U';}
          if(griddy[choicey][choicex]=='7'){griddy[choicey][choicex]='I';}
          if(griddy[choicey][choicex]=='8'){griddy[choicey][choicex]='O';}
        }
        goto CERO;
      }
      if (griddy[choicey - 1][choicex] == '0' && choicey != 0) {
        zero = true;
        choicey--;
        if(true){
          if(griddy[choicey][choicex]=='0'){griddy[choicey][choicex]='Q';}
          if(griddy[choicey][choicex]=='1'){griddy[choicey][choicex]='W';}
          if(griddy[choicey][choicex]=='2'){griddy[choicey][choicex]='E';}
          if(griddy[choicey][choicex]=='3'){griddy[choicey][choicex]='R';}
          if(griddy[choicey][choicex]=='4'){griddy[choicey][choicex]='T';}
          if(griddy[choicey][choicex]=='5'){griddy[choicey][choicex]='Y';}
          if(griddy[choicey][choicex]=='6'){griddy[choicey][choicex]='U';}
          if(griddy[choicey][choicex]=='7'){griddy[choicey][choicex]='I';}
          if(griddy[choicey][choicex]=='8'){griddy[choicey][choicex]='O';}
        }
        goto CERO;
      }
      if (griddy[choicey - 1][choicex + 1] == '0' && choicey != 0 && choicex != width - 1) {
        zero = true;
        choicey--;
        choicex++;
        if(true){
          if(griddy[choicey][choicex]=='0'){griddy[choicey][choicex]='Q';}
          if(griddy[choicey][choicex]=='1'){griddy[choicey][choicex]='W';}
          if(griddy[choicey][choicex]=='2'){griddy[choicey][choicex]='E';}
          if(griddy[choicey][choicex]=='3'){griddy[choicey][choicex]='R';}
          if(griddy[choicey][choicex]=='4'){griddy[choicey][choicex]='T';}
          if(griddy[choicey][choicex]=='5'){griddy[choicey][choicex]='Y';}
          if(griddy[choicey][choicex]=='6'){griddy[choicey][choicex]='U';}
          if(griddy[choicey][choicex]=='7'){griddy[choicey][choicex]='I';}
          if(griddy[choicey][choicex]=='8'){griddy[choicey][choicex]='O';}
        }
        goto CERO;
      }
      if (griddy[choicey][choicex - 1] == '0' && choicex != 0) {
        zero = true;
        choicex--;
        if(true){
          if(griddy[choicey][choicex]=='0'){griddy[choicey][choicex]='Q';}
          if(griddy[choicey][choicex]=='1'){griddy[choicey][choicex]='W';}
          if(griddy[choicey][choicex]=='2'){griddy[choicey][choicex]='E';}
          if(griddy[choicey][choicex]=='3'){griddy[choicey][choicex]='R';}
          if(griddy[choicey][choicex]=='4'){griddy[choicey][choicex]='T';}
          if(griddy[choicey][choicex]=='5'){griddy[choicey][choicex]='Y';}
          if(griddy[choicey][choicex]=='6'){griddy[choicey][choicex]='U';}
          if(griddy[choicey][choicex]=='7'){griddy[choicey][choicex]='I';}
          if(griddy[choicey][choicex]=='8'){griddy[choicey][choicex]='O';}
        }
        goto CERO;
      }
      if (griddy[choicey][choicex + 1] == '0' && choicex != width - 1) {
        zero = true;
        choicex++;
        if(true){
          if(griddy[choicey][choicex]=='0'){griddy[choicey][choicex]='Q';}
          if(griddy[choicey][choicex]=='1'){griddy[choicey][choicex]='W';}
          if(griddy[choicey][choicex]=='2'){griddy[choicey][choicex]='E';}
          if(griddy[choicey][choicex]=='3'){griddy[choicey][choicex]='R';}
          if(griddy[choicey][choicex]=='4'){griddy[choicey][choicex]='T';}
          if(griddy[choicey][choicex]=='5'){griddy[choicey][choicex]='Y';}
          if(griddy[choicey][choicex]=='6'){griddy[choicey][choicex]='U';}
          if(griddy[choicey][choicex]=='7'){griddy[choicey][choicex]='I';}
          if(griddy[choicey][choicex]=='8'){griddy[choicey][choicex]='O';}
        }
        goto CERO;
      }
      if (griddy[choicey + 1][choicex - 1] == '0' && choicey != height - 1 && choicex != 0) {
        zero = true;
        choicey++;
        choicex--;
        if(true){
          if(griddy[choicey][choicex]=='0'){griddy[choicey][choicex]='Q';}
          if(griddy[choicey][choicex]=='1'){griddy[choicey][choicex]='W';}
          if(griddy[choicey][choicex]=='2'){griddy[choicey][choicex]='E';}
          if(griddy[choicey][choicex]=='3'){griddy[choicey][choicex]='R';}
          if(griddy[choicey][choicex]=='4'){griddy[choicey][choicex]='T';}
          if(griddy[choicey][choicex]=='5'){griddy[choicey][choicex]='Y';}
          if(griddy[choicey][choicex]=='6'){griddy[choicey][choicex]='U';}
          if(griddy[choicey][choicex]=='7'){griddy[choicey][choicex]='I';}
          if(griddy[choicey][choicex]=='8'){griddy[choicey][choicex]='O';}
        }
        goto CERO;
      }
      if (griddy[choicey + 1][choicex] == '0' && choicey != height - 1) {
        zero = true;
        choicey++;
        if(true){
          if(griddy[choicey][choicex]=='0'){griddy[choicey][choicex]='Q';}
          if(griddy[choicey][choicex]=='1'){griddy[choicey][choicex]='W';}
          if(griddy[choicey][choicex]=='2'){griddy[choicey][choicex]='E';}
          if(griddy[choicey][choicex]=='3'){griddy[choicey][choicex]='R';}
          if(griddy[choicey][choicex]=='4'){griddy[choicey][choicex]='T';}
          if(griddy[choicey][choicex]=='5'){griddy[choicey][choicex]='Y';}
          if(griddy[choicey][choicex]=='6'){griddy[choicey][choicex]='U';}
          if(griddy[choicey][choicex]=='7'){griddy[choicey][choicex]='I';}
          if(griddy[choicey][choicex]=='8'){griddy[choicey][choicex]='O';}
        }
        goto CERO;
      }
      if (griddy[choicey + 1][choicex + 1] == '0' && choicey != height - 1 && choicex != width - 1) {
        zero = true;
        choicey++;
        choicex++;
        if(true){
          if(griddy[choicey][choicex]=='0'){griddy[choicey][choicex]='Q';}
          if(griddy[choicey][choicex]=='1'){griddy[choicey][choicex]='W';}
          if(griddy[choicey][choicex]=='2'){griddy[choicey][choicex]='E';}
          if(griddy[choicey][choicex]=='3'){griddy[choicey][choicex]='R';}
          if(griddy[choicey][choicex]=='4'){griddy[choicey][choicex]='T';}
          if(griddy[choicey][choicex]=='5'){griddy[choicey][choicex]='Y';}
          if(griddy[choicey][choicex]=='6'){griddy[choicey][choicex]='U';}
          if(griddy[choicey][choicex]=='7'){griddy[choicey][choicex]='I';}
          if(griddy[choicey][choicex]=='8'){griddy[choicey][choicex]='O';}
        }
        goto CERO;
      }
    }
    
    //does the outputthingie yknow
    output = "  ";
    gamecontinue = false;
    for (int w = 0; w < width; w++) {
      if (w >= 0 && w <= 8) {
        output += to_string(w+1) + " ";
      } else if (w >= 9 && w <= 18) {
        output += to_string(w-9) + " ";
      } else if (w >= 19 && w <= 28) {
        output += to_string(w-19) + " ";
      } else if (w >= 29) {
        output += to_string(w-29) + " ";
      }
    }
    output += "\n";
    for (int h = 0; h < height; h++) {
      if (h >= 0 && h <= 8) {
        output += to_string(h+1) + " ";
      } else if (h >= 9 && h <= 18) {
        output += to_string(h-9) + " ";
      } else if (h >= 19 && h <= 28) {
        output += to_string(h-19) + " ";
      } else if (h >= 29) {
        output += to_string(h-29) + " ";
      }
      for (int w = 0; w < width; w++) {
        if(griddy[h][w] == 'X'){
          output+=". ";
        }
        if(griddy[h][w] == '0' || griddy[h][w] == '1' || griddy[h][w] == '2' || griddy[h][w] == '3' || griddy[h][w] == '4' || griddy[h][w] == '5' || griddy[h][w] == '6' || griddy[h][w] == '7' || griddy[h][w] == '8'){
          output+=". ";
          gamecontinue=true;
        }
        if(griddy[h][w] == 'Q'){output+="* ";}
        if(griddy[h][w] == 'W'){output+="1 ";}
        if(griddy[h][w] == 'E'){output+="2 ";}
        if(griddy[h][w] == 'R'){output+="3 ";}
        if(griddy[h][w] == 'T'){output+="4 ";}
        if(griddy[h][w] == 'Y'){output+="5 ";}
        if(griddy[h][w] == 'U'){output+="6 ";}
        if(griddy[h][w] == 'I'){output+="7 ";}
        if(griddy[h][w] == 'O'){output+="8 ";}
      }
      output += "\n";
    }
    cout << "\n"<<output<<"\n";
    if(!gamecontinue){
      break;
    }
    
    cin >> choicex;
    cin >> choicey;
    choicex-=1;
    choicey-=1;
    if(true){
      if(griddy[choicey][choicex]=='X'){win=false;}
      if(griddy[choicey][choicex]=='0'){griddy[choicey][choicex]='Q';zero = true;}
      if(griddy[choicey][choicex]=='1'){griddy[choicey][choicex]='W';}
      if(griddy[choicey][choicex]=='2'){griddy[choicey][choicex]='E';}
      if(griddy[choicey][choicex]=='3'){griddy[choicey][choicex]='R';}
      if(griddy[choicey][choicex]=='4'){griddy[choicey][choicex]='T';}
      if(griddy[choicey][choicex]=='5'){griddy[choicey][choicex]='Y';}
      if(griddy[choicey][choicex]=='6'){griddy[choicey][choicex]='U';}
      if(griddy[choicey][choicex]=='7'){griddy[choicey][choicex]='I';}
      if(griddy[choicey][choicex]=='8'){griddy[choicey][choicex]='O';}
    }

  }

  if (win) {
    cout << "You win! Time: "<<	time(NULL)-tiempo <<"\n";
  } else {
    cout << loss << "\n" << "You lose :3 meow\n";
  }
  cout << "Thank you for playing\nenter Y to replay\n";
  cin >> replay;
  if(replay == 'Y' || replay == 'y'){
    win= true;
    goto REPLAY;
  }
}
