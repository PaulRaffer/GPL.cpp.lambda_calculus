
// Copyright Paul Raffer 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// https://www.boost.org/LICENSE_1_0.txt)

//#if __cplusplus >= 201103L


#include <functional>
#include <iostream>


namespace gpl { // interface/implementation
namespace lambda_calculus {

class function :
		private ::std::function<function (function)> {
	public: using type =
			::std::function<function (function)>;
	public: using type::function;
	public: using type::operator();
	public: using type::operator bool;

	public: auto operator()() const -> function
	{
		return (*this)(0);
	}
};


template <
		typename T,
		template <typename> class F = ::std::function>
using lazy =
		F<T ()>;


class lazy_function :
		private lazy<::std::function<lazy_function (lazy_function)>> {
	public: using strict_type = 
			::std::function<lazy_function (lazy_function)>;
	public: using lazy_type =
			lazy<strict_type>;
	public: using lazy_type::function;
	public: using lazy_type::operator();
	public: using lazy_type::operator bool;

	public: lazy_function(strict_type f)
	:
		lazy_type{[=] { return f; }}
	{}

	public: auto operator()(lazy_function f) const -> lazy_function
	{
		return (*this)()(f);
	}
};

#include "short_begin.hpp"


inline namespace std { // interface/implementation

inline namespace combinators {

inline namespace sk {

FUNC(S,
	F(x,F(y,F(z,
		x(z)(y(z))
	)))
);

FUNC(K,
	F(x,F(y,
		x
	))
);

} // namespace sk


inline namespace ski {

using namespace sk;

FUNC(I,
	F(x,
		x
	)
);

} // namespace ski


FUNC(Iota,
	F(f,
		f(S)(K)
	)
);


inline namespace bckw {

FUNC(B,
	F(x,F(y,F(z
		x(y(z))
	)))
);

FUNC(C,
	F(x,F(y,F(z
		x(z)(y)
	)))
);

using sk::basic_K;
using sk::K;

FUNC(W
	F(x,F(y,
		x(y)(y)
	))
);

} // namespace bckw


inline namespace bamt {

using bckw::basic_B;
using bckw::B;

FUNC(A,
	F(x,F(y,
		y
	))
);

FUNC(M,
	F(x,
		x(x)
	)
);

FUNC(T,
	F(x,F(y,
		y(x)
	))
);

}

} // namespace combinators



inline namespace church {


FUNC(True,
	F(t,F(f,
		t
	))
);
FUNC(False,
	F(t,F(f,
		f
	))
);

FUNC(Not,
	F(x,
		x _(False)_(True)
	)
);
FUNC(Or,
	F(x,F(y,
		x(x)(y)
	))
);
FUNC(And,
	F(x,F(y,
		x(y)(x)
	))
);
FUNC(If,
	_(I)
);


FUNC(Succ,
	F(n,F(f,
		F(x, f(n(f)(x)) )
	))
);

/*template <typename Function, unsigned n>
Function   basic_UInt = basic_Succ<Function>(basic_UInt<Function, n-1>);

FUNC(UInt)<Function, 0> = F(f,F(s, s ));*/

FUNC(Zero,
	F(f,F(s,
		s
	))
);
FUNC(One,
	_(Succ)_(Zero)
);
FUNC(Two,
	_(Succ)_(One)
);
FUNC(Three,
	_(Succ)_(Two)
);
FUNC(Four,
	_(Succ)_(Three)
);
FUNC(Five,
	_(Succ)_(Four)
);
FUNC(Six,
	_(Succ)_(Five)
);
FUNC(Seven,
	_(Succ)_(Six)
);
FUNC(Eight,
	_(Succ)_(Seven)
);
FUNC(Nine,
	_(Succ)_(Eight)
);
FUNC(Ten,
	_(Succ)_(Nine)
);
FUNC(Eleven,
	_(Succ)_(Ten)
);
FUNC(Twelve,
	_(Succ)_(Eleven)
);
FUNC(Thirteen,
	_(Succ)_(Twelve)
);
FUNC(Fourteen,
	_(Succ)_(Thirteen)
);
FUNC(Fifteen,
	_(Succ)_(Fourteen)
);

FUNC(IsZero,
	F(n,
		n(F(,_(False)))_(True)
	)
);

FUNC(Add,
	F(x,F(y,
		y _(Succ)(x)
	))
);
FUNC(Mul,
	F(x,F(y,
		F(f, y(x(f)) )
	))
);
FUNC(Pow,
	F(b,F(e,
		e(b)
	))
);


FUNC(Cons,
	F(a,F(b,
		F(s, s(a)(b) )
	))
);
FUNC(Car,
	F(p,
		p _(True)
	)
);
FUNC(Cdr,
	F(p,
		p _(False)
	)
);


FUNC(T,
	F(p,
		_(Cons) (_(Succ)(_(Car)(p))) (_(Car)(p))
	)
);
FUNC(Pred,
	F(n,
		_(Cdr)(n _(T)(_(Cons)_(Zero)_(Zero)))
	)
);
FUNC(Sub,
	F(x,F(y,
		y _(Pred)(x)
	))
);

FUNC(Y,
	F(f,
		F(x,
			f L(x(x))
		)F(x,
			f L(x(x))
		)
	)
);

FUNC(Z,
	F(f,
		F(x,
			f(x(x))
		)F(x,
			f(x(x))
		)
	)
);

/*
template <typename Function> Function basic_Fact;

template <>
lazy_function basic_Fact<lazy_function> =
		basic_Y<lazy_function>(
			LF(f, LF(n,
				basic_IsZero<lazy_function>(n)
					(basic_One<lazy_function>)
					(basic_Mul<lazy_function>
						(n)
						L(f(basic_Pred<lazy_function>(n))())
					)
			))
		);

template <typename Function> Function basic_Fib;

template <>
lazy_function basic_Fib<lazy_function> =
		basic_Y<lazy_function>(
			LF(f, LF(n,
				basic_Or<lazy_function>
					(basic_IsZero<lazy_function>(n))
					(basic_IsZero<lazy_function>(basic_Pred<lazy_function>(n)))
						(n)
						(L(basic_Add<lazy_function>
							(f(basic_Pred<lazy_function>))
							(f(basic_Sub<lazy_function>(n)(basic_Two<lazy_function>)))
						))
			))
		);*/


FUNC(Fact,
	_(Y) F(f,
		F(n,
			_(IsZero)(n)
				_(One)
				(_(Mul)
					(n)
					L(f(_(Pred)(n))))
		)
	)
);

FUNC(Fib,
	_(Y)
		LF(f, LF(n,
			_(Or)
				(_(IsZero)(n))
				(_(IsZero)(_(Pred)(n)))
					(n)
					L(_(Add)
						(f(_(Pred)(n)))
						(f(_(Sub)(n)_(Two)))
					)
		))
);

} // namespace church

} // namespace std





namespace helper { // interface

FUNC(Null, {});

template <typename T> auto from_bool(bool b) -> T;
template <typename T> auto to_bool(T fb) -> bool;

template <typename T> auto from_int(int n, T fn = church::basic_Zero<T>) -> T;
template <typename T> auto to_int(T fn) -> int;

} // namespace helper



namespace helper { // implementation

template <typename T> auto from_bool(bool const b) -> T
{
	using namespace church;
	return b ? basic_True<T> : basic_False<T>;
}

template <typename T> auto to_bool(T b) -> bool
try {
	using namespace church;
	if (
	   !b(basic_Null<T>)(basic_Null<T>)
	&& !b(basic_Null<T>)(basic_True<T>)
	&&  b(basic_True<T>)(basic_Null<T>)
	&&  b(basic_True<T>)(basic_True<T>))
		return true;
	else if (
	   !b(basic_Null<T>)(basic_Null<T>)
	&&  b(basic_Null<T>)(basic_True<T>)
	&& !b(basic_True<T>)(basic_Null<T>)
	&&  b(basic_True<T>)(basic_True<T>))
		return false;
	else
		throw -1;
}
catch (::std::bad_function_call&) {
	throw -1;
}


template <typename T> auto from_int(int const n, T N) -> T
{
	using namespace church;
	return n == 0 ? N : from_int(n - 1, basic_Succ<T>(N));
}

template <typename T> auto to_int(T N) -> int
{
	auto count = 0;
	T inc_count{
			[&count](T x) {
				++count;
				return x;
			}};
	N(inc_count)(N);
	return count;
}

} // namespace helper

#include "short_end.hpp"

} // namespace lambda_calculus
} // namespace gpl


//#endif // __cplusplus >= 201103L
