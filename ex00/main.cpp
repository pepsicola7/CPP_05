/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:29:35 by peli              #+#    #+#             */
/*   Updated: 2025/06/04 14:25:47 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 2);
        std::cout << bob.getName() << "bureaucrat grade " << bob.getGrade() << std::endl;

        bob.increment_grade();
        std::cout << "After promotion : " << bob.getGrade() << std::endl;

        bob.increment_grade();
        std::cout << "It shouldn't present!" << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() <<std::endl;
    }
    
    try
    {
        Bureaucrat stuart("Stuart", 151);
        std::cout << "It shouldn't present!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "construction failed : " << e.what() << std::endl;
    }
    
}