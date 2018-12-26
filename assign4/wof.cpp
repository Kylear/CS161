/*
 * Program: wof.cpp
 * Author: Aren Kyle
 * Date: 2/24/2017
 * Description: Game of Wheel of Fortune
 * Input: User chosen values on words, rounds, players, and guesses
 * Output: Winner of Wheel of Fortune. Winner determined by guesses
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void get_string(string &);
void set_replace_string(string &, string);
int get_search_replace(string &, string &, char &);
void start(int &, int &);
int spin(int &);
void menu(string &, string &, char &, int &, int &, bool &, bool &, int &, int &, int &);
void win(int &, int &, int &);
void letter(char &);
void menuwheel(int, int &, string, string &, char &, bool &);
int finish(string, bool &, bool &, int &, int &, int &, int &);
void moneyup(string, char &, int, int &, bool &);
void total(int &, string &, string &, char &, int &, int &, int &, int &, int &, int &, int &, bool &, bool &);
void turn(int &p, string &word, string &hide, char &vowel, int &t1, int &t2, int &t3, int &rt1, int &rt2, int &rt3, int &wheel, bool &ro, bool &to);

/*
 * Function: main
 * Description: Runs Wheel of Fortune
 * Parameters:
 * Pre-condition: Program called
 * Post-condition: Winner of wheel of fortune
 */

int main(){
   int wheel, r, p, correct, x = 1, rt1 = 0, rt2 = 0, rt3 = 0, t1 = 0, t2 = 0, go = 0, t3 = 0;
   string word, hide;
   char vowel;
   bool ro = false, to = false;
   start(p, r);
   while(x <= r){
      get_string(word);
      set_replace_string(hide, word);
      do{
	 total(p, word, hide, vowel, t1, t2, t3, rt1, rt2, rt3, wheel, ro, to);
      }while (to == 0);
      x++;
   }
   win(t1, t2, t3);
   return 0;
}

/*
 * Function: turn
 * Description: Same as turn, used to shorten function
 * Parameters: Number of players, initial word, hidden word, guessed letter, players 1 total money, player 2s total money, player 3s total money, player 1 round money, player 2s round money, players 3s round money, random value, round over or not, turn over or not
 * Pre-condition: More then one player
 * Post-condition: Initiates the next players turn
 */

void turn(int &p, string &word, string &hide, char &vowel, int &t1, int &t2, int &t3, int &rt1, int &rt2, int &rt3, int &wheel, bool &ro, bool &to){
   do{
      menu(word, hide, vowel, t1, wheel, ro, to, rt1, rt2, rt3);
      if((to == false)){
	 cout << "It is the second players turn.\n";
	 menu(word, hide, vowel, t2, wheel, ro, to, rt1, rt2, rt3);
      }
   }while(to == false);
}

/*
 * Function: total
 * Description: Switches between players
 * Parameters: Number of players, initial word, hidden word, guessed letter, players 1 total money, player 2s total money, player 3s total money, player 1 round money, player 2s round money, players 3s round money, random value, round over or not, turn over or not
 * Pre-condition: Used in main
 * Post-condition: Initiates the next players turn
 */

void total(int &p, string &word, string &hide, char &l, int &t1, int &t2, int &t3, int &rt1, int &rt2, int &rt3, int &wheel, bool &ro, bool &to){
   if(p == 1)
      menu(word, hide, l, t1, wheel, ro, to, rt1, rt2, rt3);
   else if(p == 2){
      turn(p, word, hide, l, t1, t2, t3, rt1, rt2, rt3, wheel, ro, to);
   }
   else if(p == 3){
      do{
	 menu(word, hide, l, t1, wheel, ro, to, rt1, rt2, rt3);
	 if((to == false)){
	    cout << "It is the second players turn\n";
	    menu(word, hide, l, t2, wheel, ro, to, rt1, rt2, rt3);
	 }
	 if((to == false)){
	    cout << "It is the third players turn\n";
	    menu(word, hide, l, t3, wheel, ro, to, rt1, rt2, rt3);
	 }
      }while(to == false);
   }
}

/*
 * Function: win
 * Description: Determines who wins the Wheel of Fortune
 * Parameters: Players 1s total money, player 2s total money, player 3s total money
 * Pre-condition: All rounds have been completed
 * Post-condition: Winner is chosen
 */

void win(int &t1, int &t2, int &t3){
   if((t1 > t2) && (t1 > t3)){
      cout << "The first player wins with $" << t1 << endl;
   }
   else if((t2 > t1) && (t2 > t3)){
      cout << "The second player wins with $" << t2 << endl;
   }
   else if((t3 > t1) && (t3 > t2)){
      cout << "The third player wins with $" << t3 << endl;
   }
}

/*
 * Function: vowel
 * Description: Lets the user guess a vowel in the word
 * Parameters: Players overall money, initial word, hidden word, guess letter
 * Pre-condition: User choses to guess a vowel
 * Post-condition: Player either guesses a vowel or they can't buy one
 */

void vowel(int &pt, string word, string &hide, char &l){
   if(pt >= 10){
      pt = pt - 10;
      get_search_replace(hide, word, l);
   }
   else
      cout << "Not enough cash yet to buy a vowel\n";
}

/*
 * Function: moneyup
 * Description: Updates the users money
 * Parameters: Initial word, guessed letter, random value, round over or not, players overall money
 * Pre-condition: User chose to spin wheel
 * Post-condition: Players money is updated. Turn ends if false
 */

