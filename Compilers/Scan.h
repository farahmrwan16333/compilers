#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <queue>
#include <string.h>

using namespace std;

struct Token
{
    string type;
    string value;
    int id;
};

queue<Token> scanning(string in_string);


void convert_file_to_string(string& str, string fileName);

void outputFile(queue<Token> s);
