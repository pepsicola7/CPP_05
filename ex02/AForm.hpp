/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:32:52 by peli              #+#    #+#             */
/*   Updated: 2025/06/05 17:52:46 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        const std::string Name;
        bool    Is_signed;
        const int     Grade_sign;
        const int     Grade_execute;
    public:
        Form(const std::string& name, int gradeSign, int gradeExecute);
        virtual ~Form();
        Form(const Form &other);
        Form&   operator = (const Form &other);

        std::string getname() const;
        int get_grade_sign() const;
        int grade_execute() const;
        bool    get_signed() const;
        void    beSigned(const Bureaucrat& other);

        virtual void execute(Bureaucrat const & executor) const = 0;

    class   GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade is too high!");
        }
    };
    
    class   GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade is too low!");
        }   
    };
};
