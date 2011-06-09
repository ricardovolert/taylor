/*
 * constant_generator.hpp
 *
 *  Created on: Jun 9, 2011
 *      Author: karsten
 */

#ifndef CONSTANT_GENERATOR_HPP_
#define CONSTANT_GENERATOR_HPP_

#include <boost/numeric/odeint/stepper/taylor/tree_nodes/constant_node.hpp>

#include <boost/proto/proto.hpp>
#include <boost/mpl/size_t.hpp>


namespace boost {
namespace numeric {
namespace odeint {


namespace tree_generators {

namespace proto = boost::proto;




struct constant_transform : proto::transform< constant_transform >
{
	template< typename Expr , typename State , typename Data >
	struct impl : proto::transform_impl< Expr , State , Data >
	{
		typedef typename tree_nodes::constant_node< double > result_type;

		result_type operator ()(
				typename impl::expr_param expr ,
				typename impl::state_param state ,
				typename impl::data_param data ) const
		{
			return result_type( proto::value( expr ) );
		}
	};
};

struct constant_generator : proto::when< proto::terminal< double > , constant_transform > { };




} // namespace tree_generators



} // namespace odeint
} // namespace numeric
} // namespace boost


#endif /* CONSTANT_GENERATOR_HPP_ */