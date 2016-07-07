// LevelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tetris.h"
#include "LevelDlg.h"
#include "afxdialogex.h"


// CLevelDlg 对话框实现

IMPLEMENT_DYNAMIC(CLevelDlg, CDialogEx)

CLevelDlg::CLevelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLevelDlg::IDD, pParent)
{
	m_level = 0;		//初始化游戏等级
}

CLevelDlg::~CLevelDlg()
{
}

void CLevelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
											//游戏等级设置变量与资源映射
	DDX_Text(pDX, IDC_LEVEL_EDIT, m_level);
	DDV_MinMaxInt(pDX, m_level,1, 10);		//设置变量最大和最小值
}


BEGIN_MESSAGE_MAP(CLevelDlg, CDialogEx)
END_MESSAGE_MAP()


// CLevelDlg 消息处理程序


void CLevelDlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类
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
	// TODO:  在此添加专用代码和/或调用基类

	CDialogEx::OnCancel();
}


BOOL CLevelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	char pszTmp[128] = { 0 };
	// TODO:  在此添加额外的初始化
	GetPrivateProfileString("SETUP", "level", "0", pszTmp, 127, ".\\setup.ini");

	m_level = atoi(pszTmp);

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
