#include "stdafx.h"
#include "MyString.h"
#include<string.h>

CMyString::CMyString()
{
	m_nBufferSize = 1;
	m_pBuff = new char[1];
	
	strcpy(m_pBuff, "");
	m_nLen = strlen(m_pBuff);
}
CMyString::CMyString(char *argString)
{
	m_nBufferSize = 0;
	m_nLen = 0;
	m_pBuff = nullptr;
	SetString(argString);
}
CMyString::CMyString(CMyString &otherObj)
{
	m_nBufferSize = otherObj.m_nBufferSize;
	m_nLen = otherObj.m_nLen;
	m_pBuff = new char[m_nBufferSize];
	strcpy(m_pBuff, otherObj.m_pBuff);
}
CMyString::~CMyString()
{
	if (m_pBuff!=nullptr)
	{
		delete[] m_pBuff;
	}
}

void CMyString::SetString(char *argString)
{
	
	
	int nNewBufferSize = 0;
	nNewBufferSize = strlen(argString) + 1;

	
	if (m_pBuff == nullptr)
	{
		m_pBuff = new char[nNewBufferSize];
		m_nBufferSize = nNewBufferSize;
	}
	else if (m_nBufferSize<nNewBufferSize)
	{
		delete[] m_pBuff;
		m_pBuff = new char[nNewBufferSize];
		m_nBufferSize = nNewBufferSize;
	}

	strcpy(m_pBuff, argString);
	m_nLen = strlen(m_pBuff);
}
void CMyString::StrCat(char *argString)
{
	int nNeedBufferSize = 0;
	nNeedBufferSize = m_nLen + strlen(argString)+1;

	char *tempString = nullptr;
	tempString = new char[m_nLen+1 ];
	strcpy(tempString, m_pBuff);

	if (nNeedBufferSize<m_nBufferSize)
	{
		strcat(m_pBuff, argString);

	}
	else
	{
		delete[] m_pBuff;
		m_pBuff = new char[nNeedBufferSize];
		m_nBufferSize = nNeedBufferSize;
		strcpy(m_pBuff, tempString);
		strcat(m_pBuff, argString);
	}

	m_nLen = strlen(m_pBuff);
	delete[] tempString;
}

CMyString CMyString::operator+(char* argString)
{
	CMyString retString = *this;
	retString.StrCat(argString);
	return retString;
}
CMyString CMyString::operator+(CMyString &otherObj)
{
	CMyString retString = *this;
	retString.StrCat(otherObj.m_pBuff);
	return retString;
}


void CMyString:: operator=(char* argString)
{
	int nNeedBuffSize = strlen(argString) + 1;
	if (m_nBufferSize>nNeedBuffSize)
	{
		strcpy(m_pBuff, argString);
		m_nLen = strlen(m_pBuff);
	}
	else
	{
		delete[] m_pBuff;
		m_nBufferSize = nNeedBuffSize;
		m_pBuff = new char[m_nBufferSize];
		strcpy(m_pBuff, argString);
		m_nLen = strlen(m_pBuff);
	}
}

void CMyString::operator=(CMyString &otherObj)
{
	if (m_nBufferSize>otherObj.m_nBufferSize)
	{
		strcpy(m_pBuff, otherObj.m_pBuff);
		m_nLen = strlen(m_pBuff);
	}
	else
	{
		delete[] m_pBuff;
		m_nBufferSize = otherObj.m_nLen + 1;
		m_pBuff = new char[m_nBufferSize];
		strcpy(m_pBuff, otherObj.m_pBuff);
		m_nLen = strlen(m_pBuff);
	}
}

void CMyString::capitalize()
{
	char cFirst = 0;
	char cTemp = 0;
	if (m_pBuff[0]<='z'&&m_pBuff[0]>='a')
	{
		cFirst = 'A' + m_pBuff[0] - 'a';
		memset(m_pBuff, cFirst, 1);
	}
	for (int i = 1; i < m_nLen; i++)
	{
		if (m_pBuff[i]>='A'&&m_pBuff[i]<='Z')
		{
			cTemp = 'a' + m_pBuff[i] - 'A';
			memset(m_pBuff + i, cTemp, 1);
		}
	}
}

bool CMyString::isalnum()
{
	for (int i = 0; i < m_nLen; i++)
	{
		if (m_pBuff[i]>='0'&&m_pBuff[i]<='9')
		{
			return true;
		}
		
	}
	return false;
}
bool CMyString::isdigit()
{
	for (int i = 0; i < m_nLen; i++)
	{
		if ((m_pBuff[i] >= 'a'&&m_pBuff[i] <= 'z')
			||( m_pBuff[i] >= 'A'&&m_pBuff[i] <= 'Z'))
		{
			return false;
		}

	}
	return true;
}
bool CMyString::isupper()
{
	for (int i = 0; i < m_nLen; i++)
	{
		if (m_pBuff[i] >= 'a'&&m_pBuff[i] <= 'z')
		{
			return false;
		}
	}
	return true;
}
bool CMyString::startwith(char *headString)
{
	int nLen = strlen(headString);
	if (nLen>m_nLen)
	{
		return false;
	}
	
	if (memcmp(m_pBuff,headString,strlen(headString))==0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool CMyString::endwith(char* tailString)
{
	int nLen = strlen(tailString);
	if (nLen>m_nLen)
	{
		return false;
	}

	char *cTempString = nullptr;
	cTempString = new char[m_nLen + 1];
	strcpy(cTempString, m_pBuff);

	
	int nCursor = 0;
	while (nCursor!=m_nLen-nLen)
	{
		cTempString++;
		nCursor++;
	}
	if (strcmp(cTempString, tailString) == 0)
	{
		
		return true;
	}
	else
	{
		
		return false;
	}
}
void CMyString::replace(char* oldStr, char* newStr)
{
 	int nOldLen = strlen(oldStr);
	int nNewLen = strlen(newStr);
	int nNeedBufferSize = 0;
	int nCursor = 0;

	if (nOldLen>m_nLen)
	{
		return;
	}
	char *cTempString = nullptr;
	cTempString = new char[m_nLen + 1];
	strcpy(cTempString, m_pBuff);

	for (int i = 0; i < m_nLen; i++)
	{
		if (memcmp(cTempString, oldStr, nOldLen) == 0)
		{
			break;
		}
		cTempString++;
		nCursor++;
	}
	if (nCursor==m_nLen)
	{
		return;
	}
	nNeedBufferSize = m_nLen - nOldLen + nNewLen + 1;
	if (nNeedBufferSize<=m_nBufferSize)
	{

		memcpy(m_pBuff+nCursor, newStr, nNewLen);
		memcpy(m_pBuff + nCursor + nNewLen, cTempString + nCursor + nOldLen, strlen(cTempString) - nNewLen + 1);
	}
	else
	{
		delete[]m_pBuff;
		m_pBuff = new char[nNeedBufferSize];
		memcpy(m_pBuff, cTempString - nCursor,nCursor);
		
		memcpy(m_pBuff + nCursor, newStr,nNewLen);
		memcpy(m_pBuff+nCursor+nNewLen, cTempString + nOldLen,strlen(cTempString)-nOldLen+1);

	}
	m_nLen = strlen(m_pBuff);

}

char* CMyString::CurString()
{
	return m_pBuff;
}