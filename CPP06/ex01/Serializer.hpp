/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:02:27 by razasharuku       #+#    #+#             */
/*   Updated: 2024/03/20 17:17:48 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string.h>
#include <exception>

typedef struct Data
{
    int             num;
    std::string     str;
}          Data;

class Serializer
{
    private:
        // コンストラクタ
        Serializer();
        // コピーコンストラクタ
        Serializer(const Serializer& other);
    public:
        // コピー代入演算子
        Serializer &operator=(const Serializer& other);
        // デストラクタ
        ~Serializer(void);
        // メンバ変数
        static uintptr_t        serialize(Data* ptr);
        static Data*            deserialize(uintptr_t raw);
};



#endif