// ATSDlg.h : header file
//

#if !defined(AFX_ATSDLG_H__6695C838_2AF2_4DD1_876F_BBC7E0BD955E__INCLUDED_)
#define AFX_ATSDLG_H__6695C838_2AF2_4DD1_876F_BBC7E0BD955E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

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
		// NOTE: the ClassWizard will add data members here
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATSDLG_H__6695C838_2AF2_4DD1_876F_BBC7E0BD955E__INCLUDED_)