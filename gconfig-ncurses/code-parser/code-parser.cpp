// SPDX-License-Identifier: GPL-3.0-or-later

#include <iostream>
#include <fstream>
#include <string>

#include "../exception.h"
#include "code-parser.h"

using namespace std;

CodeParser::CodeParser()
{}

CodeParser::~CodeParser()
{}

void CodeParser::AddFile(const_str_t filePath)
{
    AddFile(string(filePath));
}

void CodeParser::AddFile(const string &filePath)
{
    ifstream file;
    file.open(filePath);
    if (!file.is_open()) {
        string msg;
        msg += "Can't open the file \"";
        msg += filePath;
        msg += "\".";
        throw Exception(msg);
    }
    file >> noskipws; // Read the file including space and newline characters.
    string content;
    while (!file.eof()) {
        char c;
        file >> c;
        char str[2];
        sprintf(str, "%c", c);
        content.append(str);
    }
    AddStringContent(content);
}

void CodeParser::AddStringContent(const_str_t strContent)
{}

void CodeParser::AddStringContent(const string &strContent)
{}
