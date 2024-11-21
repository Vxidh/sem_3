#include<iostream>
using namespace std;
//Very useful way to define a variable and use it throughout. Will use repeatedly throughout stacks and queues.
#define MAX 100
int main(){
    char str[100];
    //Every string terminates with the character '\0'
    //Alternate way of initializing a string is:
    char lolzies[] = "HelloHelloHello";
    cout << lolzies << endl;
    cout << "Enter your words: " << endl; 
    //Interesting thing about endl, it doesn't occupy any memory. \n on the other hand does
    
    //We can input a string by 2 ways, either by directly using cin or by using cin.getline()
    //We use cin for words, cin.getline() for sentences, since cin is just bad and stops reading after a whitespace
    cin >> str;
    cout << str;

    cin.getline(str,50); //Makes sure that there is no input after 50 characters, so it can also handle buffer overflow.
    
}