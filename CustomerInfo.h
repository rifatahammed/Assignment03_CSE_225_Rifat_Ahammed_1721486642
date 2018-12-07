#ifndef CUSTOMERINFO_H_INCLUDED
#define CUSTOMERINFO_H_INCLUDED

#include "Person.h"
#include "SortedType.cpp"
#include "PhoneNumber.h"
#include <iostream>

class CustomerInfo :  public Person
{
public:

    CustomerInfo(const std::string& nationalIDNumber = {}
            ,   const std::string& firstname = {}
            ,   const std::string& lastname = {}
            ,   const std::string& fathersname = {}
            ,   const std::string& mothersname = {}
            ,   const std::string& presentaddr = {}
            ,   const std::string& permanentaddr = {}
            ,   const int& dob = 1
            ,   const int& mob = 1
            ,   const int& yob = 1975
            ,   const SortedType<PhoneNumber>& numberList = SortedType<PhoneNumber>());

	CustomerInfo(const CustomerInfo& obj);
	CustomerInfo& operator=(const CustomerInfo& src);

	~CustomerInfo();

	void InsertNewNumber(const std::string &number, const std::string &operatorName);
	void ChangeOperatorForNumber(const std::string &number, const std::string &operatorName);
	bool HasNumber(const std::string &number) const;

	bool operator== (const CustomerInfo& rhs);
	bool operator!= (const CustomerInfo& rhs);
	bool operator< (const CustomerInfo& rhs);
	bool operator> (const CustomerInfo& rhs);


    friend std::ostream &operator<<(std::ostream &output, const CustomerInfo &customer );
protected:
	SortedType<PhoneNumber> allNumbers;
};

#endif
