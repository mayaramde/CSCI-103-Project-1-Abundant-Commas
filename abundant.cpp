/********************************************************
 * CS 103 PA 1: Abundant numbers
 * Name: Maya Ramde
 * USC email: ramde@usc.edu
 * Comments (you want us to know):
 *
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0. 
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /* Your code here */
    int num, sum;
    sum = 0;
    cin >> num;
    
    while (num != 0) { // Check if each inputted number is abundant until the user inputs 0.
        
        // Iterate from 1 to num-1 to count each of its divisors.
        for (int i = 1; i < num; i++) {
            if(num % i == 0) {
                // When a divisor is found, add it to the sum.
                sum += i; 
            }
        }
        
        // If the sum is greater than the inputted number, then the number is abundant
        if (sum > num) {
            
            // Increase the abundance count by 1
            num_abundant++;
            
            /* If the abundance of the number is within the top three most abundant numbers that have been inputted, add the number and its abundance to the rankings. */
            if (sum > a1) {
                // Hold all the current rankings in temporary variables and moved then one place down on the list
                int hold_a1 = a1;
                int hold_n1 = n1;
                int hold_a2 = a2;
                int hold_n2 = n2;
                a1 = sum;
                n1 = num;
                a2 = hold_a1;
                n2 = hold_n1;
                a3 = hold_a2;
                n3 = hold_n2;
            } else if (sum > a2) {
                int hold_a2 = a2;
                int hold_n2 = n2;
                a2 = sum;
                n2 = num;
                a3 = hold_a2;
                n3 = hold_n2;
            } else if (sum > a3) {
                a3 = sum;
                n3 = num;
            }
        }
        
        // Reset the sum to zero before reviewing the next inputted number, then take in the next input.
        sum = 0;
        cin >> num;
    }

    
    
  /* End of your code */

  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;


  return 0;

}
