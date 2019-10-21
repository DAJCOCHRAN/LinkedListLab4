
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
void Split(NodeType *head, NodeType *&firstHalf, NodeType *&secondHalf);

/* Merge two list into two 
 @param list1: points to the first list
 @param list2: points to the second list 
 @return the address of the first node of the merged linked list (
  list1 element  -> list2 elements
 */
NodeType *Merge(NodeType *list1, NodeType *list2);

void AppendMiddle(NodeType * &afterNode, ItemType beforeValue);

int main()
{
    NodeType *head = new NodeType;
    //stores the address of the first node
    //The above is an empty list
    char op;
    ItemType value, beforeThis;
    ItemType newValue;
    ItemType values[9] = {'a', '2', 'd', '4', '5', 'f', 'z', '9', 'f'};
    NodeType *list;
    NodeType *found;

    do
    {
        cout << "*********Menu***************" << endl;
        cout << "What you want to do:" << endl;
        cout << "d: delete a value from the list\n";
        cout << "a: append a value to the end of the list\n";
        cout << "i: insert a value to the beginning of the list\n";
        cout << "m: insert a value before an existing value \n";
        cout << "n: create list from a programmed array \n";
        cout << "l: lookup a value and modify the same value inside of the list\n";
        cout << "c: break the list into two, merge back so that second half becomes first half\n";
        cout << "s: show the content of the list\n";
        cout << "q: to exit\n";
        cout << "*********Menu***************" << endl;
        cin >> op;

        switch (op)
        {
        case 'd':
            cout << "What value do you want to remove:";
            cin >> value;
            cout << "Before deleting:\n";
            DisplayLinkedList(head);

            if (Delete(head, value))
            {
                cout << "After deleting:\n";
                DisplayLinkedList(head);
            }
            else
                cout << "value not in the list " << value << endl;
            break;

        case 'a':
            cout << "what value do you want to append to list" << endl;
            cin >> value;
            cout << "Before appending:\n";
            DisplayLinkedList(head);
            AppendInTheEnd(head, value);
            cout << "After appending:" << endl;
            DisplayLinkedList(head);
            break;
        case 'i':
            cout << "what value do you want to insert to beginning of list" << endl;
            cin >> value;
            cout << "Before inserting:\n";
            DisplayLinkedList(head);
            InsertAtFront(head, value);

            cout << "after inserting:\n";
            DisplayLinkedList(head);

            break;
        case 'l':

            cout << "What value do you want to look up?";
            cin >> value;

            found = Search(head, value);
            cout << "What new value do you want to assign to the node?";
            cin >> newValue;
            found->value = newValue;
            break;
        case 's':
            cout << "Displaying the current list:" << endl;
            DisplayLinkedList(head);
            break;

        case 'n':
            cout << "Create a list from an array\n";

            list = InitList(values, 9);

            //Display the newly created list
            DisplayLinkedList(list);

            //Todo: destroy the list...
            ClearLinkedList(list);
            break;
        case 'c': //Extra credit parts
            cout << "Cut the list into half in the middle\n";

            //Todo by you, calling your function that breaks
            //a list into two
            //

            //Display both lists using the DisplayLinkedList() functions
            //

            // Merge the two lists back, the second sublist goes first
            //

            //Display the merged list
            break;
        case 'm':
            cout << "What new value do you want to insert in the middle?" << endl;
            cin >> value;
            cout << "which current value in the list you want the new value placed before?" << endl;
            cin >> beforeThis;
            //find value just before insertion
            found = Search(head, beforeThis);
            AppendMiddle(found, value);
            break;
        case 'q':
            cout << "Exiting..." << endl;

            //Call the DeleteLinkedList () function to deallocate
            //all memory ...
            ClearLinkedList(head);
            break;
        default:
            cout << "Unknown request\n";
        }
    } while (op != 'q');
}

