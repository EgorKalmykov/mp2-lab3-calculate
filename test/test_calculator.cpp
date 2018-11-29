#include "calculator.h"
#include <gtest.h>

TEST(Calculator, can_create_postfix)
{
	ASSERT_NO_THROW(Calculator p);
}

TEST(Calculator, can_create_postfix_with_expression)
{
	ASSERT_NO_THROW(Calculator p("2+4*(1/6)-8"));
}

TEST(Calculator, can_create_postfix_form)
{
	Calculator p("1+2/(3-3)");
	p.CreatePostfix();

	EXPECT_EQ("1 2 3 3 - / + ", p.GetPostfix());
}

TEST(Calculator, can_calculate)
{
	Calculator p("1+2*(3-2)-4");
	p.CreatePostfix();

	EXPECT_EQ(-1, p.Calculate());
}

TEST(Calculator, can_not_divide_by_zero)
{
	Calculator p("1+2/(3-3)");
	p.CreatePostfix();

	ASSERT_ANY_THROW(p.Calculate());
}

TEST(Calculator, can_not_create_postfix_with_wrong_brackets)
{
	Calculator p("(((1+23)*1-22)+5)*2-(7");
	ASSERT_ANY_THROW(p.CreatePostfix(););
}

TEST(Calculator, can_mult_bracket_on_bracket)
{
	Calculator p("(1+2/4/5-5)*(1-2)");
	p.CreatePostfix();

	EXPECT_EQ(3.9, p.Calculate());
}

TEST(Calculator, can_work_with_nested_brackets)
{
	Calculator p("(1+(2+(3/3)))*(1-2)");
	p.CreatePostfix();

	EXPECT_EQ(-4, p.Calculate());
}

TEST(Calculator, can_not_calculate_expression_with_not_enough_opernands)
{
	Calculator p("1++1");
	p.CreatePostfix();

	ASSERT_ANY_THROW(p.Calculate());
}