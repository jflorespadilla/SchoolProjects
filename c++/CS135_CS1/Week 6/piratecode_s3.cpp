//Header files
# include "formatted_cmdline_io_v06.h"
# include <iostream>

using namespace std;

//Global constants

//Function Prototypes

/*
Name: displayTable
Processing: Displays the table showing the phrase options
Input: none
Output/display: Table
Dependacies: formatted command line
*/
void displayTable();

/*
Name: displayInstr
Processing: Displays the bottom instructions
Input: none
Output/display: Instructions
Dependacies: formatted command line
*/
void displayInstr();

/*
Name: isGoodInput
Processing: Checks for acceptable input
Input: A letter character from the row, and integer from the column
Output/return: Boolean value
Dependacies: iostream
*/
bool isGoodInput( char row , int col );

/*
Name: translate
Processing: Translates user input to pirate speech
Input: A letter character from the row, integer from the column, and 
       a '-' or ',' to indicate continuation or not
Output/return: String pirate phrase
Dependacies: Formatted command line
*/
string translate( char row, int col, char sign );

/*
Name: isCont
Processing: checks if the user wants to continue or stop the phrase
Input: Character
Output/return: A boolean value
Dependacies: iostream
*/
bool isCont( char sign );


//Main function

int main()
   {
    // Initinalize variables
    

    // Display table
       // Function: displayTable
       

    // Display instruction
       // Function: displayIntsr
       

    // Get user input
       // get row
          // Operator >>
       // get col
          // Operator >>
       // get next
          // Operator >>
       
        
    // Test input
       // Function: isGoodInput

    // Translate
       // Function: translate

    // Check for continue (from user input to here, repeat x10)
       // Function: isCont

    // Display result
       // Function: printString

     // Hold system for user
     system( "pause" );
     return 0;

   }

//Function Implementations
void displayTable()
   {
    // stub
   }

void displayInstr()
   {
    // stub
   }

bool isGoodInput( char row , int col )
   {
    return 0; // stub
   }

string translate( char row, int col, char sign )
   {
    return "z";// stub
   }

bool isCont( char sign )
   {
    return 0; // stub
   }
