#include <iostream>  
#include <string>  
using namespace std;  
  
  
class lexicon {  
 public:  
 lexicon() { root=nullptr;}  
 // ~lexicon() {}  
  
  
  
 void insert(const string &s) {  
 node *q;  
if(root==nullptr) { node *q= new node(s); root=q; return;}  
     q= root;  
   insertHelper(q,s);  
  return;  
}  
  
 int lookup(const string &s) const {  
  if (root==nullptr) return 0;  
  node *q=root;  
  return lookupHelper(q,s);  
 }  
 int depth(const string &s) {  
  int l=0;  
  if (root==nullptr) return -1;  
  node *q=root;  
  return depthHelper(q,s,l);  
 }  
 void replace(const string &s1, const string &s2) {  
  int counterdel = 0;  
  bool firstTime = true;  
  doDeleteNode(root, s1, counterdel, firstTime);  
  for (int i = 0; i < counterdel; i++) insert(s2);  
 }  
  
  
 friend ostream & operator << (ostream &out, const lexicon &l) {  
  printInorder(l.root);  
  return out;  
 }  
  
 private:  
bool k=true;  
int counterdel;  
 struct node {  
 string word;  
 int counter;  
 node *left;  
 node *right;  
 node *wait;  
 node (const string &s) : word(s), counter(1), left(nullptr), right(nullptr), wait(nullptr) {}  
 };  
 node * root;  
  
 void insertHelper( node *&q,const string &s) {  
  if(q!=nullptr && q->word>s) {  insertHelper(q->left,s);}  
  else if(q!=nullptr && q->word<s) {  insertHelper(q->right,s);}  
  else if (q!=nullptr && q->word==s) {q->counter++; return;}  
  else q= new node(s);  
  return;  
 }  
  
  
 int lookupHelper( node *&q,const string &s) const {  
  if (q!=nullptr && q->word>s) {  return lookupHelper(q=q->left,s);}  
  if (q!=nullptr && q->word<s) {  return lookupHelper(q=q->right,s);}  
  if (q!=nullptr && q->word==s) return q->counter;  
  if (q==nullptr) return 0;  //sigoura tha mpei ekei  
 }  
  
 int depthHelper( node *&q,const string &s, int l) const {  
  if (q!=nullptr && q->word>s) {   l++; return depthHelper(q=q->left,s,l);}  
   if (q!=nullptr && q->word<s) {  l++;  return depthHelper(q=q->right,s,l);}  
   if (q!=nullptr && q->word==s) return l;  
   if (q==nullptr) return -1;  
 }  
  
     node *minValueNode(node *n) {  
     while (n->left != nullptr) n = n->left;  
     return n;  
 }  
  
  
 void doDeleteNode(node* &n, const string &key, int &counterdel, bool &k) {  
  if (n == nullptr) return;  
  
  if (key < n->word)  
   return doDeleteNode(n->left, key, counterdel, k);  
  else if (key > n->word)  
   return doDeleteNode(n->right, key, counterdel, k);  
  else {  
   if (k) {  
    counterdel = n->counter;  
    k = false;  
   }  
  
   if (n->left == nullptr && n->right == nullptr) {  
    delete n;  
    n = nullptr;  
   }  
   else if (n->left == nullptr) {  
    node* temp = n->right;  
    delete n;  
    n = temp;  
   }  
   else if (n->right == nullptr) {  
    node* temp = n->left;  
    delete n;  
    n = temp;  
   }  
   else {  
    node* temp = n->left;  
    while (temp->right != nullptr)  
     temp = temp->right;  
    n->word = temp->word;  
    n->counter = temp->counter;  
    doDeleteNode(n->left, temp->word, counterdel, k);  
   }  
  }  
 }  
  
 void static printInorder( const node* node)  {  
  if (node == nullptr) return;  
  printInorder(node->left); // visit left subtree  
   cout << node->word << " "<<node->counter<<endl; // visit node  
  printInorder(node->right); // visit right subtree  
 }  
 };  
  
  
/* 
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
 
*/  
