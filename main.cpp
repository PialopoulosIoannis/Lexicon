#include "lexicon.h" 
#include <iostream>

int main() { 
 lexicon l; 
 l.insert("the");
 l.insert("boy");
 l.insert("and");
 l.insert("the");
 l.insert("wolf");
 
 cout << "The word 'the' is found " << l.lookup("the") << " time(s)" << endl;
 cout << "The word 'and' is found at depth " << l.depth("and") << endl;
 
 cout << l;
 
 l.replace("boy", "wolf");
 
 cout << "After replacement:\n";
 cout << l;
 
 cout << "Now the word 'and' is found at depth " << l.depth("and") << endl;
}
