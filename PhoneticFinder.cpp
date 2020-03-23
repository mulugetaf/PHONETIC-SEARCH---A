#include "PhoneticFinder.hpp"
#include <sstream>
#include <iostream>
#include<bits/stdc++.h> 

using namespace std;

namespace phonetic{
string find(string s1,string s2){ 

int length = 0;
int words =1;

for (int i = 0; s1[i]!='\0'; i++){
    length ++;
}
for (int i=0; i < length; i++){

    if(s1[i] == ' '){
        words++;
    }
}

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

}

    throw (s2 + " is not a full word in the sentence");    
    
    return s2;
    };



bool checkWords(string array,string s2){
transform(array.begin(), array.end(), array.begin(), ::tolower);
transform(s2.begin(), s2.end(), s2.begin(), ::tolower);


if(array == s2) return true;

for (int i =0; i < array.length(); i++){

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
        if(s2[i] !='b' && s2[i]!= 'f' && array[i] == 'p') return false;
    }

    else if(array[i] == 'c' || array[i] == 'k' || array[i] == 'q'){
        if(s2[i] !='c' && s2[i]!= 'k' && array[i] == 'q') return false;
    }

   else if(array[i] != s2[i]){
        return false;
   }
    
} 
return true;
}

   
}