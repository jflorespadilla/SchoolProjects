//Header files
#include <fstream>
#include "formatted_console_io_v16.h"

using namespace std;

//Global constants
const int MAX_COL = 70;
const int MAX_ROW = 21;

//Function Prototypes

/*
Name: welcomeScreen
Processing: Displays the first splash screen
Input: None
Output/Return: Splash Screen display
Dependencies: formatted console io
Developer:
*/
void welcomeScreen();


/*
Name: instructionScreen
Processing: Displas the instructions for the game
Input: None
Output/Return: Instructions display
Dependencies: formatted console io
Developer:
*/
void instructionScreen();

/*
Name: playGame
Processing: Runs gameplay loop until game ends (Acts as a second driver)
Input: None
Output/Return: Runs the game
Dependencies: formatted console io, fstream, and other supporting functions
Developer:
*/
void playGame();

/*
Name: displayTops
Processing: Displays the top ten scores of the game with names, error message if 
            the score file is not found
Input: None
Output/Return: Displays the scores or an error message
Dependencies: formatted console io and ifstream
Developer:
*/
void displayTops();

/*
Name: displayMaze
Processing: Looks through a file containing a maze and prints out the maze on  
            screen.
Input: ifstream variable
Output/Return: printing the maze on to the screen
Dependencies: formatted console io, ifstream
Developer:
*/
void displayMaze( char arr[][MAX_COL] );

/*
Name: fileFailureMessage
Processing: Displays an error message to the user notifying a failure in opening
            a file.
Input: None
Output/Return: An error message display
Dependencies: ifstream, formatted consol io
Developer:
*/
void fileFailureMessage();

/*
Name: printStatBar
Processing: Prints the status bar seen below the gameplay screen.
Input: None
Output/Return: Status screen display
Dependencies: formatted console io
Developer:
*/
void printStatBar();

/*
Name: collisionDectction
Processing: Tells whether or not the space that the user indicated to go to is a
            wall (Number that decrements the score)
Input: cursor location indicating where the user has moved to.
Output/Return: True or false statement
Dependencies: formatted console io
Developer:
*/
bool collisionDectction( int xLoc, int yLoc, char arr[][MAX_COL] );

/*
Name: scoreFailureMessage
Processing: Displays message to indicate that no scores file was found.
Input: None
Output/Return: Error message display
Dependencies: formetted console io
Developer:
*/
void scoreFailureMessage();

/*
Name: goodbyeScreen
Processing: Displays a goodbye message for the user
Input: None
Output/Return: Goodbye message display
Dependencies: formetted console io
Developer:
*/
void goodbyeScreen();

/*
Name: printMainMenu
Processing: Displays the game's main menu
Input: None
Output/Return: Diplay main menu
Dependencies: formetted console io
Developer:
*/
void printMainMenu();

/*
Name: addNumbsToMaze
Processing: Adds numbs to maze
Input: Two dementional array
Output/Return: adds numbers to the arry
Dependencies: formetted console io
Developer:
*/
void addNumbsToMaze(char arr[][MAX_COL]);

//Main function

int main()
   {
    // Initialize variables

    // Display splash
       // Function: welcomeScreen

    // Instruction screen
       // Function: instructionScreen

    //Loop//
    // Menu
      // function: printMainMenu

       // Play game ( As a second driver )
         // Function: playGame (Other functions within this function)

       // Display top scores
          // Function: displayTops

       // Quit

       // End Loop//

    // Display good-bye screen (After loop has ended)
       // Function: goodbye

    return 0;
   }

//Function Implementations

void welcomeScreen()
   {
    // Stub
   }

void instructionScreen()
   {
    // Stub
   }

void playGame()
   {
     // Intialize variables

     // Get Name
        // Function: promptForStringAt

     // Display maze
            // Open master file

            // Start loop

            // Error if failed open
            // Take in file name as a c-style string
            

               // Open Maze file
               // Error if failed open
                  // Function: fileFailureMessage
               // Store in values
                  // add numbers to maze
                  //Function: addNumbsToMaze
               // Display maze
                  //Function:displayMaze
 
               // Display Stats bar 
                  // Function: printStatBar
               // Write and update score file          


          // Navigate

            // Set winLevel flag
            // Set endGame flag


            // Start inner loop

             // Get Input
                // function: waitForInput

             // If counter is = 10
                // Count Time

                // Decrement score
                //initialize counter to 0
            // End if statement

             // If Q
                // Pause and quit
             // End if statemnt

             // If arrows
                // Move
                 // Detecting collision
                    // Function: collisionDectction
             //  End if statement

             // If spacebar
                 // Pause
             // End if statement

              // End inner loop

              // Close maze file

              // count levels

              // Update score

            // End loop
        
     // Store score into file
     // close master file    


   }

void displayTops()
   {
    // Stub
   }

void displayMaze( char arr[][MAX_COL] )
   {
    // Stub
   }

void fileFailureMessage()
   {
    // Stub
   }

void printStatBar()
   {
    // Stub
   }

bool collisionDectction( int xLoc, int yLoc, char arr[][MAX_COL])
   {
    
    return false; // Stub retrun
   }

void scoreFailureMessage()
   {
    // Stub
   }

void goodbyeScreen()
   {
    // Stub
   }

void printMainMenu()
   {
    // Stub
   }

void addNumbsToMaze( char arr[][MAX_COL])
   {
    // Stub
   }
