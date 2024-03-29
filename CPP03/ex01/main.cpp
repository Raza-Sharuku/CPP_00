/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:23:27 by razasharuku       #+#    #+#             */
/*   Updated: 2024/02/12 13:10:49 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"
#include"ScavTrap.hpp"


int main(void) 
{
    ClapTrap pikachu("ピカチュウ");
    ScavTrap darkry("ダークライ");

    std::cout << "------------------------------------------------------" << std::endl;

    pikachu.attack("ダークライ");
    darkry.takeDamage(0);
    darkry.attack("ピカチュウ");
    pikachu.takeDamage(20);
    pikachu.beRepaired(2);
    darkry.attack("ピカチュウ");
    pikachu.takeDamage(20);

    std::cout << "------------------------------------------------------" << std::endl;
    pikachu.attack("ダークライ");
    darkry.guardGate();
    std::cout << "------------------------------------------------------" << std::endl;
    pikachu.attack("ダークライ");
    darkry.takeDamage(0);
    darkry.attack("ピカチュウ");
    pikachu.takeDamage(20);
    std::cout << "------------------------------------------------------" << std::endl;


    return 0;
}