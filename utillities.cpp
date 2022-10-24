#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
int datatypehandler(string datatype) {
    if (datatype == "-rand") {
        return 0;
    } else if (datatype == "-sorted") {
        return 1;
    } else if (datatype == "-rev") {
        return 2;
    } else if (datatype == "-nsorted") {
        return 3;
    } else {
        return -1;
    }
}
bool numberChecker(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}

void filehandler(string filename, int a[], int& n) {
    ifstream myfile;
    myfile.open(filename);
    myfile >> n;
    for (int i = 0; i < n; i++) {
        myfile >> a[i];
    }
    myfile.close();
}

void printarray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}