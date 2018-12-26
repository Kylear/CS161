/*
 * Program: bowl.cpp
 * Author: Aren Kyle
 * Date: 3/5/2017
 * Description: Bowling game
 * Input: Player numbers, name, bowl
 * Output: Winner of bowling gamae
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/*
 * Function: pinko
 * Description: Generates bowl
 * Parameters: Pin declared, result declared
 * Pre-Condition: Program called
 * Post-Condition: Random value
 */

void pinko(int &pin, int &result){
   srand(time(NULL));
   result = rand () % pin;
   pin = pin - result;
}

/*
 * Function: names
 * Description: Gets user names
 * Parameters: Name array declared, player number received
 * Pre-Condition: Program called
 * Post-Condition: Names saved in array
 */

void names(char name[][20], int &play, int len[5]){
   for(int x = 0; x < play; x++){
      cout << "Player number: " << x+1 << ", please enter your name. No more then 20 characters please\n";
      cin.clear();
      cin.getline(name[x], 21);
      len[x] = 20-strlen(name[x]);
   }
}

/*
 * Function: fboard
 * Description: Creates the frame portion of the scoreboard
 * Parameters: Number of players
 * Pre-Condition: User bowls
 * Post-Condtion: Portion of board printed
 */

void fboard(int &play){
   cout << "Name:";
   for(int x = 0; x < 15; x++)
      cout << ' ';
   cout << " | F1, F1| F2, F2| F3, F3| F4, F4| F5, F5| F6, F6| F7, F7| F8, F8| F9, F9| F10, F10| Total:" << endl; 
}

/*
 * Function: board
 * Description: Creates scoreboard
 * Parameters: Name array, score array, pt array, player count
 * Pre-Condition: Parameters declared
 * Post-Condition: Scoreboard printed to screen
 */

void board(char name[][20], int score[5][20], int pt[5], int &play, int len[5]){
   fboard(play);
   for(int x = 0; x < play; x++){
      cout << name[x];
      for(int i = 0; i < len[x]; i++){
      cout << ' ';
      }
      for(int y = 0; y < 20; y++){
	 cout << " | ";
	if(score[x][y] == 'X')
	  cout << 'X';
	else if(score[x][y] == '/')
	   cout << "/";
	else
      	   cout << score[x][y];
      }
      cout << " | Total: " << pt[x];
      cout << "\n";
   }
}

/*
 * Function: b1
 * Description: Runs first bowl in frame
 * Parameters: name array, pin, result, x, y, score array
 * Pre-Condition: Program called
 * Post-Condition: Value after first bowl
 */

void b1(char name[][20], int &pin, int &result, int &x, int &y, int score[5][20]){
   cout << name[x] << ": Press enter to continue\n";
   cin.get();
   pinko(pin, result);
   if(result == 0){
      cout << "You missed all of the pins!\n";
      score[x][y] = 0;
   }
   else if(result == 10){
      cout << "Nice, you got a strike!\n";
      score[x][y] = 'X';
   }
   else{
      cout << "You knocked down " << result << " pins!\n";
      score[x][y] = result;
   }
} 

/*
 * Function: b2
 * Description: Runs second bowl in frame
 * Parameters: name array, pin, result, x, y, score array
 * Pre-Condition: Player did not score a strike
 * Post-Condition: Value after second bowl
 */

void b2(char name[][20], int &pin, int &result, int &x, int &y, int score[5][20]){
   int temp;
   cout << name[x] << ": It is now your second bowl. Press enter to continue\n";
   cin.get();
   pinko(pin, result);
   if(result == 0){
      cout << "You missed all of the pins! You have knocked down " << result << " pins this bowl\n";
      score[x][y] = 0;
   }
   else if((result + score[x][y-1]) == 10){
      cout << "Nice, you got a spare!\n";
      score[x][y] = '/';
   }
   else{
      cout << "You knocked down " << result << " pins this bowl\n"; 
      score[x][y] = result;
   }
}

/*
 * Function: Total
 * Description: Updates player totals
 * Parameters: pt, x, result
 * Pre-Condition: pt array declared, x declared, result declared
 * Post-Condition: Updated player values
 */

void total(int pt[5], int &x, int &result){
   switch (x){
      case 1:
	 pt[1] += result;
	 break;
      case 2:
	 pt[2] += result;
	 break;
      case 3:
	 pt[3] += result;
	 break;
      case 4:
	 pt[4] += result;
	 break;
      default:
	 pt[0] += result;
   }
}

/*
 * Function: change
 * Description: Changes spares and strikes to proper values
 * Parameters: Score array
 * Pre-Condition: User received a spare or strike
 * Post-Condition: Proper score is displayed
 */

void change(int score[5][20], int pt[5]){
   for(int x = 0; x < 5; x++){
      for(int y = 0; y < 20; y++){
	 if(score[x][y] == 'X'){
	    score[x][y] = 10;
	    score[x][y] = 10 + score[x][y+2] + score[x][y+3];
	    if(score[x][y+3] == 0 || score[x][y+3] == '/')
	       score[x][y] = score[x][y+4] + 10 + score[x][y+2] - score[x][y+3];
	    pt[x] += score[x][y] - 10;
	 }
	 else if(score[x][y] == '/'){
	    score[x][y] = 10 - score[x][y-1] + score[x][y+1];
	    pt[x] += score[x][y+1];
	 }
      }
   }
}

