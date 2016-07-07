#pragma once

//LevelDlg.h 游戏等级设置对话框类声明头文件
// CLevelDlg 对话框类声明

class CLevelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLevelDlg)

public:
	CLevelDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLevelDlg();

// 对话框数据
	enum { IDD = IDD_LEVEL_DIG };	   //资源加载
	int m_level;					   //游戏等级数据成员

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	
	
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	virtual BOOL OnInitDialog();
};
