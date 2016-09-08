//Header files
#include <iostream>
#include "doctor_interface_tools.h"
#include "hospital_interface_tools.h"

using namespace std;

//Global constants

//Function Prototypes
/* 
Name: displayTitle
Process: Displays title
Input: none
Output/Display: Display title
Dependencies: iostream
*/
void displayTitle();

/* 
Name: systolicCode
Process: Takes in systolic information and gives out an integer code
Input: double via getPatientData
Output/Retrun: int 1, 2, or 3 indicating danger level
Dependencies: iostream, getPatientData
*/
int systolicCode( double sDataCode );

/* 
Name: diastolicCode
Process: Takes in diastolic infromation and gives out an integer code
Input: double via getPatientData
Output/Retrun: int 1, 2, or 3 indicating danger level
Dependencies: iostream, getPatientData
*/
int diastolicCode( double dDataCode );

/* 
Name: patientInfo
Process: prompts user to string in information
Input: user string
Output/Retrun: string typed in by the user
Dependencies: iostream
*/
string patientInfo( string userInfo );

/* 
Name: nameLine
Process: Instructions on where to type name
Input: none
Output/Display: Where to type name 
Dependencies: iostream
*/
string nameLine();

/* 
Name: dateLine
Process: Instructions on where to type date of birth
Input: none
Output/Display: Where to type date of birth
Dependencies: iostream
*/
string dateLine();

/* 
Name: pressureCode
Process: compares the values given by systolicCode and diastolicCode and returns
         the greater value between the two
Input: int values given by systolicCode and diastolicCode
Output/Retrun: int 1, 2, or 3 indicating danger level
Dependencies: iostream, systolicCode, diastolicCode
*/
int pressureCode( int systData, int diastData );

/* 
Name:
Process: Takes in heart rate infromation and gives out an integer code
Input: double via getPatientData
Output/Retrun: int 1, 2, or 3 indicating danger level
Dependencies: iostream, getPatientData
*/
int rateCode( double rDataCode );

/* 
Name:
Process: Takes in blood gas infromation and gives out an integer code
Input: double via getPatientData
Output/Retrun: int 1, 2, or 3 indicating danger level
Dependencies: iostream, getPatientData
*/
int gasCode( double gDataCode );

//Main function

int main()
   {
    // initinalize variables



    // Title for operation
       // Function: displayTitle
   
    // Prompt for patient information
      // Get Name
         // Function: nameLine
         // Function: patientInfo
      //Get date of birth
         // function: dateLine
         // Function: patientInfo

    // Analyze blood pressure
       // get blood pressure data
          // Function: getPatientData x2
       // Anlayze
          // Function: systolicCode
          // Function: diastolicCode
          // Fucntion: pressureCode

    // Analyze heart rate
       // get heart rate data
          // Function: getPatientData
       // Analyze
          // Function: rateCode


    // Analyze Blood gas
       // get blood gas data
          // Function: getPatientData
       // Analyze
          // Fucntion: gasCode

    // Display information 
       // Function: displayToMonitor

    // End program
    return 0;

   }

//Function Implementations
void displayTitle()
   {
    // stub
   }

int systolicCode( double sDataCode )
   {
    return 0; // stub return
   }

int diastolicCode( double dDataCode )
   {
    return 0; // stub return
   }

string patientInfo( string userInfo )
   {
    return ""; // stub return
   }

string nameLine()
   {
    return ""; // stub return
   }

string dateLine()
   {
    return ""; // stub return
   }

int pressureCode( int systData, int diastData )
   {
    return 0; // stub return
   }

int rateCode( double rDataCode )
   {
    return 0; // stub return
   }
int gasCode( double gDataCode )
   {
    return 0; // stub return
   }
