/*
* soundex.cpp
* Soundex algorithm produces a code for a surname based on the way it sounds.
* All soundex codes have the same format: an uppercase letter followed 
* by three digits.
* 
* December 23, 2014
* Mariana Lopez Jaimez
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "simpio.h"

using namespace std;

string convertSurname(vector<std::string> &codes, string surname);
void printSoundex(string sourname, string s);
void initSurnameCodes(vector<std::string> &codes);
string toUppercase(string surname);
string deleteDuplicates(string &s);
string removeZeros(string &s);
string adjustSize(string &s);

int main()
{
   vector<std::string> surnameCodes;
   string soundexCode = "";

   initSurnameCodes(surnameCodes);

   cout << "Enter surname (RETURN to quit): ";
   string surname = getLine();
   while(surname.size() > 0){
      cout << toUppercase(surname) << endl;
      soundexCode = convertSurname(surnameCodes, surname);
      soundexCode = deleteDuplicates(soundexCode);
      soundexCode = removeZeros(soundexCode);
      soundexCode = adjustSize(soundexCode);
      printSoundex(surname, soundexCode);
      cout << "Enter surname (RETURN to quit): ";
      surname = getLine();
   }
  

   return 0;
}

string deleteDuplicates(string &s){
   stringstream ss;

   ss << s[0];
   ss << s[1];
   
   for(int i = 2; i < s.length(); ++i){
      if(s[i] != s[i-1]){
         ss << s[i];
      }
   }

   return ss.str();
}

string removeZeros(string &s){
   stringstream ss;
   int i = 0;

   while(i < s.length()){
      if(s[i] != '0'){
         ss << s[i];
      }
      ++i;
   }

   return ss.str();
}

string adjustSize(string &s){
   stringstream ss;
   ss << s;
   int correctSize = 4;
   int i = ss.str().length();

   while(i < correctSize){
      ss << '0';
      i = ss.str().length();
   }

   if(i > correctSize){
      return ss.str().substr(0,correctSize);
   }
   else{
      return ss.str();
   }
}

string toUppercase(string surname)
{
   stringstream ss;

   for(std::string::iterator it=surname.begin(); it!=surname.end(); ++it){
      if((*it > 96) && (*it < 123)){ // if char *it is lowercase (ASCII code)
         // The difference between upper and lower case in ASCII:
         ss << char(*it -32);
      } else if((*it >64) && (*it < 91)){
         ss << *it; // append char if it's already uppercase
      }
   }

   return ss.str();
}

void initSurnameCodes(vector<std::string> &codes)
{
   codes.push_back("AEIOUHWY");
   codes.push_back("BFPV");
   codes.push_back("CGJKQSXZ");
   codes.push_back("DT");
   codes.push_back("MN");
   codes.push_back("L");
   codes.push_back("R");
}

void printSoundex(string surname, string code)
{
   cout << "Soundex code for " << surname << " is " << code << endl;
}

string convertSurname(vector<std::string> &codes, string surname)
{
   string upperCaseSurname = toUppercase(surname);
   stringstream ss;

   ss << upperCaseSurname[0]; 
   
   for(int c=1; c<upperCaseSurname.length(); ++c){
      for(int index=0; index<codes.size(); ++index){
         for(int strIndex=0; strIndex<codes[index].length(); ++strIndex){
            if(upperCaseSurname[c] == codes[index][strIndex]){
               ss << index;
            }
         }
      }
   }
   return ss.str();
}
