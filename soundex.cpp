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
#include <cstring>

typedef unsigned char uint8_t;

using namespace std;

void convertSurname(uint8_t *codes, char *surname);
void initSurnameCodes(uint8_t *codes);
void deleteDuplicates(char *s);
void removeZeros(char *s);
void adjustSize(char *s);

int main(int argc, char* argv[])
{
   uint8_t surnameCodes[256];
   char * surname = argv[1];

   initSurnameCodes(surnameCodes);
   convertSurname(surnameCodes, surname);
   deleteDuplicates(surname);
   removeZeros(surname);
   adjustSize(surname);
   cout << surname << endl;
   
   return 0;
}

void deleteDuplicates(char *s){
   char *last = s + 1;
   char *current = last + 1;
   
   for(; *current; ++current){
      if(*current != *(current-1)){
         last++;
         *last = *current;
      }
   }
   
   last++;
   last = '\0'; // end of string
}

void removeZeros(char *s){
   char *last = s + 1;
   char *current = s + 1;
   
   for(; *current; ++current) {
      if(*current != '0') {
         *last = *current;
         last++;
      }
   }
   last = '\0';
}

void adjustSize(char *s){
   size_t len = strlen(s);
   const int correctSize = 4;
   
   for(; len < correctSize; ++len) {
      s[len] = '0';
   }
   
   s[correctSize] = '\0';
}

void initSurnameCodes(uint8_t *codes)
{
   codes['A'] = 0;
   codes['E'] = 0;
   codes['I'] = 0;
   codes['O'] = 0;
   codes['U'] = 0;
   codes['H'] = 0;
   codes['W'] = 0;
   codes['Y'] = 0;
   codes['B'] = 1;
   codes['F'] = 1;
   codes['P'] = 1;
   codes['V'] = 1;
   codes['C'] = 2;
   codes['G'] = 2;
   codes['J'] = 2;
   codes['K'] = 2;
   codes['Q'] = 2;
   codes['S'] = 2;
   codes['X'] = 2;
   codes['Z'] = 2;
   codes['D'] = 3;
   codes['T'] = 3;
   codes['M'] = 4;
   codes['N'] = 4;
   codes['L'] = 5;
   codes['R'] = 6;

   codes['a'] = 0;
   codes['e'] = 0;
   codes['i'] = 0;
   codes['o'] = 0;
   codes['u'] = 0;
   codes['h'] = 0;
   codes['w'] = 0;
   codes['y'] = 0;
   codes['b'] = 1;
   codes['f'] = 1;
   codes['p'] = 1;
   codes['v'] = 1;
   codes['c'] = 2;
   codes['g'] = 2;
   codes['j'] = 2;
   codes['k'] = 2;
   codes['q'] = 2;
   codes['s'] = 2;
   codes['x'] = 2;
   codes['z'] = 2;
   codes['d'] = 3;
   codes['t'] = 3;
   codes['m'] = 4;
   codes['n'] = 4;
   codes['l'] = 5;
   codes['r'] = 6;
}

void convertSurname(uint8_t *codes, char *surname)
{
   surname[0] = toupper(surname[0]);
   
   for(int i = 1; surname[i]; ++i) {
      surname[i] = codes[surname[i]] + '0';
   }
}
