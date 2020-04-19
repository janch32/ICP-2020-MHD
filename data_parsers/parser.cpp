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

void Parser::OpenFile(string file){
    if(ParsedFile == nullptr)
        ParsedFile = new ifstream(file.c_str());

    if(!ParsedFile->is_open())
        ParsedFile->open(file.c_str());
}

int Parser::ReadLine(string** parts){

    string line;
    if(!getline(*ParsedFile, line)) return 0;
    //if(get)
    // TODO dokončit
}

void Parser::CloseFile(){
    if(ParsedFile == nullptr) return;

    if(ParsedFile->is_open()) ParsedFile->close();

    delete ParsedFile;
    ParsedFile = nullptr;
}
