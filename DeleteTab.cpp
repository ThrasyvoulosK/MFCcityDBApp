// DeleteTab.cpp : implementation file
//

#include "pch.h"
#include "MFCcityDBApp.h"
#include "DeleteTab.h"
#include "afxdialogex.h"

#include "WinUser.h"
#include "odbcinst.h"
#include "afxdb.h"
#include "afxcmn.h"
#include "commctrl.h"


// DeleteTab dialog

IMPLEMENT_DYNAMIC(DeleteTab, CPropertyPage)

DeleteTab::DeleteTab()
	: CPropertyPage(IDD_DeleteTab)
{

}

DeleteTab::~DeleteTab()
{
}

void DeleteTab::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteTab, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &DeleteTab::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DeleteTab::OnBnClickedButton2)
END_MESSAGE_MAP()


// DeleteTab message handlers


void DeleteTab::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CListBox* lbox1;
	CListBox* lbox2;

	lbox1 = (CListBox*)GetDlgItem(IDC_LIST1);
	lbox2 = (CListBox*)GetDlgItem(IDC_LIST2);

	lbox1->AddString(L"cityID");
	lbox1->AddString(L"cityName");
	lbox1->AddString(L"countryName");
	lbox1->AddString(L"cityPopulation");

	lbox2->AddString(L"=");
	lbox2->AddString(L">=");
	lbox2->AddString(L">");
	lbox2->AddString(L"<=");
	lbox2->AddString(L"<");
}


void DeleteTab::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CListBox* lbox1;
	CListBox* lbox2;

	lbox1 = (CListBox*)GetDlgItem(IDC_LIST1);
	lbox2 = (CListBox*)GetDlgItem(IDC_LIST2);

	CEdit* dbPath = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* value = (CEdit*)GetDlgItem(IDC_EDIT2);

	CString sel1;
	CString sel2;
	CString sel3;
	lbox1->GetText(lbox1->GetCurSel(), sel1);
	lbox2->GetText(lbox2->GetCurSel(), sel2);

	GetDlgItem(IDC_EDIT2)->GetWindowText(sel3);

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
		TRACE("Open");
	// Open the database
	database.Open(NULL,false,false,sDsn);

	CRecordset recset(&database);
	
	SqlString.Format(L"DELETE FROM city WHERE %s %s %s",sel1,sel2,sel3);

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
