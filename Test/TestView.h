
// TestView.h : CTestView ��Ľӿ�
//

#pragma once

#include "Line.h"//����ֱ����
#include "Transform.h"

class CTestView : public CView
{
protected: // �������л�����
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// ����
public:
	CTestDoc* GetDocument() const;

// ����
public:

// ��д
public:
	void DoubleBuffer(CDC *pDC);//˫����
	void ReadPoint();//���붥���
	void DrawObject(CDC *);//����ͼ��
	void DrawPolygon(CDC *pDC);//���ƶ����
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CP2 P[4];//���	
	CRect rect;//����ͻ���
	CTransform trans;
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawpic();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTleft();
	afx_msg void OnTright();
	afx_msg void OnTup();
	afx_msg void OnTdown();
	afx_msg void OnSincrease();
	afx_msg void OnSdecrease();
	afx_msg void OnRclockwise();
	afx_msg void OnRcounterclockwise();
	afx_msg void OnRxaxis();
	afx_msg void OnRyaxis();
	afx_msg void OnRorg();
	afx_msg void OnSxdirectionneg();
	afx_msg void OnSxdirectionplus();
	afx_msg void OnSydirectionneg();
	afx_msg void OnSydirectionplus();
//	afx_msg void OnReset();
	virtual void OnInitialUpdate();
	afx_msg void OnReset();
};

#ifndef _DEBUG  // TestView.cpp �еĵ��԰汾
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif

