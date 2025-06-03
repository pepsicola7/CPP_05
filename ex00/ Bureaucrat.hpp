/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Bureaucrat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:30:03 by peli              #+#    #+#             */
/*   Updated: 2025/06/03 16:42:07 by peli             ###   ########.fr       */
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
    void    increment_grade(int& Grade);
    void    decrement_grade(int& Grade);
    std::string    getName() const;
    
    class GradeTooHighException : public std::exception
    {
    public :
        const char* what() const noexcept override 
        {
            return "Grade too high!";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public :
        const char* what() const noexcept override 
        {
            return "Grade too low!";
        }
    };
    int    getGrade() const;
};
