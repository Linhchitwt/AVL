#include <iostream>
#include <math.h>
#include <algorithm>
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
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else{
        if (x < t->data){
            Add_Element(t->pLeft, x);
        }
        else{
            Add_Element(t->pRight, x);
        }
    }
}
void Input(int &n, int arr[], TREE &t){
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        cin >>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        Add_Element(t, arr[i]);
    }
}
void deleteNode(TREE &t, int x){
	if(t != NULL){
        if (t->data ==x ){
		delete(t);}
		if (t->pLeft != NULL) deleteNode(t->pLeft, x);
		if (t->pRight != NULL) deleteNode(t->pRight, x);
	}
}
void Output (TREE t){
    if (t != NULL){
        Output(t->pLeft);
        cout <<t->data<< " ";
        Output(t->pRight);
    }
    else {
       /// cout <<"NULL";
    }
}
int main(){
    int n, arr[100], x;
    int count = 0;
    TREE t;
    Init(t);
    Input(n,arr,t);
    cin >>x;
    deleteNode(t,x);
    Output(t);
    return 0;
}