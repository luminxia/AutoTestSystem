; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CATSDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ATS.h"

ClassCount=6
Class1=CATSApp
Class2=CATSDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_REGISTER_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=RegisterDlg
Resource4=IDD_ATS_DIALOG
Class5=SelectClassDlg
Resource5=IDD_SELECT_CLASS_DIALOG
Class6=PaperDlg
Resource6=IDD_PAPER_DIALOG

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
LastObject=IDC_EDIT_PASSWORD
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
LastObject=IDC_BUTTON_OK

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
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_QUESTION,edit,1342244992
Control3=IDC_RADIO_A,button,1342177289
Control4=IDC_RADIO_B,button,1342177289
Control5=IDC_RADIO_C,button,1342177289
Control6=IDC_RADIO_D,button,1342177289
Control7=IDC_BUTTON_NEXT,button,1342242816

[CLS:PaperDlg]
Type=0
HeaderFile=PaperDlg.h
ImplementationFile=PaperDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_NEXT

