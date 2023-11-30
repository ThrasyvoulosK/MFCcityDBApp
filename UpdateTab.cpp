// UpdateTab.cpp : implementation file
//

#include "pch.h"
#include "MFCcityDBApp.h"
#include "UpdateTab.h"
#include "afxdialogex.h"

#include "WinUser.h"
#include "odbcinst.h"
#include "afxdb.h"
#include "afxcmn.h"
#include "commctrl.h"


// UpdateTab dialog

IMPLEMENT_DYNAMIC(UpdateTab, CPropertyPage)

UpdateTab::UpdateTab()
	: CPropertyPage(IDD_UpdateTab)
{

}

UpdateTab::~UpdateTab()
{
}

void UpdateTab::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UpdateTab, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &UpdateTab::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &UpdateTab::OnBnClickedButton2)
END_MESSAGE_MAP()


// UpdateTab message handlers


void UpdateTab::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CListBox* lbox1;
	CListBox* lbox2;
	CListBox* lbox3;
	CListBox* lbox4;

	lbox1 = (CListBox*)GetDlgItem(IDC_LIST1);
	lbox2 = (CListBox*)GetDlgItem(IDC_LIST2);
	lbox3 = (CListBox*)GetDlgItem(IDC_LIST3);
	lbox4 = (CListBox*)GetDlgItem(IDC_LIST4);

	lbox1->AddString(L"cityID");
	lbox1->AddString(L"cityName");
	lbox1->AddString(L"countryName");
	lbox1->AddString(L"cityPopulation");

	lbox2->AddString(L"=");
	lbox2->AddString(L">=");
	lbox2->AddString(L">");
	lbox2->AddString(L"<=");
	lbox2->AddString(L"<");

	lbox3->AddString(L"cityID");
	lbox3->AddString(L"cityName");
	lbox3->AddString(L"countryName");
	lbox3->AddString(L"cityPopulation");

	lbox4->AddString(L"=");
	lbox4->AddString(L">=");
	lbox4->AddString(L">");
	lbox4->AddString(L"<=");
	lbox4->AddString(L"<");
}


void UpdateTab::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CListBox* lbox1;
	CListBox* lbox2;
	CListBox* lbox3;
	CListBox* lbox4;

	lbox1 = (CListBox*)GetDlgItem(IDC_LIST1);
	lbox2 = (CListBox*)GetDlgItem(IDC_LIST2);
	lbox3 = (CListBox*)GetDlgItem(IDC_LIST3);
	lbox4 = (CListBox*)GetDlgItem(IDC_LIST4);

	CEdit* dbPath = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* value1 = (CEdit*)GetDlgItem(IDC_EDIT2);
	CEdit* value2 = (CEdit*)GetDlgItem(IDC_EDIT5);

	CString sel1;
	CString sel2;
	CString sel3;
	CString sel4;
	CString sel5;
	CString sel6;

	lbox1->GetText(lbox1->GetCurSel(), sel1);
	lbox2->GetText(lbox2->GetCurSel(), sel2);
	GetDlgItem(IDC_EDIT2)->GetWindowText(sel3);

	lbox3->GetText(lbox3->GetCurSel(), sel4);
	lbox4->GetText(lbox4->GetCurSel(), sel5);
	GetDlgItem(IDC_EDIT5)->GetWindowText(sel6);

	CString query;

	CDatabase database;
	CString SqlString;
	CString sDriver = L"MICROSOFT ACCESS DRIVER (*.mdb)";
	CString sDsn;

	CString sFile;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sFile);

	// Build ODBC connection string
	sDsn.Format(L"ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, sFile);

	TRY{
		//std::cout << "Open" << std::endl;
		//TRACE("Open");
	// Open the database
	database.Open(NULL,false,false,sDsn);

	CRecordset recset(&database);

	SqlString.Format(L"UPDATE city SET %s %s %s WHERE %s %s %s",sel1,sel2,sel3,sel4,sel5,sel6);
	TRACE("Open %s %s %s %s %s %s", sel1, sel2, sel3, sel4, sel5, sel6);

	database.ExecuteSQL(SqlString);

	// Close the database
	database.Close();

	}
		CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		//std::cout << "Error" << std::endl;
		TRACE("Error");
		//AfxMessageBox(L"Database error: " + e→m_strError);

		//text->SetWindowTextW(_T("Error"));
	}
	END_CATCH;
}
