/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiqi <peiqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:45:31 by peli              #+#    #+#             */
/*   Updated: 2025/06/06 16:34:09 by peiqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm
{
private:
    std::string Target;
public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};
