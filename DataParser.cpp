#include "DataParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

std::vector<SalesRecord> DataParser::parseCSV(const std::string& filename) {
    std::vector<SalesRecord> records;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return records;
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        SalesRecord record;
        std::string value;

        // Read each field and store it in the appropriate record member
        std::getline(ss, value, ',');
        try {
            record.rowID = std::stoi(value);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid value for rowID: " << value << std::endl;
            record.rowID = 0;
        }

        std::getline(ss, record.orderID, ',');
        std::getline(ss, record.orderDate, ',');
        std::getline(ss, record.shipDate, ',');
        std::getline(ss, record.shipMode, ',');
        std::getline(ss, record.customerID, ',');
        std::getline(ss, record.customerName, ',');
        std::getline(ss, record.segment, ',');
        std::getline(ss, record.country, ',');
        std::getline(ss, record.city, ',');
        std::getline(ss, record.state, ',');
        std::getline(ss, record.postalCode, ',');
        std::getline(ss, record.region, ',');
        std::getline(ss, record.productID, ',');
        std::getline(ss, record.category, ',');
        std::getline(ss, record.subCategory, ',');
        std::getline(ss, record.productName, ',');

        // Parse and assign sales value
        std::getline(ss, value, ',');
        try {
            record.sales = std::stod(value);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid value for sales: " << value << std::endl;
            record.sales = 0.0;
        }

        // Parse and assign quantity value
        std::getline(ss, value, ',');
        try {
            record.quantity = std::stoi(value);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid value for quantity: " << value << std::endl;
            record.quantity = 0;
        }

        // Parse and assign discount value
        std::getline(ss, value, ',');
        try {
            record.discount = std::stod(value);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid value for discount: " << value << std::endl;
            record.discount = 0.0;
        }

        // Parse and assign profit value
        std::getline(ss, value, ',');
        try {
            record.profit = std::stod(value);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid value for profit: " << value << std::endl;
            record.profit = 0.0;
        }

        records.push_back(record);
    }

    file.close();
    return records;
}
