#include <iostream>
#include <tgmath.h>
#include <ctime>
using namespace std;
int height = 9, width = 9, minecount = 10, x, y, mines = 0, tiempo, difficulty = 0, flaggy, middle;
bool win = true, gamecontinue = false, zero =false, flags = false;
string output = "", loss = "";
char replay;
char letters[] = {'Q','W','E','R','T','Y','U','I','O'};

int main() {

  //start screen with roolz and difficulty selector
  cout << "  __  __ _             ____\n |  \\/  (_)_ __   ___ / ___| _     "
          "_\n | |\\/| | | '_ \\ / _ \\ |   _| |_ _| |_\n | |  | | | | | |  "
          "__/ |__|_   _|_   _|\n |_|  |_|_|_| |_|\\___|\\____||_|   |_|\n";
  cout << "By Eden Harvey, Thushar Reppale, and Tracy Sheng\nsingle digits showed for ease of entry\n";
  cout << "Enter column number first, then enter row number"
          "\n";
  //comes back to the start so they can replay and choose a different difficulty if desired;
  REPLAY:
  cout << "ENTER NUMBER FOR DIFFICULTY\n1 for beginner\n2 for intermediate\n3 for expert\n4 for custom\n";
  cin >> difficulty;
  //switch to set size and number of mines based off difficulty
  switch(difficulty) {
    case 1:
      height=9;
      width=9;
      minecount=10;
      break;
    case 2:
      height=16;
      width=16;
      minecount=40;
      break;
    case 3:
      height=16;
      width=30;
      minecount=99;
      break;
    case 4:
      cout << "enter board height:\n";
      cin >> height;
      cout << "enter board width:\n";
      cin >> width;
      cout << "enter number of mines:\n";
      cin >> minecount;
  }
  cout << "do you want flags enabled? 0 for no 1 for yes\n";
  cin >> difficulty;
  if(difficulty == 0){flags=false;}
  if(difficulty == 1){
    flags = true;
    cout << "before entering numbers enter 1 if you wnat to clear the square and 0 if you want to flag it\n";
  }
  
  // creates the griddy first
  // randomization for mine placement
  // divides mines left to place by squares left to check to rng
  srand(time(NULL));
  char griddy[height][width];
  bool friddy[height][width];
  for (int i = 0; i < width * height; i++) {
    if (rand() % 10000 < (10000 * minecount / (width * height - i))) {
      griddy[int(floor(i/width))][int(i-width*(floor(i/width)))] = 'X';
      minecount--;
    } else {
      griddy[int(floor(i/width))][int(i-width*(floor(i/width)))] = 'O';
    }
    friddy[int(floor(i/width))][int((i)-width*(floor(i/width)))] = false;
  }

  //deterines the number of mines surrunding a square
  // and puts it into the griddy
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      if (griddy[h][w] != 'X') {
        mines = 0;
        for(int r= -1;r<=1;r++) {
          for(int c= -1;c<=1;c++) {
            if(h+r!=-1 && w+c!=-1 && h+r!=height && w+c!=width){
              if(griddy[h+r][w+c] == 'X'){
                mines++;
              }
            }
          }  
        }
        griddy[h][w] = '0' + mines;
      }
    }
  }

  //creates the loss output that displays when they lose the game
  loss = "";
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      loss+= string(1,griddy[h][w])+ " ";
    }
    loss+= "\n";
  }

  
  tiempo = time(NULL);
  while(win){

    //wehn theres a zero this clears all the surrounding squares
    //that are also zeroes or next to zeroes
    for (int t = 0; t < max(width,height); t++) {
      for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
          if(griddy[h][w] == 'Q') {
            for(int r= -1;r<=1;r++) {
              for(int c= -1;c<=1;c++) {
                if(h+r!=-1 && w+c!=-1 && h+r!=height && w+c!=width){
                  for(int k = 0; k < 9; k++){
                    if(griddy[h+r][w+c] == '0'+k){
                      griddy[h+r][w+c] = letters[k];
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
      
    output = "  ";
    gamecontinue = false;

    //first adds the numbers up top
    for (int w = 1; w <= width; w++) {
      output+= to_string(int((w) - 10*(floor(w/10))))+" ";
    }
    output += "\n";
    
    for (int h = 0; h < height; h++) {
      //adds numbers to the left side as well 
      output+= to_string(int((h+1) - 10*(floor((h+1)/10)))) + " ";
      for (int w = 0; w < width; w++) {
        //puts out flag if its flagged
        if(friddy[h][w]){
          output+="⚐ ";
        }else{
          //adds the uncleared square if its a mine
          if(griddy[h][w] == 'X'){
            output+="◼ ";
          }
          //adds the uncleared square if its an uncleared nonmine
          for(int k = 0; k < 9; k++){
            if(griddy[h][w] == '0'+k){
              output+="◼ ";
              gamecontinue=true;
            }
          }

          //adds the number of dot if its a cleared nonmine
          if(griddy[h][w] == 'Q'){output+=". ";}
          for(int k = 1; k < 9; k++){
            if(griddy[h][w] == letters[k]) {
              output+=to_string(k)+" ";
            }
          }
        }
      }
      output += "\n";
    }

    //displays the actual output
    cout << "\n"<<output<<"\n";
    //exits the loop if all the nonmine squares are cleared
    if(!gamecontinue) break;

    //asks for flag input if they agree to turnon flags
    if(flags) {
      cin >> flaggy;
    }

    //askes them for their choices and subtracts one immediately
    cin >> x;
    cin >> y;
    x--;
    y--;
	
    //alters friddy if flags are enabled
    if(flaggy == 0){
			for(int k = 0; k < 9; k++){
        if(griddy[y][x] == '0'+k || griddy[y][x] == 'X'){
          friddy[y][x]=!friddy[y][x];
					break;
        }
      }
    }else{
			if(!friddy[y][x]){
				
	      //if they picked a mine they take an L and lose 
	      if(griddy[y][x]=='X'){win=false;}
	
	      //if they didnt pick a mine then it clears it
	      for(int k = 0; k < 9; k++){
	        if(griddy[y][x] == '0'+k){
	          griddy[y][x] = letters[k];
	        }
	      }

				//if they pick a cleared mine it checks the flags around it
				// and does the middle click thing
				if(flags){
					middle = 0;
					for(int k = 1; k < 9; k++){
		        if(griddy[y][x] == letters[k]) {
		          for(int r= -1;r<=1;r++) {
			          for(int c= -1;c<=1;c++) {
			            if(y+r!=-1 && x+c!=-1 && y+r!=height && x+c!=width){
			              if(friddy[y+r][x+c]){
			                middle++;
			              }
			            }
			          }  
			        }
							if(k==middle){
								for(int r= -1;r<=1;r++) {
			          	for(int c= -1;c<=1;c++) {
										if(y+r!=-1 && x+c!=-1 && y+r!=height && x+c!=width){
											if(!friddy[y+r][x+c]){
												//if they picked a mine they take an L and lose 
									      if(griddy[y][x]=='X'){win=false;}
									      //if they didnt pick a mine then it clears it
									      for(int k = 0; k < 9; k++){
									        if(griddy[y+r][x+c] == '0'+k){
									          griddy[y+r][x+c] = letters[k];
									        }
									      }
				              }
										}
									}
								}
							}
		        }
		      }
				}
			}
    }
  }

  //win and lose conditions, and asks if they want to replay
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
