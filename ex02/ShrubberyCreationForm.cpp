/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:42:48 by peli              #+#    #+#             */
/*   Updated: 2025/06/05 17:57:53 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): Form("ShrubberyCreationForm", 145, 137), Target(target)
{
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : Form(other), Target(other.Target) {
    std::cout << "[Shrubbery] Copy constructor called for: " << Target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
    std::cout << "[Shrubbery] Assignment operator called." << std::endl;
    Form::operator=(other);
    return *this;
}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!get_signed())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > grade_execute())
        throw GradeTooLowException();
    std::ofstream ofs ((Target + "_shrubbery").c_str(), std::ofstream::out);
    if (!ofs)
    {
        std::cerr << "Cannot open ofs" << std::endl;
        return;
    }
    ofs << "       /\\\n";
    ofs << "      /**\\\n";
    ofs << "     /****\\\n";
    ofs << "    /******\\\n";
    ofs << "   /********\\\n";
    ofs << "       ||\n";
    ofs << "       ||\n";;
    ofs.close();    
};