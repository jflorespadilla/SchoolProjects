// Header files
#include <iostream>
#include <cmath>

using namespace std;

// Global constants

   // none

// Function prototypes

/*
name: displayTitle
process: display title with underline
input: none
output/displayed: title with underline
dependencies: iostream I/O tools
*/
void displayTitle();

/*
name: getCoefficent
input: user prompt (string)
output: requested coefficient (integer)
dependencies: none
process: output prompt, input value
*/
int getCoefficient( const string &prompt );

/*
name: calcDiscriminant
process: b^2 - 4*a*c calculated
input: all three coefficients (integer)
output: calculated discriminant (integer)
dependencies: none
*/
int calcDiscriminant( int c_a, int c_b, int c_c );

/*
name: calcDenom
process: 2 * a calculated
input: coeffient a (integer)
output: calculated denominator (integer)
dependencies: none
*/
int calcDenom( int c_a );

/*
name: calcRoot
process: ( -b + discriminant ) / denominator calculated
input: coefficient b, denominator, discriminant
output: calculated result
dependencies: none
*/
int calcRoot( int c_b, int den, int dsc );
   
/*
name: displayResult
process: display description string and result to console
input: display description (string), result (integer)
output/displayed: root description string with root value
dependencies: none
*/
void displayResult( const string &disp, int result );

// Main program
int main()
   {
    // initialize the program

       // initialize variables
       int coef_a, coef_b, coef_c;
       int disc, discRoot, denom;
       int result_one, result_two;

       // show title
          // function: displayTitle
       displayTitle();

    // get coefficients (3x, a, b, c )

       // get coefficient a
          // function: getCoefficient
       coef_a = getCoefficient( "Enter coefficient a: " );

       // get coefficient b
          // function: getCoefficient
       coef_b = getCoefficient( "Enter coefficient b: " );

       // get coefficient c
          // function: getCoefficient
       coef_c = getCoefficient( "Enter coefficient c: " );
    
    // process the roots

       // calculate the discriminant
          // function: calcDiscriminant
       disc = calcDiscriminant( coef_a, coef_b, coef_c );

       // test for discriminant greater than zero
       if( disc > 0 )
          {    
           // get the disc root
           discRoot = (int) sqrt( disc );
    
           // calculate the denominator
              // function: calcDenom
           denom = calcDenom( coef_a );
    
           // calculate the result (2x)

              // calc root one
                 // function: calcRoot
              result_one = calcRoot( coef_b, denom, discRoot );

              // calc root two
                 // function: calcRoot
              result_two = calcRoot( coef_b, denom, -discRoot );
    
           // output the results (2x)

              // create vertical spaces
                 // function: cout <<
              cout << endl << endl;

           // display root 1
              // function: displayResult
           displayResult( "Root 1: ", result_one );

           // display root 2
              // function: displayResult
           displayResult( "Root 2: ", result_two );
          }
       // test for discriminant equal to zero
       else if( disc == 0 )
          {
           // get the disc root
              // function: sqrt
           discRoot = (int) sqrt( disc );
    
           // calculate the denominator
              // function: calcDenom
           denom = calcDenom( coef_a );
    
           // calculate the result (1x)      
              // function: calcRoot
           result_one = calcRoot( coef_b, denom, discRoot );
    
           // output the results (1x)

              // create vertical spaces
                 // function: cout <<
              cout << endl << endl;

           // display root 1
              // function: displayResult
           displayResult( "Single Root: ", result_one );
          }
       // if other tests fail
       else
          {
           // display error message
              // function: cout <<
           cout << endl << endl;
           cout << "No real roots exist for these coefficients"
                << endl;
          }

    // end program

       // shift cursor down
          // function: cout <<
       cout << endl << endl;

       // hold program
          // function: system
       system( "PAUSE" );
    
       // return success
       return 0;       
   }

// Supporting functions

void displayTitle()
   {

   }

int getCoefficient( const string &prompt )
   {

    return 0; // temporary stub return
   }

int calcDiscriminant( int c_a, int c_b, int c_c )
   {

    return 0; // temporary stub return
   }                                             

int calcDenom( int c_a )
   {

    return 0; // temporary stub return
   }

int calcRoot( int c_b, int den, int dsc )
   {

    return 0; // temporary stub return
   }                
   
void displayResult( const string &disp, int result )
   {

   }


