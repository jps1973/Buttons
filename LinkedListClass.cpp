// LinkedListClass.cpp

#include "LinkedListClass.h"

Node::~Node()
{
	// Free string memory
	delete [] m_lpszTargetPath;

} // End of function Node::~Node

Node::Node( int nID, HWND hWnd, LPTSTR lpszTargetPath )
{
	// Update id
	m_nID = nID;

	// Update window
	m_hWnd = hWnd;

	// Allocate string memory
	m_lpszTargetPath = new char[ STRING_LENGTH + sizeof( char ) ];

	// Store target path
	lstrcpy( m_lpszTargetPath, lpszTargetPath );

	// Clear next node
	m_lpNextNode = NULL;

} // End of function Node::Node

LinkedList::LinkedList()
{
	// Clear head node
	m_headNode = NULL;

} // End of function LinkedList::LinkedList

LinkedList::~LinkedList()
{
	Node *lpTempNode;

	// Loop through all nodes
	while( m_headNode )
	{
		// Copy head node into temp node
		lpTempNode = m_headNode;

		// Move head node into next node
		m_headNode = m_headNode->m_lpNextNode;

		// Delete temp node
		delete lpTempNode;

	}; // End of loop through all nodes

} // End of function LinkedList::~LinkedList

void LinkedList::AddNode( int nID, HWND hWnd, LPTSTR lpszTargetPath )
{
	Node *lpNewNode = new Node( nID, hWnd, lpszTargetPath );

	// See if linked list is empty
	if( m_headNode == NULL )
	{
		// Linked list is empty

		// Copy new node into head node
		m_headNode = lpNewNode;

	} // End of linked list is empty
	else
	{
		// Linked list is not empty

		// Store head node
		Node *lpTempNode = m_headNode;

		// Loop through all nodes
		while( lpTempNode->m_lpNextNode != NULL )
		{
			// Get next node
			lpTempNode = lpTempNode->m_lpNextNode;

		}; // End of loop through all nodes

		// Add new node to end of linked list
		lpTempNode->m_lpNextNode = lpNewNode;

	} // End of linked list is not empty

} // End of function LinkedList::AddNode

int LinkedList::CountNodes()
{
	int nResult = 0;

	// Copy head node into temp node
	Node *lpTempNode = m_headNode;

	// Loop through all nodes
	while( lpTempNode != NULL )
	{
		// Update return value
		nResult ++;

		// Get next node
		lpTempNode = lpTempNode->m_lpNextNode;

	}; // End of loop through all nodes

	return nResult;

} // End of function LinkedList::CountNodes

BOOL LinkedList::GetTargetPath( int nID, LPTSTR lpszTargetPath )
{
	BOOL bResult = FALSE;

	int nCurrentNode = 0;

	// Copy head node into temp node
	Node *lpTempNode = m_headNode;

	// Loop through all nodes
	while( lpTempNode != NULL )
	{
		// See if current node is the required node
		if( lpTempNode->m_nID == nID )
		{
			// Current node is the required node

			// Copy target path
			if( lstrcpy( lpszTargetPath, lpTempNode->m_lpszTargetPath ) )
			{
				// Successfully copied target path

				// Update return value
				bResult = TRUE;

			} // End of successfully copied target path

			// Force exit from loop
			lpTempNode = NULL;

		} // End of current node is the required node
		else
		{
			// Current node is not the required node

			// Advance current node
			nCurrentNode ++;

			// Get next node
			lpTempNode = lpTempNode->m_lpNextNode;

		} // End of current node is not the required node

	}; // End of loop through all nodes

	return bResult;

} // End of function LinkedList::GetTargetPath

HWND LinkedList::GetWindow( int nWhichNode )
{
	HWND hWndResult = NULL;

	int nCurrentNode = 0;

	// Copy head node into temp node
	Node *lpTempNode = m_headNode;

	// Loop through all nodes
	while( lpTempNode != NULL )
	{
		// See if current node is the required node
		if( nCurrentNode == nWhichNode )
		{
			// Current node is the required node

			// Update return value
			hWndResult = lpTempNode->m_hWnd;

			// Force exit from loop
			lpTempNode = NULL;

		} // End of current node is the required node
		else
		{
			// Current node is not the required node

			// Advance current node
			nCurrentNode ++;

			// Get next node
			lpTempNode = lpTempNode->m_lpNextNode;

		} // End of current node is not the required node

	}; // End of loop through all nodes

	return hWndResult;

} // End of function LinkedList::GetWindow

/*
int LinkedList::
{
} // End of function LinkedList::
*/
