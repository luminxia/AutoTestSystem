#if !defined(AFX_SELECTCLASSDLG_H__7DE97B0A_E6E0_4134_8F05_C541BAD3168F__INCLUDED_)
#define AFX_SELECTCLASSDLG_H__7DE97B0A_E6E0_4134_8F05_C541BAD3168F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectClassDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SelectClassDlg dialog

class SelectClassDlg : public CDialog
{
// Construction
public:
	SelectClassDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SelectClassDlg)
	enum { IDD = IDD_SELECT_CLASS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SelectClassDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SelectClassDlg)
	afx_msg void OnButtonScOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// Ñ¡Ôñ¿Î³Ì
	int selectClass;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTCLASSDLG_H__7DE97B0A_E6E0_4134_8F05_C541BAD3168F__INCLUDED_)
