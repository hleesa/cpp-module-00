#include <iostream>
#include <string>
#include <cctype>

class Megaphone {

private:
	std::string content;

public:
	Megaphone(int argc, char *argv[]) {
		if (argc == 1) {
			content = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		}
		else {
			for (int i = 1; i < argc; ++i) {
				std::string tempString(argv[i]);
				for (size_t j = 0; j < tempString.length(); ++j) {
					tempString[j] = std::toupper(tempString[j]);
				}
				content.append(tempString);
			}
		}
		content.append("\n");
	}

	void speak(void) {
		std::cout << content;
	}
};

int main(int argc, char *argv[]) {
	Megaphone megaphone(argc, argv);
	megaphone.speak();
	return 0;
}