/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:30:03 by peli              #+#    #+#             */
/*   Updated: 2025/06/04 12:02:33 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
    private:
    const std::string Name;
    int Grade;

    public:
    Bureaucrat(const std::string& Name, int Grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator = (const Bureaucrat& other);
    void    increment_grade();
    void    decrement_grade();
    std::string    getName() const;
    int    getGrade() const;
    
    class GradeTooHighException : public std::exception
    {
        public :
            virtual const char* what() const throw()
            {
                return "Grade too high!";
            }
    };
    class GradeTooLowException : public std::exception
    {
    public :
        virtual const char* what() const throw()
        {
            return "Grade too low!";
        }
    };
};
