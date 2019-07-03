// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef __HEADER_FILE_PROTECTION__CODE_PARSER_H
#define __HEADER_FILE_PROTECTION__CODE_PARSER_H

#include <string>

#include "../object.h"
#include "../typedefs.h"

class CodeParser : public Object
{
public:
    CodeParser();
    virtual ~CodeParser();

    void AddFile(const_str_t filePath);
    void AddFile(const std::string &filePath);
    void AddStringContent(const_str_t strContent);
    void AddStringContent(const std::string &strContent);
};

#endif
