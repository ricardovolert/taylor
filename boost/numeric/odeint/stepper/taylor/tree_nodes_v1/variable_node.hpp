/*
 * variable_node.hpp
 *
 *  Created on: Jun 9, 2011
 *      Author: karsten
 *
 *
 * Copyright Karsten Ahnert 2011.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef VARIABLE_NODE_HPP_
#define VARIABLE_NODE_HPP_

#include <ostream>

namespace boost {
namespace numeric {
namespace odeint {
namespace taylor_detail {
namespace tree_nodes_v1 {


template< size_t Index , class Value = double >
struct variable_node
{
    variable_node( void ) : m_index( Index ) { }

	template< class State , class Derivs >
	Value operator()( const State &x , const Derivs &derivs , size_t which ) const
	{
		return ( which == 0 ) ? x[ m_index ] : derivs[ which - 1 ][ m_index ];
	}

	size_t m_index ;

};

template< size_t Index , class Value >
variable_node< Index , Value > make_variable_node( void )
{
	return variable_node< Index , Value >();
}


} // namespace tree_nodes_v1

template< size_t Index , class Value >
void print_node( std::ostream &out , const tree_nodes_v1::variable_node< Index , Value > &node , size_t indent = 0 )
{
	for( size_t i=0 ; i<indent ; ++i ) out << "  ";
	out << "Variable ( " << Index << " )";
}



} // namespace taylor_detail
} // namespace odeint
} // namespace numeric
} // namespace boost


#endif /* VARIABLE_NODE_HPP_ */
