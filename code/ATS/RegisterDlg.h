#if !defined(AFX_REGISTERDLG_H__77EC04E9_74F9_4A29_8374_F447EFE020A4__INCLUDED_)
#define AFX_REGISTERDLG_H__77EC04E9_74F9_4A29_8374_F447EFE020A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegisterDlg.h : header file
//

#include "Database.h"

/////////////////////////////////////////////////////////////////////////////
// RegisterDlg dialog

class RegisterDlg : public CDialog
{
// Construction
public:
	RegisterDlg(CWnd* pParent = NULL, Database* dB = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RegisterDlg)
	enum { IDD = IDD_REGISTER_DIALOG };
	CString	m_stu_num;
	CString	m_name;
	CString	m_rpwd;
	CString	m_rrpwd;
	CString	m_birth;
	CString m_sex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RegisterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RegisterDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// Êý¾Ý¿â
	Database* mydB;
	// ÖØ¸´
	bool repeat;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTERDLG_H__77EC04E9_74F9_4A29_8374_F447EFE020A4__INCLUDED_)
