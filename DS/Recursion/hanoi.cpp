#include<iostream>
using namespace std;

//Algorithm: Move n-1 disks from A to B. Use C as auxilliary for this.
//Biggest disk will be at C now. Move this from A to C.

int TOH(int n, char source, char aux, char dest){
    if(n==1){
        cout << "Move disk from: " << source << " to destination." << endl;
    }
    TOH(n-1, source, dest, aux);
    cout << "Moved" << n << "disks from" << source << "to" << dest << endl;
    TOH(n-1, aux, dest, source);
}
int main(){
    TOH(3,'A', 'B', 'C');
}