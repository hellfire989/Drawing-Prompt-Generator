#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

std::string wordsFileName = "words.txt";
std::string adjectivesFileName = "adjectives.txt";

std::vector<std::string> fillVectorWithWords(std::string fileName){
    //Fill a vector with words from a given file
    std::vector<std::string> words;
    std::ifstream wordsFile;
    wordsFile.open(fileName);
    std::string line;

    if(wordsFile.is_open()){
        while(wordsFile){
            std::getline(wordsFile, line);
            words.push_back(line);
        }
    }

    return words;
}

int main(){
    std::vector<std::string> words = fillVectorWithWords(wordsFileName);
    std::vector<std::string> adjectives = fillVectorWithWords(adjectivesFileName);

    // Get system time in milliseconds to avoid possible duplicate words
    auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    //Get random seed
    srand(milli);
    int wordIndex = rand() % words.size();
    int adjIndex = rand() % adjectives.size();

    std::cout << adjectives.at(adjIndex) << " " << words.at(wordIndex) << std::endl;

    return 0;
}