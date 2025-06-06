/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiqi <peiqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:29:59 by peli              #+#    #+#             */
/*   Updated: 2025/06/06 16:32:28 by peiqi            ###   ########.fr       */
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

void    Bureaucrat::signAForm(AForm& AForm)
{
    try 
    {
        AForm.beSigned(*this);
        std::cout << getName() << " signed " << AForm.getname() << std::endl;
    }
    catch (std::exception& e) 
    {
        std::cout << getName() << " couldn’t sign " << AForm.getname() << " because " << e.what() << std::endl;
    }
};

void Bureaucrat::executeAForm(AForm const & AForm) const 
{
    try {
        AForm.execute(*this);
        std::cout << this->getName() << " executed " << AForm.getname() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << this->getName() << " couldn’t execute " << AForm.getname()
                  << " because " << e.what() << std::endl;
    }
}
