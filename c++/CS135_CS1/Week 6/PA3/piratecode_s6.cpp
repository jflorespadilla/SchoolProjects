//Header files
# include "formatted_cmdline_io_v06.h"
# include <iostream>

using namespace std;

//Global constants
string HORIZONTAL_LINE = "----------------------------------------------------------------------------";
string DOT_LINE = "-----------------------------------------------------------------";
int TITLE_SPCE = 76;
int ALT_SPCE = 71;
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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 9 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 8 more times

       // Second set of possible inputs

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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk2 = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 8 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 7 more times
        
        // Third set possible input

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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk3 = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 7 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 6 more times

        // Fourth possible set of inputs

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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk4 = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 6 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 5 more times
       
       // Fifth set of possible input

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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk5 = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 5 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 4 more times

       // Sixth possible set of input

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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk6 = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 4 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 3 more times

        // Seventh possible set of input

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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk7 = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 2 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 2 more times

       // Eighth possible set of input

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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk8 = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 2 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 1 more times

       // Ninth possible set of input

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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk9 = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 1 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 1 more times

       // Tenth  possible set of input

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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk10 = translate( letter, number, punctuation );

    // Check for continue (Error for futher input )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repetion result in Funcntion: errorForTooMany
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
       // Operation: if
       if( !isGoodInput( letter, number ) ) 
          {
           finalPhrase = "";
           cout << endl;
           // function: errorMessageForWrongInput
           errorMessageForWrongInput();
           cout << endl;

           system( "pause" );
           return 0;
          }

       
    // Translate
       // Function: translate
       pirateTalk = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 9 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           finalPhrase = "";
           cout << endl;
           // Error message
           errorMessageForTooMany();
           cout << endl;

           system( "pause" );
           return 0;
          }

    else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = "";
           cout << endl;
           errorMessageForTooMany();
           cout << endl;

           system( "pause" );
           return 0;
          }

       // End of error message set
           
          }

     else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           finalPhrase += pirateTalk2;
           finalPhrase += pirateTalk3;
           finalPhrase += pirateTalk4;
           finalPhrase += pirateTalk5;
           finalPhrase += pirateTalk6;
           finalPhrase += pirateTalk7;
           finalPhrase += pirateTalk8;
           finalPhrase += pirateTalk9;
           finalPhrase += pirateTalk10;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }

       // End of tenth possible set of input
           
          }

      else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           finalPhrase += pirateTalk2;
           finalPhrase += pirateTalk3;
           finalPhrase += pirateTalk4;
           finalPhrase += pirateTalk5;
           finalPhrase += pirateTalk6;
           finalPhrase += pirateTalk7;
           finalPhrase += pirateTalk8;
           finalPhrase += pirateTalk9;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }

       // End of ninth possible set of input
           
          }

      else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           finalPhrase += pirateTalk2;
           finalPhrase += pirateTalk3;
           finalPhrase += pirateTalk4;
           finalPhrase += pirateTalk5;
           finalPhrase += pirateTalk6;
           finalPhrase += pirateTalk7;
           finalPhrase += pirateTalk8;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }

       // End of eighth possible set of input
           
          }

      else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           finalPhrase += pirateTalk2;
           finalPhrase += pirateTalk3;
           finalPhrase += pirateTalk4;
           finalPhrase += pirateTalk5;
           finalPhrase += pirateTalk6;
           finalPhrase += pirateTalk7;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }

       // End of seventh possible set of input
           
          }

     else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           finalPhrase += pirateTalk2;
           finalPhrase += pirateTalk3;
           finalPhrase += pirateTalk4;
           finalPhrase += pirateTalk5;
           finalPhrase += pirateTalk6;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }
           
        // End of sixt set of possible input

          }

      else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           finalPhrase += pirateTalk2;
           finalPhrase += pirateTalk3;
           finalPhrase += pirateTalk4;
           finalPhrase += pirateTalk5;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }

        // End of fifth set of possible input
           
          }

      else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           finalPhrase += pirateTalk2;
           finalPhrase += pirateTalk3;
           finalPhrase += pirateTalk4;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }

       // End of fourth set of possible input
           
          }

       else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           finalPhrase += pirateTalk2;
           finalPhrase += pirateTalk3;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }
          
        // End of third set of possible input

          }

       else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           finalPhrase += pirateTalk2;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }

       // End of second set of possible input

          }

       else if( !isCont( punctuation ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           // finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc)
           finalPhrase = pirateTalk;
           cout << endl;
           cout << DOT_LINE << endl;
           cout << "translation: ";
          }


    // Display result
       // Function: printString
       cout << finalPhrase;
       cout << endl << endl;

     // Hold sytem for user
     system( "pause" );
     return 0;

   }

