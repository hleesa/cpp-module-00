#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();

	Contact(std::string firstName, std::string lastName, std::string nickname,
			std::string phoneNumber, std::string darkestSecret);

	void printAll(void);

	std::string getFirstName();

	std::string getLastName();

	std::string getNickname();
};

#endif //CONTACT_HPP
