/*
 * Node.hpp
 *
 *  Created on: Apr 5, 2020
 *      Author: osboxes
 */

#ifndef NODE_HPP_
#define NODE_HPP_

namespace ipr {

struct Node {
    const int node_id;
    const Category_code category;

    // hook for visitor classes
    virtual void accept(Visitor&) const = 0;

protected:
    Node(Category_code);
};

}


#endif /* NODE_HPP_ */
