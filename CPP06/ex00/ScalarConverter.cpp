/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:06 by razasharuku       #+#    #+#             */
/*   Updated: 2024/03/14 18:05:04 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}


ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

// ------------------------------------------------------ //

enum char_type
{
    INVALID = -1,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
};



static bool is_char(const std::string &str)
{
    if (str.length() != 1)
        return (false);
    if (isdigit(str.at(0)) ||  str.at(0) < -127 || str.at(0) > -128)
        return (false);
    return (true);
}

static bool is_int(const std::string &str)
{
    int i = 0;
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

static bool is_float(const std::string &str)
{
    unsigned long i = 0;
    bool find_dot = false;

    if (str[str.length() - 1] != 'f')
        return (false);
    while (i < str.length() - 1)
    {
        if (str[i] == '.' && find_dot == true)
            return (false);
        if (find_dot == false && str[i] == '.')
        {
            find_dot = true;
            continue;
        }
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

static bool is_double(const std::string &str)
{
    unsigned long i = 0;
    bool find_dot = false;

    while (i < (str.length() - 1))
    {
        if (str[i] == '.' && find_dot == true)
            return (false);
        if (find_dot == false && str[i] == '.')
        {
            find_dot = true;
            continue;
        }
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

static char_type getType(const std::string &str)
{
    if (is_char(str))
        return (CHAR);
    else if (is_int(str))
        return (INT);
    else if (is_double(str))
        return (DOUBLE);
    else if (is_float(str))
        return (FLOAT);
    return (INVALID);
}

static void print_char_ver(std::string str)
{
    std::cout << "char: " << str[0] << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: ";
    std::cout << std::fixed << std::setw(1) << static_cast<float>(str[0]) << std::endl;
    std::cout << "double: ";
    std::cout << std::fixed << std::setw(1) << static_cast<double>(str[0]) << std::endl;
    return ;
}

static void print_int_ver(std::string str)
{
    int num = atoi(str.c_str());
    if (num < 0 || num >= 128)
        std::cout << "char: impossible" << std::endl;
    else if (num < 32 || num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    std::cout << "int: " << (num) << std::endl;
    std::cout << "float: ";
    std::cout << std::fixed << std::setw(2) << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: ";
    std::cout << std::fixed << std::setw(2) << static_cast<double>(num) << std::endl;
    return ;
}

static void print_float_ver(std::string str)
{
    float f_num = atof(str.c_str());

    if (f_num < 0 || f_num >= 128)
        std::cout << "char: impossible" << std::endl;
    else if (f_num < 32 || f_num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(f_num) << std::endl;
    std::cout << "int: " << static_cast<int>(f_num) << std::endl;
    std::cout << "float: ";
    std::cout << std::fixed << std::setw(2) << f_num << "f" << std::endl;
    std::cout << "double: ";
    std::cout << std::fixed << std::setw(2) << static_cast<double>(f_num) << std::endl;
    return ;
}

static void print_double_ver(std::string str)
{
    float d_num = atof(str.c_str());

    if (d_num < 0 || d_num >= 128)
        std::cout << "char: impossible" << std::endl;
    else if (d_num < 32 || d_num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(d_num) << std::endl;
    std::cout << "int: " << static_cast<int>(d_num) << std::endl;
    std::cout << "float: ";
    std::cout << std::fixed << std::setw(1) << static_cast<float>(d_num) << "f" << std::endl;
    std::cout << "double: ";
    std::cout << std::fixed << std::setw(1) << (d_num) << std::endl;  
    return ;
}

static void print_infinity(std::string str)
{
    std::cout << "char: impossible" << std::endl;
    if (str == "nan" || str == "nanf")
    {
        std::cout << "int: 0" << std::endl;
        std::cout << "float: 0" << std::endl;
        std::cout << "double: 0" << std::endl;
    }
    else if(str == "-inff" || str == "-inf")
    {
        std::cout << "int: " << INT_MIN << std::endl;
        std::cout << "float: " << __FLT_MIN__ << std::endl;
        std::cout << "double: " << __DBL_MIN__ << std::endl;
    }
    else if (str == "+inf" || str == "+inff")
    {
        std::cout << "int: " << INT_MAX << std::endl;
        std::cout << "float: " << __FLT_MAX__ << std::endl;
        std::cout << "double: " << __DBL_MAX__ << std::endl;
    }
    return ;
}

void ScalarConverter::convert(std::string str)
{
    std::cout << "\033[1;33m" << "++++++++++++++++++ 1 ++++++++++++++++++++\n" << "\033[0m" << std::endl;
    if (str == "-inff" || str == "+inff" || str == "nanf" 
        || str == "-inf" || str == "+inf"  || str == "nan")
        return (print_infinity(str));
    
    char_type type;

    std::cout << "\033[1;33m" << "++++++++++++++++++ 2 ++++++++++++++++++++\n" << "\033[0m" << std::endl;

    type = getType(str);

    std::cout << "\033[1;33m" << "++++++++++++++++++ 3 ++++++++++++++++++++\n" << "\033[0m" << std::endl;

    switch (type)
    {
    case CHAR:
        print_char_ver(str);
        break;
    case INT:
        print_int_ver(str);
        break;
    case FLOAT:
        print_float_ver(str);
        break;
    case DOUBLE:
        print_double_ver(str);
        break;
    default:
        std::cout << "the type conversion is impossible" << std::endl;
        break;
    }
}