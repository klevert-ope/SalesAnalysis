#include "SalesAnalysis.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

// ANSI color codes
const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string MAGENTA = "\033[35m";

// Helper function to convert a date string to year
int extractYear(const std::string& date) {
    std::istringstream iss(date);
    std::string yearStr;
    std::getline(iss, yearStr, '-'); // Assuming date format is YYYY-MM-DD
    return std::stoi(yearStr);
}

void SalesAnalysis::analyzeSalesByCustomerSegment(const std::vector<SalesRecord>& records) {
    std::map<std::string, double> salesBySegment;

    for (const auto& record : records) {
        salesBySegment[record.segment] += record.sales;
    }

    std::cout << MAGENTA << "Sales by Customer Segment:" << RESET << std::endl;
    for (const auto& entry : salesBySegment) {
        std::cout << GREEN << entry.first << ": $" << entry.second << RESET << std::endl;
    }
}

void SalesAnalysis::analyzeSalesTrends(const std::vector<SalesRecord>& records) {
    std::map<int, double> salesByYear;

    for (const auto& record : records) {
        int year = extractYear(record.orderDate);
        salesByYear[year] += record.sales;
    }

    std::cout << MAGENTA << "Sales Trends by Year:" << RESET << std::endl;
    for (const auto& entry : salesByYear) {
        std::cout << GREEN << entry.first << ": $" << entry.second << RESET << std::endl;
    }
}

void SalesAnalysis::analyzeDiscountImpact(const std::vector<SalesRecord>& records) {
    double totalSalesWithDiscount = 0.0;
    double totalSalesWithoutDiscount = 0.0;
    int countWithDiscount = 0;
    int countWithoutDiscount = 0;

    for (const auto& record : records) {
        if (record.discount > 0) {
            totalSalesWithDiscount += record.sales;
            countWithDiscount++;
        } else {
            totalSalesWithoutDiscount += record.sales;
            countWithoutDiscount++;
        }
    }

    std::cout << MAGENTA << "Discount Impact Analysis:" << RESET << std::endl;
    std::cout << GREEN << "Average sales with discount: $"
              << (countWithDiscount > 0 ? totalSalesWithDiscount / countWithDiscount : 0.0) << RESET << std::endl;
    std::cout << GREEN << "Average sales without discount: $"
              << (countWithoutDiscount > 0 ? totalSalesWithoutDiscount / countWithoutDiscount : 0.0) << RESET << std::endl;
}

void SalesAnalysis::calculateProfitMargins(const std::vector<SalesRecord>& records) {
    std::map<std::string, double> profitMarginsByCategory;

    for (const auto& record : records) {
        double profitMargin = (record.sales == 0) ? 0 : (record.profit / record.sales) * 100.0;
        profitMarginsByCategory[record.category] += profitMargin;
    }

    std::cout << MAGENTA << "Profit Margins by Category:" << RESET << std::endl;
    for (const auto& entry : profitMarginsByCategory) {
        std::cout << GREEN << entry.first << ": " << entry.second << "%" << RESET << std::endl;
    }
}

void SalesAnalysis::analyzeSalesByShipMode(const std::vector<SalesRecord>& records) {
    std::map<std::string, double> salesByShipMode;

    for (const auto& record : records) {
        salesByShipMode[record.shipMode] += record.sales;
    }

    std::cout << MAGENTA << "Sales by Shipping Mode:" << RESET << std::endl;
    for (const auto& entry : salesByShipMode) {
        std::cout << GREEN << entry.first << ": $" << entry.second << RESET << std::endl;
    }
}

void SalesAnalysis::analyzeCustomerLoyalty(const std::vector<SalesRecord>& records) {
    std::map<std::string, int> ordersPerCustomer;

    for (const auto& record : records) {
        ordersPerCustomer[record.customerID]++;
    }

    std::cout << MAGENTA << "Customer Loyalty (Orders per Customer):" << RESET << std::endl;
    for (const auto& entry : ordersPerCustomer) {
        std::cout << GREEN << entry.first << ": " << entry.second << " orders" << RESET << std::endl;
    }
}

double SalesAnalysis::calculateSalesGrowth(const std::vector<SalesRecord>& records) {
    std::map<int, double> salesByYear;

    for (const auto& record : records) {
        int year = extractYear(record.orderDate);
        salesByYear[year] += record.sales;
    }

    auto it = salesByYear.begin();
    if (std::distance(it, salesByYear.end()) < 2) {
        std::cout << MAGENTA << "Insufficient data to calculate growth." << RESET << std::endl;
        return 0.0;
    }

    double lastYearSales = std::prev(salesByYear.end())->second;
    double previousYearSales = std::prev(salesByYear.end(), 2)->second;

    double growthRate = ((lastYearSales - previousYearSales) / previousYearSales) * 100;
    std::cout << GREEN << "Sales Growth: " << growthRate << "%" << RESET << std::endl;
    return growthRate;
}

void SalesAnalysis::findTopCustomersBySales(const std::vector<SalesRecord>& records) {
    std::map<std::string, double> salesByCustomer;

    for (const auto& record : records) {
        salesByCustomer[record.customerID] += record.sales;
    }

    // Sort customers by sales
    std::vector<std::pair<std::string, double>> customers(salesByCustomer.begin(), salesByCustomer.end());
    std::sort(customers.begin(), customers.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });

    // Print top 10 customers
    std::cout << MAGENTA << "Top 10 Customers by Sales:" << RESET << std::endl;
    for (size_t i = 0; i < 10 && i < customers.size(); ++i) {
        std::cout << GREEN << customers[i].first << ": $" << customers[i].second << RESET << std::endl;
    }
}

void SalesAnalysis::compareSalesByRegion(const std::vector<SalesRecord>& records) {
    std::map<std::string, double> salesByState;

    for (const auto& record : records) {
        salesByState[record.state] += record.sales;
    }

    std::cout << MAGENTA << "Sales by State:" << RESET << std::endl;
    for (const auto& entry : salesByState) {
        std::cout << GREEN << entry.first << ": $" << entry.second << RESET << std::endl;
    }
}
