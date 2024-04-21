
// TestView.h : CTestView 类的接口
//

#pragma once

#include "Line.h"//包含直线类
#include "Transform.h"

class CTestView : public CView
{
protected: // 仅从序列化创建
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// 特性
public:
	CTestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	void DoubleBuffer(CDC *pDC);//双缓冲
	void ReadPoint();//读入顶点表
	void DrawObject(CDC *);//绘制图形
	void DrawPolygon(CDC *pDC);//绘制多边形
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CP2 P[4];//点表	
	CRect rect;//定义客户区
	CTransform trans;
// 生成的消息映射函数
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

#ifndef _DEBUG  // TestView.cpp 中的调试版本
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif

