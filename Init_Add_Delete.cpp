#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE *TREE;
void Init(TREE &t){
 t = NULL;
}
void Add_Element(TREE &t, int &x){
    if (t == NULL ){
        // chua co phan tu nao
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else {
        if (x < t->data){
            Add_Element(t->pLeft, x);
        }
        else if (x > t->data){
            Add_Element(t->pRight, x);
        }
        else {
            return;
        }
    }
}
void Input(int &n, int arr[], TREE &t){
    cout <<"Number of element n = ";
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Element "<<i+1<<" = ";
        cin >>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        Add_Element(t,arr[i]);
    }
}
void Delete_Element(int &k, TREE &t){
    if (t != NULL){
        if (k < t->data){
            Delete_Element(k, t->pLeft);
        }
        else if (k > t->data){
            Delete_Element(k, t->pRight);
        }
        else {
            // k = t-> data
            NODE *g = t; // g la node the mang cho t
            if (t->pLeft == NULL){
                // trường hợp node có 1 con bên phải hoặc là lá
                t = t->pRight;
            }
            else if (t->pRight == NULL){
                 // trường hợp là node có 1 con bên trái
                t = t->pLeft;
            }
            else {
                // khi node do co 2 con
                    NODE *h = t->pRight; // trường hợp node có 2 con thì tìm node h trái nhất của cây bên phải 
                    NODE *k = t->pRight; // k là node cha của node h 
                    while (h->pLeft != NULL){
                        k = h;
                        h = h->pLeft;
                        // tim duoc h la node trai nhat
                    }
                    if (k != h){
                        // k là node cha của h
                        // ta cho k trỏ tới node mà h liên kết bên phải
                        k->pLeft = h->pRight;
                        // để h giữ các mối liên kết của t (thay thế cho t)
                        h->pLeft = t->pLeft;
                        h->pRight = t->pRight;
                        // lúc này t trờ thành h 
                        t = h;
                    }
                    // trường hợp h tìm được không còn node con
                    /* trường hợp này không cần dùng đến k để giữ mối 
                    liên kết mà ta sẽ đưa thẳng h lên vị trí cần thế */
                    else {
                    h->pLeft = t->pLeft;
                    t = h;
                    }
            }
                    delete(g);
        }
    }
    else {
        return;
    }
}
void Output(TREE t){
    if (t != NULL){
        cout << t->data <<" ";
        Output(t->pLeft);
        Output(t->pRight);
    }
}
int main(){
    int n, arr[100],k;
    TREE t;
    Init(t);
    Input(n,arr,t);
    cout <<"Input the value need delete k = ";
    cin >> k;
    Delete_Element(k,t);
    Output(t);
    return 0;
}