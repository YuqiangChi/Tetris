#pragma once
#ifndef __RULE_H__
#define __RULE_H__

class CRule
{
public:
	CRule();
	~CRule();
	void SetLevel(int nLevel);		//设置当前等级
	int UpLevel(int nLine);			//升级判断
	bool Win(int Now[4][4], int Russia[100][100], CPoint NowPosition);
									//胜负判断
	void drawScore(CDC* pDC);
private:
	int m_nLevel;					//当前等级

};

#endif // !__RULE_H__