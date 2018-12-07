#include "Person.h"


Person::Person(const std::string& nationalIDNumber
        ,   const std::string& firstname
        ,   const std::string& lastname
        ,   const std::string& fathersname
        ,   const std::string& mothersname
        ,   const std::string& presentaddr
        ,   const std::string& permanentaddr
        ,   const int& dob
        ,   const int& mob
        ,   const int& yob)
        :   nID(nationalIDNumber)
        ,   firstName(firstname)
        ,   lastName(lastname)
        ,   fathersName(fathersname)
        ,   mothersName(mothersname)
        ,   presentAddress(presentaddr)
        ,   permanentAddress(permanentaddr)
        ,   dateOfBirth(dob)
        ,   monthOfBirth(mob)
        ,   yearOfBirth(yob) {
}


Person::Person(const Person &obj)
		:   nID(obj.nID)
		,   firstName(obj.firstName)
		,   lastName(obj.lastName)
		,   fathersName(obj.fathersName)
		,   mothersName(obj.mothersName)
		,   presentAddress(obj.presentAddress)
		,   permanentAddress(obj.permanentAddress)
		,   dateOfBirth(obj.dateOfBirth)
		,   monthOfBirth(obj.monthOfBirth)
		,   yearOfBirth(obj.yearOfBirth)
{
}


Person& Person::operator=(const Person& src){
	if(this == &src)
		return *this;

	this->nID = src.nID;
	this->firstName = src.firstName;
	this->lastName = src.lastName;
	this->fathersName = src.fathersName;
	this->mothersName = src.mothersName;
	this->presentAddress = src.presentAddress;
	this->permanentAddress = src.permanentAddress;
	this->dateOfBirth = src.dateOfBirth;
	this->monthOfBirth = src.monthOfBirth;
	this->yearOfBirth = src.yearOfBirth;

	return *this;
}

Person::~Person(){
}

std::string Person::GetFirstName() const{
	return this->firstName;
}

std::string Person::GetLastName() const{
	return this->lastName;
}

std::string Person::GetFathersName() const{
	return this->fathersName;
}

std::string Person::GetMothersName() const{
	return this->mothersName;
}

std::string Person::GetPresentAddress() const{
	return this->presentAddress;
}

std::string Person::GetPermanentAddress() const{
	return this->permanentAddress;
}

std::string Person::GetDateOfBirth() const{
	std::string dob = std::to_string(this->dateOfBirth) 
		+ "-" + std::to_string(this->monthOfBirth)
		+ "-" + std::to_string(this->yearOfBirth);
	return dob;
}

std::string Person::GetNid() const{
	return this->nID;
}

void Person::SetFathersName(const std::string &fathersName){
	this->fathersName = fathersName;
}

void Person::SetMothersName(const std::string &mothersName){
	this->mothersName = mothersName;
}

void Person::SetPresentAddress(const std::string &presentAddress){
	this->presentAddress = presentAddress;
}

void Person::SetPermanentAddress(const std::string &permanentAddress){
	this->permanentAddress = permanentAddress;
}

void Person::SetDateOfBirth(int date, int month, int year){
	this->dateOfBirth = date;
	this->monthOfBirth = month;
	this->yearOfBirth = year;
}

void Person::SetNid(const std::string &nid){
	this->nID = nid;
}

bool Person::operator==(const Person& rhs){
	return (this->nID == rhs.GetNid());
}

bool Person::operator!=(const Person& rhs){
    return (this->nID != rhs.GetNid());
}

bool Person::operator<(const Person& rhs){
	return (this->nID < rhs.GetNid());
}

bool Person::operator>(const Person& rhs){
	return (this->nID > rhs.GetNid());
}

