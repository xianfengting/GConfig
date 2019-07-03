// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef __HEADER_FILE_PROTECTION__CODE_PARSER_H
#define __HEADER_FILE_PROTECTION__CODE_PARSER_H

#include <string>
#include <list>

#include "../object.h"
#include "../typedefs.h"

class CodeFile : public Object
{
public:
    CodeFile();
    CodeFile(const std::string &filePath);
    ~CodeFile();

    void AttachFilePath(const std::string &filePath);
    void InitFileContent();

private:
    std::string *m_filePath;
    std::string *m_fileContent;
};

class CodeParser : public Object
{
public:
    CodeParser();
    virtual ~CodeParser();

    void AddFile(const_str_t filePath);
    void AddFile(const std::string &filePath);
    // void AddStringContent(const_str_t filePath, const_str_t strContent);
    // void AddStringContent(const_str_t filePath, const std::string &strContent);

private:
    std::list<CodeFile *> *m_fileList;
};

#endif
