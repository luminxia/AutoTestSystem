#if !defined(AFX_STUDENTMANAGERDLG_H__A4B9EEBF_879C_4816_AEB4_3864E422C9C7__INCLUDED_)
#define AFX_STUDENTMANAGERDLG_H__A4B9EEBF_879C_4816_AEB4_3864E422C9C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentManagerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// StudentManagerDlg dialog

class StudentManagerDlg : public CDialog
{
// Construction
public:
	StudentManagerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(StudentManagerDlg)
	enum { IDD = IDD_STUDENT_MANAGER_DIALOG };
		// NOTE: the ClassWizard will add data members here
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
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTMANAGERDLG_H__A4B9EEBF_879C_4816_AEB4_3864E422C9C7__INCLUDED_)
