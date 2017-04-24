#ifndef TOKEN_H
#define TOKEN_H

namespace BasicParser
{
    enum Token {
	T_NULL  = 0,
	T_ZERO  = 1,
	T_ONE   = 2,
	T_TWO   = 3,
	T_THREE = 4,
	T_FOUR  = 5,
	T_FIVE  = 6,
	T_SIX   = 7,
	T_SEVEN = 8,
	T_EIGTH = 9,
	T_NINE  = 10,
	T_ADD   = 11,
	T_MIN   = 12,
	T_MUL   = 13,
	T_DIV   = 14,
	T_BEGIN = 100,
	T_END   = 101,
	T_ERROR = 102
    };
}
#endif /* TOKEN_H */
