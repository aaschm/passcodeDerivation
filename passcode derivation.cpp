/*
Program: Passcode Derviation
Summary: Analyze a textfile of keys corresponding to a passscode, and determine the shortest possible secret passcode. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

//secuirty check 1: cppcheck without any errors 

std::vector<char> bubbleSort(const std::vector<char>& v); 

void uniqueValues(const std::vector<char>& v,std::vector<char>& v1);

void printValues(const std::vector<char>& v);

void pushingFinalPasscode(const std::vector<char>& v, const std::vector<char>& v1, std::vector<char>& v2);

void swapElements(const std::vector<char> &v, const std::vector<char> &v1, std::vector<char>& v2);

int main(){
    //variable declaration for ifstream/keys within file
    std::string textfile = "keylog.txt"; //security check 2, use of std::string
    std::ifstream in_stream;
    std::string key; 

    //variable declaration for vectors 
    std::vector<std::string> keys;
    std::vector<char> column1; 
    std::vector<char> column2; 
    std::vector<char> column3; 
    std::vector<char> sortedColumn1; 
    std::vector<char> sortedColumn2; 
    std::vector<char> sortedColumn3; 
    std::vector<char> unique;
    std::vector<char> unique1; 
    std::vector<char> unique2;  
    std::vector<char> finalPasscode; 

    //open keylog.txt file 
    in_stream.open(textfile);

    //security check 3 File IO
    //if file falis to open
    if(in_stream.fail()){
        std::cout << "Input file failed to open";
        //end program and exit 
        exit(1);
    }

    //read all keys in file, and push back into "keys" vector
    std::cout << "Reading Keys \n"; 
    while(std::getline (in_stream, key)){
        std::string regExpStr = "[0-9]+"; //security check 4 (check that all keys are integer characters before pushing)
        std::regex rgx(regExpStr);
        if(std::regex_match(key,rgx))
            keys.push_back(key);
    }

    //separate keys by 0th,1st,and 2nd element, and store in individaul vectors
    for(unsigned long i = 0; i < keys.size(); i++){
        column1.push_back(keys[i][0]); 
        column2.push_back(keys[i][1]);
        column3.push_back(keys[i][2]); 
    }

    //call bubble sort algorithm to sort elements in ascending order 
    sortedColumn1 = bubbleSort(column1);
    sortedColumn2 = bubbleSort(column2);
    sortedColumn3 = bubbleSort(column3);

    //extract only unique values from the sorted vectors 
    uniqueValues(sortedColumn1, unique);
    uniqueValues(sortedColumn2, unique1);
    uniqueValues(sortedColumn3, unique2);
    
    //create an initial passcode by comparing characters in unique vector
    //abd extracting unique values from all 3 unique vectors
    pushingFinalPasscode(unique, unique1, finalPasscode);
    pushingFinalPasscode(unique1, finalPasscode, finalPasscode);
    pushingFinalPasscode(unique2, finalPasscode, finalPasscode); 
    
    //call function to make swaps based on keys, swapping elements in finalPasscode
    //if the order of the elements in finalPasscode do not match the order of elements
    //in key.
    swapElements(column1, column2, finalPasscode);
    swapElements(column2, column3, finalPasscode);


    //print finalPasscode to console
    printValues(finalPasscode);

    //close in_stream
    in_stream.close(); 

    //return 0 for successful code run 
    return 0; 
}

//sorts vector in ascending order and returns new vector 
std::vector<char> bubbleSort(const std::vector<char>& v){
    std::vector<char> v2; 

    int length = v.size(); 

    for(int i = 0; i < length; i++){
        v2.push_back(v[i]);
    }

    for(int i = 0; i < length-1; i++){
        for(int j = 0; j < length - i - 1; j++){
            if(v2[j] > v2[j+1]){
                std::swap(v2[j], v2[j+1]); 
            }
        }
    }
    return v2; 
}

//removes duplicates from column vectors
void uniqueValues(const std::vector<char>& v, std::vector<char>& v1){
    for(unsigned long i = 0; i < v.size(); i++){
        if(v[i] != v[i+1]){
            v1.push_back(v[i]);
        }
        else if(i == v.size()-1 && v[i] != v[i-1]){
            v1.push_back(v[i]);
        }
        else{
            continue; 
        }
    }
}

//prints elements of vector to console
void printValues(const std::vector<char>& v){
    for(unsigned long i = 0; i < v.size(); i++){
        std::cout << v[i];
    }
    std::cout << " \n";
}

//evaluates vector of unique column values, and creates an initial passcode state
void pushingFinalPasscode(const std::vector<char>& v, const std::vector<char>& v1, std::vector<char>& v2){
    for(unsigned long i = 0; i < v.size(); i++){
        for(unsigned long j = 0; j < v1.size(); j++){
            if(v[i] == v1[j]){
                break; 
            }

            else if(j == v1.size()-1){
                v2.push_back(v[i]);
            }
            else{
                continue; 
            }
        }
    }
}

//swaps elemnts in final passcode if key ordering does not match initial passcode state
void swapElements(const std::vector<char> &v, const std::vector<char> &v1, std::vector<char>& v2){
    int firstElement = 0; 
    int secondElement = 0; 

    for(unsigned long i = 0; i < v.size(); i++){
        for(unsigned long j = 0; j < v2.size(); j++){
            if(v[i] == v2[j]){
                firstElement = j; 
            }

            if(v1[i] == v2[j]){
                secondElement = j; 
            }
        }
        if(firstElement > secondElement){
             std::swap(v2[firstElement], v2[secondElement]);
             swapElements(v, v1, v2); //recursive function, if swap occurs rerun from the beginning
        }
    }
}



