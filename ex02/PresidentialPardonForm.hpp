/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:12:37 by peli              #+#    #+#             */
/*   Updated: 2025/06/05 17:56:58 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm: public Form
{
private:
    std::string Target;
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;
};

