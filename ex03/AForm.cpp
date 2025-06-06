/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiqi <peiqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:27:53 by peli              #+#    #+#             */
/*   Updated: 2025/06/06 16:32:45 by peiqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm:: AForm(const std::string& name, int gradeSign, int gradeExecute):Name(name), Grade_sign(gradeSign), Grade_execute(gradeExecute)
{
    if (Grade_sign < 1 || Grade_execute < 1)
        throw GradeTooHighException();
    if (Grade_sign > 150 || Grade_execute > 150)
        throw GradeTooLowException();
    Is_signed = false;
};

AForm::~AForm()
{
    
};

AForm::AForm(const AForm &other):Name(other.Name),Is_signed(other.Is_signed), Grade_sign(other.Grade_sign), Grade_execute(other.Grade_execute)
{
};

AForm&   AForm::operator = (const AForm &other)
{
    if (this != &other)
        this->Is_signed = other.Is_signed; // SEUL attribut non-const
    return *this;
};

std::string AForm::getname() const
{
    return (this->Name);
};

int AForm::get_grade_sign() const
{
    return (this->Grade_sign);
};

int AForm::grade_execute() const
{
    return (this->Grade_execute);
};

bool    AForm::get_signed() const
{
    return (this->Is_signed);
};

void    AForm::beSigned(const Bureaucrat& other)
{
    if (other.getGrade() > Grade_sign)
        throw GradeTooLowException();
    Is_signed = true;
};