
// TetrisView.cpp : CTetrisView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Tetris.h"
#endif

#include "Russia.h"
#include <mmsystem.h>
#include "LevelDlg.h"
#include "TetrisDoc.h"
#include "TetrisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTetrisView

IMPLEMENT_DYNCREATE(CTetrisView, CFormView)

BEGIN_MESSAGE_MAP(CTetrisView, CFormView)
	ON_COMMAND(ID_VIEW_TOOLBAR, &CTetrisView::OnLevelSetup)
	ON_COMMAND(IDR_PLAY_MUSIC, &CTetrisView::OnPlayMusic)
	ON_COMMAND(IDR_STOP_MUSIC, &CTetrisView::OnStopMusic)
END_MESSAGE_MAP()

// CTetrisView ����/����

CTetrisView::CTetrisView()
	: CFormView(CTetrisView::IDD)
{
	// TODO:  �ڴ˴����ӹ������

}

CTetrisView::~CTetrisView()
{
}

void CTetrisView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CTetrisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CTetrisView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CTetrisView ���

#ifdef _DEBUG
void CTetrisView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTetrisView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTetrisDoc* CTetrisView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTetrisDoc)));
	return (CTetrisDoc*)m_pDocument;
}
#endif //_DEBUG


// CTetrisView ��Ϣ��������





void CTetrisView::OnLevelSetup()
{
	// TODO:  �ڴ�����������������
	CLevelDlg dlg;
	dlg.DoModal();
}


void CTetrisView::OnDraw(CDC* pDC)
{
	// TODO:  �ڴ�����ר�ô����/����û���
	CRussia russia;
	russia.DrawSocre(pDC);
	
	
}


void CTetrisView::OnPlayMusic()
{
	// TODO:  �ڴ�����������������
	sndPlaySound("..\\sound\\BGM.wav", SND_ASYNC | SND_LOOP);
}


void CTetrisView::OnStopMusic()
{
	// TODO:  �ڴ�����������������
	sndPlaySound(NULL, SND_ASYNC);
}