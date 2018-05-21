#if !defined(AFX_PAPERMANAGERDLG_H__48FAE22B_9F6C_46C6_B0D6_3CC27D63F75A__INCLUDED_)
#define AFX_PAPERMANAGERDLG_H__48FAE22B_9F6C_46C6_B0D6_3CC27D63F75A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaperManagerDlg.h : header file
//

#include "Question.h"

/////////////////////////////////////////////////////////////////////////////
// PaperManagerDlg dialog

class PaperManagerDlg : public CDialog
{
// Construction
public:
	PaperManagerDlg(CWnd* pParent = NULL, Question *newq = NULL, long id = 0, long idMax = 0, CString className = ""/*,Database *dB = NULL*/);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PaperManagerDlg)
	enum { IDD = IDD_PAPER_MANAGER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PaperManagerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PaperManagerDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAPERMANAGERDLG_H__48FAE22B_9F6C_46C6_B0D6_3CC27D63F75A__INCLUDED_)