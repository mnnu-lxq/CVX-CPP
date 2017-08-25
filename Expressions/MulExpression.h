/*
 * MulExpression.h
 *
 *  Created on: Aug 25, 2017
 *      Author: tim
 */

#ifndef EXPRESSIONS_MULEXPRESSION_H_
#define EXPRESSIONS_MULEXPRESSION_H_

#include "../ExpressionTraits.h"
namespace cvx{

template <class Left, class Right>
class MulExpression: public FunctionExpression<MulExpression<Left, Right>>
{
public:
	using self_type = AddExpression<Left, Right>;
	using base_type = FunctionExpression<AddExpression<Left, Right>>;
	using left_type = Left;
	using right_type = Right;
	using eval_result_type = OP_RESULT_TYPE(left_type, right_type, *);
	MulExpression(const left_type & left, const right_type & right):
		left_(left), right_(right)
	{

	}
	eval_result_type evaluate() const
	{
		return evaluate_expression(left_) * evaluate_expression(right_);
	}
	const left_type & left() const
	{
		return left_;
	}
	const right_type & right() const
	{
		return left_;
	}
private:
	const left_type & left_;
	const right_type & right_;
};

template <class Left, class Right>
MulExpression<derived_type_t<Left>, derived_type_t<Right>> make_mul_expression(Left && left, Right && right)
{
	return MulExpression<derived_type_t<Left>, derived_type_t<Right>>(forward_as_derived(left), forward_as_derived(right));
}
} /* namespace cvx */

#endif /* EXPRESSIONS_MULEXPRESSION_H_ */

