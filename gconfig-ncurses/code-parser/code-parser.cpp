// SPDX-License-Identifier: GPL-3.0-or-later

#include <iostream>
#include <fstream>
#include <string>

#include "../exception.h"
#include "code-parser.h"

using namespace std;

// --------------------------------------------------
// class CodeFile

CodeFile::CodeFile() : m_filePath(nullptr), m_fileContent(nullptr)
{}

CodeFile::CodeFile(const string &filePath) : m_fileContent(nullptr)
{
    AttachFilePath(filePath);
}

CodeFile::~CodeFile()
{
    if (m_filePath) delete m_filePath;
    if (m_fileContent) delete m_fileContent;
}

void CodeFile::AttachFilePath(const string &filePath)
{
    if (m_filePath)
        throw Exception("Already attached.");
    m_filePath = new string(filePath.c_str());
}

void CodeFile::InitFileContent()
{
    if (m_fileContent)
        throw Exception("Already initialized.");
    if (!m_filePath)
        throw Exception("m_filePath hasn't attached yet.");
    ifstream file;
    file.open(*m_filePath);
    if (!file.is_open()) {
        string msg;
        msg += "Can't open the file \"";
        msg += m_filePath->c_str();
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
}

// --------------------------------------------------
// class CodeParser

CodeParser::CodeParser()
{
    m_fileList = new list<CodeFile *>;
}

CodeParser::~CodeParser()
{
    delete m_fileList;
}

void CodeParser::AddFile(const_str_t filePath)
{
    AddFile(string(filePath));
}

void CodeParser::AddFile(const string &filePath)
{
    // AddStringContent(filePath.c_str(), content);
    CodeFile *file = new CodeFile(filePath);
    file->InitFileContent();
    m_fileList->push_back(file);
}

// void CodeParser::AddStringContent(const_str_t filePath, const_str_t strContent)
// {
//     AddStringContent(filePath, string(strContent));
// }

// void CodeParser::AddStringContent(const_str_t filePath, const string &strContent)
// {}
