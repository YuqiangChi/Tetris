#include "stdafx.h"
#include "Russia.h"
#include "Tetris.h"


CRussia::CRussia()
{
}


CRussia::~CRussia()
{
}

//绘分数和等级
void CRussia::DrawSocre(CDC*pDC)
{
	int nOldDC = pDC->SaveDC();
	CFont font;
									//设置字体
	if (0 == font.CreatePointFont(300, "Comic Sans MS"))
	{
		AfxMessageBox("Can't Create Font");
	}
	pDC->SelectObject(&font);

	CString str;
	pDC->SetTextColor(RGB(39, 244, 10));	//设置字体颜色及背景颜色
	pDC->SetBkColor(RGB(255, 255, 0));

	str.Format("%d", m_Level);
	if (m_Level >= 0)
	{
		pDC->TextOut(420, 120, str);	//输出等级数字
	}
	str.Format("%d", m_CountLine);
	if (m_Speed>=0)
	{
		pDC->TextOut(420, 64, str);		//输出消除行数
	}
	str.Format("%d", m_Score);
	if (m_Score >= 0)
	{
		pDC->TextOut(420, 2, str);		//输出分数
	}
	pDC->RestoreDC(nOldDC);
}

void CRussia::LineDelete()
{
	int m = 0;
	bool flag = 0;
	for (int i = 0; i < m_RowCount; i++)
	{
		flag = true;
		for (int j = 0; j < m_ColCount; j++)
		{
			if (Russia[i][j]==0)
			{
				flag = false;
			}
		}
		if (flag == true)
		{
			m++;
			for (int k = i; k>0; k--)
			{
				for (int l = 0; l < m_ColCount; l++)
				{
					Russia[k][l] = Russia[k - 1][l];
				}
			}
			for (int l = 0; l < m_ColCount;l++)
			{
				Russia[0][1] = 0;
			}
		}
	}

	//DrawWill();

	switch (m)
	{
	case 1:
		m_Score = m_Score + 10 + m_Level * 10;
		break;
	case 2:
		m_Score = m_Score + 30 + m_Level * 10;
		break;
	case 3:
		m_Score = m_Score + 50 + m_Level * 10;
		break;
	case 4:
		m_Score = m_Score + 100 + m_Level * 10;
		break;
	default:
		break;
	}

	m_CountLine += m;
	m_Level = rule.UpLevel(m_CountLine);

	end = rule.Win(Now, Russia, NowPosition);
}