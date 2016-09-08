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
   int inputNumbers();

   /*
   Name: inputOperator
   Processing: prompt user for operator
   inputs: mathematical operations
   output/return: none
   Dependencies: formatted console i/o
   */
   char inputOperator();

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
   int calcAnswer();

   /*
   Name: displayAnswer 
   Processing: Displays answer from calculation
   inputs: none
   output/display: integer answer
   Dependencies: formatted console i/o
   */
   void displayAnswer();

//Main function

int main()
   {
   // initinialize variables

   // Welcome Screen
     // Use Welcome and good-bye screen function
     // funtion: helloGoodbye

   // Create Calculator screen
     // Use Calculator screen function
     // function: calcScreen

   // Get user input and Calculate
     // Get user input 1
     // function: inputNumbers

        // Check for input error
        // function: errorCheck

           // Display goodbye screen
           // function: helloGoodbye

     // Get user input 2
     // function: inputNumbers

        // Check for input error
        // function: errorCheck

           // Display goodbye screen
           // function: helloGoodbye

     // Get operator
     // function: inputOperator

       // Check for input error
       // function: errorCheck

           // Display goodbye screen
           // function: helloGoodbye

    // Calculate answer
    // function: calcAnswer

       // Check for error
       // function: errorCheck

           // Display goodbye screen
           // function: helloGoodbye

    // Display answer
    // function: displayAnswer

   // Good-bye screen
     // Use welcome and good-bye screen fucntion
     // function: helloGoodbye

   // hold system for user

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

int inputNumbers()
   {
     return 0; // stub return
   }

char inputOperator()
   {
   // stub
   }

void errorCheck()
   {
    // stub
   }

int calcAnswer()
   {
     return 0; // stub return
   }

void displayAnswer()
   {
    // stub
   }
