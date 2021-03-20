#include <string>
#include <array>
#include <iostream>
#include <stdexcept>
#include "snowman.hpp"
const int ROW =8;
const int COL= 4;
const int SIZE =8;
using namespace std;
const int HEAD=0;
const int NOSE=1;
const int LEFTEYE=2;
const int RIGHTEYE=3;
const int LEFTARM=4;
const int RIGHTARM=5;
const int TORSO=6;
const int BASE=7;
const int MININPUT=11111111;
const int MAXINPUT=44444444;
const int TEN=10;
namespace ariel{
 const array<array <string, COL>, ROW> snowManMatrix={{
    {"       \n _===_ \n","  ___  \n ..... \n","   _   \n  /_\\  \n"," ___  \n (_*_) \n"},
    {",",".","_"," "},
    {"(.","(o", "(O","(-" },
    {".)","o)","O)","-)"},
    {"<","\\","/"," "},
    {">","/","\\"," "},
    {"( : )","(] [)","(> <)","(   )"},
    {"( : )","(\" \")","(___)","(   )"}

}};
/**
 * the function gets array reprsent the number we get from the user and build a string  
 * of the snowman and return the string
 * @param array 
 * @return string 
 */
string drawsnowman(std::array<int,SIZE> &array)
{
   
    string snowman; 
    snowman+=snowManMatrix[HEAD][array[HEAD]-1];
    // check if the left arm is upwards if yes she need to be before the eyes
    if(array[LEFTARM]==2)
    {
        snowman+=snowManMatrix[LEFTARM][array[LEFTARM]-1];
    }
    else{
        snowman+=" ";
    }
    snowman+=snowManMatrix[LEFTEYE][array[LEFTEYE]-1];
    snowman+=snowManMatrix[NOSE][array[NOSE]-1];
    snowman+=snowManMatrix[RIGHTEYE][array[RIGHTEYE]-1];
     // check if the right arm is upwards if yes she need to be after the eyes
    if(array[RIGHTARM]==2)
    {
        snowman+=snowManMatrix[RIGHTARM][array[RIGHTARM]-1];
    }
    snowman+="\n";
    // if the left arm isnt upwards she need to be before the torso
    if(array[LEFTARM]!=2){
        snowman+=snowManMatrix[LEFTARM][array[LEFTARM]-1];}
    else
    {
        snowman+=" ";
    }
    snowman+=snowManMatrix[TORSO][array[TORSO]-1];
     // if the left arm isnt upwards she need to be after the torso
    if(array[RIGHTARM]!=2){
        snowman+=snowManMatrix[RIGHTARM][array[RIGHTARM]-1];}
    snowman+="\n";
    snowman+=" ";
    snowman+=snowManMatrix[BASE][array[BASE]-1];
    return snowman;
}
/**
 * the function get number from the user represent the snow man and return
 * a string of the snow man
 * @param num 
 * @return string 
 */
string snowman(int  num)
{
   std::array<int,SIZE> array{};
   if (num<0){
        throw std::out_of_range{" the number must be positive"};}
    if((num<MININPUT)|| (num>MAXINPUT)){
        throw std::out_of_range{"the number is not in the range"};}
    
    int x=num;
    int i=SIZE-1;
    while(x>0)
    {
        if((x%TEN==0)||(x%TEN>4)){
            throw std::out_of_range{"the digit needs to be between 1 to 4"};}
    
        array.at(i)=x%TEN;
        i--;
        
            
        x=x/TEN;    
    }
    string ans=drawsnowman(array);
    return ans;

}

}