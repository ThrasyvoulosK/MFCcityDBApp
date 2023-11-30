// InsertTab.cpp : implementation file
//

#include "pch.h"
#include "MFCcityDBApp.h"
#include "InsertTab.h"
#include "afxdialogex.h"

#include "WinUser.h"
#include "odbcinst.h"
#include "afxdb.h"

// InsertTab dialog

IMPLEMENT_DYNAMIC(InsertTab, CPropertyPage)

InsertTab::InsertTab()
	: CPropertyPage(IDD_InsertTab)
{

}

InsertTab::~InsertTab()
{
}

void InsertTab::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InsertTab, CPropertyPage)
	ON_EN_CHANGE(IDC_EDIT1, &InsertTab::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &InsertTab::OnBnClickedButton1)
END_MESSAGE_MAP()


// InsertTab message handlers


void InsertTab::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void InsertTab::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	//insert values
	CString dbPath;

	CString cityID;
	CString cityName;
	CString countryName;
	CString cityPopulation;

	GetDlgItem(IDC_EDIT1)->GetWindowText(dbPath);
	GetDlgItem(IDC_EDIT3)->GetWindowText(cityID);
	GetDlgItem(IDC_EDIT4)->GetWindowText(cityName);
	GetDlgItem(IDC_EDIT5)->GetWindowText(countryName);
	GetDlgItem(IDC_EDIT6)->GetWindowText(cityPopulation);

	CString query;

	CDatabase database;
	CString SqlString;
	CString sDriver = L"MICROSOFT ACCESS DRIVER (*.mdb)";
	CString sDsn;

	int iRec = 0;

	// Build ODBC connection string
	sDsn.Format(L"ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, dbPath);
	TRY{
		//std::cout << "Open" << std::endl;
		TRACE("Open");
	// Open the database
	database.Open(NULL,false,false,sDsn);

	SqlString.Format(L"INSERT INTO city (cityID,cityName,countryName,cityPopulation) VALUES (%s,'%s','%s',%s)",cityID,cityName,countryName,cityPopulation);
	database.ExecuteSQL(SqlString);
	// Close the database
	database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		//std::cout << "Error" << std::endl;
		TRACE("Error");
		//AfxMessageBox(L"Database error: " + e→m_strError);
	}
	END_CATCH;

}
