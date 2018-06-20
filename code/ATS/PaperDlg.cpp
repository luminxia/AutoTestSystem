// PaperDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "PaperDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PaperDlg dialog


PaperDlg::PaperDlg(CWnd* pParent /*=NULL*/, Question *q, bool flag)
	: CDialog(PaperDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(PaperDlg)
	question = q->question;
	a = q->choice_a;
	b = q->choice_b;
	c = q->choice_c;
	d = q->choice_d;	
	scoreSum=0;
	f = flag;
	m_countdown = _T("");
	//}}AFX_DATA_INIT

	for(int i = 0; i < 4; i++)
	{
		score[i]=q->score[i];
	}
}


void PaperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PaperDlg)
	DDX_Text(pDX, IDC_STATIC_COUNTDOWM, m_countdown);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PaperDlg, CDialog)
	//{{AFX_MSG_MAP(PaperDlg)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_SUBMIT, OnButtonSubmit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PaperDlg message handlers

BOOL PaperDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	SetDlgItemText(IDC_EDIT_QUESTION, question);
	SetDlgItemText(IDC_RADIO_A, a);
	SetDlgItemText(IDC_RADIO_B, b);
	SetDlgItemText(IDC_RADIO_C, c);
	SetDlgItemText(IDC_RADIO_D, d);
	
	flag = false;
	
	if(f)
	{
		minuteten = 1;
		minute = 0;
		secondten = 0;
		second = 0;
		m_countdown = "10 : 00";
	}
	else
	{
		m_countdown.Format("%d%d : %d%d", minuteten, minute, secondten, second);
		UpdateData(FALSE);
	}

	SetTimer(1, 1000, NULL);
	SetTimer(2, 540000, NULL);
	SetTimer(3, 600000, NULL);

	UpdateData(TRUE);	
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PaperDlg::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	int s = GetCheckedRadioButton(IDC_RADIO_A, IDC_RADIO_D);	
	if(s == 0)
	{
		MessageBox("请选择！");
	}
	else
	{
		switch(s)
		{
		case IDC_RADIO_A:
			scoreSum = scoreSum + score[0] * 10;
			break;
			
		case IDC_RADIO_B:
			scoreSum = scoreSum + score[1] * 10;
			break;
			
		case IDC_RADIO_C:
			scoreSum = scoreSum + score[2] * 10;
			break;
			
		case IDC_RADIO_D:
			scoreSum = scoreSum + score[3] * 10;
			break;
			
		default:
			break;		
		}
		OnOK();
	}
}

bool startTime = true;
bool endTime = true;
void PaperDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if((nIDEvent == 1) && startTime)
	{
		startTime = false;
		MessageBox("考试时间为10分钟！");
	}
	else if(nIDEvent == 1)
	{
		if(second > 0)
		{
			second --;
		}
		else
		{
			second = 9;
			if(secondten > 0)
			{
				secondten --;
			}
			else
			{
				secondten = 5;
				if(minute > 0)
				{
					minute --;
				}
				else
				{
					minute = 9;
					if(minuteten > 0)
					{
						minuteten --;
					}
					else
					{
						nIDEvent = 3;
					}
				}
			}
		}
		m_countdown.Format("%d%d : %d%d", minuteten, minute, secondten, second);
		UpdateData(FALSE);
	}
	if((nIDEvent == 2) && endTime)
	{
		MessageBox("还剩1分钟结束答题！");
		endTime = false;
	}
	if(nIDEvent == 3)
	{
		MessageBox("考试结束！");
		flag = true;
		OnOK();
	}
	CDialog::OnTimer(nIDEvent);
}


void PaperDlg::OnButtonSubmit() 
{
	// TODO: Add your control notification handler code here
	flag = true;
	OnOK();
}
