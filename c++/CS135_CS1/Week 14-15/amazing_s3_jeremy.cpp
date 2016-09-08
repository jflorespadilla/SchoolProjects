//Header files
#include <fstream>
#include "formatted_console_io_v16.h"
#include <ctime>

using namespace std;

//Global constants

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
Dependencies: formatted console io and other supporting functions
Developer:
*/
void playGame();

/*
Name: displayTops
Processing: Displays the top ten scores of the game with names  // looks into the file first and then displays error message if it can't open
Input: 
Output/Return:
Dependencies:
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
void displayMaze( ifstream fileNameIn );

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
bool collisionDectction( int xLoc, int yLoc );

/*
Name: scoreFailureMessage
Processing: Displays message to indicate that no scores file was found.
Input: None
Output/Return: Error message display
Dependencies: formetted console io
Developer:
*/
void promptForNameScreen();

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

int randomNumber();

//Main function

int main()
   {
   startCurses();
    // Initialize variables

    // Display splash
       // Function: welcomeScreen
       welcomeScreen();

    // Instruction screen
       // Function: instructionScreen
       instructionScreen();
       

    //Loop//
    // Menu
      // function: printMainMenu
      printMainMenu();

       // Play game ( As a second driver )
         // Function: playGame (Other functions within this function)

       // Display top scores
          // Function: displayTops

          //fileFailureMessage();
          //promptForNameScreen();

       // Quit

       // End Loop//

    // Display good-bye screen (After loop has ended)
       // Function: goodbye
       goodbyeScreen();

    waitForInput( FIXED_WAIT );
    endCurses();
    return 0;
   }

//Function Implementations

void welcomeScreen()
   {
   int random, key;
   bool done= false;
     
     
    setColor( COLOR_RED, COLOR_CYAN, SET_BRIGHT);
    clearScreen( 0, 0, 79, 24 );


     while( done == false )
               {
               random = randomNumber();    


               if(random>=0 && random<=5)
                     {
                     setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT);
                     clearScreen( 0, 0, 79, 24 );
                     
                     printStringAt( 22, 2, "TTTTTTTTTT   HH     HH   EEEEEEEE", "LEFT" );
                     printStringAt( 22, 3, "TTTTTTTTTT   HH     HH   EE     E", "LEFT" );
                     printStringAt( 22, 4, "    TT       HHHHHHHHH   EEEE    ", "LEFT" );
                     printStringAt( 22, 5, "    TT       HHHHHHHHH   EEEE    ", "LEFT" );
                     printStringAt( 22, 6, "    TT       HH     HH   EE     E", "LEFT" );
                     printStringAt( 22, 7, "    TT       HH     HH   EEEEEEEE", "LEFT" );

                     printStringAt( 4, 10, "  AAAA     MMM    MMM     AAAA     ZZZZZZZ   IIII   NNN     NN    GGGGGG ", "LEFT" );
                     printStringAt( 4, 11, " AA  AA    MM M  M MM    AA  AA        ZZZ    II    NN N    NN   GG    GG", "LEFT" );
                     printStringAt( 4, 12, "AA    AA   MM  MM  MM   AA    AA      ZZZ     II    NN  N   NN   GG      ", "LEFT" );
                     printStringAt( 4, 13, "AAAAAAAA   MM      MM   AAAAAAAA     ZZZ      II    NN   N  NN   GG  GGGG", "LEFT" );
                     printStringAt( 4, 14, "AA    AA   MM      MM   AA    AA    ZZZ       II    NN    N NN   GG    GG", "LEFT" );
                     printStringAt( 4, 15, "AA    AA   MM      MM   AA    AA   ZZZZZZZ   IIII   NN     NNN    GGGGGG ", "LEFT" );

                     printStringAt( 19, 18, " GGGGGG      AAAA     MMM    MMM   EEEEEEEE", "LEFT" );
                     printStringAt( 19, 19, "GG    GG    AA  AA    MM M  M MM   EE     E", "LEFT" );
                     printStringAt( 19, 20, "GG         AA    AA   MM  MM  MM   EEEE    ", "LEFT" );
                     printStringAt( 19, 21, "GG  GGGG   AAAAAAAA   MM      MM   EEEE    ", "LEFT" );
                     printStringAt( 19, 22, "GG    GG   AA    AA   MM      MM   EE     E", "LEFT" );
                     printStringAt( 19, 23, " GGGGGG    AA    AA   MM      MM   EEEEEEEE", "LEFT" );
                     }

              else if(random>=6)
                     {     
                    setColor( COLOR_CYAN, COLOR_GREEN, SET_BRIGHT);
                     clearScreen( 0, 0, 79, 24 );
                     printStringAt( 22, 2, "TTTTTTTTTT   HH     HH   EEEEEEEE", "LEFT" );
                     printStringAt( 22, 3, "TTTTTTTTTT   HH     HH   EE     E", "LEFT" );
                     printStringAt( 22, 4, "    TT       HHHHHHHHH   EEEE    ", "LEFT" );
                     printStringAt( 22, 5, "    TT       HHHHHHHHH   EEEE    ", "LEFT" );
                     printStringAt( 22, 6, "    TT       HH     HH   EE     E", "LEFT" );
                     printStringAt( 22, 7, "    TT       HH     HH   EEEEEEEE", "LEFT" );

                     printStringAt( 4, 10, "  AAAA     MMM    MMM     AAAA     ZZZZZZZ   IIII   NNN     NN    GGGGGG ", "LEFT" );
                     printStringAt( 4, 11, " AA  AA    MM M  M MM    AA  AA        ZZZ    II    NN N    NN   GG    GG", "LEFT" );
                     printStringAt( 4, 12, "AA    AA   MM  MM  MM   AA    AA      ZZZ     II    NN  N   NN   GG      ", "LEFT" );
                     printStringAt( 4, 13, "AAAAAAAA   MM      MM   AAAAAAAA     ZZZ      II    NN   N  NN   GG  GGGG", "LEFT" );
                     printStringAt( 4, 14, "AA    AA   MM      MM   AA    AA    ZZZ       II    NN    N NN   GG    GG", "LEFT" );
                     printStringAt( 4, 15, "AA    AA   MM      MM   AA    AA   ZZZZZZZ   IIII   NN     NNN    GGGGGG ", "LEFT" );

                     printStringAt( 19, 18, " GGGGGG      AAAA     MMM    MMM   EEEEEEEE", "LEFT" );
                     printStringAt( 19, 19, "GG    GG    AA  AA    MM M  M MM   EE     E", "LEFT" );
                     printStringAt( 19, 20, "GG         AA    AA   MM  MM  MM   EEEE    ", "LEFT" );
                     printStringAt( 19, 21, "GG  GGGG   AAAAAAAA   MM      MM   EEEE    ", "LEFT" );
                     printStringAt( 19, 22, "GG    GG   AA    AA   MM      MM   EE     E", "LEFT" );
                     printStringAt( 19, 23, " GGGGGG    AA    AA   MM      MM   EEEEEEEE", "LEFT" );

                     }
             key = waitForInput( 1 );
             if ( key >=0 )
                {
                done = true;

                }

              }

        
   
   }

