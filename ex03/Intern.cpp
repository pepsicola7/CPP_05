/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiqi <peiqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:27:51 by peiqi             #+#    #+#             */
/*   Updated: 2025/06/06 16:38:06 by peiqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern&) 
{};

Intern& Intern::operator=(const Intern&)
{
	return *this;
};


AForm* Intern::makeAForm(std::string nameAForm, std::string targetAForm)
{
	std::string name[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* AForms[3] = 
	{ 
		new ShrubberyCreationForm(targetAForm),
		new RobotomyRequestForm(targetAForm),
		new PresidentialPardonForm(targetAForm)
	};
	int	i = 0;

	while (i < 3)
	{
		if (nameAForm == name[i])
		{
			for(int j= 0; j < 3; j++)
			{
				if (j != i)
					delete AForms[j];
			}
			std::cout << "Intern creates " << nameAForm << std::endl;
			return (AForms[i]);
		}
		i++;
	}
	for(int j= 0; j < 3; j++)
			delete AForms[j];
	throw std::runtime_error("The name of AForm existn't");
	std::cerr << nameAForm << std::endl;
	return (NULL);
};