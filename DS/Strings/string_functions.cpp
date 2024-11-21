#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char str[50];
    cin.getline(str, 50);
    int len = 0;
    for(int i =0; str[i]!='\0'; i++){ //ALWAYS use '\0' and not "\0" because the former is a character literal and the latter is a string literal
        len++;
    }
    cout << "String length is: " << len << endl;
    //Used to find length of a string

    char str1[100], str2[50];
    cin >> str1;
    cin >> str2;
    int i=0, j=0;
    while(str1[i]!='\0'){
        i++;
    }
    while(str2[j]!='\0'){
        str1[i] = str[2];
        i++;
        j++;
    }
    //Code above is used to concatenate 2 strings
    cout << "Another way to find string length is: " << strlen(str) << endl;
    cout << "Another way to concatenate string is: " << strcat(str1, str2) << endl;
    //An easy way to copy one string to another is by using strcpy
    strcpy(str1, str2);
    //str2 now has the contents of str2
    //Main advantage of using strcpy is appending the '\0'

    //After inputting an integer, we flush the buffer using fflush
    //Another way of inputting a string is by using gets() 
}