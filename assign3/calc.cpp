/*:
 *Program: calc.cpp
 *Author: Aren Kyle
 *Date: 2/4/2017
 *Description: Calculates a grade for CS 161 based on user input
 *Input: Values/scores from user for various categories
 *Output: Average grade for each cateogry as well as overall for the class
 */

#include <iostream>

using namespace std;

/*
 * Function: lat (lab, assignment, test)
 * Description: Calculates average for labs, assignments, and tests
 * Pre-condition: User must have selected this subcategory
 * Post-condition:
 * Return: Average for chosen subcategory
 */

double lat(double x, double y){
   double a, b, d, e, f, z;
   d = 0;
   int end1 = true;
   do { 
      if(y == 2){
	 cout << "How many points are they worth?\n";
	 cin >> z;
	 for(a = 1; a <= x; a+=1){
	    cout << "Score for number " << a << "?\n";
	    cin >> b;
	    d += b;
	 }
	 d = ((d / z) / x) * 100; 
	 return d;
	 end1 = false;
      }

      else if(y == 1){
	 for(a = 1; a <= x; a+=1){
	    cout << "Score for number " << a << " out of how many points?\n";
	    cin >> b;
	    cin >> e;
	    d += b;
	    f += e;
	 }
	 d = ((d / f) / x) * 100;
	 return d;
	 end1 = false;
      }
   }while (end1 == true);
}

/*
 * Function: total
 * Description: Calculates overall average for the class
 * Pre-condition: User must have selected this subcategory
 * Post-condition:
 * Return: Average grade for entire class based on input
 */


double total(double x, double y, double z, double w){ 
   double l, a1, t1, r, t, oavg;
   cout << "You've chosen to calculate your class average grade\n";
   cout << "What is the weight for each category? (Enter as a %. For instance, 15% would be '15')\n";
   cout << "Labs\n";
   cin >> l;
   cout << "Assignments\n";
   cin >> a1;
   cout << "Tests\n";
   cin >> t1;
   cout << "Recitation\n";
   cin >> r;
   x = x * (l / 100.0);
   y = y * (a1 / 100.0);
   z = z * (t1 / 100.0);
   w = w * (r / 100.0);
   oavg = x + y + z + w;
   return oavg;
}

/*
 * Function: hi 
 * Description: Determines how many categories there are within each sub
 * Pre-condition: User must have selected this subcategory
 * Post-condition:
 * Return: How many categories there are
 */


int hi(int choice){ 
   int x;
   if (choice == 1){
      cout << "You've chosen to calculate your average for: Labs\n";
      cout << "Please enter the number of labs you have had.\n";
      cin >> x;
      return x;
   }

   else if(choice == 2){
      cout << "You've chosen to calculate your average for: Assignments\n";
      cout << "Please enter the number of assignments you have had.\n";
      cin >> x;
      return x;
   }

   else
      cout << "You've chosen to calculate your average for: Tests\n";
   cout << "Please enter the number of tests you have had.\n";
   cin >> x;
   return x;
}

/*
 * Function: hi2
 * Description: Determines if user needs to input individual values for each category
 * Pre-condition: User must have selected this subcategory
 * Post-condition:
 * Return: If individual values must be entered
 */


int hi2(int choice){ 
   int y;
   cout << "Do the values vary? Yes(1) or No(2)\n";
   cin >> y;
   return y;
}

/*
 * Function: rec1
 * Description: Calculates average for quizzes within the recitation category
 * Pre-condition: User must have selected this subcategory
 * Post-condition:
 * Return: Average for quizzes
 */

double rec1(double r1){
   double x, y, z, a, f, b, e;
   int end1 = true;
   if(r1 > 0){
      cout << "Please enter the number of quizzes you had\n";
      cin >> x;
      cout << "Do the values vary? Yes(1) or No(2)?\n";
      cin >> y;

      do { 
	 if(y == 2){
	    cout << "How many points are they worth?\n";
	    cin >> z;
	    r1 = 0;
	    for(a = 1; a <= x; a+=1){
	       cout << "Score for number " << a << "?\n";
	       cin >> b;
	       r1 += b;
	    }
	    r1 = ((r1 / z) / x) * 100; 
	    return r1;
	    end1 = false;
	 }

	 else if(y == 1){
	    for(a = 1; a <= x; a+=1){
	       cout << "Score for number " << a << " out of how many points?\n";
	       cin >> b;
	       cin >> e;
	       r1 += b;
	       f += e;
	    }
	    r1 = ((r1 / f) / x) * 100;
	    return r1;
	    end1 = false;
	 }
      }while (end1 == true);	
   }

   else
      r1 = 0;
   return r1;
}

