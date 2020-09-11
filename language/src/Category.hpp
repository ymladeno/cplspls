/*
 * Category.hpp
 *
 *  Created on: May 16, 2020
 *      Author: osboxes
 */

#ifndef CATEGORY_HPP_
#define CATEGORY_HPP_


template<Category_code Cat, typename T = Expr>
struct Category : T {
protected:
    Category() : T(Cat) { }
};



#endif /* CATEGORY_HPP_ */
