/*  11/29/2011
1) display splash (function)
2) display instructions (function)
3) display Menu (function)
   Menu runs while not Quitting program
        Play Game (Master function)
        1) get name (function)
        2) display Maze (function)
        3) navigate maze (create function for this and treat it as a driver function)
           1) move
           2) Count time
           3) detecting collisions
           4) pause
              1) end game with q/Q
           5) End (time is 0/ win/ Q)
           6) If a win, continue to next maze
              1) update score
              2) continue to maze function (displayMaze( int &score ) )
           7) Win all-- Show winners (top scores)
** create "scores.txt" after the game is over/ level is left

////////////    bool displayMaze()  //////////////
{
  // get file name (from mazenames.txt) <--- keep this open while displaying mazes
     // error --> display error message or return false
  // open file
     // read name
     // open new file (maze file)
     // get starting points
     // get X's (fill 2D character array)
        // ifstream or getline??
     // close maze file
     // print X's (loop)
     // print numbers on edge (function: will use random number generator)
        // getRandomNumber
     // print score bar 
        // printTime and printScore functions with initial values (will be different)
  // return true
}

//////   11/29/2011 /////////////

bool navigateMaze( int score) (bool for a win or loose)
{
  // get input
     // if arrow, move the cursor
        // move cursor?
        // number or space?
           // change color of number if hit
     // update score
  // if q
     // pause
     // key
  // update time
     // update score( lose = end game)
  // win level
}

win = navigateMaze(score)
    if(win)
      // update score
      // display maze
      if(win)
        // update score
        // display maze
updateScoresFile

updateScoresFile( int scores )
{
  // open file with names and scores ( scores.txt )
  // upload info
  // if score is in top 10
     // insert name and score
     // update file
}


Power Quiz
int parseWords( char sentence[], char wordList[][WORD_LENGTH] );
{
  // variables
  int index = 0, rowCtr = 0, colCtr = 0;
 
  // loop through sentence array
    while(sentence[index] != NULL_CHAR )
      {
         if( isLetter( sentence[index] ) )
           {
              list[row][col] = sentence[index];
              colCtr++;
           }
         else
           {
              list[row][col] = NULL_CHAR;
              rowCtr++;
           }
         index++;
      }
  return row++;
}

*/
