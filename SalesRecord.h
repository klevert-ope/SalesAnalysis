#ifndef SALESANALYSIS_SALESRECORD_H
#define SALESANALYSIS_SALESRECORD_H

#include <string>

struct SalesRecord {
    int rowID;
    std::string orderID;
    std::string orderDate;
    std::string shipDate;
    std::string shipMode;
    std::string customerID;
    std::string customerName;
    std::string segment;
    std::string country;
    std::string city;
    std::string state;
    std::string postalCode;
    std::string region;
    std::string productID;
    std::string category;
    std::string subCategory;
    std::string productName;
    double sales;
    int quantity;
    double discount;
    double profit;
};


#endif //SALESANALYSIS_SALESRECORD_H