//Function Implementations
void displayTable()
   {
    // Top line
       // Function: printString
       // Function: printchar
       printChar( '|' );
       printString( HORIZONTAL_LINE, 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);
       
    // Title
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( "PIRATE TRANSLATOR", TITLE_SPCE, "CENTER");
       printChar( '|' );
       printEndLines(1);
    // First row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( HORIZONTAL_LINE, 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // second row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
        printChar( '|' );
        printString( " A: | 1-Hello  2-Pardon me  3-Excuse me", 0, "LEFT" );
        printString( "                                     ", 0, "LEFT" );
        printChar( '|' );
        printEndLines(1);

    // Third row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Fourth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " B: | 1-Sir  2-Madam  3-Miss  4-Stranger  5-Officer", 0,
                                                                       "LEFT" );
       printString( "                         ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);
       
    // Fifth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Sixth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " C: | 1-Where is  2-Can you help me find  3-Is that  ", 0,
                                                                     "LEFT" );
       printString( "4-How far is it to     ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Seventh row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Eight row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " D: | 1-The  2-A  3-Any  4-Nearby 5-My  ", 0, "LEFT" );
       printString( "6-Your                              ", 0 , "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Ninth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Tenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " E: | 1-Old  2-Attractive  3-Happy", 0, "LEFT" );
       printString( "                                          ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Eleventh row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Twelveth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " F: | 1-Restroom  2-Restaurant  3-Hotel  ", 0, "LEFT" );
       printString( "4-Mall  5-Pub  6-Bank              ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Thirteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Fourtheenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( "    | 1-I would like to  2-I desire  ", 0, "LEFT" );
       printString( "3-I wish I knew how to                 ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Fifteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " G: |", 0, "LEFT" );
       printString( " ", ALT_SPCE, "CENTER");
       printChar( '|' );
       printEndLines(1);

    // Sixteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( "    | 4-My mother told me  ", 0, "LEFT" );
       printString( "5-My companion would like to", 0, "LEFT" );
       printString( "                     ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Seventeenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Eighteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " H: | 1-Find  2-Take a Nap  ", 0, "LEFT" );
       printString( "3-Make a withdrawal  4-Have a cocktail", 0, "LEFT" );
       printString( "          ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Ninteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);


    // Bottom row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( HORIZONTAL_LINE, 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

   }

void displayInstr()
   {
    // Function: printString
    // Function: pringEndLine
    printString( "Code is in the form \"A1, B3, C2-\", ", 0, "LEFT" );
    printString( "up to ten items, ending with a dash", 0, "LEFT" );
    printEndLines(1);
    printString( "Enter Code: ", 0, "LEFT" );

   }

bool isGoodInput( char row , int col )
   {
    // Operation: switch
    switch( row )
       {
        // Cases for A
        case 'a':
        case 'A':
         if( col == 1 )
            {
             return true;
            }
         else if(col == 2 )
            {
             return true;
            }
          else if( col == 3 )
            {
             return true;
            }
         break;

        // Cases B
        case 'b':
        case 'B':
         if( col == 1 )
            {
             return true;
            }
         else if( col == 2 )
            {
             return true;
            }
         else if( col == 3 )
            {
             return true;
            }
         else if( col ==  4 )
            {
             return true;
            }
         else if( col ==  5 )
            {
             return true;
            }
         break;

        // Cases for C
        case 'c':
        case 'C':
         if( col == 1 )
            {
             return true;
            }
         else if( col == 2 )
            {
             return true;
            }
         else if( col == 3 )
            {
             return true;
            }
         else if( col == 4 )
            {
             return true;
            }

         break;

        // Cases for D
        case 'd':
        case 'D':
         if( col == 1 )
            {
             return true;
            }
         else if( col == 2 )
            {
             return true;
            }
         else if( col == 3 )
            {
             return true;
            }
         else if( col == 4 )
            {
             return true;
            }
         else if( col == 5 )
            {
             return true;
            }
         else if( col == 6 )
            {
             return true;
            }

         break;

        // Cases for E
        case 'e':
        case 'E':
         if( col == 1 )
            {
             return true;
            }
         else if( col == 2 )
            {
             return true;
            }
         else if( col == 3 )
            {
             return true;
            }

         break;

        // Cases for F
        case 'f':
        case 'F':
         if( col == 1 )
            {
             return true;
            }
         else if( col == 2 )
            {
             return true;
            }
         else if( col == 3 )
            {
             return true;
            }
         else if( col == 4 )
            {
             return true;
            }
         else if( col == 5 )
            {
             return true;
            }
         else if( col == 6 )
            {
             return true;
            }

         break;

        // Cases for G
        case 'g':
        case 'G':
         if( col == 1 )
            {
             return true;
            }
         else if( col == 2 )
            {
             return true;
            }
         else if( col == 3 )
            {
             return true;
            }
         else if( col == 4 )
            {
             return true;
            }
         else if( col == 5 )
            {
             return true;
            }

         break;

        // Cases for H
        case 'h':
        case 'H':
         if( col == 1 )
            {
             return true;
            }
         else if( col == 2 )
            {
             return true;
            }
         else if( col == 3 )
            {
             return true;
            }
         else if( col == 4 )
            {
             return true;
            }

         break;

        default:
        break;   

       }    

    return false;
   }

string translate( char row, int col, char sign )
   {
    // initialize variables
    string sentence;

    // Operation: switch
    switch( row )
       {
        // Cases for A
        case 'a':
        case 'A':
         if( col == 1 )
            {
             sentence = "ahoy ";
            }
         else if(col == 2 )
            {
             sentence = "avast ";
            }
          else if( col == 3 )
            {
             sentence = "arr ";
            }
         break;

        // Cases B
        case 'b':
        case 'B':
         if( col == 1 )
            {
             sentence = "matey ";
            }
         else if( col == 2 )
            {
             sentence = "proud beauty ";
            }
         else if( col == 3 )
            {
             sentence = "comely wench ";
            }
         else if( col ==  4 )
            {
             sentence = "scurvy dog ";
            }
         else if( col ==  5 )
            {
             sentence = "foul blaggart ";
            }
         break;

        // Cases for C
        case 'c':
        case 'C':
         if( col == 1 )
            {
             sentence = "whar be ";
            }
         else if( col == 2 )
            {
             sentence = "know ye ";
            }
         else if( col == 3 )
            {
             sentence = "be that ";
            }
         else if( col == 4 )
            {
             sentence = "how many leagues to ";
            }

         break;

        // Cases for D
        case 'd':
        case 'D':
         if( col == 1 )
            {
             sentence = "th' ";
            }
         else if( col == 2 )
            {
             sentence = "a briny ";
            }
         else if( col == 3 )
            {
             sentence = "some godforsaken ";
            }
         else if( col == 4 )
            {
             sentence = "broadside ";
            }
         else if( col == 5 )
            {
             sentence = "me ";
            }
         else if( col == 6 )
            {
             sentence = "yer ";
            }

         break;

        // Cases for E
        case 'e':
        case 'E':
         if( col == 1 )
            {
             sentence = "barnacle-covered " ;
            }
         else if( col == 2 )
            {
             sentence = "comely " ;
            }
         else if( col == 3 )
            {
             sentence = "grog-filled  " ;
            }

         break;

        // Cases for F
        case 'f':
        case 'F':
         if( col == 1 )
            {
             sentence = "head " ;
            }
         else if( col == 2 )
            {
             sentence = "galley " ;
            }
         else if( col == 3 )
            {
             sentence = "fleabag inn " ;
            }
         else if( col == 4 )
            {
             sentence = "market " ;
            }
         else if( col == 5 )
            {
             sentence = "skull & scuppers " ;
            }
         else if( col == 6 )
            {
             sentence = "buried treasure " ;
            }

         break;

        // Cases for G
        case 'g':
        case 'G':
         if( col == 1 )
            {
             sentence = "I be needin' t' " ;
            }
         else if( col == 2 )
            {
             sentence = "I've a fierce fire in me belly t' " ;
            }
         else if( col == 3 )
            {
             sentence = "I be hankerin' t' " ;
            }
         else if( col == 4 )
            {
            sentence = "my dear ol' mum, bless her black soul, ";
            sentence += "tol' me t' ";
            }
         else if( col == 5 )
            {
             sentence = "me mate, ol' Rumpot, wants t' " ;
            }

         break;

        // Cases for H
        case 'h':
        case 'H':
         if( col == 1 )
            {
             sentence = "come across " ;
            }
         else if( col == 2 )
            {
             sentence = "have a bit of a lie-down " ;
            }
         else if( col == 3 )
            {
             sentence = "seize all yer doubloons " ;
            }
         else if( col == 4 )
            {
              sentence = "swill put a pint or two o' grog " ;
            }

         break;

        default:
            
        break;
           

       }
    return sentence;
   }

bool isCont( char sign )
   {
    // Operation: if
    if( sign == '-' )
       {
        return false;
       }
    else if( sign == ',' )
       {
        return true;
       }
    return 0;
   }

void errorMessageForWrongInput()
   {
    printString( "ERROR - Incorrect code entry, please try again!", 0, "LEFT" );
    cout << endl;
   }

void errorMessageForTooMany()
   {
    printString( "ERROR - Too many input items, please try again!", 0, "LEFT" );
    cout << endl;
   }
