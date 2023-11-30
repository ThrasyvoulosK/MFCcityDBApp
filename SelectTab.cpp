// SelectTab.cpp : implementation file
//

#include "pch.h"
#include "MFCcityDBApp.h"
#include "SelectTab.h"
#include "afxdialogex.h"

#include "WinUser.h"
#include "odbcinst.h"
#include "afxdb.h"
#include "afxcmn.h"
#include "commctrl.h"


// SelectTab dialog

IMPLEMENT_DYNAMIC(SelectTab, CPropertyPage)

SelectTab::SelectTab()
	: CPropertyPage(IDD_SelectTab)
{

}

SelectTab::~SelectTab()
{
}

void SelectTab::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
}


BEGIN_MESSAGE_MAP(SelectTab, CPropertyPage)
	ON_LBN_SELCHANGE(IDC_LIST1, &SelectTab::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &SelectTab::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &SelectTab::OnBnClickedButton2)
END_MESSAGE_MAP()


// SelectTab message handlers


void SelectTab::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
	CStatic* text = (CStatic*)GetDlgItem(IDC_STATIC2);
	//text->SetWindowTextW(_T("Yes"));
}

void SelectTab::MyFunction()
{
	//SelectTab* temp = (SelectTab*)GetDlgItem(IDC_LIST1); //Reference to dialog item IDC_ID
	//temp->DoSomething(); //This gives me an assertion error
	//temp->add
	/*CListBox* lbox;
	lbox = (CListBox*)GetDlgItem(IDC_LIST1);
	lbox->AddString(L"Yes");*/

}


void SelectTab::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CListBox* lbox1;
	CListBox* lbox2;
	//CListBox* lbox3;
	lbox1 = (CListBox*)GetDlgItem(IDC_LIST1);
	lbox2 = (CListBox*)GetDlgItem(IDC_LIST2);
	//lbox3 = (CListBox*)GetDlgItem(IDC_LIST3);

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


void SelectTab::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CListBox* lbox1;
	CListBox* lbox2;

	lbox1 = (CListBox*)GetDlgItem(IDC_LIST1);
	lbox2 = (CListBox*)GetDlgItem(IDC_LIST2);

	CStatic* text = (CStatic*)GetDlgItem(IDC_STATIC2);

	CEdit* dbPath = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* value = (CEdit*)GetDlgItem(IDC_EDIT2);

	CString sel1;
	CString sel2;
	CString sel3;
	lbox1->GetText(lbox1->GetCurSel(), sel1);
	lbox2->GetText(lbox2->GetCurSel(), sel2);

	GetDlgItem(IDC_EDIT2)->GetWindowText(sel3);

	CString cityID;
	CString cityName;
	CString countryName;
	CString cityPopulation;

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

	SqlString.Format(L"SELECT * FROM city WHERE %s %s %s",sel1,sel2,sel3);

	recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);

	CString strValue;
	strValue = "cityID	cityName	CountryName	cityPopulation \n";

	while (!recset.IsEOF())
	{
		CString strCur;
		CString cityID,cityName,countryName,cityPopulation;

		// Copy each column into a variable
		recset.GetFieldValue(_T("cityID"), cityID);
		recset.GetFieldValue(_T("cityName"), cityName);
		recset.GetFieldValue(_T("countryName"), countryName);
		recset.GetFieldValue(_T("cityPopulation"), cityPopulation);
		strCur.Append(cityID + "\t" + cityName + "\t" + countryName + "\t" + cityPopulation);
		strValue.Append(strCur + "\n");
		recset.MoveNext();
	}

	recset.Close(); // Close the recordset

	text->SetWindowTextW(strValue);
	return;


	}
		CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		//std::cout << "Error" << std::endl;
		TRACE("Error");
		//AfxMessageBox(L"Database error: " + e→m_strError);
		//text->SetWindowTextW(_T("Error"));

		END_CATCH;
	}
}
