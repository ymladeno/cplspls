/*
 * Node.hpp
 *
 *  Created on: May 16, 2020
 *      Author: osboxes
 */

#ifndef IMPL_NODE_HPP_
#define IMPL_NODE_HPP_

namespace impl {

// make the template argument type available to users
template<typename T>
struct Node : T {
    using Interface = T;
    void accept(ipr::Visitor& v) const override { v.visit(∗this); }
};

}



#endif /* IMPL_NODE_HPP_ */
