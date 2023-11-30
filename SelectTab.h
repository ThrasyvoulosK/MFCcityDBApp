#pragma once


// SelectTab dialog

class SelectTab : public CPropertyPage
{
	DECLARE_DYNAMIC(SelectTab)

public:
	SelectTab();
	virtual ~SelectTab();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SelectTab };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	CListBox m_listBox;
	void MyFunction();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	CListCtrl m_ListControl;
};
