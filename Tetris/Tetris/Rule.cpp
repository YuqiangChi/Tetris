#include "stdafx.h"
#include "Rule.h"
#include <mmsystem.h>


CRule::CRule()
{
}


CRule::~CRule()
{
}

void CRule::SetLevel(int nLevel)	//设置当前游戏等级
{
	m_nLevel = nLevel;
}

int CRule::UpLevel(int nLine)		//升级判断接口
{
	if (nLine / 30)					//如果可以整除，等级升级
	{
		m_nLevel++;
		sndPlaySound("..\\upgrade.wav",SND_ASYNC);
	}
	return m_nLevel;				//返回当前游戏等级
}

bool CRule::Win(int Now[4][4], int Russia[100][100], CPoint NowPosition)
{
	if (m_nLevel == 11)			//游戏等级超过最高
	{							//超过10级游戏结束
		sndPlaySound("..\\victory.wav", SND_ASYNC);

		return true;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Now[i][j] == 1)
			{//到了顶点
				if (Russia[i+NowPosition.x][j+NowPosition.y]==1)
				{
					sndPlaySound("..\\fail.wav", SND_ASYNC);
					return true;	//游戏结束
					
				}
			}
		}
	}

	return false;					//游戏未结束
}