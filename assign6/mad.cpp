/*
 * Program: mad.cpp
 * Author: Aren Kyle
 * Date: 3/19/2017
 * Description: Mad Libs game
 * Input: Story choice, word file
 * Output: Completed Mad Libs story
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>

using namespace std;

/*
 * Function: get_adjec
 * Description: Gets all adjectives and stores in array
 * Parameters: Entire word array, empty adjective array, number of words in the adjective array
 * Pre-Condition: User has chosen a word file
 * Post-Condition: Adjective array is filled and word count received
 */

void get_adjec(char words[][30], char adjec[][30], int &temp3){
   temp3 = 0;
   for(int i = 0; i < 75; i++){
      if(words[i][0] == 'a'){
	 for(int x = 0; x < 30; x++){
	    adjec[temp3][x] = words[i][x];
	 }
	 temp3 += 1;
      }
   }
}

/*
 * Function: get_verbs
 * Description: Gets all verbs and stores in array
 * Parameters: Entire word array, empty verbs array, number of words in the verbs array
 * Pre-Condition: User has chosen a word file
 * Post-Condition: Verbs array is filled and word count received
 */

void get_verbs(char words[][30], char verbs[][30], int &temp2){
   temp2 = 0;
   for(int i = 0; i < 75; i++){
      if(words[i][0] == 'v'){
	 for(int x = 0; x < 30; x++){
	    verbs[temp2][x] = words[i][x];
	 }
	 temp2 += 1;
      }
   }
}

/*
 * Function: get_nouns
 * Description: Gets all nouns and stores in array
 * Parameters: Entire word array, empty nouns array, number of words in the nouns array
 * Pre-Condition: User has chosen a word file
 * Post-Condition: Nouns array is filled and word count received
 */

void get_nouns(char words[][30], char nouns[][30], int &temp1){
   temp1 = 0;
   for(int i = 0; i < 75; i++){
      if(words[i][0] == 'n'){
	 for(int x = 0; x < 30; x++){
	    nouns[temp1][x] = words[i][x];
	 }
	 temp1 += 1;
      }
   }
}

/* 
 * Function: categorize
 * Description: Fills the words array, then the noun, verb, and adjective arrays
 * Parameters: Empty words array, empty nouns array, empty verbs array, empty adjective array, word counts for noun, verb, and adjective arrays
 * Pre-Condition: User has chosen a text file
 * Post-Condition: All arrays are filled
 */

void categorize(char words[][30], char nouns[][30], char verbs[][30], char adjec[][30], int &temp1, int &temp2, int &temp3){
   for(int i = 0; i < 75; i++)
      cin.getline(words[i], 30);
   get_nouns(words, nouns, temp1);
   get_verbs(words, verbs, temp2);
   get_adjec(words, adjec, temp3);
}

/* 
 * Function: bad_input
 * Description: Tells user how to use program
 * Parameters: none
 * Pre-Condition: User enters an invalid input
 * Post-Condition: none
 */

void bad_input(){
   cout << "That was an invalid input. Run as follows:\n";
   cout << "file_name story_number(1-3) < text_file\n";
}

/* 
 * Function: noun
 * Description: Outputs random word without printing type
 * Parameters: nouns array, number of words in array
 * Pre-Condition: Point in story needs a noun
 * Post-Condition: Noun is printed to screen
 */

char noun(char nouns[][30], int &temp1){
   int x = 0, y = 0;
   x = rand() % temp1;
   y = strlen(nouns[x]);
   char t[1][y];
   for(int i = 4; i < y; i++)
      t[1][i-4] = nouns[x][i+1];
   cout << t[1];
}

/* 
 * Function: noun_s
 * Description: Outputs rand noun that ends with an s without printing type
 * Parameters: Nouns array, number of words in array
 * Pre-Condition: Point in story needs a noun ending in s
 * Post-Condition: Noun ending in s printed to screen
 */

char noun_s(char nouns[][30], int &temp1){
   int x = 26, y = 0;
   do{
      x = rand() % temp1;
      y = strlen(nouns[x]);
   }while (nouns[x][y-1] != 's');
   char t[1][y];
   for(int i = 4; i < y; i++)
      t[1][i-4] = nouns[x][i+1];
   cout << t[1];
}

