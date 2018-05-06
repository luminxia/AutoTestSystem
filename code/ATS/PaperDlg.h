#if !defined(AFX_PAPERDLG_H__7F5D1E10_7D53_4C1D_91C7_F1BA929549FB__INCLUDED_)
#define AFX_PAPERDLG_H__7F5D1E10_7D53_4C1D_91C7_F1BA929549FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaperDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PaperDlg dialog

class PaperDlg : public CDialog
{
// Construction
public:
	PaperDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PaperDlg)
	enum { IDD = IDD_PAPER_DIALOG };
		// NOTE: the ClassWizard will add data members here
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
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAPERDLG_H__7F5D1E10_7D53_4C1D_91C7_F1BA929549FB__INCLUDED_)
