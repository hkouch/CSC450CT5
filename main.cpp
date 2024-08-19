#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to reverse the contents of a file
void reverseFileContents(const string& iFileName, const string& oFileName) {
    ifstream iFile(iFileName);
    ofstream oFile(oFileName);

    if (!iFile.is_open()) {
        cerr << "Error: Could not open " << iFileName << endl;
        return;
    }

    if (!oFile.is_open()) {
        cerr << "Error: Could not open " << oFileName << endl;
        return;
    }

    string content((istreambuf_iterator<char>(iFile)), istreambuf_iterator<char>());
    reverse(content.begin(), content.end());

    oFile << content;

    iFile.close();
    oFile.close();
}

int main() {
    string input;
    string iFileName = "CSC450_CT5_mod5.txt";
    string revFileName = "CSC450-mod5-reverse.txt";

    // Get user input
    cout << "Enter the data you want to append to the file: ";
    getline(cin, input);

    // Append user input to the file
    ofstream oFile(iFileName, ios::app);
    if (!oFile) {
        cerr << "Error: Could not open " << iFileName << endl;
        return 1;
    }

    oFile << input << endl;
    oFile.close();

    // Reverse the contents of the input file and store it in a new file
    reverseFileContents(iFileName, revFileName);

    cout << "Data has been appended to " << iFileName <<
    		" and reversed content saved in " << revFileName << endl;

    cout << "Goodbye. ♥" << endl << endl;
    return 0;
}
