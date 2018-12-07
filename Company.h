//
// Created by SHAIKH SHAWON AREFIN SHIMON on 11/14/18.
//

#ifndef ASSIGNMENT_02_COMPANY_H
#define ASSIGNMENT_02_COMPANY_H

#include "SortedType.h"
#include "CustomerInfo.h"
#include <string>

class Company {
public:
    Company(const std::string& name  = {}
            , const SortedType<CustomerInfo>& customerList  = SortedType<CustomerInfo>()) ;

    Company(Company&& src);

    bool operator==(const Company& rhs);
    bool operator!=(const Company& rhs);
    bool operator<(const Company& rhs);
    bool operator>(const Company& rhs);

    std::string GetCompanyName();
    bool AddCustomer(CustomerInfo newCustomer);
    bool DeleteCustomer(CustomerInfo existingCustomer);
    bool AddNumberForExistingCustomer(const std::string &nid, const std::string &phoneNumber,
                                      const std::string &operatorName);
    bool UpdateOperatorForExistingNumber(const std::string &nid, const std::string &phoneNumber,
                                         const std::string &operatorName);

    friend std::ostream &operator<<(std::ostream &output, const Company& company);

private:
    std::string companyName;
    SortedType<CustomerInfo> customerList;
};


#endif //ASSIGNMENT_02_COMPANY_H

