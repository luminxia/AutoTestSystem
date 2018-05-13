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

// ��ʼ�����ݿ�����
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
		AfxMessageBox("���ݿ�����ʧ��");
	}
}

// ��ü�¼
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

// �˳�����
void Database::ExitConnect()
{
    if(pRecordset!=NULL) pRecordset->Close();
	pConnection->Close();
	pRecordset =NULL ;
	pConnection =NULL;
	CoUninitialize();
}

// ����
void Database::MyCommand(CString strSql)
{
	BSTR bstrSQL = strSql.AllocSysString();

	// ����ָ��
	_CommandPtr pCommand;
	pCommand.CreateInstance(__uuidof(Command));
	pCommand->ActiveConnection = pConnection;
	pCommand->CommandText = bstrSQL;
	pRecordset = pCommand->Execute(NULL, NULL,adCmdText);
	AfxMessageBox("CMD Success!");
}