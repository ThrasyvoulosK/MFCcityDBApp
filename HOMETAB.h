#pragma once


// HOMETAB dialog

class HOMETAB : public CPropertyPage
{
	DECLARE_DYNAMIC(HOMETAB)

public:
	HOMETAB();
	virtual ~HOMETAB();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOMETAB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
