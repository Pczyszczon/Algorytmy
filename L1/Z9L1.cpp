#include <iostream>
#include <fstream>

using namespace std;

void countASCII(const std::string & fileName, int array[]){
    char character;
    ifstream myFile;
    myFile.open(fileName.c_str());
    while (myFile >> character)
        array[character]++;
    myFile.close();
}


int main(){
    int array[127] = {};
    countASCII("Z9L1.txt", array);
    for (int i=0; i<127; i++)
        cout << (char)i << " : " << array[i] << endl;
    return 0;
}
