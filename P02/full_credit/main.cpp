#include <ctime>
#include <iostream>
using namespace std;

int main() {

    srand(time(NULL));
    
    int d,r,f, sum;
    cout << "Number of dice? ";
    cin >> d; cin.ignore(32767, '\n');
    cout << "Number of faces per dice? ";
    cin >> f; cin.ignore(32767, '\n');
    cout << "Number of rolls? ";
    cin >> r; cin.ignore(32767, '\n');


    for(int x =0; x <= r-1; x++){
        cout << "Roll " << x << " : ";
        sum = 0;
    for (int i = 0; i <= d-1; i++){
        int random = rand()%6+1;
        cout << random << " " ; 
        sum += random;  
    }
    for (int j = d-1; j== d-1; j++){
        cout << "Sum: "<< sum;
    }
        cout << endl;
    }
}