/* 
 * Function: verb_ing
 * Description: Outputs rand verb that ends with an ing without printing type
 * Parameters: Verbs array, number of words in array
 * Pre-Condition: Point in story needs a verb ending with ing
 * Post-Condition: Verb ending in ing printed to screen
 */

char verb_ing(char verbs[][30], int &temp2){
   int x = 26, y = 0;
   do{
      x = rand() % temp2;
      y = strlen(verbs[x]);
   }while (verbs[x][y-1] != 'g');
   char t[1][y];
   for(int i = 4; i < y; i++)
      t[1][i-4] = verbs[x][i+1];
   cout << t[1];
}

/* 
 * Function: adject
 * Description: Prints rand adjective to the screen
 * Parameters: Adjective array, number of words in array
 * Pre-Condition: Point in story needs an adjective
 * Post-Condition: Adjective is printed to screen
 */

char adject(char adjec[][30], int &temp3){
   int x = 0, y = 0;
   x = rand() % temp3;
   y = strlen(adjec[x]);
   char t[1][y];
   for(int i = 4; i < y; i++)
      t[1][i-4] = adjec[x][i+6];
   cout << t[1];
}

/* 
 * Function: verb
 * Description: Prints rand verb to the screen
 * Parameters: Verbs array, number of words in array
 * Pre-Condition: Point in story needs a verb
 * Post-Condition: Verb is printed to screen
 */

char verb(char verbs[][30], int &temp2){
   int x = 0, y = 0;
   x = rand() % temp2;
   y = strlen(verbs[x]);
   char t[1][y];
   for(int i = 4; i < y; i++)
      t[1][i-4] = verbs[x][i+1];
   cout << t[1];
}

/* 
 * Function: story1
 * Description: Prints the first of three stories
 * Parameters: nouns array, verbs array, adjective array, number of words in each array
 * Pre-Condition: User chose story 1
 * Post-Condition: First half of story 1 is output to screen
 */

void story1(char nouns[][30], char verbs[][30], char adjec[][30], int &temp1, int &temp2, int &temp3){
   cout << "Most doctors agree that bicycle ";
   verb_ing(verbs, temp2);
   cout << " is a/an ";
   adject(adjec, temp3);
   cout << " form of exercise. ";
   verb_ing(verbs, temp2);
   cout << " a bicycle enables you to develop your ";
   noun(nouns, temp1);
   cout << " muscles, as well as increase the rate of your ";
   noun(nouns, temp1);
   cout << " beat. ";
   cout << "More ";
   noun_s(nouns, temp1);
   cout << " around the world ";
   verb(verbs, temp2);
}

/* 
 * Function: story1_2
 * Description: Prints the first of three stories
 * Parameters: nouns array, verbs array, adjective array, number of words in each array
 * Pre-Condition: User chose story 1
 * Post-Condition: Second half of story 1 is output to screen
 */

void story1_2(char nouns[][30], char verbs[][30], char adjec[][30], int &temp1, int &temp2, int &temp3){
   cout << " bicycles than drive ";
   noun_s(nouns, temp1);
   cout << ". ";
   cout << "No matter what kind of ";
   noun(nouns, temp1);
   cout << " you ";
   verb(verbs, temp2);
   cout << ", always be sure to wear a/an ";
   adject(adjec, temp3);
   cout << " helmet. ";
   cout << "Make sure to have ";
   adject(adjec, temp3);
   cout << " reflectors too!\n";
}

/* 
 * Function: story2
 * Description: Prints the second of three stories
 * Parameters: nouns array, verbs array, adjective array, number of words in each array
 * Pre-Condition: User chose story 2
 * Post-Condition: First half of story 2 is output to screen
 */

void story2(char nouns[][30], char verbs[][30], char adjec[][30], int &temp1, int &temp2, int &temp3){
   cout << "Yesterday, ";
   noun(nouns, temp1);
   cout << " and I went to the park. On our way to the ";
   adject(adjec, temp3);
   cout << " park, we saw a ";
   adject(adjec, temp3);
   cout << " ";
   noun(nouns, temp1);
   cout << " on a bike. We also saw big ";
   adject(adjec, temp3);
   cout << " ballons tied to a ";
   noun(nouns, temp1);
   cout << ". Once we got to the ";
   adject(adjec, temp3);
   cout << " park, the sky turned ";
}

