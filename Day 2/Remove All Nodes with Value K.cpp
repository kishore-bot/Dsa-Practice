// EASY BUT NOT GOT ANSWER

// https://www.naukri.com/code360/problem-of-the-day/easy?leftPanelTabValue=PROBLEM

Node *removeNodes(Node *head, int k)
{
    if (head == NULL)
        return head;

    Node *curr = head, *prev = NULL;

    while (curr != nullptr)
    {

        if (curr->data == k)
        {

            if (prev == nullptr)
            {

                head = curr->next;
            }
            else
            {

                prev->next = curr->next;
            }

            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}