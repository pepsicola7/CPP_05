/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:13:41 by peli              #+#    #+#             */
/*   Updated: 2025/06/05 17:57:44 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm",25, 5), Target(target)
{
};

PresidentialPardonForm::~PresidentialPardonForm()
{
};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!get_signed())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > grade_execute())
        throw GradeTooLowException();
    std::cout << Target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};
