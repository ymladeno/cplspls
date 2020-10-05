/*
 * boo.cpp
 *
 *  Created on: Sep 15, 2020
 *      Author: osboxes
 */

#define ID 0xb00
#include "thing.hpp"

unsigned boo()
{
    thing<unsigned> t;
    return t.id();
}