/* 
 * Function: story2_2
 * Description: Prints the second of three stories
 * Parameters: nouns array, verbs array, adjective array, number of words in each array
 * Pre-Condition: User chose story 2
 * Post-Condition: Second half of story 2 is output to screen
 */

void story2_2(char nouns[][30], char verbs[][30], char adjec[][30], int &temp1, int &temp2, int &temp3){
   adject(adjec, temp3);
   cout << ". It started to ";
   verb(verbs, temp2);
   cout << " and ";
   verb(verbs, temp2);
   cout << ". ";
   noun(nouns, temp1);
   cout << " and I ";
   verb(verbs, temp2);
   cout << " all the way home. Tomorrow we will try to go to the ";
   adject(adjec, temp3);
   cout << " park again and hope it doesn't ";
   verb(verbs, temp2);
   cout << ".\n";
}

/* 
 * Function: story3
 * Description: Prints the third of three stories
 * Parameters: nouns array, verbs array, adjective array, number of words in each array
 * Pre-Condition: User chose story 3
 * Post-Condition: First half of story 3 is output to screen
 */

void story3(char nouns[][30], char verbs[][30], char adjec[][30], int &temp1, int &temp2, int &temp3){
   cout << "Spring break 2017, oh how I have been waiting for you! Spring break is when you go to some ";
   adject(adjec, temp3);
   cout << " place to spend time with ";
   noun(nouns, temp1);
   cout << ". Getting to ";
   noun(nouns, temp1);
   cout << " is going to take ";
   adject(adjec, temp3);
   cout << " hours. My favorite part of spring break is ";
   verb_ing(verbs, temp2);
   cout << " in the ";
   noun(nouns, temp1);
   cout << ". During spring break, ";
   noun(nouns, temp1);
   cout << " and I plan to ";
}

/* 
 * Function: story3_2
 * Description: Prints the third of three stories
 * Parameters: nouns array, verbs array, adjective array, number of words in each array
 * Pre-Condition: User chose story 3
 * Post-Condition: Second half of story 3 is output to screen
 */

void story3_2(char nouns[][30], char verbs[][30], int &temp1, int &temp2){
   verb(verbs, temp2);
   cout << " all the way to ";
   noun(nouns, temp1);
   cout << ". After spring break, I will be ready to return to ";
   noun(nouns, temp1);
   cout << " and ";
   verb(verbs, temp2);
   cout << " hard to finish ";
   noun(nouns, temp1);
   cout << ". Thanks spring break 2017!\n";
}

/* 
 * Function: main 
 * Description: Runs all functions to print chosen story
 * Parameters: Choice of story, word file
 * Pre-Condition: User choses a text file and story
 * Post-Condition: Story is printed
 */

int main(int argc, char *argv[]){
   srand(time(NULL));
   char words[75][30]; //takes all words from the file
   char nouns[26][30]; //stores all nouns from words array
   char verbs[26][30]; //stores all verbs from words array
   char adjec[26][30]; //stores all adjectives from words array
   int temp1, temp2, temp3; //stores number of words in arrays
   if(argc != 2){
      bad_input();
   }
   else if(argv[1][0] != '1' && argv[1][0] != '2' && argv[1][0] != '3'){
      bad_input();
   }
   else{
      categorize(words, nouns, verbs, adjec, temp1, temp2, temp3);
      if(argv[1][0] == '1'){
	 story1(nouns, verbs, adjec, temp1, temp2, temp3);
	 story1_2(nouns, verbs, adjec, temp1, temp2, temp3);
      }
      else if(argv[1][0] == '2'){
	 story2(nouns, verbs, adjec, temp1, temp2, temp3);
	 story2_2(nouns, verbs, adjec, temp1, temp2, temp3);
      }
      else if(argv[1][0] == '3'){
	 story3(nouns, verbs, adjec, temp1, temp2, temp3);
	 story3_2(nouns, verbs, temp1, temp2);
      }
   }
}
