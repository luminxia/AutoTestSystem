#if !defined(AFX_MODIFYSTUDENTDLG_H__C206275B_8053_4960_B54B_78E6CA1117C9__INCLUDED_)
#define AFX_MODIFYSTUDENTDLG_H__C206275B_8053_4960_B54B_78E6CA1117C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModifyStudentDlg.h : header file
//

#include "Database.h"

/////////////////////////////////////////////////////////////////////////////
// ModifyStudentDlg dialog

class ModifyStudentDlg : public CDialog
{
// Construction
public:
	ModifyStudentDlg(CWnd* pParent = NULL, CString snum = "");   // standard constructor

// Dialog Data
	//{{AFX_DATA(ModifyStudentDlg)
	enum { IDD = IDD_MODIFY_STUDENT_DIALOG };
	CString	m_birthday;
	CString	m_composition_principle;
	CString	m_operating_system;
	CString	m_password;
	CString	m_student_number;
	CString	m_user_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ModifyStudentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ModifyStudentDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonStudentNumber();
	afx_msg void OnButtonUserName();
	afx_msg void OnButtonBirthday();
	afx_msg void OnButtonOperatingSystem();
	afx_msg void OnButtonPassword();
	afx_msg void OnButtonCompositionPrinciple();
	afx_msg void OnButtonComplete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CString stu_num;
	Database dB;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFYSTUDENTDLG_H__C206275B_8053_4960_B54B_78E6CA1117C9__INCLUDED_)
