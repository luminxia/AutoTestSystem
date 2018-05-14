// Database.cpp: implementation of the Database class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ATS.h"
#include "Database.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Database::Database()
{

}

Database::~Database()
{

}

// 初始化数据库连接
void Database::OnInitADOConn()
{
	CoInitialize(NULL);
	pConnection.CreateInstance(__uuidof(Connection));
	
	try
	{
		pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=ATS.mdb","","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("数据库连接失败");
	}
}

// 获得记录
_RecordsetPtr Database::GetRecord(CString strSql)
{
	if (pRecordset==NULL)
	{
		OnInitADOConn();
		
		pRecordset.CreateInstance(__uuidof(Recordset));
	}
	pRecordset.CreateInstance(__uuidof(Recordset));
	
	BSTR bstrSQL = strSql.AllocSysString();
	try
	{
		pRecordset->Open(bstrSQL,
			pConnection.GetInterfacePtr(),
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}

	return pRecordset;
}

// 退出连接
void Database::ExitConnect()
{
    if(pRecordset!=NULL) pRecordset->Close();
	pConnection->Close();
	pRecordset =NULL ;
	pConnection =NULL;
	CoUninitialize();
}

// 命令
void Database::MyCommand(CString strSql)
{
	BSTR bstrSQL = strSql.AllocSysString();

	// 命令指针
	_CommandPtr pCommand;
	pCommand.CreateInstance(__uuidof(Command));
	pCommand->ActiveConnection = pConnection;
	pCommand->CommandText = bstrSQL;
	pRecordset = pCommand->Execute(NULL, NULL,adCmdText);
	AfxMessageBox("CMD Success!");
}

// 获取记录数量
int Database::GetRecordNum(CString fromTable)
{
	BSTR bstrSQL = fromTable.AllocSysString(); 
	
	_variant_t RecordsAffected;
    pRecordset = pConnection->Execute(bstrSQL, &RecordsAffected, adCmdText);
    _variant_t vIndex = (long)0;
    _variant_t vCount = pRecordset->GetCollect(vIndex);
	return (long)vCount;
}

// 获取问题
Question* Database::GetQuestion(long questionId)
{
	int i = questionId - 1;
	pRecordset->MoveFirst();
	pRecordset->Move(i);
	var = pRecordset->GetCollect("question"); 
	if(var.vt != VT_NULL) 
		theQuestion.question= (LPCSTR)_bstr_t(var); 
	
	var = pRecordset->GetCollect("choice_a"); 
	if(var.vt != VT_NULL) 
		theQuestion.choice_a = (LPCSTR)_bstr_t(var); 
	var = pRecordset->GetCollect("choice_b"); 
	if(var.vt != VT_NULL) 
		theQuestion.choice_b = (LPCSTR)_bstr_t(var); 
	var = pRecordset->GetCollect("choice_c"); 
	if(var.vt != VT_NULL) 
		theQuestion.choice_c = (LPCSTR)_bstr_t(var); 
	var = pRecordset->GetCollect("choice_d"); 
	if(var.vt != VT_NULL) 
		theQuestion.choice_d = (LPCSTR)_bstr_t(var); 
	
	
	var = pRecordset->GetCollect("score_a"); 
	if(var.vt != VT_NULL) 
		theQuestion.score[0] = (long)var;	
	var = pRecordset->GetCollect("score_b"); 
	if(var.vt != VT_NULL) 
		theQuestion.score[1] = var.lVal; 	
	var = pRecordset->GetCollect("score_c"); 
	if(var.vt != VT_NULL) 
		theQuestion.score[2] = var.lVal; 
	var = pRecordset->GetCollect("score_d"); 
	if(var.vt != VT_NULL) 
		theQuestion.score[3] = var.lVal; 
	
	return &theQuestion;
}