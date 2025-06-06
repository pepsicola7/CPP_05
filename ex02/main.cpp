/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiqi <peiqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:19:02 by peli              #+#    #+#             */
/*   Updated: 2025/06/06 16:34:36 by peiqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "--- Creating Bureaucrats ---" << std::endl;
    Bureaucrat bob("Bob", 150);             // trop bas pour tout
    Bureaucrat alice("Alice", 1);           // top grade
    Bureaucrat charlie("Charlie", 45);      // suffisant pour RobotomyRequestForm
    Bureaucrat ford("Ford Prefect", 5);     // suffisant pour PresidentialPardonForm

    std::cout << "\n--- Creating AForms ---" << std::endl;
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Marvin");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << "\n--- Trying to sign with Bob (too low) ---" << std::endl;
    bob.signAForm(shrub);
    bob.signAForm(robot);
    bob.signAForm(pardon);

    std::cout << "\n--- Signing with Alice ---" << std::endl;
    alice.signAForm(shrub);
    alice.signAForm(robot);
    alice.signAForm(pardon);

    std::cout << "\n--- Executing AForms ---" << std::endl;
    bob.executeAForm(shrub);     // trop bas
    charlie.executeAForm(robot); // suffisant pour exec mais pas forcément signé ?
    ford.executeAForm(pardon);   // suffisant si signé

    std::cout << "\n--- Executing shrubbery AForm with Alice ---" << std::endl;
    alice.executeAForm(shrub);   // devrait créer le fichier et afficher success

    std::cout << "\n--- Testing Robotomy multiple times ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        alice.executeAForm(robot);  // 50% chance de réussite
    }

    return 0;
}


