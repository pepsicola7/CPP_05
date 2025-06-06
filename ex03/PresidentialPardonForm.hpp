/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiqi <peiqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:12:37 by peli              #+#    #+#             */
/*   Updated: 2025/06/06 16:34:36 by peiqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
    std::string Target;
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;
};

