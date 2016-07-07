#pragma once

#ifndef __RUSSIA_H__
#define __RUSSIA_H__

#include "Rule.h"

#define KEY_LEFT 1
#define  KEY_RIGHT 2
#define  KEY_DOWN 3
#define  KEY_UP 4

class CRussia
{
public:
	CRussia();
	~CRussia();
	void DrawSocre(CDC*pDC);
	void LineDelete();
	void DrawWill();

	int Russia[100][100];
	int Now[4][4];
	int Will[4][4];
	int After[4][4];
	CPoint NowPosition;
	int Count;
	bool end;
	int m_Level;
	int m_Speed;
	int m_Score;
	int m_CountLine;
	int m_RowCount, m_ColCount;
	CBitmap fkMap;
	CBitmap bkMap;
	CRule rule;
};

#endif



