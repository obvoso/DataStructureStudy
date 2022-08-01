#ifndef _STACK_CALC_
#define _STACK_CALC_

#include "../linkedstack.h"

typedef enum PrecedenceType
{
	lparen,
	rparen,
	times,
	divide,
	plus,
	minus,
	operand
}	Precedence;

typedef struct ExprTokenType 
{
	float		value;
	Precedence	type;
}	ExprToken;

// void calcExpr(ExprToken *pExprTokens, int tokenCount); // ㄱㅖ사ㄴ?
// ExprToken *pushLSExprToken(LinkedStack* pStack, ExprToken *data); // 링크드 스택 만드는 거
// void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount); // 중위후위변환
// int inStackPrecedence(Precedence oper); // 푸쉬
// int outStackPrecedence(Precedence oper); // 팝
// void printToken(ExprToken element); // 토큰 출력??

#endif