#ifndef SALESANALYSIS_SALESANALYSIS_H
#define SALESANALYSIS_SALESANALYSIS_H

#include <vector>
#include <string>
#include "SalesRecord.h"

class SalesAnalysis {
public:
    static void analyzeSalesByCustomerSegment(const std::vector<SalesRecord> &records);

    static void analyzeSalesTrends(const std::vector<SalesRecord> &records);

    static void analyzeDiscountImpact(const std::vector<SalesRecord> &records);

    static void calculateProfitMargins(const std::vector<SalesRecord> &records);

    static void analyzeSalesByShipMode(const std::vector<SalesRecord> &records);

    static void analyzeCustomerLoyalty(const std::vector<SalesRecord> &records);

    static double calculateSalesGrowth(const std::vector<SalesRecord> &records);

    static void findTopCustomersBySales(const std::vector<SalesRecord> &records);

    static void compareSalesByRegion(const std::vector<SalesRecord> &records);
};


#endif //SALESANALYSIS_SALESANALYSIS_H
