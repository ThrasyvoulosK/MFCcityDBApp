// Actions.cpp : implementation file
//

#include "pch.h"
#include "MFCcityDBApp.h"
#include "Actions.h"
#include "afxdialogex.h"

#include "odbcinst.h"
#include "afxdb.h"

#include "atlstr.h"
#include "commctrl.h"

// Actions dialog

IMPLEMENT_DYNAMIC(Actions, CDialogEx)

Actions::Actions(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Actions::~Actions()
{
}

void Actions::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Actions, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO2, &Actions::OnBnClickedSelect)
	ON_BN_CLICKED(IDC_RADIO1, &Actions::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_BUTTON1, &Actions::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &Actions::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// Actions message handlers


void Actions::OnBnClickedSelect()
{
	// TODO: Add your control notification handler code here
	CDatabase database;
	CString SqlString;
	CString sCatID, sCategory;
	CString aCString = CString(_T("A string"));
	_tprintf(_T("%s"), (LPCTSTR)aCString);

	CString sDriver = _T("MICROSOFT ACCESS DRIVER (*.mdb)");
	CString sDsn;
	CString sFile = _T("d:\works\ReadDB\Test.mdb");
	// You must change above path if it's different
	int iRec = 0;

	// Build ODBC connection string
	sDsn.Format(_T("ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, sFile));
	TRY
	{
		// Open the database
		database.Open(NULL,false,false,sDsn);

	// Allocate the recordset
	CRecordset recset(&database);

	// Build the SQL statement
	SqlString = "SELECT CatID, Category "
			"FROM Categories";

	// Execute the query
	recset.Open(CRecordset::forwardOnly,SqlString,CRecordset::readOnly);
	/*
	// Reset List control if there is any data
	ResetListControl();
	// populate Grids
	ListView_SetExtendedListViewStyle(m_ListControl,LVS_EX_GRIDLINES);

	// Column width and heading
	m_ListControl.InsertColumn(0,"Category Id",LVCFMT_LEFT,-1,0);
	m_ListControl.InsertColumn(1,"Category",LVCFMT_LEFT,-1,1);
	m_ListControl.SetColumnWidth(0, 120);
	m_ListControl.SetColumnWidth(1, 200);
	
	// Loop through each record
	while (!recset.IsEOF())
	{
		// Copy each column into a variable
		recset.GetFieldValue("CatID",sCatID);
		recset.GetFieldValue("Category",sCategory);

		// Insert values into the list control
		iRec = m_ListControl.InsertItem(0,sCatID,0);
		m_ListControl.SetItemText(0,1,sCategory);

		// goto next record
		recset.MoveNext();
	}
	*/
	// Close the database
	database.Close();
	}
		CATCH(CDBException, e)
	{
		// If a database exception occured, show error msg
		//AfxMessageBox("Database error: " + e->m_strError);
	}
	END_CATCH;
	
}


void Actions::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	
}


void Actions::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void Actions::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}
