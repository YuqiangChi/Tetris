#include "stdafx.h"
#include "Rule.h"
#include <mmsystem.h>


CRule::CRule()
{
}


CRule::~CRule()
{
}

void CRule::SetLevel(int nLevel)	//���õ�ǰ��Ϸ�ȼ�
{
	m_nLevel = nLevel;
}

int CRule::UpLevel(int nLine)		//�����жϽӿ�
{
	if (nLine / 30)					//��������������ȼ�����
	{
		m_nLevel++;
		sndPlaySound("..\\upgrade.wav",SND_ASYNC);
	}
	return m_nLevel;				//���ص�ǰ��Ϸ�ȼ�
}

bool CRule::Win(int Now[4][4], int Russia[100][100], CPoint NowPosition)
{
	if (m_nLevel == 11)			//��Ϸ�ȼ��������
	{							//����10����Ϸ����
		sndPlaySound("..\\victory.wav", SND_ASYNC);

		return true;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Now[i][j] == 1)
			{//���˶���
				if (Russia[i+NowPosition.x][j+NowPosition.y]==1)
				{
					sndPlaySound("..\\fail.wav", SND_ASYNC);
					return true;	//��Ϸ����
					
				}
			}
		}
	}

	return false;					//��Ϸδ����
}