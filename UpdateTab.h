#pragma once


// UpdateTab dialog

class UpdateTab : public CPropertyPage
{
	DECLARE_DYNAMIC(UpdateTab)

public:
	UpdateTab();
	virtual ~UpdateTab();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UpdateTab };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