/* Displaying a linked list of NodType
 @head: address of the first node 
*/
void DisplayLinkedList(NodeType *head)
{
    NodeType *p;

    p = head; //initialize pointer p to point to the first node in the linked list

    cout << "Displaying the list: " << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    while (p != NULL)
    {
        cout << " Node at " << p << endl;
        cout << " 	value:  " << p->value << endl;
        cout << "	next:   " << p->next << endl;
        cout << "        previous:" << p->prev << endl;
        p = p->next; //update p to point to next node in the linked list ...
    }
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}

/* Create a new node to store the given value,
 * and make this new node the first of the linked lsit 
 @head: address of the first node, will be updated
 @value: 
*/
void InsertAtFront(NodeType *&head, ItemType value)
{
    NodeType *p, *next;

    p = new NodeType;

    p->value = value;
    p->next = head;
    p->prev = NULL;

    next = p->next;
    next->prev = p;

    head = p;
}

void AppendInTheEnd(NodeType *&head, ItemType num)
{
    //Todo by you ...
    NodeType *temp, *prevy;
    temp = head;
    //WE ARE AT FIRST EMPTY SLOT
    if (temp->next == NULL)
    {
        temp->value = num;
        NodeType *n = new NodeType;
        temp->next = n;
        return;
    }
    //IF SELECTED SLOT NOT EMPTY
    while (temp->next != NULL)
    {
        prevy = temp;
        temp = temp->next;
        if (temp->value == 0)
        {
            temp->prev = prevy;
            temp->value = num;
            NodeType *n = new NodeType;
            temp->next = n;
            return;
        }
    }
}

NodeType *Search(NodeType *firstNodePtr, ItemType value)
{
    NodeType *p;

    p = firstNodePtr;
    while (p->next != NULL)
    {
        if (p->value == value)
            return p;
        p = p->next; //update p with the current node's next field
    }
    cout << "cannot find what you were looking for..." << endl;
    return NULL;
}

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
NodeType *Search(NodeType *firstNodePtr, ItemType value,
                 NodeType *&prevNode)
{
    //Todo by you
}

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
bool Delete(NodeType *&firstPtr, ItemType value)
{
    NodeType *prev, *cur, *next;

    cur = Search(firstPtr, value);
    if (cur == NULL)
        return false;
    else
    {
        // remove cur node from the linked list
        if (cur->prev != NULL)
        {
            prev = cur->prev;
            prev->next = cur->next;
            next = cur->next;
            next->prev = prev;
            delete cur;
            return true;
        }
        else                      //cur is the first node
            firstPtr = cur->next; //update the head pointer
            delete cur;               //deallocate the node itself
            return true;
    }
}
//deletes all links to selected list
void ClearLinkedList(NodeType *&head)
{
    NodeType *prevy, *curr;
    curr = head;
    prevy = head;
    while (curr->value != 0 && curr->next != NULL)
    {
        curr = curr->next;
        delete prevy;
    }
    delete curr;
    cout << "All linked pointers in list have been deleted!" << endl;
}
//stores array values in linked list
NodeType *InitList(ItemType a[], int size)
{
    NodeType * temp = new NodeType;
    NodeType * head, *prev;
    for(int i=0; i<size; i++){
        if(i==(size-1)){
            temp->value = a[i];
            temp->next = NULL;
            temp->prev = prev;

            prev = temp;
            temp = temp->next;
            return head;
        }
        NodeType * next = new NodeType;
        if(i==0){
            head = temp;
            temp->value = a[0];
            temp->next = next;
            temp->prev = NULL;
            prev = temp;
            temp = temp->next;
        }
        else 
        {
            temp->value = a[i];
            temp->next = next;
            temp->prev = prev;

            prev = temp;
            temp = temp->next;
        }
        
    }
    
}
//insertion of new value
void AppendMiddle(NodeType * &afterNode, ItemType beforeValue){
    NodeType * cur, *before;
    cur = afterNode;
    before = cur->prev;
    NodeType * newNode = new NodeType;
    before->next = newNode;
    cur->prev = newNode;
    newNode->value = beforeValue;
    newNode->next = cur;
    newNode->prev = before;
    cout << "New node should have been inserted!!!" <<endl;
    //create new node for end
}