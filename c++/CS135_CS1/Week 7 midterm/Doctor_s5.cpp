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
    double systData, diastData, heartData, bloodData;
    int resultPressure, resultRate, resultGas;
    int resultSyst, resultDiast;
    string infoFromUser

    // Title for operation
       // Function: displayTitle
       displayTitle();
   
    // Prompt for patient information
      // Get Name
         // Function: nameLine
         nameLine();
         // Function: patientInfo
         patientInfo( infoFromUser );
      //Get date of birth
         // function: dateLine
         dateLine();
         // Function: patientInfo
         patientInfo( infoFromUser );

    // Analyze blood pressure
       // get blood pressure data
          // Function: getPatientData x2
          systData = getPatientData( GET_SYSTOLIC );
          diastData = getPatientData( GET_DIASTOLIC );
       // Anlayze
          // Function: systolicCode
          resultSyst = systolicCode( systData );
          // Function: diastolicCode
          resultDiast = diastolicCode( diastData );
          // Fucntion: pressureCode
          resultPressure = pressureCode( resultSyst, resultDiast );

    // Analyze heart rate
       // get heart rate data
          // Function: getPatientData
          heartData = getPatientData( GET_HEART_RATE );
       // Analyze
          // Function: rateCode
          resultRate = rateCode( heartData );

    // Analyze Blood gas
       // get blood gas data
          // Function: getPatientData
          bloodData = getPatientData( GET_BLOOD_GAS );
       // Analyze
          // Fucntion: gasCode
          resultGas = gasCode( bloodData );

    // Display information 
       // Function: displayToMonitor
       displayToMonitor( resultPressure, resultRate, resultGas );

    // End program
    return 0;

   }

//Function Implementations
void displayTitle()
   {
    // intitinalize variables
       // None
    
    // Title
       // Operation: <<

    // Line
       // Operation: <<

   }

int systolicCode( double sDataCode )
   {
    // intitinalize variables
    int reslut;

    // Operation: if
       // if for 1, constant used ( NORMAL_SYSTOLIC_VALUE )
       // if for 2, <10, 20>
       // if for 3, 20<

    return result;
   }

int diastolicCode( double dDataCode )
   {
    // intitinalize variables
    int reslut;

    // Operation: if
       // if for 1, constant used ( NORMAL_DIASTOLIC_VALUE )
       // if for 2, <10, 20>
       // if for 3, 20<

    return result; 
   }

string patientInfo( string userInfo )
   {
    // intitinalize variables
    string input;
    // Operation: >>
    //Operation: <<


    return input; 
   }

string nameLine()
   {
    // intitinalize variables
    string nameInst;

    // Operation <<

    return nameInst;
   }

string dateLine()
   {
    // intitinalize variables
    string dateInst;

    // Operation: <<

    return dateInst; // stub return
   }

int pressureCode( int systData, int diastData )
   {
    // intitinalize variables
    int code;

    // Operation: if
       // if for systData > distData
       // if for systData < distData
       // if for systData == distData


    return code; // stub return
   }

int rateCode( double rDataCode )
   {
    // intitinalize variables
    int reslut;

    // Operation: if
       // if for 1, constant used ( NORMAL_HEART_RATE_VALUE )
       // if for 2, <10, 20>
       // if for 3, 20<

    return result; // stub return
   }
int gasCode( double gDataCode )
   {
    // intitinalize variables
    int reslut;

    // Operation: if
       // if for 1, constant used ( NORMAL_BLOOD_GAS_VALUE )
       // if for 2, <10, 20>
       // if for 3, 20<

    return result; // stub return
   }
