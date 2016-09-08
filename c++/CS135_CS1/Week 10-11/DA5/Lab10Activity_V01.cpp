//  Header Files  //////////////////////////////////////////////////////////////
#include "formatted_console_io_V16.h" // for advanced console functions

using namespace std;

//  Global Constants  //////////////////////////////////////////////////////////
//
    const char MARKER_CHAR = '*';
    const char SPACE = ' ';
//
//  Function Prototypes  ///////////////////////////////////////////////////////
//
    bool move( int &xPos, int &yPos, int xVect, int yVect );
//
//  Main Function  /////////////////////////////////////////////////////////////
int main()
   {
    // initialize program / function
    
       // initialize variables
       int userInput, xLoc, yLoc, xVector, yVector;
       bool continueProgram = true;

       // initialize locations and movement vectors
       xLoc = SCRN_MAX_X / 2;
       yLoc = SCRN_MAX_Y / 2;
       xVector = 0; yVector = 0;

       // initialize curses
       startCurses();
       setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );

   // start loop
    do
       {
        // get an input key, waiting for user input
        userInput = waitForInput( FIXED_WAIT );

        // if user input, set direction, otherwise ignore
        switch( userInput )
           {
            case KB_RIGHT_ARROW:
               xVector = 1;
               yVector = 0;
               break;

            case KB_LEFT_ARROW:
               xVector = -1;
               yVector = 0;
               break;
 
            // set up a case for moving up with the up arrow key

            // set up a case for moving down with the down arrow key

            // set up a case for ending the program with the ESC key
           }

        // move the character
        move( xLoc, yLoc, xVector, yVector );
       }
    while( continueProgram );

    // shut down program

       // shut down curses 
       endCurses();

       // return success
       return 0;
   }

//  Supporting Function Implementation  ////////////////////////////////////////

bool move( int &xPos, int &yPos, int xVect, int yVect )
   {
    // initialize function/variables
    bool moved = false;
    int oldX = xPos, oldY = yPos;

    // if x vector is live, test for acceptable movement limits
    if( ( xVect != 0 ) // is meant to move
          && ( xPos + xVect >= SCRN_MIN_X ) // won't go off left side of screen 
               && ( xPos + xVect <= SCRN_MAX_X )  ) // won't go off right side of screen
       {
        // cover up the old marker
        //printCharAt( oldX, oldY, SPACE );

        // reset the x position
        xPos = xPos + xVect;

        // set moved flag to indicate success
        moved = true;
       }

    // if y vector is live, test for acceptable movement limits
    else if( ( yVect != 0 ) // is meant to move
               && ( yPos + yVect >= SCRN_MIN_Y ) // won't go off top of screen
                    && ( yPos + yVect <= SCRN_MAX_Y ) ) // won't go off bottom of screen
       {
        // cover up the old marker
        printCharAt( oldX, oldY, SPACE );

        // reset the y position
        yPos = yPos + yVect;

        // set the moved flag to indicate success
        moved = true;
       }

    // print the marker at the specified location
    printCharAt( xPos, yPos, MARKER_CHAR );

    // return successful move
    return moved;
   }
