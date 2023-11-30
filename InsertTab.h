#pragma once


// InsertTab dialog

class InsertTab : public CPropertyPage
{
	DECLARE_DYNAMIC(InsertTab)

public:
	InsertTab();
	virtual ~InsertTab();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_InsertTab };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
};
