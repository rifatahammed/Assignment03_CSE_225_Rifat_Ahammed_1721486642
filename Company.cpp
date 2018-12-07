//
// Created by SHAIKH SHAWON AREFIN SHIMON on 11/14/18.
//

#include "Company.h"


Company::Company(const std::string& name
        , const SortedType<CustomerInfo>& list)
    :   companyName(name)
    ,   customerList(list)
{
}

Company::Company(Company&& src)
    :   companyName(std::string())
    ,   customerList(SortedType<CustomerInfo>())
{
    //*this = std::move(src);
}

bool Company::AddCustomer(CustomerInfo newCustomer) {
    return this->customerList.PutItem(newCustomer);
}

bool Company::DeleteCustomer(CustomerInfo existingCustomer) {
    return this->customerList.DeleteItem(existingCustomer);
}

bool Company::AddNumberForExistingCustomer(const std::string &nid, const std::string &phoneNumber,
                                           const std::string &operatorName) {
    CustomerInfo existingCustomer(nid);
    bool found = false;
    existingCustomer = this->customerList.GetItem(existingCustomer,found);
    if(found){
        this->customerList.DeleteItem(existingCustomer);
        existingCustomer.InsertNewNumber(phoneNumber, operatorName);
        this->customerList.PutItem(existingCustomer);
    }
    return found;
}

bool Company::UpdateOperatorForExistingNumber(const std::string &nid,
                                              const std::string &phoneNumber,
                                              const std::string &operatorName) {
    CustomerInfo existingCustomer(nid);
    bool found = false;
    existingCustomer = this->customerList.GetItem(existingCustomer,found);
    if(found){
        this->customerList.DeleteItem(existingCustomer);
        existingCustomer.ChangeOperatorForNumber(phoneNumber, operatorName);
        this->customerList.PutItem(existingCustomer);
    }
    return found;
}

std::string Company::GetCompanyName(){
    return this->companyName;
}


bool Company::operator== (const Company& rhs) {
    return (this->companyName == rhs.companyName);
}

bool Company::operator!= (const Company& rhs) {
    return (this->companyName != rhs.companyName);
}

bool Company::operator< (const Company& rhs) {
    return (this->companyName < rhs.companyName);
}

bool Company::operator> (const Company& rhs) {
    return (this->companyName > rhs.companyName);
}

std::ostream& operator<<(std::ostream &output, const Company &company) {
    output << "Company Name: " << company.companyName << "\n";
    output << "===============================================" << "\n";
    output << company.customerList;
    output << "===============================================" << "\n";
    return output;
}

