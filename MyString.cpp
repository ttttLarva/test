//A*算法 八数码问题  #include #include #define base 99999999 using namespace std;  
struct X
{
	int now, x, s;
	//分别存储当前状态，康托展开式编号，0的位置  }p[37000]; struct X tmp,d; 
	//总状态数为9!=362880 
	int h[370000] = { 0 }, g[370000] = { 0 };
	//判重+记录到某种状态的H(N),G(N)   
	int all = 0, now[9] = { 0 }, end[9] = { 0 };
	//分别记录待扩展节点数，当前状态，目标状态 bool in_[370000]={0};//表示某个结点是否在堆内 int cantor(int s[])//用康托展开式压缩  { 
	int num = 0, i = 0, j = 0, b = 0;
	int cantor(int s[])//用康托展开式压缩  
	{
		int num = 0, i = 0, j = 0, b = 0;
		for (i = 8; i >= 1; --i)
		{
			b = s[i];
			for (j = 8; j > i; --j)
				if (s[j] = 0)
					s[i] = num % 10, num /= 10;
			return;
		}
	}
	int h_(int s[]) //启发函数H（N） 
	{
		int i = 0, num = 0;
		for (i = 0; i < 9; ++i)
			if (s[i] != end[i])
				++num;
		return num;
	}
	void init() {
		int i = 0;     char a = 0;
		memset(g, -1, sizeof(g));     memset(h, -1, sizeof(h));     for (i = 0; i < 9; ++i)     {
			cin >> now[i];         if (now[i] == 0)             p[1].s = i;
		}
		for (i = 0; i < 9; ++i)         cin >> end[i];
		p[1].x = cantor(&now[0]);     p[1].now = cps(&now[0]);
		g[p[1].x] = 0; h[p[1].x] = h_(&now[0]);     in_[p[1].x] = 1;     all = 1;
	}

	void mtd(int x) //维护堆  
	{
		int d = x;
		if (x * 2 <= all && g[p[x * 2].x] + h[p[x * 2].x]1 && g[p[x].x] + h[p[x].x]g[d.x] + 1)     {
			g[num] = g[d.x] + 1;         if (in_[num] == 0)         {
				++all; if (h[num] == -1)h[num] = h_(&now[0]);
				p[all].x = num, p[all].now = cps(&now[0]), p[all].s = step;             mtu(all); in_[num] = 1;
			}
		}
		return;
	}

	void A_()
	{
		int temp = 0;     while (all >= 1)     {
			if (h[p[1].x] == 0)
			{
				cout < 2)         {
				temp = now[d.s], now[d.s] = now[d.s - 3], now[d.s - 3] = temp;
				Try(d.s - 3);
				temp = now[d.s], now[d.s] = now[d.s - 3], now[d.s - 3] = temp;         }
				if (d.s % 3 != 0)         {
					temp = now[d.s], now[d.s] = now[d.s - 1], now[d.s - 1] = temp;             Try(d.s - 1);
					temp = now[d.s], now[d.s] = now[d.s - 1], now[d.s - 1] = temp;
				}
				if ((d.s + 1) % 3 != 0)         {
					temp = now[d.s], now[d.s] = now[d.s + 1], now[d.s + 1] = temp;             Try(d.s + 1);
					temp = now[d.s], now[d.s] = now[d.s + 1], now[d.s + 1] = temp;
				}
				if (d.s < 6)         {
					temp = now[d.s], now[d.s] = now[d.s + 3], now[d.s + 3] = temp;             Try(d.s + 3);
					temp = now[d.s], now[d.s] = now[d.s + 3], now[d.s + 3] = temp;
				}
			}
			cout << "-1\n";
			return;
		}
	}
};

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	init();
	A_();
	return 0;
}



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
