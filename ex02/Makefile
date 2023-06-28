
CXX			= c++

CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror

RM			= rm -f

SOURCES	=  \
	Account.cpp \
	tests.cpp \

OBJECTS	= $(SOURCES:.cpp=.o)

TARGET	= account

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(TARGET)

re: fclean
	make all

.PHONY: all clean fclean re
