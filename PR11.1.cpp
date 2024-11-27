#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countComaTirePairs(const string& filename) {
    ifstream file(filename);
    if (!file) return -1;

    char currentChar, nextChar;
    int count = 0;

    while (file.get(currentChar)) {
        nextChar = file.peek();
        if (currentChar == ',' && nextChar == '-') {
            count++;
        }
       /* file.get();*/
    }

    file.close();
    return count;
}

int main() {
    string filename = "t.txt";
    int result = countComaTirePairs(filename);

    if (result != -1) {
        cout <<"Comma and Dash pairs " << result << endl;
    }

    return 0;
}