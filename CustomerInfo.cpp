#include "CustomerInfo.h"


CustomerInfo::CustomerInfo(const std::string& nationalIDNumber
        ,   const std::string& firstname
        ,   const std::string& lastname
        ,   const std::string& fathersname
        ,   const std::string& mothersname
        ,   const std::string& presentaddr
        ,   const std::string& permanentaddr
        ,   const int& dob
        ,   const int& mob
        ,   const int& yob
        ,   const SortedType<PhoneNumber>& numberList)
        :   Person(nationalIDNumber
        ,   firstname
        ,   lastname
        ,   fathersname
        ,   mothersname
        ,   presentaddr
        ,   permanentaddr
        ,   dob
        ,   mob
        ,   yob)
        ,   allNumbers(numberList) {
}

CustomerInfo::CustomerInfo(const CustomerInfo& obj)
	: Person(obj)
	, allNumbers(obj.allNumbers){
}

CustomerInfo& CustomerInfo::operator=(const CustomerInfo& src){
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

    this->allNumbers.MakeEmpty();
    this->allNumbers = src.allNumbers;

    return *this;
}


CustomerInfo::~CustomerInfo(){
}

void CustomerInfo::InsertNewNumber(const std::string& number, const std::string& operatorName){

	//Exception should be thrown.	
	if (this->allNumbers.IsFull()){
		std::cout << "Can not insert more than " << this->allNumbers.GetLength();
		std::cout << " numbers in the DB for a person." << std::endl;
		return;
	}

	PhoneNumber newNumber(number, operatorName);
	this->allNumbers.PutItem(newNumber);
}

void CustomerInfo::ChangeOperatorForNumber(const std::string& number, const std::string& operatorName){

	bool found = false;
	PhoneNumber existingNumber(number,"DummyOperator");
	existingNumber = this->allNumbers.GetItem(existingNumber,found);
	if(found){
		this->allNumbers.DeleteItem(existingNumber);
        existingNumber.SetOperatorName(operatorName);
		this->allNumbers.PutItem(existingNumber);
	}
}

bool CustomerInfo::HasNumber(const std::string& number) const{
	PhoneNumber existingNumber(number,"DummyOperator");
	bool found = false;
	existingNumber = this->allNumbers.GetItem(existingNumber,found);

	return found;
}

bool CustomerInfo::operator== (const CustomerInfo& rhs) {
	return (this->nID == rhs.GetNid());
}

bool CustomerInfo::operator!= (const CustomerInfo& rhs) {
	return (this->nID == rhs.GetNid());
}

bool CustomerInfo::operator< (const CustomerInfo& rhs) {
    return (this->nID < rhs.GetNid());
}

bool CustomerInfo::operator> (const CustomerInfo& rhs) {
    return (this->nID > rhs.GetNid());
}

void CustomerInfo::Print(){
	cout<<this.number<<endl;
	
}

std::ostream &operator<<(std::ostream &output, const CustomerInfo& customer) {

    std::string printString("---------------------------------------------\n") ;
    printString += ("Customer NID: " + customer.nID + "\n");
    printString += ("Customer Name: " + customer.firstName +" " + customer.lastName + "\n");
    printString += ("Father's Name: " + customer.fathersName + "\n");
    printString += ("Mother's Name: " + customer.mothersName + "\n");
    printString += ("Present Address: " + customer.presentAddress + "\n");
    printString += ("Permanent Address: " + customer.permanentAddress + "\n");
    printString += ("Date of Birth:" + customer.GetDateOfBirth() + "\n");
    printString += ("---------------------------------------------\n");
    output << printString;

    output << customer.allNumbers;

    return output;
}
