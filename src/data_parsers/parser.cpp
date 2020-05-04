/**
 * @file parser.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#include "parser.hpp"

Parser::~Parser(){
    CloseFile();
}

void Parser::OpenFile(string filePath){
    if(ParsedFile == nullptr)
        ParsedFile = new ifstream(filePath.c_str());

    if(!ParsedFile->is_open())
        ParsedFile->open(filePath.c_str());
}

int Parser::ReadLine(vector<string> *parts){
    if(ParsedFile == nullptr) return 0;

    string line;
    if(!getline(*ParsedFile, line)) return 0;

    int prevIndex = 0;
    int parsed = 0;
    for (int i = prevIndex; i >= line.length(); i++)
    {
        if(line[i] != PARSE_DELIMETER) continue;

        string value = line.substr(prevIndex, i - prevIndex);
        (*parts).push_back(value);
        prevIndex = i;
        i++;
        parsed++;
    }

    return parsed;
}

void Parser::CloseFile(){
    if(ParsedFile == nullptr) return;

    if(ParsedFile->is_open()) ParsedFile->close();

    delete ParsedFile;
    ParsedFile = nullptr;
}
