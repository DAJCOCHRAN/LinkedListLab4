#include "header.h"

/* Displaying a linked list of NodType
 @head: address of the first node 
*/
void DisplayLinkedList(NodeType *head)
{
    NodeType *p;
    p = head; //initialize pointer p to point to the first node in the linked list
    cout << "Displaying the list: " << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    while (p)
    {
        cout << " Node at " << p << endl;
        cout << " 	value:  " << p->value << endl;
        cout << "	next:   " << p->next << endl;
        cout << "        previous:" << p->prev << endl;
        if (p->next)
            p = p->next; //update p to point to next node in the linked list ...
        else
            return;
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
    while (temp->value != 0)
    {
        prevy = temp;
        temp = temp->next;
        if (temp->value == 0)
        {
            temp->prev = prevy;
            temp->value = num;
            NodeType *n = new NodeType;
            temp->next = n;
            n->prev = temp;
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
    NodeType *temp = new NodeType;
    NodeType *head, *prev;
    for (int i = 0; i < size; i++)
    {
        if (i == (size - 1))
        {
            temp->value = a[i];
            temp->next = NULL;
            temp->prev = prev;

            prev = temp;
            temp = temp->next;
            return head;
        }
        NodeType *next = new NodeType;
        if (i == 0)
        {
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
void AppendMiddle(NodeType *&afterNode, ItemType beforeValue)
{
    NodeType *cur, *before;
    cur = afterNode;
    before = cur->prev;
    NodeType *newNode = new NodeType;
    before->next = newNode;
    cur->prev = newNode;
    newNode->value = beforeValue;
    newNode->next = cur;
    newNode->prev = before;
    cout << "New node should have been inserted!!!" << endl;
    //create new node for end
}
NodeType *SplitHalf(NodeType *head)
{
    NodeType *temp = head;
    NodeType *tempTwo = head;
    int nodeCnt = 0;
    int half = 0;
    //end of list will have node with 0 value to get node count
    while (temp->next != NULL)
    {
        temp = temp->next;
        nodeCnt++;
    }
    cout << "This should be last head " << temp << endl;

    if (temp->next == NULL)
    {
        temp = temp->prev;
        temp->next = NULL;
    }

    cout << "Count is --> " << nodeCnt << endl;
    half = nodeCnt / 2;
    cout << "Half is --> " << half << endl;
    for (int i = 0; i < half; i++)
    {
        tempTwo = tempTwo->next;
    }
    cout << "Address of second head is" << tempTwo << endl;
    //cut head
    temp = tempTwo->prev;
    temp->next = NULL;
    //make the new head
    tempTwo->prev = NULL;

    //NOW WE MUST REMOVE EMPTY ARRAY AT END OF TEMP TWO

    return tempTwo;
}
NodeType *Merge(NodeType *head, NodeType *secondHead)
{
    //take account of empty node at end of original head
    //second head ahead of head

    NodeType *temp = head;
    NodeType *secondTemp = secondHead;
    NodeType *addEmpty;
    while (secondTemp->next != NULL)
    {
        secondTemp = secondTemp->next;
    }
    cout << "I passed" << endl;

    if (secondTemp->next == NULL)
    {
        secondTemp->next = temp;
        temp->prev = secondTemp;
        //point back to head
        secondTemp = secondHead;
        addEmpty = secondHead;
        while (addEmpty->next != NULL)
        {
            addEmpty = addEmpty->next;
        }
        if (addEmpty->next == NULL)
        {
            NodeType *newNode = new NodeType;
            addEmpty->next = newNode;
            newNode->prev = addEmpty;
        }
        return secondTemp;
    }
}
void NodeCount(NodeType *&head)
{
    int count = 0;
    NodeType *p = head;
    if (p->next == NULL)
    {
        cout << "you only have one reserved node that is not in use" << endl;
        return;
    }
    while (p->next != NULL)
    {
        p = p->next;
        count++;
    }
    cout << "You have " << count << " Nodes being used along with 1 reserved node" << endl;
    cout << "A total of " << (count + 1) << "Nodes!!!" << endl;
    return;
}