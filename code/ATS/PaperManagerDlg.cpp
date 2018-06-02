// PaperManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "PaperManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PaperManagerDlg dialog


PaperManagerDlg::PaperManagerDlg(CWnd* pParent /*=NULL*/, Question *newq, long id, long idMax, CString className/*,Database *dB = NULL*/)
	: CDialog(PaperManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(PaperManagerDlg)
	m_id = id;
	m_choice_a = _T("");
	m_choice_b = _T("");
	m_choice_c = _T("");
	m_choice_d = _T("");
	m_question = _T("");
	myclassName = className;
	myidMax = idMax ;
	//}}AFX_DATA_INIT

	if(id == 0)
	{
		m_id = id;
		m_question = "";
		m_choice_a = "";
		m_choice_b = "";
		m_choice_c = "";
		m_choice_d = "";
		
		for(int i = 0; i < 4; i++)
		{
			myScore[i] = 0;	
		}
	}
	else
	{
		m_id = id;
		m_question = newq->question;
		m_choice_a = newq->choice_a;
		m_choice_b = newq->choice_b;
		m_choice_c = newq->choice_c;
		m_choice_d = newq->choice_d;
		
		for(int i = 0; i < 4; i++)
		{
			myScore[i] = newq->score[i];
		}
	}
}


void PaperManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PaperManagerDlg)
	DDX_Control(pDX, IDC_COMBO_D, m_cb_d);
	DDX_Control(pDX, IDC_COMBO_C, m_cb_c);
	DDX_Control(pDX, IDC_COMBO_B, m_cb_b);
	DDX_Control(pDX, IDC_COMBO_A, m_cb_a);
	DDX_Text(pDX, IDC_EDIT_PAGE, m_id);
	DDX_Text(pDX, IDC_EDIT_A, m_choice_a);
	DDX_Text(pDX, IDC_EDIT_B, m_choice_b);
	DDX_Text(pDX, IDC_EDIT_C, m_choice_c);
	DDX_Text(pDX, IDC_EDIT_D, m_choice_d);
	DDX_Text(pDX, IDC_EDIT_QUESTION, m_question);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PaperManagerDlg, CDialog)
	//{{AFX_MSG_MAP(PaperManagerDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PaperManagerDlg message handlers

BOOL PaperManagerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	m_cb_a.SetCurSel(myScore[0]);
	m_cb_b.SetCurSel(myScore[1]);
	m_cb_c.SetCurSel(myScore[2]);
	m_cb_d.SetCurSel(myScore[3]);
	UpdateData(FALSE);

	dB.OnInitADOConn();
	addFlag = false;
	strSql = "select * from Paper where course_name ='"+myclassName+"'";

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PaperManagerDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	if(!addFlag)
	{
		addFlag = true;
		
		m_question = "";
		m_choice_a = "";
		m_choice_b = "";
		m_choice_c = "";
		m_choice_d = "";
		
		for(int i = 0; i < 4; i++)
		{
			myScore[i] = 0;
		}
		
		m_cb_a.SetCurSel(myScore[0]);
		m_cb_b.SetCurSel(myScore[1]);
		m_cb_c.SetCurSel(myScore[2]);
		m_cb_d.SetCurSel(myScore[3]);

		SetDlgItemText(IDC_BUTTON_ADD, "确认增加");
		m_id ++;
		myidMax ++;
		UpdateData(FALSE);
		
		return;
	}
	else
	{
		UpdateData(TRUE);
		myScore[0] = m_cb_a.GetCurSel();
		myScore[1] = m_cb_b.GetCurSel();
		myScore[2] = m_cb_c.GetCurSel();
		myScore[3] = m_cb_d.GetCurSel();
		
		dB.GetRecord(strSql);
		try
		{
			dB.pRecordset->AddNew();
			dB.pRecordset->PutCollect("course_name", _variant_t(myclassName));
			dB.pRecordset->PutCollect("question", _variant_t(m_question));
			
			dB.pRecordset->PutCollect("choice_a", _variant_t(m_choice_a));
			dB.pRecordset->PutCollect("choice_b", _variant_t(m_choice_b));
			dB.pRecordset->PutCollect("choice_c", _variant_t(m_choice_c));
			dB.pRecordset->PutCollect("choice_d", _variant_t(m_choice_d));
			
			dB.pRecordset->PutCollect("score_a", (long)(myScore[0]));
			dB.pRecordset->PutCollect("score_b", (long)(myScore[1]));
			dB.pRecordset->PutCollect("score_c", (long)(myScore[2]));
			dB.pRecordset->PutCollect("score_d", (long)(myScore[3]));							
			dB.pRecordset->Update();
			
			AfxMessageBox("插入成功！");
			dB.pRecordset->Close();
		}
		catch(_com_error *e)
		{
			AfxMessageBox(e->ErrorMessage());
			m_id--;
			return;
		}
		addFlag = false;
		SetDlgItemText(IDC_BUTTON_ADD, "增加新题");
	}
}

void PaperManagerDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	myScore[0] = m_cb_a.GetCurSel();
	myScore[1] = m_cb_b.GetCurSel();
	myScore[2] = m_cb_c.GetCurSel();
	myScore[3] = m_cb_d.GetCurSel();
	
	dB.pRecordset.CreateInstance(__uuidof(Recordset));
	dB.pRecordset = dB.GetRecord(strSql);
	try
	{
		dB.pRecordset->MoveFirst();
		dB.pRecordset->Move(m_id - 1);
		dB.pRecordset->PutCollect("question", _variant_t(m_question));
		
		dB.pRecordset->PutCollect("choice_a", _variant_t(m_choice_a));
		dB.pRecordset->PutCollect("choice_b", _variant_t(m_choice_b));
		dB.pRecordset->PutCollect("choice_c", _variant_t(m_choice_c));
		dB.pRecordset->PutCollect("choice_d", _variant_t(m_choice_d));

		dB.pRecordset->PutCollect("score_a", (long)(myScore[0]));
		dB.pRecordset->PutCollect("score_b", (long)(myScore[1]));
		dB.pRecordset->PutCollect("score_c", (long)(myScore[2]));
		dB.pRecordset->PutCollect("score_d", (long)(myScore[3]));								
		dB.pRecordset->Update();
		dB.pRecordset->Close();
		MessageBox("修改成功！");
		
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
		return;
	}
}

void PaperManagerDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	if(m_id == 0)
	{
		MessageBox("无题可删！");
		return;
	}
	dB.pRecordset.CreateInstance(__uuidof(Recordset));
	dB.pRecordset = dB.GetRecord(strSql);
	try
	{
		dB.pRecordset->MoveFirst();
		dB.pRecordset->Move(m_id - 1);
		dB.pRecordset->Delete(adAffectCurrent);					
		dB.pRecordset->Update();
		dB.pRecordset->Close();
		AfxMessageBox( "删除成功!");
		m_id = m_id - 1;
		myidMax --;
		UpdateData(FALSE);
	} 
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
		return;
	}

	UpdateData(TRUE);
	
	if(m_id > 0)
	{
		dB.pRecordset.CreateInstance(__uuidof(Recordset));
		dB.GetRecord(strSql);
		dB.GetQuestion(m_id);
		m_question = dB.theQuestion.question;
		m_choice_a = dB.theQuestion.choice_a;
		m_choice_b = dB.theQuestion.choice_b;
		m_choice_c = dB.theQuestion.choice_c;
		m_choice_d = dB.theQuestion.choice_d;
		dB.pRecordset->Close();
		
		for(int i = 0; i < 4; i++)
		{
			myScore[i] = dB.theQuestion.score[i];
		}
		m_cb_a.SetCurSel(myScore[0]);
		m_cb_b.SetCurSel(myScore[1]);
		m_cb_c.SetCurSel(myScore[2]);
		m_cb_d.SetCurSel(myScore[3]);
	}
	else
	{
		m_question = "";
		m_choice_a = "";
		m_choice_b = "";
		m_choice_c = "";
		m_choice_d = "";
		
		for(int i = 0; i < 4; i++)
		{
			myScore[i] = 0;
		}
		
		m_cb_a.SetCurSel(myScore[0]);
		m_cb_b.SetCurSel(myScore[1]);
		m_cb_c.SetCurSel(myScore[2]);
		m_cb_d.SetCurSel(myScore[3]);	
	}
	UpdateData(FALSE);
}
