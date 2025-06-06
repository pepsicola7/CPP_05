# nom de l'excutable
TARGET = ./a.out

#Compilateur
CXX = c++

#Flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

#Fichier sources et objets
SRC = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \
	Intern.cpp

OBJ = $(SRC:.cpp=.o)

#regle principale
all: $(TARGET)

re: clean all

#compilation de l'executable
$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o$(TARGET) $(OBJ)

#compilation des fichiers sources en objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Nettoyage
clean:
	rm -f $(OBJ)

#Nettoyage complets
fclean: clean
	rm -rf $(TARGET)

#Regle pour executer le programme
run: $(TARGET)
	./$(TARGET)