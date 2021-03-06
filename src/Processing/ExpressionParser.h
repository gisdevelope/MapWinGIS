#pragma once
#include "CustomExpression.h"

class ExpressionParser
{

public:	
	ExpressionParser()
		: _expression(NULL)
	{
			
	}
	
private:
	CustomExpression* _expression;

private:
	bool IsDecimal(CString& str);
	bool IsDecimal(char chr, bool& exponential);
	bool IsDecimalZero(CString& str);
	bool IsInteger(CString& str);
	bool IsOperator(char s);
	bool IsOperator(CString s);
	bool IsFunctionName(char s);

	bool ParseTree(CString s);
	CustomFunction* ParseFunction(CString& s, int begin, int& fnBegin);
	bool ParseArgumentList(CString s, CustomFunction* fn);

	bool GetBrackets(CString expression, int& begin, int& end, CString openingSymbol = "(", CString closingSymbol = ")");
	CString GetInnerString(CString& s, int begin, int end);

	CExpressionPart* ParseExpressionPart(CString s);
	bool ReadValue(CString s, int& position, CElement* element);
	bool ReadOperation(CString s, int& position, CElement& element);
	
	void ReplacePart(CString& s, int begin, int end);
	bool ReplaceStringLiterals(CString& s, int& count);
	bool ReplaceFieldNames(CString& s, int& count);
	void ReplaceSubString(CString& s, int begin, int length, CString replacement);

	void SetErrorMessage(CString msg) { _expression->SetErrorMessage(msg); }
	void SetErrorPosition(int position) { _expression->SetErrorPosition(position); }
public:
	bool Parse(CustomExpression* expression, CString s, bool useFields);
	bool ReplaceParameterlessFunctions(CString& s);

};

