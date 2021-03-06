
// TetrisView.h : CTetrisView 类的接口
//

#pragma once

#include "resource.h"


class CTetrisView : public CFormView
{
protected: // 仅从序列化创建
	CTetrisView();
	DECLARE_DYNCREATE(CTetrisView)

public:
	enum{ IDD = IDD_TETRIS_FORM };

// 特性
public:
	CTetrisDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CTetrisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLevelSetup();
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnPlayMusic();
	afx_msg void OnStopMusic();
};

#ifndef _DEBUG  // TetrisView.cpp 中的调试版本
inline CTetrisDoc* CTetrisView::GetDocument() const
   { return reinterpret_cast<CTetrisDoc*>(m_pDocument); }
#endif

