#if !defined(AFX_STUDENTMANAGERDLG_H__A4B9EEBF_879C_4816_AEB4_3864E422C9C7__INCLUDED_)
#define AFX_STUDENTMANAGERDLG_H__A4B9EEBF_879C_4816_AEB4_3864E422C9C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentManagerDlg.h : header file
//

#include "Database.h"

/////////////////////////////////////////////////////////////////////////////
// StudentManagerDlg dialog

class StudentManagerDlg : public CDialog
{
// Construction
public:
	StudentManagerDlg(CWnd* pParent = NULL);   // standard constructor
	// 显示学生信息
	void ShowStudentInfo();

// Dialog Data
	//{{AFX_DATA(StudentManagerDlg)
	enum { IDD = IDD_STUDENT_MANAGER_DIALOG };
	CListCtrl	m_list;
	Database dB;
	long m_stu_num;
	CString	m_smd_stu_num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(StudentManagerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(StudentManagerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTMANAGERDLG_H__A4B9EEBF_879C_4816_AEB4_3864E422C9C7__INCLUDED_)
