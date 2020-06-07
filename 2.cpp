#include <bits/stdc++.h>
using namespace std;
#define pb push_back  
#define loop(i,n) for(int i = 0; i < n; i++)
#define mp make_pair
#define F first
#define S second
#define asort(a) sort(a,a+n)
#define vsort(v) sort(v.begin(), v.end())
#define remdup(v) v.erase(unique(v.begin(), v.end()), v.end())
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

class Node{
    public:
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

Node* addTwoNumbers(Node* l1, Node* l2) {
        int carry = 0;
        Node* list, * head;
        int sum = l1->val+l2->val;

            if(sum > 9){
                carry = 1;
                sum = sum%10;
            }
            head = new Node(sum);
            list = head;
            l1 = l1->next;
            l2 = l2->next;
        head = list;
        while(l1 && l2){
            int sum = l1->val+l2->val;
            if(carry){
                sum++;
                carry = 0;
            }
            if(sum > 9){
                carry = 1;
                sum = sum%10;
            }
            list->next = new Node(sum);
            list = list->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val;
            if(carry){
                sum++;
                carry = 0;
            }
            if(sum > 9){
                carry = 1;
                sum = sum%10;
            }
            list->next = new Node(sum);
            list = list->next;
            l1 = l1->next;
        }
           while(l2){
            int sum =l2->val;
            if(carry){
                sum++;
                carry = 0;
            }
            if(sum > 9){
                carry = 1;
                sum = sum%10;
            }
            list->next = new Node(sum);
            list = list->next;
            l2 = l2->next;
        }
        if(carry) list->next = new Node(carry);
        return head;
}

Node* reverse(Node* head){
    Node* prev = NULL, *nxt = NULL, *curr = head;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

void printList(Node* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* a = new Node(2);
    a->next = new Node(4);
    a->next->next = new Node(3);
    Node* b = new Node(5);
    b->next = new Node(6);
    b->next->next = new Node(4);
    Node* res = addTwoNumbers(a, b);
    res = reverse(res);
    printList(res);
}