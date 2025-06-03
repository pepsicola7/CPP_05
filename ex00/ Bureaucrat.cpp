/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Bureaucrat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:29:59 by peli              #+#    #+#             */
/*   Updated: 2025/06/03 16:12:42 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " Bureaucrat.hpp"

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
    void    Bureaucrat::increment_grade(int& Grade)
    {
        if (Grade + 1 > 150)
            throw GradeTooLowException();
        Grade++;
        
    };
    void    Bureaucrat::decrement_grade(int& Grade)
    {
        if (Grade - 1 < 1)
            throw GradeTooHighException();
        Grade--;
    };
    std::string    Bureaucrat::getName() const
    {
        return (this->Name);
    };
    int    Bureaucrat::getGrade() const
    {
        return (this->Grade);
    };