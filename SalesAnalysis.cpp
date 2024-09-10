#include "SalesAnalysis.h"
#include <iostream>
#include <map>

// ANSI color codes
const std::string RESET = "\033[0m";
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

    std::cout << MAGENTA << "Sales by Region:" << RESET << std::endl;
    for (const auto& entry : salesByRegion) {
        std::cout << GREEN << entry.first << ": $" << entry.second << RESET << std::endl;
    }
}

void SalesAnalysis::compareSalesByCategory(const std::vector<SalesRecord>& records) {
    std::map<std::string, double> salesByCategory;

    for (const auto& record : records) {
        salesByCategory[record.category] += record.sales;
    }

    std::cout << MAGENTA << "Sales by Category:" << RESET << std::endl;
    for (const auto& entry : salesByCategory) {
        std::cout << GREEN << entry.first << ": $" << entry.second << RESET << std::endl;
    }
}

void SalesAnalysis::compareSalesByProduct(const std::vector<SalesRecord>& records) {
    // Aggregate sales and quantities by product
    std::map<std::string, std::pair<double, int>> salesByProduct; // <total sales, total quantity>

    for (const auto& record : records) {
        salesByProduct[record.productName].first += record.sales;
        salesByProduct[record.productName].second += record.quantity;
    }

    // Transfer the aggregated data to a vector for sorting
    std::vector<std::pair<std::string, std::pair<double, int>>> productList(salesByProduct.begin(), salesByProduct.end());

    // Sort the vector by quantity in descending order
    std::sort(productList.begin(), productList.end(),
              [](const auto& a, const auto& b) {
                  return a.second.second > b.second.second; // Compare quantities
              });

    // Print the results
    std::cout << MAGENTA << "Sales by Product (Sorted by Quantity):" << RESET << std::endl;
    for (const auto& entry : productList) {
        std::cout << GREEN << entry.first << ": Sales = $" << entry.second.first
                  << ", Quantity = " << entry.second.second << RESET << std::endl;
    }
}

void SalesAnalysis::findHighestSellingProduct(const std::vector<SalesRecord>& records) {
    std::map<std::string, double> salesByProduct;

    for (const auto& record : records) {
        salesByProduct[record.productName] += record.sales;
    }

    auto maxEntry = std::max_element(
            salesByProduct.begin(), salesByProduct.end(),
            [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; }
    );

    if (maxEntry != salesByProduct.end()) {
        std::cout << MAGENTA << "Highest Selling Product:" << RESET << std::endl;
        std::cout << GREEN << maxEntry->first << ": $" << maxEntry->second << RESET << std::endl;
    } else {
        std::cout << MAGENTA << "No sales data available." << RESET << std::endl;
    }
}
