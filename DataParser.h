#ifndef SALESANALYSIS_DATAPARSER_H
#define SALESANALYSIS_DATAPARSER_H


#pragma once
#include <vector>
#include <string>
#include "SalesRecord.h"

class DataParser {
public:
    static std::vector<SalesRecord> parseCSV(const std::string &filename);
};


#endif //SALESANALYSIS_DATAPARSER_H
