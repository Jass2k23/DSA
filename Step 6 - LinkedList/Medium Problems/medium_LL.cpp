#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
        back = NULL;
    }
};

//! Middle of LL
//* Brute, O(N+N/2)
Node *middleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *mover = head;
    int cnt = 0;
    while (mover)
    {
        mover = mover->next;
        cnt++;
    }
    int middle_position = (cnt / 2) + 1;
    mover = head;
    for (int i = 1; i < middle_position; i++)
    {
        mover = mover->next;
    }
    return mover;
}

//* Using Tortoise and Hare Approach, O(N/2)
// Intuition -> When 2 people are traveling with x and x/2 speed. When 1st person reaches the end, the other person must be somewhere in the middle.
Node *middleNodeTH(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//! Reverse Singly LL
Node *reverseSLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = head;
    Node *current = head->next;
    while (current)
    {
        Node *forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    head->next = NULL;
    return prev;
}

//! Reverse Singly LL using recursion
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    // going to the last node
    Node *newHead = reverse(head->next);
    Node *forward = head->next;
    forward->next = head;
    head->next = NULL;

    return newHead;
}

//! LL cycle
//* Brute, O(N*logN)
bool hasCycle_brute(Node *head)
{
    if (head == nullptr)
        return false;
    Node *mover = head;
    unordered_map<Node *, int> m;

    while (mover->next)
    {
        if (m.find(mover) != m.end())
        {
            return true;
        }
        else
        {
            m[mover]++;
            mover = mover->next;
        }
    }
    return false;
}

//* Optimal, O(N)
bool hasCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

//! Position of LL cycle
//* Brute, O(N*logN)
// space -> O(N)
Node *detectCycle(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *mover = head;
    unordered_map<Node *, int> m;

    while (mover->next)
    {
        if (m.find(mover) != m.end())
        {
            return mover;
        }
        else
        {
            m[mover]++;
            mover = mover->next;
        }
    }
    return nullptr;
}

//* Optimal, avg O(N) & at max it can go to O(2N) i think
// space -> O(1)
Node *firstNode(Node *head)
{
    if (head == nullptr || head->next == head)
        return head;
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

//! Length of LL cycle
//* Brute, O(N*logN)
int lengthOfLoop_brute(Node *head)
{
    if (head == nullptr)
        return 0;

    Node *mover = head;
    unordered_map<Node *, int> m;
    int cnt = 0;

    while (mover->next)
    {
        if (m.find(mover) != m.end())
        {
            return cnt - m[mover];
        }
        else
        {
            cnt++;
            m[mover] = cnt;
            mover = mover->next;
        }
    }
    return 0;
}

//* Optimal
int lengthOfLoop(Node *head)
{
    if (head == nullptr || head->next == head)
        return 0;
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int cnt = 1;
            fast = fast->next;
            while (slow != fast)
            {
                fast = fast->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
}

Node *rev(Node *head)
{
    Node *curr = head->next;
    Node *prev = curr;

    while (curr)
    {
        Node *frwd = curr->next;
        curr->next = prev;
        curr = frwd;
        prev = curr;
    }
    head->next = nullptr;
    return prev;
}

//! Palindrome Check 4 LL
bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverse(slow);

    Node *revMover = newHead;
    Node *mover = head;

    while (revMover)
    {
        if (revMover->data != mover->data)
        {
            reverse(newHead);
            return false;
        }
        revMover = revMover->next;
        mover = mover->next;
    }
    reverse(newHead);
    return true;
}

//! Segregate Even And Odd Nodes In a Linked List
// odd appears before even

Node *oddEvenList(Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;

    while (even->next && even)
    {
        Node *nextOddLoc = odd->next->next;
        odd->next = nextOddLoc;
        odd = nextOddLoc;

        Node *nextEvenLoc = even->next->next;
        even->next = nextEvenLoc;
        even = nextEvenLoc;
    }
    odd->next = evenHead;
    if (even != NULL)
        even->next = NULL;
    return head;
}

//! Delete Kth Node From End
Node *removeKthNode(Node *head, int K)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *fast = head;
    Node *slow = head;
    int cnt = 0;

    while (cnt != K)
    {
        fast = fast->next;
        cnt++;
    }

    if (fast == NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *dltNode = slow->next;
    slow->next = slow->next->next;
    delete dltNode;

    return head;
}

//! Delete Middle Node
Node *deleteMiddle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

//! Merging 2 Sorted LL
Node *sortTwoLists(Node *first, Node *second)
{
    if (first == NULL)
        return second;
    else if (second == NULL)
        return first;

    Node *t1 = first;
    Node *t2 = second;
    Node *dNode = new Node(-1); //* new Node
    Node *temp = dNode;         //* only pointing to dNode

    while (t1 && t2)
    {
        if (t1->data <= t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    if (t1 == NULL)
    {
        temp->next = t2;
    }
    else
    {
        temp->next = t1;
    }

    return dNode->next;
}

//! Sorting LL
// bcz we need the 1st mid in case of even num
Node *middle_sort(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *middle_node = middle_sort(head);
    Node *leftHead = head;
    Node *rightHead = middle_node->next;
    middle_node->next = NULL;

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    return sortTwoLists(leftHead, rightHead);
}

//! Find the Intersection of Two LL
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    if (firstHead == NULL || secondHead == NULL)
        return nullptr;

    Node *t1 = firstHead;
    Node *t2 = secondHead;

    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
        {
            return t1;
        }

        else if (t1 == nullptr)
        {
            t1 = secondHead;
        }

        else if (t2 == nullptr)
        {
            t2 = firstHead;
        }
    }

    return t1;
}

//! Add 1 to a number rep. by LL
//* Optimal, using backtracking

int helper(Node *temp)
{
    if (temp == nullptr)
    {
        return 1;
    }

    int carry = helper(temp->next);

    temp->data += carry;
    if (temp->data < 10)
        return 0;
    temp->data = 0;
    return 1;
}

Node *addOne(Node *head)
{
    if (head == nullptr)
    {
        Node *dummy = new Node(1);
        return dummy;
    }

    int carry = helper(head);

    if (carry == 1)
    {
        Node *front = new Node(1);
        front->next = head;
        head = front;
    }

    return head;
}

//! Adding 2 number represented by LL
