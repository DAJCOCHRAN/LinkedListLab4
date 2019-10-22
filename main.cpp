
#include "header.h"

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
    NodeType *found; // store found pointer value
    NodeType *secondHead; //store second half head of split

    do
    {
        cout << "*********Menu***************" << endl;
        cout << "What you want to do:" << endl;
        cout << "d: delete a value from the list\n";
        cout << "a: append a value to the end of the list\n";
        cout << "i: insert a value to the beginning of the list\n";
        cout << "m: insert a value before an existing value \n";
        cout << "b: show the amount of nodes being used \n";
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
            cout << "We shall cut the list into half...\n";

            //Todo by you, calling your function that breaks
            //a list into two
            secondHead = SplitHalf(head);

            //Display both lists using the DisplayLinkedList() functions
            //
            cout << "~----LIST ONE-----~" << endl;
            DisplayLinkedList(head);

            cout << "~----LIST TWO-----~" << endl;
            DisplayLinkedList(secondHead);
            // Merge the two lists back, the second sublist goes first
            //
            head = Merge(head, secondHead);
            //Display the merged list
            cout << "~-----NEW LIST-----~" << endl;
            DisplayLinkedList(head);
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
        case 'b':
            NodeCount(head);
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
    return 0;
}
