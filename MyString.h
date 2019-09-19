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

	//�鿴��ǰ�ַ���
	char* CurString();
	//����ĸ��д����Сд
	void capitalize();
	//�Ƿ��������
	bool isalnum();
	//�Ƿ��������ַ�����ȫ��������Ϊ�����ַ���
	bool isdigit();
	//�Ƿ�ȫΪ��д��ĸ���ַ���
	bool isupper();
	//�Ƿ��Բ����ַ�����ʼ
	bool startwith(char *headString);
	//�Ƿ��Բ����ַ�����β
	bool endwith(char* tailString);
	//�滻�ַ���
	void replace(char* oldStr, char* newStr);
	
};

