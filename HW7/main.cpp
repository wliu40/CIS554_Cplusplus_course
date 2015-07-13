////////////////////////////////////////////////////////////////////////////////////////
// main.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 7
// Author: Wei Liu
// Date: 4/15/2015
///////////////////////////////////////////////////////////////////////////////////////
// This is the main function for testing the functions of class NodeSLList
////////////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "NodeSLList.h"
using std::setw;
using std::left;


void NodeSLList_Test();
void TestSort();

int main()
{
	NodeSLList_Test();
}

void NodeSLList_Test()
{
	//creat a NodeSLList with default constructor
	NodeSLList list1;

	//set up the IntNodes for adding to the NodeSLList later
	IntNode temp;
	IntNode n1;
	n1.data = 10;
	IntNode n2;
	n2.data = 20;
	IntNode n3;
	n3.data = 30;
	IntNode n4;
	n4.data = 40;
	IntNode n5;
	n5.data = 50;

	//Start testing each function of the class NodeSLList
	cout << "**********************   1.Testing default constructor   **********************" << endl << endl;
	cout << "Creating NodeSLList list1" << endl;
	cout << "cout << list1 " << endl;
	cout << list1 << endl << endl;

	cout << "**********************   2.Testing AddToHead() operation   ********************" << endl << endl;
	cout << "Adding " << n5.data << " to list1" << endl;
	list1.AddToHead(n5);
	cout << "Adding " << n4.data << " to list1" << endl;
	list1.AddToHead(n4);
	cout << "Adding " << n3.data << " to list1" << endl;
	list1.AddToHead(n3);
	cout << "Adding " << n2.data << " to list1" << endl;
	list1.AddToHead(n2);
	cout << "Adding " << n1.data << " to list1" << endl;
	list1.AddToHead(n1);

	cout << "cout << list1 " << endl;
	cout << list1 << endl << endl;


	cout << "************************   3.Testing Copy Constructor   ***********************" << endl << endl;
	cout << "1). Creating list2 from list1" << endl;
	NodeSLList list2(list1);
	cout << "cout << list2 " << endl;
	cout << list2 << endl;
	cout << endl;

	cout << "2). Creating list_empty_copy from an empty list" << endl;
	NodeSLList list_empty;
	NodeSLList list_empty_copy(list_empty);
	cout << "cout << list_empty " << endl;
	cout << list_empty << endl;
	cout << "cout << list_empty_copy " << endl;
	cout << list_empty_copy << endl;

	cout << "3). Creating const list from list2" << endl;
	const NodeSLList list_const(list2);
	cout << "cout << list_const " << endl;
	list_const.PrintList();
	cout << endl;


	cout << "*********************   4.Testing AddToTail() operation   *********************" << endl << endl;
	NodeSLList list3;
	cout << "Adding " << n5.data << " to list1" << endl;
	list3.AddToTail(n5);
	cout << "Adding " << n4.data << " to list1" << endl;
	list3.AddToTail(n4);
	cout << "Adding " << n3.data << " to list1" << endl;
	list3.AddToTail(n3);
	cout << "Adding " << n2.data << " to list1" << endl;
	list3.AddToTail(n2);
	cout << "Adding " << n1.data << " to list1" << endl;
	list3.AddToTail(n1);
	cout << "cout << list3 " << endl;
	cout << list3 << endl;
	cout << endl;


	cout << "**********************   5.Testing GetSize() operation   **********************" << endl << endl;
	cout << "1). Testing GetSize() operation by non-const object" << endl;
	cout << "list1 is: ";
	cout << list1 << endl;
	cout << "list1 contains " << list1.GetSize() << " node(s)" << endl << endl;
	

	cout << "2). Testing GetSize() operation by const object" << endl;
	cout << "list_const is: ";
	list_const.PrintList();
	cout << "list_const contains " << list_const.GetSize() << " node(s)" << endl << endl;

	cout << "3). Testing GetSize() operation by empty list" << endl;
	cout << "list_empty is: ";
	cout << list_empty << endl;
	cout << "list_empty contains " << list_empty.GetSize() << " node(s)" << endl << endl;


	cout << "*************************   6.Testing operator =   ****************************" << endl << endl;
	cout << "Original list1 is " << list1 << endl;
	cout << "Original list2 is " << list2 << endl;
	cout << "Original list3 is " << list3 << endl;

	cout << "\n1). By assigning list1 = list3." << endl;
	list1 = list3;
	cout << "now list1 is: " << endl;
	cout << list1 << endl;

	cout << "\n2). By assigning list1 = list2." << endl;
	list1 = list2;
	cout << "now list1 is: " << endl;
	cout << list1 << endl;


	cout << "\n3). By assigning list1 = list2 = list3." << endl;
	cout << "Original list1 is " << list1 << endl;
	cout << "Original list2 is " << list2 << endl;
	cout << "Original list3 is " << list3 << endl;
	cout << "\nafter excuting list1 = list2 = list3" << endl;
	list1 = list2 = list3;
	cout << "now list1 is: ";
	cout << list1 << endl;
	cout << "now list2 is:  ";
	cout << list2 << endl;
	cout << "now list3 is:  ";
	cout << list3 << endl;

	cout << "\n4). By assigning list1_1 = empty list." << endl;

	NodeSLList list1_1;
	list1_1.AddToHead(n1);
	list1_1.AddToHead(n2);
	cout << "cout << list1_1 " << endl;
	cout << list1_1 << endl;

	cout << "After excute list1_1 = list_empty" << endl;
	list1_1 = list_empty;
	cout << "cout << now list1_1: " << endl;
	cout << list1_1 << endl;


	cout << "*******************   7.Testing DeleteFromHead() operation   ******************" << endl << endl;
	temp = list1.DeleteFromHead();
	cout << "node retrieved " << temp.data << endl;
	cout << "cout << list1 " << endl;
	cout << list1 << endl;
	cout << endl;


	cout << "************   8.Testing equality == and inequality != operators   ************" << endl << endl;
	cout << "now list1 is: ";
	cout << list1 << endl;
	cout << "now list2 is: ";
	cout << list2 << endl;
	cout << "excute == operator, we get" << endl;
	if (list1 == list2) cout << "list1 == list2" << endl << endl;
	if (list1 != list2) cout << "list1 != list2" << endl << endl;

	cout << "Putting the previous node back on the head of list1. Now list1 and list2 should be equal" << endl;
	list1.AddToHead(temp);
	cout << "cout << list1 " << endl;
	cout << list1 << endl;

	cout << "excute == operator, we get" << endl;
	if (list1 == list2) cout << "list1 == list2" << endl << endl;
	if (list1 != list2) cout << "list1 != list2" << endl << endl;


	cout << "******************   9.Testing DeleteFromTail() operation   *******************" << endl << endl;
	temp = list1.DeleteFromTail();
	cout << "node retrieved " << temp.data << endl;
	cout << "cout << list1 " << endl;
	cout << list1 << endl;
	cout << endl;

	cout << "Adding " << n3.data << " to head" << endl;
	cout << "Adding " << n2.data << " to head" << endl;
	list1.AddToHead(n3);
	list1.AddToHead(n2);
	cout << "cout << list1 " << endl;
	cout << list1 << endl << endl;


	cout << "********************   10.Testing DeleteNode() operation   ********************" << endl << endl;
	cout << "Deleting node 35 (should be last node, since 35 is beyond end of list)" << endl;
	temp = list1.DeleteNode(35);
	cout << "cout << list1 " << endl;
	cout << list1 << endl;
	temp = list1.DeleteNode(3);
	cout << "Deleteing node 3 (" << temp.data << ")" << endl;
	cout << "cout << list1 " << endl;
	cout << list1 << endl;

	temp = list1.DeleteNode(-3);
	cout << "Deleteing node -3 (" << temp.data << ")" << endl;
	cout << "cout << list1 " << endl;
	cout << list1 << endl << endl;


	cout << "**********************   11.Testing InsertNode() operation   ******************" << endl << endl;
	cout << "The original list3 is: " << endl;
	cout << list3 << endl;

	cout << "After list3.InsertNode(-1, n3), now list3 is: " << endl;
	list3.InsertNode(-1, n3);
	cout << list3 << endl;

	cout << "After list3.InsertNode(1, n4), now list3 is: " << endl;
	list3.InsertNode(1, n4);
	cout << list3 << endl;

	cout << "After list3.InsertNode(2, n3), now list3 is: " << endl;
	list3.InsertNode(2, n3);
	cout << list3 << endl;

	cout << "After list3.InsertNode(15, n3), now list3 is: " << endl;
	list3.InsertNode(15, n3);
	cout << list3 << endl << endl;


	cout << "***********************   12.Testing IsEmpty() operation   ********************" << endl << endl;
	cout << "cout << list2 " << endl;
	cout << list2 << endl;
	cout << (list2.IsEmpty() ? "list2 is EMPTY" : "list2 is NOT EMPTY") << endl;

	NodeSLList list4;
	cout << "cout << list4" << endl;
	cout << list4 << endl;
	cout << (list4.IsEmpty() ? "list4 is EMPTY" : "list4 is NOT EMPTY") << endl << endl;


	cout << "********************   13.Testing UpdateNode() operation   *********************" << endl << endl;
	cout << "The original list1 is: " << endl;
	cout << list1 << endl;
	cout << "1).Updating 3rd node with 500.";
	temp.data = 500;
	list1.UpdateNode(3, temp);
	cout << "cout << now list1 is: " << endl;
	cout << list1 << endl;

	cout << "2).Updating 1rd node with 700.";
	temp.data = 700;
	list1.UpdateNode(1, temp);
	cout << "cout << now list1 is: " << endl;
	cout << list1 << endl << endl;


	cout << "*************   14.Testing the ability to delete nodes from head   ************" << endl << endl;
	cout << "list1 has " << list1.GetSize() << " nodes" << endl;
	cout << "The original list1 is: " << endl;
	cout << list1 << endl;
	int numNodesToDelete = list1.GetSize();
	for (int x = 0; x<numNodesToDelete; x++)
	{
		cout << "Deleting from head" << endl;
		temp = list1.DeleteFromHead();
		cout << "cout << list1 " << endl;
		cout << list1 << endl;
	}
	cout << "Deleting from head, after list is empty. Should receive an error." << endl;
	temp = list1.DeleteFromHead();
	cout << "cout << list1 " << endl;
	cout << list1 << endl;


	cout << "*******************   15.Testing DestroyList() operation   ********************" << endl << endl;
	cout << "cout << list2 " << endl;
	cout << list2 << endl;
	cout << "calling DestoryList()" << endl;
	list2.DestroyList();
	cout << "cout << list2 " << endl;
	cout << list2 << endl;


	cout << "**********************   16.Test IsEmpty() operation   ************************" << endl << endl;
	cout << "cout << list2 " << endl;
	cout << list2 << endl;
	cout << "calling list2.IsEmpty()" << endl;
	cout << (list2.IsEmpty() ? "list2 is EMPTY" : "list2 is NOT EMPTY") << endl << endl;
	
	list2.InsertNode(0, n2);
	cout << list2 << endl;
	cout << "calling list2.IsEmpty()" << endl;
	cout << (list2.IsEmpty() ? "list2 is EMPTY" : "list2 is NOT EMPTY") << endl << endl;


	cout << "**************   17.Testing SortList() operation, ascending   *****************" << endl << endl;
	cout << "The original list is: " << endl;
	cout << list3 << endl;
	list3.SortList(1);//input 1 for ascending sort
	cout << "after ascending sort: " << endl;
	cout << list3 << endl << endl;


	cout << "***************   18.Testing SortList() operation, descending   ***************" << endl << endl;
	cout << "The original list is: " << endl;
	cout << list3 << endl;
	cout << "after descending sort: " << endl;
	list3.SortList(2);//input 2 for descending sort
	cout << list3 << endl << endl;


	cout << "************************   19.Testing PrintList()   ***************************" << endl << endl;
	cout << "list3.PrintList(): ";
	list3.PrintList();
	cout << "list_empty.PrintList(): ";
	list_empty.PrintList();


	cout << "**************************   20.Testing operator +   **************************" << endl << endl;
	cout << "list1 = ";
	cout << list1 << endl;
	cout << "list2 = ";
	cout << list2 << endl;
	cout << "list3 = ";
	cout << list3 << endl;
	cout << endl;

	cout << "list1 + list2 = ";
	cout << list1 + list2 << endl;

	cout << "list2 + list1 = " ;
	cout << list2 + list1 << endl;

	cout << "list2 + list3 = ";
	cout << list2 + list3 << endl;

	cout << "list3 + list2 = ";
	cout << list3 + list2 << endl << endl;


	NodeSLList list5;
	NodeSLList list6;

	list6.AddToTail(n1);
	list6.AddToTail(n2);
	list6.AddToTail(n3);
	cout << "list5 = ";
	cout << list5 << endl;
	cout << "list6 = ";
	cout << list6 << endl << endl;

	cout << "After excuting list6 = list5 + list6" << endl;
	list6 = list5 + list6;
	cout << "now list5 = ";
	cout << list5 << endl;
	cout << "now list6 = ";
	cout << list6 << endl;

	cout << "After excuting list5 = list5 + list6" << endl;
	list5 = list5 + list6;
	cout << "now list5 = ";
	cout << list5 << endl;
	cout << "now list6 = ";
	cout << list6 << endl << endl;

	cout << "After excuting list6 = list6 + list_empty" << endl;
	list6 = list6 + list_empty;
	cout << "now list6 = ";
	cout << list6 << endl;
	cout << "now list_empty = ";
	cout << list_empty << endl << endl;

	cout << "After excuting list7 = list5 + list6 + list6" << endl;
	NodeSLList list7 = list5 + list6 + list6;
	cout << "now list7 = ";
	cout << list7 << endl;
	cout << "now list5 = ";
	cout << list5 << endl;
	cout << "now list6 = ";
	cout << list6 << endl << endl;

	cout << "After excuting list7 = list7 + list7" << endl;
	cout << "now list7 = ";
	list7 = list7 + list7;
	cout << list7 << endl;

	cout << endl;
	system("pause");
}

