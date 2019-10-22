#include <iostream>
using namespace std;

typedef char ItemType;

// define a struct type named NodeType that includes a ItemType and pointer
// (to a NodeType) field
struct NodeType
{
    ItemType value = 0;
    NodeType *next = NULL;
    NodeType *prev = NULL;
};

/* Displaying a linked list of NodType
 @head: address of the first node 
*/
void DisplayLinkedList(NodeType *head);

/* Create a new node to store the given value,
 * and make this new node the first of the linked lsit 
 @head: address of the first node, will be updated
 @value: 
*/
void InsertAtFront(NodeType *&head, ItemType value);

void AppendInTheEnd(NodeType *&head, ItemType num);

/* delete (deallocate) all nodes in the linked list given by the head pointer
 postcondition: all nodes in the linked list are deleted
                head is set to NULL
 */
void ClearLinkedList(NodeType *&head);

/* Search for given value in the listed list pointed to by firstNodePtr
 @param firstNodePtr: pointer to the head of the list 
 @param value : what value are we looking for 
 @return the address of the node that stores the matching value; if no match, return NULL
*/
NodeType *Search(NodeType *firstNodePtr, ItemType value);

/* Search for given value in the listed list pointed to by firstNodePtr,
 *  return the matching node's address, and 
 *  set its previous node's address in prevNode parameter
 @param firstNodePtr 
 @param value 
 @postcondition: if the value is found in the linked list,
	the node's address will be returned, and
	prevNode will point to the node before; if not found, return NULL, prevNode is NULL 
 @return value: same as Search... 
*/
NodeType *Search(NodeType *firstNodePtr, ItemType value, NodeType *&prevNode);

/* Delete the node storing the given value from the linked list 
    //    1. Find the value in the list (i.e., find the pointer that points to the node),
    //       and also remembers the address of its previous node 
    //    2. If the node to be removed is not in the header, skip it in the list 
    //        (assign its next node's address to its prev node's next)
    //       otherwise set header to its next node's address 
    //    3. delete the node (to free up heap storage) 
 @param firstPtr: if the value is stored in the head, then firstPtr will be updated  
 @param value
 @return true if the value is removed; false if the value is not found 
*/
bool Delete(NodeType *&firstPtr, ItemType value);

/* Create a linked list to store the values in array a
 @param a: the array of int values
 @param size: length of array
 @return the address of the first node
*/
NodeType *InitList(ItemType a[], int size);

/* Split the given list into two with equal length
 If the list length is odd, the first list gets one element one than
 the second one
@param head: points to the first node of the linked list
@param firstHalf: upon return, points to the first node of first splitted list
@param secondHalf: upon return, points to the first node of the second half 
*/
NodeType *SplitHalf(NodeType *head);

/* Merge two list into two 
 @param list1: points to the first list
 @param list2: points to the second list 
 @return the address of the first node of the merged linked list (
  list1 element  -> list2 elements
 */
NodeType *Merge(NodeType *list1, NodeType *list2);

//ADDS VALUE IN THE MIDDLE OF THE LIST

void AppendMiddle(NodeType *&afterNode, ItemType beforeValue);

void NodeCount(NodeType *&head);
