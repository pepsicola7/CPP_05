/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:19:02 by peli              #+#    #+#             */
/*   Updated: 2025/06/05 17:57:27 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1); // Grade 1 (can do everything)
        Bureaucrat bob("Bob", 140);   // Too low for most
        Bureaucrat charlie("Charlie", 50); // OK for robotomy

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << "\n--- Trying to sign with Bob (too low) ---\n";
        bob.signForm(shrub);
        bob.signForm(robot);
        bob.signForm(pardon);

        std::cout << "\n--- Signing with Alice ---\n";
        alice.signForm(shrub);
        alice.signForm(robot);
        alice.signForm(pardon);

        std::cout << "\n--- Executing forms ---\n";
        bob.executeForm(shrub);      // Should fail (exec grade too low)
        charlie.executeForm(robot);  // May succeed
        alice.executeForm(pardon);   // Should succeed

        std::cout << "\n--- Executing shrubbery form with Alice ---\n";
        alice.executeForm(shrub);    // Should succeed

    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

