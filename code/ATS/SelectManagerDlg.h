#if !defined(AFX_SELECTMANAGERDLG_H__2BA0F26F_A061_45D0_B717_5B5807E774AA__INCLUDED_)
#define AFX_SELECTMANAGERDLG_H__2BA0F26F_A061_45D0_B717_5B5807E774AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectManagerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SelectManagerDlg dialog

class SelectManagerDlg : public CDialog
{
// Construction
public:
	SelectManagerDlg(CWnd* pParent = NULL);   // standard constructor
	int managerSelect;

// Dialog Data
	//{{AFX_DATA(SelectManagerDlg)
	enum { IDD = IDD_SELECT_MANAGER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SelectManagerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SelectManagerDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTMANAGERDLG_H__2BA0F26F_A061_45D0_B717_5B5807E774AA__INCLUDED_)
