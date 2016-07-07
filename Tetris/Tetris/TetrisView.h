
// TetrisView.h : CTetrisView ��Ľӿ�
//

#pragma once

#include "resource.h"


class CTetrisView : public CFormView
{
protected: // �������л�����
	CTetrisView();
	DECLARE_DYNCREATE(CTetrisView)

public:
	enum{ IDD = IDD_TETRIS_FORM };

// ����
public:
	CTetrisDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CTetrisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLevelSetup();
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnPlayMusic();
	afx_msg void OnStopMusic();
};

#ifndef _DEBUG  // TetrisView.cpp �еĵ��԰汾
inline CTetrisDoc* CTetrisView::GetDocument() const
   { return reinterpret_cast<CTetrisDoc*>(m_pDocument); }
#endif

