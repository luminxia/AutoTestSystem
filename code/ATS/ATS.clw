; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=RegisterDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ATS.h"

ClassCount=11
Class1=CATSApp
Class2=CATSDlg
Class3=CAboutDlg

ResourceCount=11
Resource1=IDD_PAPER_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_REGISTER_DIALOG
Class4=RegisterDlg
Resource4=IDD_SCORE_DIALOG
Class5=SelectClassDlg
Resource5=IDD_SELECT_CLASS_DIALOG
Class6=PaperDlg
Resource6=IDD_PAPER_MANAGER_DIALOG
Class7=ScoreDlg
Resource7=IDD_SELECT_MANAGER_DIALOG
Class8=SelectManagerDlg
Resource8=IDD_ATS_DIALOG
Class9=StudentManagerDlg
Resource9=IDD_ABOUTBOX
Class10=PaperManagerDlg
Resource10=IDD_STUDENT_MANAGER_DIALOG
Class11=ModifyStudentDlg
Resource11=IDD_MODIFY_STUDENT_DIALOG

[CLS:CATSApp]
Type=0
HeaderFile=ATS.h
ImplementationFile=ATS.cpp
Filter=N

[CLS:CATSDlg]
Type=0
HeaderFile=ATSDlg.h
ImplementationFile=ATSDlg.cpp
Filter=D
LastObject=CATSDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ATSDlg.h
ImplementationFile=ATSDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ATS_DIALOG]
Type=1
Class=CATSDlg
ControlCount=9
Control1=IDC_RADIO_STUDENT,button,1342177289
Control2=IDC_RADIO_ADMINISTRATOR,button,1342177289
Control3=IDC_STATIC_USER_NAME,static,1342308352
Control4=IDC_EDIT_USER_NAME,edit,1350631552
Control5=IDC_STATIC_PASSWORD,static,1342308352
Control6=IDC_EDIT_PASSWORD,edit,1350631584
Control7=IDC_BUTTON_LOGIN,button,1342242816
Control8=IDC_BUTTON_REGISTER,button,1342242816
Control9=IDC_STATIC_ATUO_TEST_SYSTEM,static,1342308352

[DLG:IDD_REGISTER_DIALOG]
Type=1
Class=RegisterDlg
ControlCount=15
Control1=IDC_STATIC_STUDENT_NUMBER,static,1342308352
Control2=IDC_STATIC_NAME,static,1342308352
Control3=IDC_STATIC_REGISTER_PASSWORD,static,1342308352
Control4=IDC_STATIC_REPEAT_PASSWORD,static,1342308352
Control5=IDC_STATIC_BIRTHDAY,static,1342308352
Control6=IDC_EDIT_STUDENT_NUMBER,edit,1350631552
Control7=IDC_EDIT_NAME,edit,1350631552
Control8=IDC_EDIT_REGISTER_PASSWORD,edit,1350631584
Control9=IDC_EDIT_REPEAT_PASSWORD,edit,1350631584
Control10=IDC_EDIT_BIRTHDAY,edit,1350631552
Control11=IDC_RADIO_BOY,button,1342177289
Control12=IDC_RADIO_GIRL,button,1342177289
Control13=IDC_STATIC_SEX,static,1342308352
Control14=IDC_BUTTON_OK,button,1342242816
Control15=IDCANCEL,button,1342242816

[CLS:RegisterDlg]
Type=0
HeaderFile=RegisterDlg.h
ImplementationFile=RegisterDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_STUDENT_NUMBER
VirtualFilter=dWC

[DLG:IDD_SELECT_CLASS_DIALOG]
Type=1
Class=SelectClassDlg
ControlCount=3
Control1=IDC_RADIO_OPERATING_SYSTEM,button,1342177289
Control2=IDC_RADIO_COMPOSITION_PRINCIPLE,button,1342177289
Control3=IDC_BUTTON_SC_OK,button,1342242816

[CLS:SelectClassDlg]
Type=0
HeaderFile=SelectClassDlg.h
ImplementationFile=SelectClassDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_SC_OK
VirtualFilter=dWC

[DLG:IDD_PAPER_DIALOG]
Type=1
Class=PaperDlg
ControlCount=9
Control1=IDC_STATIC_COUNTDOWM,static,1342308352
Control2=IDC_EDIT_QUESTION,edit,1342244932
Control3=IDC_RADIO_A,button,1342177289
Control4=IDC_RADIO_B,button,1342177289
Control5=IDC_RADIO_C,button,1342177289
Control6=IDC_RADIO_D,button,1342177289
Control7=IDC_BUTTON_NEXT,button,1342242816
Control8=IDC_BUTTON_SUBMIT,button,1342242816
Control9=IDC_STATIC,static,1342308352

[CLS:PaperDlg]
Type=0
HeaderFile=PaperDlg.h
ImplementationFile=PaperDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STATIC_COUNTDOWM
VirtualFilter=dWC

