/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiqi <peiqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:13:41 by peli              #+#    #+#             */
/*   Updated: 2025/06/06 16:34:36 by peiqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm",25, 5), Target(target)
{
};

PresidentialPardonForm::~PresidentialPardonForm()
{
};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!get_signed())
        throw std::runtime_error("AForm is not signed");
    if (executor.getGrade() > grade_execute())
        throw GradeTooLowException();
    std::cout << Target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};
