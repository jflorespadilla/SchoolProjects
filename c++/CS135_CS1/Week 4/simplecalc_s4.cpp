//Header files
#include "formatted_console_io_v16.h"

using namespace std;

//Global constants

//Function Prototypes
   /*
   Name:helloGoodbye
   Processing: Display Welcome and good-bye screen
   inputs: none
   output/display: Welcome good-bye screen
   Dependencies: formatted console i/o
   */
   void helloGoodbye();

   /*
   Name: calcScreen
   Processing: Display the calculator screen
   inputs: none
   output/display: Calculator screen
   Dependencies: formatted console i/o
   */
   void calcScreen();

   /*
   Name: inputNumbers
   Processing: prompt user for integer input
   inputs: Integers
   output/return: none
   Dependencies: formatted console i/o
   */
   int inputNumbers( const string &prompt );

   /*
   Name: inputOperator
   Processing: prompt user for operator
   inputs: mathematical operations
   output/return: none
   Dependencies: formatted console i/o
   */
   char inputOperator( const string &prompt );

   /*
   Name: errorCheck
   Processing: Protects from over flow, checks for corret operator input,
               checks for proper integer input 
   inputs: none
   output/return: Error message
   Dependencies: formatted console i/o
   */
   void errorCheck();

   /*
   Name: calcAnswer
   Processing: Calculates the answers for user
   inputs: integers and operator from user
   output/return: integer
   Dependencies: formatted console i/o
   */
   int calcAnswer( int number1, char mathOperator, int number2 );

   /*
   Name: displayAnswer 
   Processing: Displays answer from calculation
   inputs: integer
   output/display: answer
   Dependencies: formatted console i/o
   */
   void displayAnswer( const string &disp, int result );

//Main function

int main()
   {
   // initinialize variables
   int input1;
   int input2;
   int result;
   char mathSymbol;
   
   
      //start curses
      startCurses();

   // Welcome Screen
     // Use Welcome and good-bye screen function
     // funtion: helloGoodbye
     helloGoodbye();

   // Create Calculator screen
     // Use Calculator screen function
     // function: calcScreen
     calcScreen();

   // Get user input and Calculate
     // Get user input 1
     // function: inputNumbers
     input1 = inputNumbers( "Enter Value 1 : ");

        // Check for input error
        // function: errorCheck
        errorCheck();

           // Display goodbye screen
           // function: helloGoodbye
           helloGoodbye();

     // Get user input 2
     // function: inputNumbers
     input2 = inputNumbers( "Enter Value 2 : ");

        // Check for input error
        // function: errorCheck
        errorCheck();

           // Display goodbye screen
           // function: helloGoodbye
           helloGoodbye();

     // Get operator
     // function: inputOperator
     mathSymbol = inputOperator( "Enter Operator : ");

       // Check for input error
       // function: errorCheck
       errorCheck();

           // Display goodbye screen
           // function: helloGoodbye
           helloGoodbye();

    // Calculate answer
    // function: calcAnswer
    result = calcAnswer( input1, mathSymbol, input2);

       // Check for error
       // function: errorCheck
       errorCheck();

           // Display goodbye screen
           // function: helloGoodbye
           helloGoodbye();

    // Display answer
    // function: displayAnswer
    displayAnswer( "result         :", result );

   // Good-bye screen
     // Use welcome and good-bye screen fucntion
     // function: helloGoodbye
     helloGoodbye();

   // hold system for user
   waitForInput( FIXED_WAIT );

     // end curses
     endCurses();

     return 0;

   }

//Function Implementations
void helloGoodbye()
   {
    // stub
   }

void calcScreen()
   {
    // stub
   }

int inputNumbers( const string &prompt )
   {
     return 0; // stub return
   }

char inputOperator( const string &prompt )
   {
   // stub
   }

void errorCheck()
   {
    // stub
   }

int calcAnswer( int number1, char mathOperator, int number2 )
   {
     return 0; // stub return
   }

void displayAnswer( const string &disp, int result )
   {
    // stub
   }
