/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:29:59 by peli              #+#    #+#             */
/*   Updated: 2025/06/05 17:49:52 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& Name, int Grade):Name(Name)
{
    if (Grade < 1)
        throw GradeTooHighException();
    if (Grade > 150)
        throw GradeTooLowException();
    this->Grade = Grade;
};

Bureaucrat::~Bureaucrat()
{
    
};

Bureaucrat::Bureaucrat(const Bureaucrat &other):Name(other.Name)
{
    Grade = other.Grade;
};

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other)
{
    if (Grade < 1)
        throw GradeTooHighException();
    if (Grade > 150)
        throw GradeTooLowException();
    this->Grade = other.Grade;
    return (*this);
};

void    Bureaucrat::increment_grade()
{
    if (Grade - 1 < 1)
        throw GradeTooHighException();
    Grade--;        
};

void    Bureaucrat::decrement_grade()
{
    if (Grade + 1 > 150)
        throw GradeTooLowException();
    Grade++;
};

std::string    Bureaucrat::getName() const
{
    return (this->Name);
};

int    Bureaucrat::getGrade() const
{
    return (this->Grade);
};

void    Bureaucrat::signForm(Form& Form)
{
    try 
    {
        Form.beSigned(*this);
        std::cout << getName() << " signed " << Form.getname() << std::endl;
    }
    catch (std::exception& e) 
    {
        std::cout << getName() << " couldn’t sign " << Form.getname() << " because " << e.what() << std::endl;
    }
};

void Bureaucrat::executeForm(Form const & form) const 
{
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getname() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << this->getName() << " couldn’t execute " << form.getname()
                  << " because " << e.what() << std::endl;
    }
}
