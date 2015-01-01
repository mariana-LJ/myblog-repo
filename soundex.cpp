/*
* g++ soundex.cpp -o soundex
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

char * adjustInitialSize(char *surname);
void initSurnameCodes(uint8_t *codes);
void convertSurname(uint8_t *codes, char *surname);
void deleteDuplicates(char *s);
void removeZeros(char *s);
void adjustFinalSize(char *s);

int main(int argc, char* argv[])
{
   uint8_t surnameCodes[256];
   char * surname = NULL;
   
   if(argc == 2) {
    surname = argv[1];
   } else {
    cout << "Ejemplo de uso: ./soundex mariana" << endl;
    return 1;
   }

   initSurnameCodes(surnameCodes);
   convertSurname(surnameCodes, surname);
   deleteDuplicates(surname);
   removeZeros(surname);
   adjustFinalSize(surname);
   cout << surname << endl;
   
   return 0;
}

void initSurnameCodes(uint8_t *codes)
{
   codes['A'] = codes['a'] = 0;
   codes['E'] = codes['e'] = 0;
   codes['I'] = codes['i'] = 0;
   codes['O'] = codes['o'] = 0;
   codes['U'] = codes['u'] = 0;
   codes['H'] = codes['h'] = 0;
   codes['W'] = codes['w'] = 0;
   codes['Y'] = codes['y'] = 0;
   codes['B'] = codes['b'] = 1;
   codes['F'] = codes['f'] = 1;
   codes['P'] = codes['p'] = 1;
   codes['V'] = codes['v'] = 1;
   codes['C'] = codes['c'] = 2;
   codes['G'] = codes['g'] = 2;
   codes['J'] = codes['j'] = 2;
   codes['K'] = codes['k'] = 2;
   codes['Q'] = codes['q'] = 2;
   codes['S'] = codes['s'] = 2;
   codes['X'] = codes['x'] = 2;
   codes['Z'] = codes['z'] = 2;
   codes['D'] = codes['d'] = 3;
   codes['T'] = codes['t'] = 3;
   codes['M'] = codes['m'] = 4;
   codes['N'] = codes['n'] = 4;
   codes['L'] = codes['l'] = 5;
   codes['R'] = codes['r'] = 6;
}

// adjustInitialSize makes sure that the initial array is 
// at least 5 bytes, because the final string is 4 chars
// + end of string
// TODO: release memory at the end of program
char * adjustInitialSize(char *surname) {
  size_t len = strlen(surname);
  
  if (len < 4) {
    char *newdata = new char[5];
    // len+1 to also copy end of string
    memcpy(newdata, surname, len+1);
    surname = newdata;
  }
  
  return surname;
}

void convertSurname(uint8_t *codes, char *surname)
{
   surname[0] = toupper(surname[0]);
   
   for(int i = 1; surname[i]; ++i) {
      surname[i] = codes[surname[i]] + '0';
   }
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

void adjustFinalSize(char *s){
   size_t len = strlen(s);
   const int correctSize = 4;
   
   for(; len < correctSize; ++len) {
      s[len] = '0';
   }
   
   s[correctSize] = '\0';
}

