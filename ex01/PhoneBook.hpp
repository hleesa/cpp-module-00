#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <sstream>

const size_t phoneBookSize = 8;
const size_t width = 10;

class PhoneBook {

private:
	size_t idx;
	const size_t size;
	Contact contacts[phoneBookSize];

	void addPrompt(size_t idx);

	void searchPrompt(void);

	void printSearchColum(void);

	void printSearchContent(size_t i, Contact *contact);

	size_t min(size_t lhs, size_t rhs);

	bool isRightIdx(std::string input);

	void printSearchError(void);

	void addDummyData(void);

public:
	PhoneBook();

	~PhoneBook();

	void add(void);

	void search(void);

	void exit(void);

	void prompt(void);
};

#endif //PHONEBOOK_HPP
