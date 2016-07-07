// LevelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tetris.h"
#include "LevelDlg.h"
#include "afxdialogex.h"


// CLevelDlg �Ի���ʵ��

IMPLEMENT_DYNAMIC(CLevelDlg, CDialogEx)

CLevelDlg::CLevelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLevelDlg::IDD, pParent)
{
	m_level = 0;		//��ʼ����Ϸ�ȼ�
}

CLevelDlg::~CLevelDlg()
{
}

void CLevelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
											//��Ϸ�ȼ����ñ�������Դӳ��
	DDX_Text(pDX, IDC_LEVEL_EDIT, m_level);
	DDV_MinMaxInt(pDX, m_level,1, 10);		//���ñ���������Сֵ
}


BEGIN_MESSAGE_MAP(CLevelDlg, CDialogEx)
END_MESSAGE_MAP()


// CLevelDlg ��Ϣ�������


void CLevelDlg::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (UpdateData(TRUE))
	{
		CString tmp;
		tmp.Format("%d", m_level);
		

		WritePrivateProfileString("SETUP", "level", tmp, ".\\setup.ini");
		
		
		CDialogEx::OnOK();
	}
	
}


void CLevelDlg::OnCancel()
{
	// TODO:  �ڴ����ר�ô����/����û���

	CDialogEx::OnCancel();
}


BOOL CLevelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	char pszTmp[128] = { 0 };
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetPrivateProfileString("SETUP", "level", "0", pszTmp, 127, ".\\setup.ini");

	m_level = atoi(pszTmp);

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
