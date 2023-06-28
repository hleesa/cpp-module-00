#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size(phoneBookSize) {
	idx = 0;
//	addDummyData();
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::prompt(void) {
	std::cout << "Only ADD, SEARCH, EXIT.\n$ ";
	return;
}

void PhoneBook::addPrompt(size_t idx) {
	std::string toContent[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	std::string message = "Enter contact information: " + toContent[idx] + "\n$ ";
	std::cout << message;
	return;
}

void PhoneBook::add() {
	const size_t commandSize = 5;
	std::string command[commandSize];
	size_t commandCount = 0;
	while (commandCount < commandSize) {
		addPrompt(commandCount);
		if (!std::getline(std::cin, command[commandCount])) {
			exit();
		}
		else if (command[commandCount].empty()) {
			continue;
		}
		++commandCount;
	}
	Contact contact(command[0], command[1], command[2], command[3], command[4]);
	contacts[idx % size] = contact;
	++idx;
	return;
}

void PhoneBook::searchPrompt() {
	std::cout << "Enter the index of your phonebook.\n$ ";
	return;
}

void PhoneBook::printSearchColum() {
	std::cout << "|" << std::setw(width) << std::right << "index"
			  << "|" << std::setw(width) << std::right << "first name"
			  << "|" << std::setw(width) << std::right << "last name"
			  << "|" << std::setw(width) << std::right << "nickname" << "|\n";
	return;
}

std::string truncate(std::string str) {
	if (str.length() > width) {
		str = str.substr(0, width - 1) + ".";
	}
	return str;
}

void PhoneBook::printSearchContent(size_t i, Contact *contact) {
	std::cout << "|" << std::setw(width) << std::right << i
			  << "|" << std::setw(width) << std::right
			  << truncate(contact->getFirstName())
			  << "|" << std::setw(width) << std::right
			  << truncate(contact->getLastName())
			  << "|" << std::setw(width) << std::right
			  << truncate(contact->getNickname())
			  << "|\n";
	return;
}

void PhoneBook::printSearchError() {
	std::cout << "Invalid index.\n";
	return;
}

size_t PhoneBook::min(size_t lhs, size_t rhs) {
	if (lhs < rhs)
		return lhs;
	return rhs;
}

bool PhoneBook::isRightIdx(std::string input) {
	if(input.length() != 1 || !std::isdigit(*input.begin()))
		return false;
	std::stringstream ss(input);
	size_t inputIdx;
	ss >> inputIdx;
	if (inputIdx < min(idx, size)) {
		return true;
	}
	return false;
}

void PhoneBook::search(void) {
	printSearchColum();
	for (size_t i = 0; i < min(idx, size); ++i) {
		Contact *contact = contacts + i;
		printSearchContent(i, contact);
	}
	std::string command;
	searchPrompt();
	if (!std::getline(std::cin, command)) {
		exit();
	}
	else if (command.empty()) {
		return;
	}
	else if (isRightIdx(command)) {
		std::stringstream ss(command);
		size_t contactIdx;
		ss >> contactIdx;
		Contact *contact = contacts + contactIdx;
		contact->printAll();
		return;
	}
	printSearchError();
}

void PhoneBook::exit(void) {
	std::exit(EXIT_SUCCESS);
}

void PhoneBook::addDummyData() {
	for (size_t i = 0; i < 7; ++i) {
		char c = i + 'A';
		std::string dummy = std::string(11, c);
		Contact contact(dummy, dummy, dummy, dummy, dummy);
		contacts[idx % size] = contact;
		++idx;
	}
	return;
}