// ATSDlg.h : header file
//

#if !defined(AFX_ATSDLG_H__6695C838_2AF2_4DD1_876F_BBC7E0BD955E__INCLUDED_)
#define AFX_ATSDLG_H__6695C838_2AF2_4DD1_876F_BBC7E0BD955E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PaperDlg.h"
#include "Database.h"
#include "SelectManagerDlg.h"
#include "StudentManagerDlg.h"
#include "PaperManagerDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CATSDlg dialog

class CATSDlg : public CDialog
{
// Construction
public:
	CATSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CATSDlg)
	enum { IDD = IDD_ATS_DIALOG };
	CString	m_user_name;
	CString	m_password;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CATSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CATSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonRegister();
	afx_msg void OnButtonLogin();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 判断是否登录成功
	bool Login();
	// 判断是否创建试卷
	bool CreatePaper();
	// 判断学生管理界面是否创建成功
	bool StudentManagerFace();
	// 判断试卷管理界面是否创建成功
	bool PaperManagerFace();

	// 字体变量
	CFont font;
	// 选择的身份
	Identity selectId;
	// 数据库对象
	Database dB;
	// 类型名
	CString className;
	// 总分数
	long scoreSum;
	// 多变量
	_variant_t var;

	// 背景画刷
	CBrush m_brBk;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATSDLG_H__6695C838_2AF2_4DD1_876F_BBC7E0BD955E__INCLUDED_)