[DLG:IDD_SCORE_DIALOG]
Type=1
Class=ScoreDlg
ControlCount=7
Control1=IDC_STATIC_STUDENT_NUMBER,static,1342308352
Control2=IDC_STATIC_SCORE,static,1342308352
Control3=IDC_STATIC_CLASS,static,1342308352
Control4=IDC_EDIT_STUDENT_NUMBER,edit,1350631552
Control5=IDC_EDIT_SCORE,edit,1350631552
Control6=IDC_EDIT_CLASS,edit,1350631552
Control7=IDC_BUTTON_S_OK,button,1342242816

[CLS:ScoreDlg]
Type=0
HeaderFile=ScoreDlg.h
ImplementationFile=ScoreDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_SCORE
VirtualFilter=dWC

[DLG:IDD_SELECT_MANAGER_DIALOG]
Type=1
Class=SelectManagerDlg
ControlCount=3
Control1=IDC_RADIO_STUDENT_MANAGER,button,1342177289
Control2=IDC_RADIO_PAPER,button,1342177289
Control3=IDC_BUTTON_SM_OK,button,1342242816

[CLS:SelectManagerDlg]
Type=0
HeaderFile=SelectManagerDlg.h
ImplementationFile=SelectManagerDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_SM_OK
VirtualFilter=dWC

[DLG:IDD_STUDENT_MANAGER_DIALOG]
Type=1
Class=StudentManagerDlg
ControlCount=4
Control1=IDC_LIST_STUDENT,SysListView32,1350631425
Control2=IDC_STATIC_STUDENT_NUMBER,static,1342308352
Control3=IDC_EDIT_STUDENT_NUMBER,edit,1350631552
Control4=IDC_BUTTON_SEARCH,button,1342242816

[CLS:StudentManagerDlg]
Type=0
HeaderFile=StudentManagerDlg.h
ImplementationFile=StudentManagerDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_STUDENT_NUMBER
VirtualFilter=dWC

[DLG:IDD_PAPER_MANAGER_DIALOG]
Type=1
Class=PaperManagerDlg
ControlCount=22
Control1=IDC_STATIC_QUESTION,static,1342308352
Control2=IDC_EDIT_QUESTION,edit,1350631552
Control3=IDC_STATIC_A,static,1342308352
Control4=IDC_STATIC_B,static,1342308352
Control5=IDC_STATIC_C,static,1342308352
Control6=IDC_STATIC_D,static,1342308352
Control7=IDC_EDIT_A,edit,1350631552
Control8=IDC_EDIT_B,edit,1350631552
Control9=IDC_EDIT_C,edit,1350631552
Control10=IDC_EDIT_D,edit,1350631552
Control11=IDC_COMBO_A,combobox,1344340226
Control12=IDC_COMBO_B,combobox,1344340226
Control13=IDC_COMBO_C,combobox,1344340226
Control14=IDC_COMBO_D,combobox,1344340226
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_PAGE,edit,1350631552
Control18=IDC_BUTTON_OK,button,1342242816
Control19=IDC_BUTTON_ADD,button,1342242816
Control20=IDC_BUTTON_DELETE,button,1342242816
Control21=IDC_BUTTON_SAVE,button,1342242816
Control22=IDC_BUTTON_COMPLETE,button,1342242816

[CLS:PaperManagerDlg]
Type=0
HeaderFile=PaperManagerDlg.h
ImplementationFile=PaperManagerDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=PaperManagerDlg
VirtualFilter=dWC

[DLG:IDD_MODIFY_STUDENT_DIALOG]
Type=1
Class=ModifyStudentDlg
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_STUDENT_NUMBER,edit,1350633600
Control8=IDC_EDIT_USER_NAME,edit,1350633600
Control9=IDC_EDIT_BIRTHDAY,edit,1350633600
Control10=IDC_EDIT_PASSWORD,edit,1350633600
Control11=IDC_EDIT_OPERATING_SYSTEM,edit,1350633600
Control12=IDC_EDIT_COMPOSITION_PRINCIPLE,edit,1350633600
Control13=IDC_BUTTON_COMPLETE,button,1342242816
Control14=IDC_BUTTON_STUDENT_NUMBER,button,1342242816
Control15=IDC_BUTTON_USER_NAME,button,1342242816
Control16=IDC_BUTTON_BIRTHDAY,button,1342242816
Control17=IDC_BUTTON_OPERATING_SYSTEM,button,1342242816
Control18=IDC_BUTTON_PASSWORD,button,1342242816
Control19=IDC_BUTTON_COMPOSITION_PRINCIPLE,button,1342242816

[CLS:ModifyStudentDlg]
Type=0
HeaderFile=ModifyStudentDlg.h
ImplementationFile=ModifyStudentDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ModifyStudentDlg
VirtualFilter=dWC

