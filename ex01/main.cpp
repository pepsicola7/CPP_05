/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:29:35 by peli              #+#    #+#             */
/*   Updated: 2025/06/04 19:46:35 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bob("Bob", 50);
    Form contract("Contract", 45, 30);

    bob.signForm(contract); // Affichera une erreur car 50 > 45
    
}