#if !defined(AFX_PAPERDLG_H__7F5D1E10_7D53_4C1D_91C7_F1BA929549FB__INCLUDED_)
#define AFX_PAPERDLG_H__7F5D1E10_7D53_4C1D_91C7_F1BA929549FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaperDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PaperDlg dialog

#include "Question.h"

// 身份枚举变量
enum Identity
{
	Nobody,
	Student,
	Administrator
};

class PaperDlg : public CDialog
{
// Construction
public:
	PaperDlg(CWnd* pParent = NULL, Question *q = NULL, bool flag = false);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PaperDlg)
	enum { IDD = IDD_PAPER_DIALOG };
	CString	m_countdown;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PaperDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PaperDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonNext();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonSubmit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 总分数
	int scoreSum;
	// 问题和选项
	CString question, a, b, c, d;
	// 成绩
	int score[4];
	// 是否结束
	bool flag;
	// 倒计时
	int minuteten, minute, secondten, second;
	// 字体变量
	CFont font;

	bool f;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAPERDLG_H__7F5D1E10_7D53_4C1D_91C7_F1BA929549FB__INCLUDED_)
