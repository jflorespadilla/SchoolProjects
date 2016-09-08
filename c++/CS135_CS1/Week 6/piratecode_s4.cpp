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

/*
Name: errorMessageForWrongInput
Processing: displays an error message to the user of incorrect input
Input: none
Output/display: error message
Dependacies: Formatted command line
*/
void errorMessageForWrongInput();

/*
Name: errorMessageForTooMany
Processing: displays an error message to the user of too many inputs
Input: none
Output/display: error message
Dependacies: Formatted command line
*/
void errorMessageForTooMany();


//Main function

int main()
   {
    // Initinalize variables
    char letter, punctuation;
    int number;
    string pirateTalk, pirateTalk2, pirateTalk3, pirateTalk4, pirateTalk5;
    string pirateTalk6, pirateTalk7, pirateTalk8, pirateTalk9, pirateTalk10;
    string finalPhrase;

    // Display table
       // Function: displayTable
       displayTable();

    // Display instruction
       // Function: displayInstr
       displayInstr();

    // Get user input
       // get row
          // Operator >>
       // get col
          // Operator >>
       // get next
          // Operator >>
          cin >> letter >> number >> punctuation;
       
        
    // Test input
       // Function: isGoodInput
       isGoodInput( letter, number );

    // Translate
       // Function: translate
       pirateTalk = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 9 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )

    // Display result
       // Function: printString
       printString( finalPhrase, 0, "LEFT" );

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

void errorMessageForWrongInput()
   {
    //stub
   }

void errorMessageForTooMany()
   {
    // stub
   }
