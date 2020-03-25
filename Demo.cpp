/**
 * Demo program for Gimatriya calculation.
 * 
 * Date: 2020-02
 */

#include "PhoneticFinder.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	string text = "Dond vorri be haffy";
	string text2 = "backflip xxyy" ;
	string text3 = "zeus  siZe yyy";
	string text4 = "this is a new project";
	cout << phonetic::find(text4, "pruJecd") << endl;// should print "project"
	cout << phonetic::find(text3, "size") << endl;// should print "siZE"
	cout << phonetic::find(text, "dont") << endl;   // should print "Dond"
	cout << phonetic::find(text, "worry") << endl;   // should print "vorri"
	cout << phonetic::find(text, "Be") << endl;   // should print "be"
	cout << phonetic::find(text, "happy") << endl;   // should print "haffy"
	try {
		cout << phonetic::find(text, "happ") << endl;   // should throw an exception - "happ" is not a full word in the sentence
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'happ' in the text"
	}
	try{
		cout<<phonetic::find(text,"happpy")<<endl;
	}catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'happpy' in the text"
	}
	try{
		cout<<phonetic::find(text,"")<<endl;
	}catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "null string"
	}
	try{
		cout<<phonetic::find("","haffy")<<endl;
	}catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "given sentnce is null"
	}
}