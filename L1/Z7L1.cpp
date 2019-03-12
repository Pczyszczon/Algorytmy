#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> getFromFile(const string& filePath){
    vector<int> numbers;
    fstream myFile;
    string line;
    char character;
    string number;

    myFile.open(filePath.c_str());
    getline(myFile,line);
    for (int i=1; i<line.size()-1; ++i){
        if (line[i]!=',')
            number += line[i];
        else{
            numbers.push_back(stoi(number));
            number = "";
        }
    }
    myFile.close();
    return numbers;
}

void writeToFile(vector<int> v, const string & fileName){
    fstream myFile;
    myFile.open(fileName.c_str(), ios_base::out);
    myFile << "(";
    for (int i=0; i<v.size(); i++){
        myFile << v[i];
        if (i==v.size()-1)
            myFile << ")";
        else
            myFile << ",";
    }
    myFile.close();
}

vector<int> multiply(vector<int> & a, vector<int> & b){
    vector<int> c(a.size()+b.size()-1);
    for (int i=0; i<a.size(); i++)
        for (int j=0; j<b.size(); j++)
            c[i+j] += a[i] * b[j];
    return c;
}

int main()
{
    vector<int> a = getFromFile("a.txt");
    vector<int> b = getFromFile("b.txt");
    vector<int> c = multiply(a,b);

    writeToFile(c,"c.txt");
    return 0;
}
