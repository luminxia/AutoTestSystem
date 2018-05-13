#if !defined(AFX_SCORE_H__4373C9D0_3A11_4D55_85BF_ABD9777FCBDA__INCLUDED_)
#define AFX_SCORE_H__4373C9D0_3A11_4D55_85BF_ABD9777FCBDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Score.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScore dialog

class CScore : public CDialog
{
// Construction
public:
	CScore(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScore)
	enum { IDD = IDD_SCORE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScore)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScore)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCORE_H__4373C9D0_3A11_4D55_85BF_ABD9777FCBDA__INCLUDED_)
