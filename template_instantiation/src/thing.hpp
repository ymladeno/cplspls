/*
 * thing.hpp
 *
 *  Created on: Sep 15, 2020
 *      Author: osboxes
 */

#ifndef THING_HPP_
#define THING_HPP_

#ifndef ID
#error ID undefined
#endif

template<typename T>
struct thing
{
    T id() const {
        return T{ID};
    }
};

#endif /* THING_HPP_ */
