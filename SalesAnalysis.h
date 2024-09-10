#ifndef SALESANALYSIS_SALESANALYSIS_H
#define SALESANALYSIS_SALESANALYSIS_H

#include <vector>
#include <string>
#include "SalesRecord.h"

class SalesAnalysis {
public:
    static double calculateTotalSales(const std::vector<SalesRecord>& records);
    static double calculateTotalProfit(const std::vector<SalesRecord>& records);
    static void compareSalesByRegion(const std::vector<SalesRecord>& records);
    static void compareSalesByCategory(const std::vector<SalesRecord>& records);
    static void compareSalesByProduct(const std::vector<SalesRecord>& records);
    static void findHighestSellingProduct(const std::vector<SalesRecord>& records);
};


#endif //SALESANALYSIS_SALESANALYSIS_H
