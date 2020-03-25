#include "PhoneticFinder.hpp"
#include <sstream>
#include <iostream>
#include <cassert>
#include <stdexcept>
#include<bits/stdc++.h> 

using namespace std;

namespace phonetic{
string find(string s1,string s2){ 
    if(s2.empty()){
    throw std::invalid_argument("null string exception");
    }
    if(s1.empty()){
         throw std::invalid_argument("given sentnce is null");
    }

int length = 0;
int words =1;
string temp1 = "";

for (int i = 0; s1[i]!='\0'; i++){
    length ++;
}
for (int i=0; i < length; i++){
    if(s1[i] == ' '){
        temp1 = temp1 + ' ';
    for (int j = i+1; j<length; j++)
    {
        if(s1[j] == ' ') {
            i++;
            }
        else {
            j=length;
            }
    }
    words++;
    }
else{
    temp1 = temp1+s1[i];
}
}

s1 = temp1;
int count =0;
string array[words];
string temp ="";

for (int i=0; i < length; i++){
    if(s1[i]!= ' ')temp= temp+s1[i];
    if(s1[i] == ' '){ 

        array[count] = temp;
        temp ="";
        count++;
    }
    
}
array[words-1] = temp;

for (int i = 0; i < words; i++){

    if(array[i].length() == s2.length()){
        if(checkWords(array[i],s2)){
            return array[i];
        }
    }
    else if(checkWords(array[i],s2) && array[i].length() != s2.length()){
            throw std::invalid_argument(s2 + " is not a full word in the sentence");
        
    }

}
throw std::invalid_argument("Did not find the word "+ s2  +" in the text");
    return s2;
    };

    /* boolean function return true if given string 
            equal to string in the sentnce
    */
bool checkWords(string array,string s2){
transform(array.begin(), array.end(), array.begin(), ::tolower);
transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

if(array == s2) return true;
for (int i =0; i < array.length(); i++){
     if((s2[i] == '\0' )&& i == array.length()-1){
        return true;
    }

    if(array[i] == 'v' || array[i] == 'w'){
        if(s2[i] !='v' && s2[i]!= 'w') return false;
    }

    else if(array[i] == 'g' || array[i] == 'j'){
        if(s2[i] !='g' && s2[i]!= 'j') return false;
    }

    else if(array[i] == 's' || array[i] == 'z'){
        if(s2[i] !='s' && s2[i]!= 'z') return false;
    }

    else if(array[i] == 'd' || array[i] == 't'){
        if(s2[i] !='d' && s2[i]!= 't') return false;
    }

    else if(array[i] == 'o' || array[i] == 'u'){
        if(s2[i] !='o' && s2[i]!= 'u') return false;
    }

    else if(array[i] == 'i' || array[i] == 'y'){
        if(s2[i] !='i' && s2[i]!= 'y') return false;
    }

    else if(array[i] == 'b' || array[i] == 'f' || array[i] == 'p'){
        if(s2[i] !='b' && s2[i]!= 'f' && s2[i] != 'p') {
        return false;
        }
    }

    else if(array[i] == 'c' || array[i] == 'k' || array[i] == 'q'){
        if(s2[i] !='c' && s2[i]!= 'k' && s2[i] != 'q') 
        return false;
    }
   else if(s2[i] != array[i]){
       return false;
   }
  
} 
return true;
}

   
}