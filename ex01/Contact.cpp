#include "Contact.hpp"

Contact::Contact() {
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
					 std::string phoneNumber, std::string darkestSecret) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void Contact::printAll() {
	std::string message = "first name: " + firstName
						  + "\nlast name: " + lastName
						  + "\nnickname: " + nickname
						  + "\nphone number: " + phoneNumber
						  + "\ndarkest secret: " + darkestSecret + "\n";
	std::cout << message;
	return;
}

std::string Contact::getFirstName(){
	return firstName;
};

std::string Contact::getLastName(){
	return lastName;
}

std::string Contact::getNickname(){
	return nickname;
}