void instructionScreen()
   {
    setColor( COLOR_BLUE, COLOR_CYAN, SET_BRIGHT );
    clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
    setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );
    clearScreen( 10, 4, 69, 19 );

    printStringAt( 26, 5, "Amazing Game Instructions", "LEFT" );
    printStringAt( 26, 6, "=========================", "LEFT" );

    printStringAt( 20, 8, "Get through the maze as fast as you can", "LEFT" );

    printStringAt( 14, 10, "Hitting maze edge reduces score by the value hit", "LEFT" );
    printStringAt( 25, 11, "or by the passage of time", "LEFT" );

    printStringAt(23, 13, "Each level starts with more points", "LEFT" );

    printStringAt(19, 15, "If the score reaches zero in any level,", "LEFT" );
    printStringAt(30, 16, "the game is ended", "LEFT" );

    printStringAt(23, 18, "Pressing <Q> also ends the game", "LEFT" );
    
    waitForInput( FIXED_WAIT );

   }

void playGame()
   {
     // Intialize variables

     // Get Name
        // Function: promptForStringAt

     // Display maze
            // Open master file
            // Error if failed open
            // Take in file name as a c-style string
            
            // Start loop

               // Open Maze file
               // Error if failed open
                  // Function: fileFailureMessage
               // Store in values
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


              // Count Time

              // Decrement score

             // If Q
                // Pause and quit
             // If arrows
                // Move
                 // Detecting collision
                    // Function: collisionDectction
             // If spacebar
                 // Pause

              // End inner loop

              // Close maze file

              // count levels

              // Update score

            // End loop
        
     // Store score into file
     // close master file    


   }

void displayMaze( ifstream fileNameIn )
   {
    // Stub
   }

bool collisionDectction( int xLoc, int yLoc )
   {
    return false; // Stub retrun
   }

void promptForNameScreen()
   {
   
     setColor( COLOR_WHITE, COLOR_CYAN, SET_BRIGHT );
     clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

     promptForStringAt( 20, 11, "Enter your name: " );

   }

void goodbyeScreen()
   {
   setColor( COLOR_RED, COLOR_CYAN, SET_BRIGHT );
   clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

   printStringAt( 30, 8, "THAN YOU FOR PLAYING", "LEFT" );

   printStringAt( 33, 10, "THE AMAZING GAME", "LEFT" );

   printStringAt( 28, 13, "Press Any Key to Continue", "LEFT" );
      

   }

void printMainMenu()
   {
   setColor( COLOR_WHITE, COLOR_CYAN, SET_BRIGHT );
   clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );   

   printStringAt( 30, 8, "MENU SELECTIONS", "LEFT" );
   printStringAt( 30, 9, "---------------", "LEFT" );

   printStringAt( 30, 11, "1. <P>lay Game", "LEFT" );
   printStringAt( 30, 12, "2. <S>how Top Scores", "LEFT" );
   printStringAt( 30, 13, "3. <Q>uit Program", "LEFT" );

  

           waitForInput( FIXED_WAIT ); // after switch
   }

void displayTops()
   {

   }

void printStatBar()
   {

   }

void fileFailureMessage()
     {
     setColor( COLOR_WHITE, COLOR_CYAN, SET_BRIGHT );
   clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

   printStringAt( 20, 11, "Game file not found - No mazes availiable", "LEFT" );

     }

int randomNumber()
        {             
    srand(time(NULL));
    int random; 
    random = rand()%10;    

    //printIntAt( 5,5, random, "LEFT");
    return (random);
    }


/* Jeremy's Fuctions:
~ welcome Screen
X instructions Screen
X goodbye Screen
X print main menu
X prompt For name screen
X file failure message
*/ 