/*
 * Function: rec2
 * Description: Calculates average for designs within the recitation category
 * Pre-condition: User must have selected this subcategory
 * Post-condition:
 * Return: Average for designs
 */


double rec2(double r2){
   double x, y, z, a, f, b, e;
   int end1 = true;
   if(r2 > 0){
      cout << "Please enter the number of designs you had\n";
      cin >> x;
      cout << "Do the values vary? Yes(1) or No(2)?\n";
      cin >> y;

      do { 
	 if(y == 2){
	    cout << "How many points are they worth?\n";
	    cin >> z;
	    r2 = 0;
	    for(a = 1; a <= x; a+=1){
	       cout << "Score for number " << a << "?\n";
	       cin >> b;
	       r2 += b;
	    }
	    r2 = ((r2 / z) / x) * 100; 
	    return r2;
	    end1 = false;
	 }

	 else if(y == 1){
	    for(a = 1; a <= x; a+=1){
	       cout << "Score for number " << a << " out of how many points?\n";
	       cin >> b;
	       cin >> e;
	       r2 += b;
	       f += e;
	    }
	    r2 = ((r2 / f) / x) * 100;
	    return r2;
	    end1 = false;
	 }
      }while (end1 == true);	
   }

   else
      r2 = 0;
   return r2;
}

/*
 * Function: rec2
 * Description: Calculates average for critiques within the recitation category
 * Pre-condition: User must have selected this subcategory
 * Post-condition:
 * Return: Average for critiques
 */


double rec3(double r3){
   double x, y, z, a, f, b, e;
   int end1 = true;
   if(r3 > 0){
      cout << "Please enter the number of critiques you had\n";
      cin >> x;
      cout << "Do the values vary? Yes(1) or No(2)?\n";
      cin >> y;

      do { 
	 if(y == 2){
	    cout << "How many points are they worth?\n";
	    cin >> z;
	    r3 = 0;
	    for(a = 1; a <= x; a+=1){
	       cout << "Score for number " << a << "?\n";
	       cin >> b;
	       r3 += b;
	    }
	    r3 = ((r3 / z) / x) * 100; 
	    return r3;
	    end1 = false;
	 }

	 else if(y == 1){
	    for(a = 1; a <= x; a+=1){
	       cout << "Score for number " << a << " out of how many points?\n";
	       cin >> b;
	       cin >> e;
	       r3 += b;
	       f += e;
	    }
	    r3 = ((r3 / f) / x) * 100;
	    return r3;
	    end1 = false;
	 }
      }while (end1 == true);	
   }

   else
      r3 = 0;
   return r3;
}

int main(){
   int end, choice, x, y, r1, r2, r3;
   end = true;
   double avg1, avg2, avg3, avg4, oavg, a, b, c;
   (avg1, avg2, avg3, avg4, a, b, c) = 0;
   do{
      cout << "Welcome to a CS 161 grade calculator. Would you like to calculate your grade for:\n";
      cout << "Labs(1), assignments(2), tests(3), recitations(4), the class(5), or quit the program(6)?\n";
      cin >> choice;

      if(choice == 1){
	 x = hi(choice);
	 y = hi2(choice);
	 avg1 = lat(x, y);
	 cout << "Your average lab score is: " << avg1 << "%" << endl;
      }

      else if(choice == 2){
	 x = hi(choice);
	 y = hi2(choice);
	 avg2 = lat(x, y);
	 cout << "Your average assignment score is: " << avg2 << "%" << endl;
      }

      else if(choice == 3){
	 x = hi(choice);
	 y = hi2(choice);
	 avg3 = lat(x, y);
	 cout << "Your average test score is: " << avg3 << "%" << endl;
      }

      else if(choice == 4){
	 cout << "You've chosen to calculate your recitation grade.\n";
	 cout << "Please enter the weight for quizzes, designs, and critiques. Enter as a percentage\n";
	 cin >> r1;
	 cin >> r2;
	 cin >> r3;
	 a = (r1 / 100.0);
	 b = (r2 / 100.0);
	 c = (r3 / 100.0);
	 avg4 = (rec2(r2) * b) + (rec1(r1) * a) + (rec3(r3) * c);
	 cout << "Your recitation grade is " << avg4 << "%" << endl;	
      }

      else if(choice == 5){
	 oavg = total(avg1, avg2, avg3, avg4);
	 cout << "Your average grade for this class is " << oavg << "%" << endl;
	 end = false;
      }

      else if(choice == 6){
	 cout << "Exiting program\n";
	 end = false;
      }

   }while (end == true);
}
