#include "SalesAnalysis.h"
#include <iostream>
#include <map>

// ANSI color codes
const std::string GREEN = "\033[32m";
const std::string MAGENTA = "\033[35m";

double SalesAnalysis::calculateTotalSales(const std::vector<SalesRecord>& records) {
    double totalSales = 0.0;
    for (const auto& record : records) {
        totalSales += record.sales;
    }
    return totalSales;
}

double SalesAnalysis::calculateTotalProfit(const std::vector<SalesRecord>& records) {
    double totalProfit = 0.0;
    for (const auto& record : records) {
        totalProfit += record.profit;
    }
    return totalProfit;
}

void SalesAnalysis::compareSalesByRegion(const std::vector<SalesRecord>& records) {
    std::map<std::string, double> salesByRegion;

    for (const auto& record : records) {
        salesByRegion[record.region] += record.sales;
    }

    std::cout << MAGENTA << "Sales by Region:" << std::endl;
    for (const auto& entry : salesByRegion) {
        std::cout << GREEN << entry.first << ": $" << entry.second << std::endl;
    }
}

void SalesAnalysis::compareSalesByCategory(const std::vector<SalesRecord>& records) {
    std::map<std::string, double> salesByCategory;

    for (const auto& record : records) {
        salesByCategory[record.category] += record.sales;
    }

    std::cout << MAGENTA << "Sales by Category:" << std::endl;
    for (const auto& entry : salesByCategory) {
        std::cout << GREEN << entry.first << ": $" << entry.second << std::endl;
    }
}
