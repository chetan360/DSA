#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

node* create(node* slist) {
    node *temp, *newnode;
    int n, val;
    cout<<"How many nodes : ";
    cin>>n;

    cout<<"Enter "<<n<<" values.."<<endl;
    for(int i=0; i<n; i++) {
        cin>>val;
        newnode = new node(val);

        if(slist == NULL) {
            slist = newnode;
            temp = newnode;
        }
        temp->next = newnode;
        temp = newnode;
    }

    return slist;
}

void display(node* slist) {
    node* temp = slist;
    while(temp != NULL) {
        if(temp->next == NULL) {
            cout<<" "<<temp->data<<" -> NULL";        
        } else {
            cout<<" "<<temp->data<<" ->";
        }
        temp = temp->next;
    }
}

int main() {
    node* slist = NULL;
    slist = create(slist);

    cout<<"List is :"<<endl;
    display(slist);

    return 0;
}