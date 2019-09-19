#pragma once
#include<string.h>
class CMyString
{
public:
	int m_nBufferSize;
	int m_nLen;
	char* m_pBuff;

	CMyString();
	CMyString(char *argString);
	CMyString(CMyString &otherObj);
	~CMyString();
	

	void SetString(char *argString);
	void StrCat(char* argString);
	 
	CMyString operator+(char* argString);
	CMyString operator+(CMyString &otherObj);

	void operator=(char* argString);
	void operator=(CMyString &otherObj);

	//查看当前字符串
	char* CurString();
	//首字母大写其余小写
	void capitalize();
	//是否存在数字
	bool isalnum();
	//是否是数字字符串，全是数字则为数字字符串
	bool isdigit();
	//是否全为大写字母的字符串
	bool isupper();
	//是否以参数字符串开始
	bool startwith(char *headString);
	//是否以参数字符串结尾
	bool endwith(char* tailString);
	//替换字符串
	void replace(char* oldStr, char* newStr);
	
};

