// LinkedListClass.h

#pragma once

#include <windows.h>

#include "Common.h"

class Node
{
public:
	int m_nID;
	HWND m_hWnd;
	LPTSTR m_lpszTargetPath;
	Node *m_lpNextNode;

	~Node();

	Node( int nID, HWND hWnd, LPTSTR lpszTargetPath );

}; // End of class Node

class LinkedList
{
private:
  Node *m_headNode;

public:
	LinkedList();

	~LinkedList();

	void AddNode( int nID, HWND hWnd, LPTSTR lpszTargetPath );

	int CountNodes();

	BOOL GetTargetPath( int nID, LPTSTR lpszTargetPath );

	HWND GetWindow( int nWhichNode );

}; // End of class LinkedList
