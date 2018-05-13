#if !defined(AFX_SCOREDLG_H__9C777B24_8D39_4471_986D_A5D7CC3F1961__INCLUDED_)
#define AFX_SCOREDLG_H__9C777B24_8D39_4471_986D_A5D7CC3F1961__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ScoreDlg dialog

class ScoreDlg : public CDialog
{
// Construction
public:
	ScoreDlg(CWnd* pParent = NULL, CString stu_num = "", CString theClass = "", int score = 0);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ScoreDlg)
	enum { IDD = IDD_SCORE_DIALOG };
	CString	m_class;
	CString	m_score;
	CString	m_stu_num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ScoreDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOREDLG_H__9C777B24_8D39_4471_986D_A5D7CC3F1961__INCLUDED_)
