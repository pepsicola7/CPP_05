/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:45:31 by peli              #+#    #+#             */
/*   Updated: 2025/06/05 17:56:53 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public Form
{
private:
    std::string Target;
public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};
