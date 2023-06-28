#include "PhoneBook.hpp"

enum cmdEnum {
	ADD,
	SEARCH,
	EXIT,
};

int main(void) {

	PhoneBook phoneBook;

	std::string cmdList[] = {"ADD", "SEARCH", "EXIT"};
	std::string command;
	while (true) {
		phoneBook.prompt();
		if(!std::getline(std::cin, command)) {
			break;
		}
		else if (command == cmdList[ADD]) {
			phoneBook.add();
		}
		else  if (command == cmdList[SEARCH]) {
			phoneBook.search();
		}
		else if (command == cmdList[EXIT]) {
			phoneBook.exit();
		}
	}
	return 0;
}