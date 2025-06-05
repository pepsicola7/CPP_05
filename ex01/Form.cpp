/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:27:53 by peli              #+#    #+#             */
/*   Updated: 2025/06/05 17:35:20 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form:: Form(const std::string& name, int gradeSign, int gradeExecute):Name(name), Grade_sign(gradeSign), Grade_execute(gradeExecute)
{
    if (Grade_sign < 1 || Grade_execute < 1)
        throw GradeTooHighException();
    if (Grade_sign > 150 || Grade_execute > 150)
        throw GradeTooLowException();
    Is_signed = false;
};

Form::~Form()
{
    
};

Form::Form(const Form &other):Name(other.Name),Is_signed(other.Is_signed), Grade_sign(other.Grade_sign), Grade_execute(other.Grade_execute)
{
};

Form&   Form::operator = (const Form &other)
{
    if (this != &other)
        this->Is_signed = other.Is_signed; // SEUL attribut non-const
    return *this;
};

std::string Form::getname() const
{
    return (this->Name);
};

int Form::get_grade_sign() const
{
    return (this->Grade_sign);
};

int Form::grade_execute() const
{
    return (this->Grade_execute);
};

bool    Form::get_signed() const
{
    return (this->Is_signed);
};

void    Form::beSigned(const Bureaucrat& other)
{
    if (other.getGrade() > Grade_sign)
        throw GradeTooLowException();
    Is_signed = true;
};