#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include "PhoneNumber.h"
#include <string>

class Person
{
public:
	Person(const std::string& nationalIDNumber = {}
	        ,   const std::string& firstname = {}
	        ,   const std::string& lastname = {}
	        ,   const std::string& fathersname = {}
	        ,   const std::string& mothersname = {}
	        ,   const std::string& presentaddr = {}
	        ,   const std::string& permanentaddr = {}
	        ,   const int& dob = 1
	        ,   const int& mob = 1
	        ,   const int& yob = 1975);

	Person(const Person& obj);
    Person& operator=(const Person& src);
	~Person();

	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetFathersName() const;
	std::string GetMothersName() const;
	std::string GetPresentAddress() const;
	std::string GetPermanentAddress() const;
	std::string GetDateOfBirth() const;
	std::string GetNid() const;

	void SetFathersName(const std::string &fathersName);
	void SetMothersName(const std::string &mothersName);
	void SetPresentAddress(const std::string &presentAddress);
	void SetPermanentAddress(const std::string &permanentAddress);
	void SetDateOfBirth(int date, int month, int year);
	void SetNid(const std::string &nid);

	bool operator==(const Person& rhs);
	bool operator!=(const Person& rhs);
	bool operator<(const Person& rhs);
	bool operator>(const Person& rhs);


protected:
    std::string nID; //11 digits
    std::string firstName;
	std::string lastName;
	std::string fathersName;
	std::string mothersName;
	std::string presentAddress;
	std::string permanentAddress;
	int dateOfBirth;
	int monthOfBirth;
	int yearOfBirth;
};

#endif
