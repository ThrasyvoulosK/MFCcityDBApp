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

	//text->SetWindowTextW(sel1+sel2+sel3);

	CString cityID;
	CString cityName;
	CString countryName;
	CString cityPopulation;

	CString query;
	//query.Format();

	CDatabase database;
	CString SqlString;
	//CString strID, strCityName, strCountryName, strPop;
	CString sDriver = L"MICROSOFT ACCESS DRIVER (*.mdb)";
	CString sDsn;

	CString sFile;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sFile);

	// You must change above path if it's different
	int iRec = 0;

	// Build ODBC connection string
	//sDsn.Format(L"ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, dbPath);
	sDsn.Format(L"ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, sFile);
	TRY{
		//std::cout << "Open" << std::endl;
		TRACE("Open");
	// Open the database
	database.Open(NULL,false,false,sDsn);

	CRecordset recset(&database);


	//SqlString = "INSERT INTO city (cityID,cityName,countryName,cityPopulation) VALUES (6,'London','UK',6)";
	//SqlString.Format(L"INSERT INTO city (cityID,cityName,countryName,cityPopulation) VALUES (%s,'%s','%s',%s)",cityID,cityName,countryName,cityPopulation);
	////SqlString.Format(L"SELECT * FROM city (cityID,cityName,countryName,cityPopulation) WHERE %s %s %s",sel1,sel2,sel3);
	SqlString.Format(L"SELECT * FROM city WHERE %s %s %s",sel1,sel2,sel3);
	//SqlString.Format(L"SELECT * FROM city WHERE cityID>3");
	//database.ExecuteSQL(SqlString);
	//recset.m_strFilter = sel1+sel2+sel3;


	//text->SetWindowTextW(_T(database.ExecuteSQL(SqlString)));


	recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);
	//recset.Open(CRecordset::forwardOnly, recset.m_strFilter, CRecordset::readOnly);

	CString strValue;
	strValue="cityID	cityName	CountryName	cityPopulation \n";
	while (!recset.IsEOF())
	{			
		CString strCur;
		CString cityID,cityName,countryName,cityPopulation;
		//recset.GetFieldValue(_T("cityName"), strCur);
		// Copy each column into a variable
		recset.GetFieldValue(_T("cityID"), cityID);
		recset.GetFieldValue(_T("cityName"), cityName);
		recset.GetFieldValue(_T("countryName"), countryName);
		recset.GetFieldValue(_T("cityPopulation"), cityPopulation);
		strCur.Append( cityID + "\t"+ cityName + "\t" +countryName + "\t"+ cityPopulation);
		strValue.Append(strCur+"\n");
		recset.MoveNext();
	}

	recset.Close(); // Close the recordset

	text->SetWindowTextW(strValue);
	return;


	// populate Grids
	//CListCtrl m_ListControl;
	/*ListView_SetExtendedListViewStyle(m_ListControl, LVS_EX_GRIDLINES);*/

	// Column width and heading
	/*m_ListControl.InsertColumn(0, L"cityID", LVCFMT_LEFT, -1, 0);
	m_ListControl.InsertColumn(1, L"cityName", LVCFMT_LEFT, -1, 1);
	m_ListControl.InsertColumn(2, L"countryName", LVCFMT_LEFT, -1, 1);
	m_ListControl.InsertColumn(3, L"cityPopulation", LVCFMT_LEFT, -1, 1);
	m_ListControl.SetColumnWidth(0, 120);
	m_ListControl.SetColumnWidth(1, 200);
	m_ListControl.SetColumnWidth(2, 200);
	m_ListControl.SetColumnWidth(3, 200);*/

	CString strResult,strOne;

	// Loop through each record
	while (!recset.IsEOF()) {

		CString strValue;// , strOne;
		/*recset.GetFieldValue(L"cityName",strOne);
		text->SetWindowTextW(strOne);
		break;*/
		CString recs;
		iRec = recset.GetRowsFetched();
		recs.Format(_T("%d"), iRec);
		text->SetWindowTextW(recs);
		//break;

		//recset.GetFieldValue(_T("YourColumnName"), strValue);
		recset.GetFieldValue(_T("cityName"), strValue);
		//strResult += strValue + _T("\n"); // Append to the result string
		strResult.Append(strValue+L"\n");
		//text->SetWindowTextW(strValue);
		//text->SetWindowTextW(strResult);

		// Copy each column into a variable
		//recset.GetFieldValue(L"cityID", cityID);
		recset.GetFieldValue(_T("cityID"), cityID);
		//recset.GetFieldValue(L"cityName", cityName);
		recset.GetFieldValue(_T("cityName"), cityName);
		//recset.GetFieldValue(L"countryName", countryName);
		recset.GetFieldValue(_T("countryName"), countryName);
		//recset.GetFieldValue(L"cityPopulation", cityPopulation);
		recset.GetFieldValue(_T("cityPopulation"), cityPopulation);

		//text->SetWindowTextW(cityID + cityName + countryName + cityPopulation);
		//text->SetWindowTextW(cityName);

		// Insert values into the list control
		/*iRec = m_ListControl.InsertItem(0, cityID, 0);
		m_ListControl.SetItemText(0, 1, cityName);
		m_ListControl.SetItemText(0, 2, countryName);
		m_ListControl.SetItemText(0, 3, cityPopulation);*/

		// goto next record
		recset.MoveNext();

		iRec++;

		/*CString recs;
		iRec = recset.GetRowsFetched();
		recs.Format(_T("%d"), iRec);
		text->SetWindowTextW(recs);*/
		
	}

	//CString recs;
	//recs.Format(_T("%d"), iRec);
	//text->SetWindowTextW(strResult);
	//text->SetWindowTextW(strOne);
	//text->SetWindowTextW(recs);

	// Close the database
	database.Close();

	//text->SetWindowTextW(strResult);
	//text->SetWindowText(cityID);
	//text->SetWindowTextW(_T("Yes"));

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
