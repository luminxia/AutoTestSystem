// Score.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "Score.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScore dialog


CScore::CScore(CWnd* pParent /*=NULL*/)
	: CDialog(CScore::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScore)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CScore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScore)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScore, CDialog)
	//{{AFX_MSG_MAP(CScore)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScore message handlers
