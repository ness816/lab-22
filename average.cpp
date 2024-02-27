#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

int main(int argc,char *argv[]){
    double sum = 0.0;
    if(argc > 1){ 
        for (int i = 1; i < argc; i++) {
            sum += atof(argv[i]); 
        }
        cout << "---------------------------------" << endl;
        cout << "Average of " << argc - 1 << " numbers = " << sum / (argc - 1) << endl; // Calculate and print average
        cout << "---------------------------------" << endl;
    }
    else {
        cout << "Please input numbers to find average." << endl;
    }
    return 0;
}
