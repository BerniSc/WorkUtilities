#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

static vector<vector<string>> files;

void printLines(const vector<vector<string>> &vec) {
    cout << "  Printing Vector..." << endl;
    for(uint i = 0; i < vec.size(); i++) {
        for(uint j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << endl;
        }
        cout << "     newFile" << endl;
    }
    cout << " === Done === " << endl;    
}

void readInData(const string& fileName, vector<vector<string>> &dataDestination) {
    ifstream myFile;
    myFile.open(fileName);

    vector<string> paragraph;
    if(myFile.is_open()) {
        while(myFile) {
            string inputData;
            getline(myFile, inputData);
            paragraph.push_back(inputData);
        }
        dataDestination.push_back(paragraph);
        myFile.close();
    }

    cout << "Read File " << fileName << " into Data!" << endl;
}

void writeOutData(const string& fileName, vector<string> &data) {
    ofstream myFile;
    myFile.open(fileName);

    for(const auto line : data) {
	    myFile << line << "\n";
    }
    myFile.close();
}

vector<string> getFilePaths(const string& startDirectory, const string fileExtension) {
    vector<string> paths;
    for(const auto& entry : fs::recursive_directory_iterator(startDirectory)) {
        if(entry.path().extension() == fileExtension) {
            cout << "Found " << entry.path().string() << " as Path and added it to the Path-List!" << endl;
            paths.push_back(entry.path().string());
        }
    }
    cout << " === Done === " << endl;
    return paths;
}

vector<string> seperateString(string toSeperate, const char *seperator) {
    vector<string> result;
    result.clear();
    char* dataAsPointer = &toSeperate[0];
    char* token = strtok(dataAsPointer, seperator);
    result.push_back(token);
    
    while(token != NULL) {
        token = strtok(NULL, seperator);
        if(token != NULL) result.push_back(token);
    }
    
    return result;
}

int getFirstOccurence(string largeString, string substring) {
    return largeString.find(substring);
}

void processData(vector<vector<string>> files, const vector<string>& filePaths) {
    for(uint i = 0; i < files.size(); i++) {
        //string newFileName = filePaths[i] + ".new";
        //writeOutData(newFileName, files[i]);
        cout << getFirstOccurence(files[0][0], "moin") << endl;
        cout << getFirstOccurence(files[0][1], "moin") << endl;
    }
}

int main() {    
    /** Whole Block fo reading in and processing multiple files **/
    //Get Files with Ending .txt recursively from current Directory of executable
    vector<string> filePaths = getFilePaths(".", ".txt");

    for(const auto path : filePaths) {
        readInData(path, files);
    }
    cout << " === Done === " << endl;
    /** End Of Block **/ 
  
    printLines(files);
    //processData(files, filePaths);

    return 0;
}