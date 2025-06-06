/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiqi <peiqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:32:52 by peli              #+#    #+#             */
/*   Updated: 2025/06/06 16:32:45 by peiqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    private:
        const std::string Name;
        bool    Is_signed;
        const int     Grade_sign;
        const int     Grade_execute;
    public:
        AForm(const std::string& name, int gradeSign, int gradeExecute);
        virtual ~AForm();
        AForm(const AForm &other);
        AForm&   operator = (const AForm &other);

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
