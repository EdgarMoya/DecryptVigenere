#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "decrypt.h"
#define LENGTH 26
using namespace std;

int main(int argc, char const *argv[]){
    
    //Alfabeto que se va a utilizar
    char alph[LENGTH] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
    'p','q','r','s','t','u','v','w','x','y','z'};

    if(argc != 3){
        cout << "Data entry error." << endl;
        exit(1);
    }

    //Reading name of file and key
    string file(argv[1]);  //first parameter is the "file.txt" to decrypt
    string key(argv[2]);   //second parameter is the key
    key = toLower(key);

    //Read file
    string line, lines;
    ifstream readFile(file);
    while(getline(readFile, line)){lines += line;}
    readFile.close();

    lines = toLower(lines);

    //Write file
    ofstream writeFile;
    writeFile.open("decrypt.txt");
    if(writeFile.is_open()){
        writeFile << decrypt(lines, generateKey(lines, key), alph) << endl;
        cout << "File created successfully!!" << endl;
    }else{
        cout << "Something went wrong" << endl; 
    }
    writeFile.close();

    return 0;
}