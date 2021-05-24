#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
struct node
{
    int data;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
void Init(TREE& t) {
    t = NULL;
}
void Add_Element(TREE &t, int& x) {
    if (t == NULL) {
        NODE* p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else if (x < t->data) {
        Add_Element(t->pLeft, x);
    }
    else if (x > t->data) {
        Add_Element(t->pRight, x);
    }
    else {
        return;
    }
}
void Output(TREE t) {
    if (t != NULL) {
        Output(t->pLeft);
        cout << t->data << " ";
        Output(t->pRight);
    }
}

void Read_File(ifstream& file, TREE& t) {
    file.open("Input.txt", ios_base::in);
    if (file.fail()) {
        cout << "Failed to open this file!";
    }
    int n;
    file >> n;
    for (int i = 0; i < n; i++) {
        int x;
        file >> x;
        Add_Element(t, x);
    }
    file.close();
}
int main() {
    TREE t;
    Init(t);
    ifstream file;
    Read_File(file, t);
    Output(t);
    return 0;
}



// m tao repo da ????
// cai github do
// đặt cái tên khác master
// tao m
// tai chua commit cho  no