void moneyup(string word, char &l, int wheel, bool &ro, int &pt){
   int x, correct = 0;
   for(x = 0; x < word.length(); x++){
      if(word.at(x) == l)
	 correct += 1;
   }
   pt += (wheel * correct);
   cout << "Of your guess, you found " << correct << ".\n";
   cout << "You now have $" << pt << endl;
   if(correct == 0){
      cout << "That letter is not in the hidden message\n";
      ro = true;
   }
}

/*
 * Function: finish
 * Description: Lets the user guess the hidden word. Updates value accordingly
 * Parameters: Initial word, round over or not, turn over or not, players overall money, players turn 1 money, players turn 2 money, players turn 3 money
 * Pre-condition: Chosen from menu
 * Post-condition: User gets correct and turn ends, or they are wrong and it is the next players turn
 */

int finish(string word, bool &ro, bool &to, int &pt, int &rt1, int &rt2, int &rt3){
   string atempt;
   cout << "What do you think the hidden message is?\n";
   getline(cin, atempt);
   cin.ignore(256, '\n');
   if(atempt == word){
      cout << "Good job, you've correctly guess the hidden message. Enjoy the reward\n";
      to = true;
      pt = rt1 + rt2 + rt3;
      (rt1, rt2, rt3) = 0;
   }
   else{
      cout << "That is not the hidden message. It is now the next players turn\n";
   }
   ro = true;
}

/*
 * Function: menu
 * Description: Lets user decide what they want to do
 * Parameters: Initial word, hidden word, guessed letter, players overall money, random value, round over or not, turn over or not, player 1s turn money, player 2s turn money, player 3s turn money
 * Pre-condition: Used in main
 * Post-condition: User decides where to go from here
 */

void menu(string &word, string &hide, char &l, int &pt, int &wheel, bool &ro, bool &to, int &rt1, int &rt2, int &rt3){
   int a;
   to = false;
   do{
      cout << "Will you spin the Wheel of Fortune(1), try to solve(2), or buy a vowel($10 required, enter 3)\n";
      cin >> a;
      cin.ignore(256, '\n');
      if(a == 1){
	 spin(wheel);
	 menuwheel(wheel, pt, word, hide, l, ro);
      }
      else if(a == 2){
	 finish(word, ro, to, pt, rt1, rt2, rt3);
      }
      else if(a == 3){
	 vowel(pt, word, hide, l);
      }
   }while (ro == false);
}

/*
 * Function: menuwheel
 * Description: Resulting effects of spinning the wheel
 * Parameters: Random value, players overall money, initial word, hidden word, guessed letter, and round over or not
 * Pre-condition: User spins wheel in menu
 * Post-condition: Users turn ends/updated money saved
 */

void menuwheel(int wheel, int &pt, string word, string &hide, char &l, bool &ro){
   if(wheel == 0){
      cout << "The wheel landed on " << wheel << endl;
      cout << "You are now bankrupt. It is the next players turn.\n";
      pt = 0;
      ro = true;
   }
   else if(wheel == 21){
      cout << "The wheel landed on " << wheel << endl;
      cout << "Though you keep your money, it is the next players turn\n";
      ro = true;
   }
   else{
      cout << "The wheel landed on " << wheel << endl;
      get_search_replace(hide, word, l);
      moneyup(word, l, wheel, ro, pt);
   }
}

/*
 * Function: spin
 * Description: Generates a random number
 * Parameters: Wheel was declared in main
 * Pre-condition: Function was used in main
 * Post-condition: Random number is saved
 */

int spin(int &wheel){
   srand(time(NULL));
   wheel = rand() % 22;
   return wheel;
}

/*
 * Function: start
 * Description: Takes initial user information
 * Parameters: Player input, round input
 * Pre-condition: Used in main
 * Post-condition: Saves number of players and rounds
 */

void start(int &p, int &r){
   cout << "How many players are there?\n";
   cin >> p;
   cout << "How many rounds will you be playing?\n";
   cin >> r;
   cin.ignore(256, '\n');
}

/*
 * Function: get_string
 * Description: Takes a user chosen word
 * Parameters: Word input was declared
 * Pre-condition: Used in main
 * Post-condition: Saves users input
 */

void get_string(string &word){
   cout << "Enter the hidden word\n";
   cin.clear();
   cin.ignore(256, '\n');
   getline(cin, word);
   cin.clear();
   cin.ignore(256, '\n');
   cout << string(75, '\n');
}

/*
 * Function: set_replace_string
 * Description: Replaces the entered word with a hidden one
 * Parameters: Hidden message declared, input word
 * Pre-condition: User has chosen a word
 * Post-condition: The input word will be hidden
 */

void set_replace_string(string &hide, string word){
   int x;
   hide.clear();
   for(x = 0; x < word.length(); x++){
      if(word.at(x) == ' '){
	 hide += ' ';
      }
      else
	 hide += '_';
   }
   cout << "The hidden message is: " << hide << endl;
}

/*
 * Function: get_search_replace
 * Description: Takes in a letter, then changes the hidden word to accomodate based on input
 * Parameters: Initial word, hidden word, chosen letter guess
 * Pre-condition: Hidden word was already changed
 * Post-condition: Updated new hidden word
 */

int get_search_replace(string &hide, string &word, char &l){
   int x;
   char b;
   cout << "Guess a letter\n";
   cin >> l;
   cin.clear();
   cin.ignore(256, '\n');
   b = toupper(l);
   for(x = 0; x < word.length(); x++){
      if(word.at(x) == l || word.at(x) == b){
	 hide.at(x) = word.at(x);
      }
   }
   cout << "Based on your guess, the updated message is: " << hide << endl;
}
