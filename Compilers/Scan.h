#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

struct Token
{
    string type;
    string value;
};

queue<Token>* scanning(string& in_string);


string convert_file_to_string(string& str, string fileName);

void outputFile(queue<Token> s);
