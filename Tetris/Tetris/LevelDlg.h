#pragma once

//LevelDlg.h ��Ϸ�ȼ����öԻ���������ͷ�ļ�
// CLevelDlg �Ի���������

class CLevelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLevelDlg)

public:
	CLevelDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLevelDlg();

// �Ի�������
	enum { IDD = IDD_LEVEL_DIG };	   //��Դ����
	int m_level;					   //��Ϸ�ȼ����ݳ�Ա

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	
	
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	virtual BOOL OnInitDialog();
};
