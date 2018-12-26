/* 
 * Program: adventure.cpp
 * Author: Aren Kyle
 * Date: 1/21/2017
 * Description: Test-based adventure game 
 * Input: Decisions by the user as to what should be done next
 * Output: Future options determined by input from the user
 */

#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int main() {
	int a, x, y, z;
	srand(time(NULL));
	x = rand() % 2 + 1;
	y = rand() % 2 + 1;
	z = rand() % 2 + 1; 
	
	/*
 * 	Multiple variable ensure that each time a random number is used, each individual variable will be different
 */
	cout << "Welcome to a grand adventure! Your adventure takes place in a mythical world.\n";
	cout << "You are just returning from the next town over when...\n";
	cout << "Oh no, a dragon has scorched your village! Do you:\n";
	cout << "Hide with your family(1) or go to fight(2)?\n";
	cin >> a;
			
	if (a == 1){
		cout << "After some time, you determine that the dragon has left. Do you:\n";
		cout << "Remain in shelter for a little longer(1) or leave immediately(2)?\n";
		cin >> a;
			
		if (a == 1){
			cout << "You decide to wait a day before leaving.\n";
			cout << "As you are leaving the building collapses. You die.\n";
		return 0;
		}

		else if (a == 2){
			cout << "You take your family and leave the destruction behind. Do you:\n";
			cout << "Go north(1) or south(2)?\n";
			cin >> a;
		}	
	
			if (a == 1){
				cout << "After traveling some time you run into a polar bear. Do you:\n";
				cout << "Attempt to kill it for food(1) or let it pass(2)?\n";
				cin >> a;
				

				if (a == 1){
					cout << "You attempt to kill the polar bear.\n";
					cout << "The bear hits you with his paw. You die.\n";
				return 0;
				}
				
				else if (a == 2){
					a = (a + x);
				}

					if (a == 3){
						cout << "The bear catches your scent and attacks you.\n";
						cout << "You die.\n";
					return 0;
					}
						
					else if (a != 3){ 
						cout << "The bear passes. Will you:\n";
						cout << "Continue north(1) or a make camp(2)?\n";
						cin >> a;
					}

						if (a == 1){
							cout << "You continue north.\n";
							cout << "At night the temperature drops dramatically. You freeze to death.\n";
						return 0;
						}
							
						else if (a == 2){
							cout << "You make camp for the night.\n";
							a = (a + y);
							
							if (a == 3){
								cout << "You survived the night.\n";
								cout << "It is freezing outside.\n";
								cout << "You see a local tribe in the distance. Do you:\n";
								cout << "Befriend the tribe(1) or leave them be(2)?\n";
								cin >> a;
	
								if (a == 1){
									cout << "The tribe will accept you if you can best a fighter in combat.\n";
									cout << "Will you use your sword(1) or spear(2)?\n";
									cin >> a;
									
									if (a == 1){ 
										cout << "You best the fighter. They accept you.\n";
										cout << "You become chief and reign until death.\n";
									return 0;
									}
		
									else if (a == 2){
										cout << "The fighter beats you. You die.\n";
									return 0;
									}
								}

								else if (a == 2){
									cout << "You freeze without help. You die.\n";
								return 0;
								}
							}

							else if (a != 3){
								cout << "A wampa attacks you in your sleep. You die.\n";
							return 0;
							}
						}
			}

			else if (a == 2){
				cout << "The sweltering heat beats down on you. You think you see a lake to the east. Will you:\n";
				cout << "Continue south(1) or risk going east(2)?\n";
				cin >> a;
			}	

				if (a == 1){
					cout << "You run out of water in the middle of a desert. You die\n";
				return 0;
				}	
	
				else if (a == 2){
					a = (a + (z * 2)); /*Fixed issue with code not outputting properly*/
				}	

					if (a == 4){
						cout << "You don't make it to the lake in time. You die of dehydration.\n";
					return 0;
					}	

					else if (a == 3){
						cout << "You discovered an oasis! Will you:\n";
						cout << "Stay and build a new home(1) or continue venturing(2)?\n";
						cin >> a;
					}	

						if (a == 1){
							cout << "You buld a new home and live peacefully for the rest of your life.\n";
							cout << "Thank you for playing!\n";
						return 0;
						}	

						else if (a == 2){
							cout << "You find nothing for days after leaving the oasis.\n"; 
							cout << "You die of heat and dehydration.\n";
						return 0;
						}

	}
	else if (a == 2){
		cout << "You go to fight the dragon.\n";
		cout << "You are instantly burned to a crisp. You die\n";
	}
}
