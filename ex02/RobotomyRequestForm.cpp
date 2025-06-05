/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:48:16 by peli              #+#    #+#             */
/*   Updated: 2025/06/05 17:57:48 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), Target(target)
{
};

RobotomyRequestForm::~RobotomyRequestForm()
{
};

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!get_signed())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > grade_execute())
        throw GradeTooLowException();
    std::cout << "Derrrrrr~~~" << std::endl;

    if (rand() % 2 == 0)
        std::cout << Target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << Target << " robotomy failed" << std::endl;
};
