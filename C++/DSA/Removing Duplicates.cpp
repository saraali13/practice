void RemoveDuplicates(Node<T> * head)
{
Node<T> * curr,*temp,*duplicate;
curr=head;
while(curr != 0 && curr->Next !=0)
{
temp=curr;
while(temp->Next != 0)
{
if (curr->Data == temp->Next->Data)
{
duplicate=temp->Next;
temp->Next=temp->Next->Next;
duplicate->Next=0;
delete(duplicate);
}
else
temp=temp->Next;
} // inner while
curr= curr->Next;
} // outer while
} // end of RemoveDuplicates
