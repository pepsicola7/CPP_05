/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiqi <peiqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:48:16 by peli              #+#    #+#             */
/*   Updated: 2025/06/06 16:34:09 by peiqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), Target(target)
{
};

RobotomyRequestForm::~RobotomyRequestForm()
{
};

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!get_signed())
        throw std::runtime_error("AForm is not signed");
    if (executor.getGrade() > grade_execute())
        throw GradeTooLowException();
    std::cout << "Derrrrrr~~~" << std::endl;

    if (rand() % 2 == 0)
        std::cout << Target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << Target << " robotomy failed" << std::endl;
};