/*
 * Function: frame
 * Description: Runs frame 1-9
 * Parameters: name array declared, pin declared, result declared, player number gathered, pt array declared, score array declared
 * Pre-Condition: Program called
 * Post-Condition: Scores for frame 1-9
 */

void frame(char name[][20], int &pin, int &result, int &play, int pt[5], int score[5][20], int len[5]){
   int f, x, y = 0;
   for(f = 1; f < 10; f++){
      cout << "It is frame " << f << endl;
      for(x = 0; x < play; x++){
	 b1(name, pin, result, x, y, score);
	 y += 1;
	 total(pt, x, result);
         board(name, score, pt, play, len);
	 if(result != 10){
	    b2(name, pin, result, x, y, score);
	    total(pt, x, result);
	    board(name, score, pt, play, len);
	 }
	 y -= 1;
	 pin = 11;
	 result = 0;
      }
      y += 2;
   }
}

/*
 * Function: players
 * Description: Receives player number
 * Parameters: Name array, player count declared
 * Pre-Condition: Program called
 * Post-Condition: Number of players stored
 */

void players(char name[][20], int &play, int len[5]){
   bool end = false;
   do{
      cout << "How many players are there? Maximum of 5, minimum of 1\n";
      cin >> play;
      cin.ignore();
      cin.clear();
      if(play == 1 || play == 5 || play == 2 || play == 3 || play == 4){
	 cout << "What are your names?\n";
	 names(name, play, len);
	 end = true;
      }
      else{
	 cout << "Not a valid input, please try again\n";
      }
   }while (end == false);
}

/*
 * Function: bowl1
 * Description: Runs bowl if user got strike
 * Parameters: pin, result, pt, x
 * Pre-Condition: Program called
 * Post-Condition: Score after strike
 */

void bowl1(int &pin, int &result, int pt[5], int &x, int score[5][20]){
   int n = 0;
   result = 0;
   pin = 11;
   cout << "You got a strike, so you bowl twice more. Press enter to bowl\n";
   cin.get();
   pinko(pin, result);
   cout << "You got " << result << ". Please bowl once more." << endl;
   n = result;
   cin.get();
   pinko(pin, result);
   result = n + result;
   cout << "You got " << result << " total" << endl;
   pt[x] += 10;
   score[x][18] = 10 + result;
}

/*
 * Function: bowl2
 * Description: Runs bowl if user got spare
 * Parameters: pin, result, pt, x
 * Pre-Condition: Program called
 * Post-Condition: Score after spare
 */

void bowl2(int &pin, int &result, int pt[5], int &x, int score[5][20]){
   cout << "You got a spare, so you bowl once more. Press enter to bowl\n";
   result = 0;
   pin = 11;
   cin.get();
   pinko(pin, result);
   cout << "You got " << result << endl;
   score[x][19] = result + 10 - score[x][18];
   pt[x] += score[x][19];
}

/*
 * Function: finish
 * Description: Runs last frame
 * Parameters: Name array decalred, pin declared, result declared, player number gathered, pt array declared, score array declared
 * Pre-Condition: Program called
 * Post-Condition: Final frame results
 */

void finish(char name[][20], int &pin, int &result, int &play, int pt[5], int score[5][20], int len[5]){
   int x, y = 18;
   for(x = 0; x < play; x++){
      b1(name, pin, result, x, y, score);
      if(score[x][y] == 'X'){
	 bowl1(pin, result, pt, x, score);
      }
      y += 1;
      total(pt, x, result);
      board(name, score, pt, play, len);
      if(result != 10){
	 b2(name, pin, result, x, y, score);
	 if(score[x][y] == '/'){
	    bowl2(pin, result, pt, x, score);
	 }
      }
      y -= 1;
      total(pt, x, result);
      board(name, score, pt, play, len);
      pin = 11;
      result = 0;
   }
}

/*
 * Function: winner
 * Description: Determines winner
 * Parameters: name array, pt array
 * Pre-Condition: All 10 frames completed
 * Post-Condition: Winner is determined
 */

void winner(char name[][20], int pt[5]){
   if(pt[0] > pt[1] && pt[0] > pt[2] && pt[0] > pt[3] && pt[0] > pt[4])
      cout << name[0] << " Wins!\n";
   if(pt[1] > pt[0] && pt[1] > pt[2] && pt[1] > pt[3] && pt[1] > pt[4])
      cout << name[1] << " Wins!\n";
   if(pt[2] > pt[1] && pt[2] > pt[0] && pt[2] > pt[3] && pt[2] > pt[4])
      cout << name[2] << " Wins!\n";
   if(pt[3] > pt[1] && pt[3] > pt[2] && pt[3] > pt[0] && pt[3] > pt[4])
      cout << name[3] << " Wins!\n";
   if(pt[4] > pt[1] && pt[4] > pt[2] && pt[4] > pt[3] && pt[4] > pt[0])
      cout << name[4] << " Wins!\n";
}

/*
 * Function: main
 * Description: Runs bowling game
 * Parameters:
 * Pre-Condition: Program called
 * Post-Condition: Winner of bowling game
 */

int main(){
   int len[5];
   int pin = 11, result, play;
   int pt[5] = {0};
   int score[5][20] = {0};
   char name[play][20];
   players(name, play, len);
   frame(name, pin, result, play, pt, score, len);
   cout << "It is the final frame\n";
   finish(name, pin, result, play, pt, score, len);
   change(score, pt);
   board(name, score, pt, play, len);
   winner(name, pt);
}
