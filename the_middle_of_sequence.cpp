#include<iostream>
using namespace std;
class node{
    public:
    int data,l,r;
    node* left,*right;
    node(int d,int l0=0,int r0=0):data(d),l(l0),r(r0),left(nullptr),right(nullptr){}
};
class tree{
    public:
    node* root;
    tree(int d){
        root=new node(d);
    }
    void insert(int d){
        node* temp=root;
        while(true){
            if(d<temp->data){
                temp->l++;
                if(temp->left==NULL){
                    temp->left=new node(d);
                    return;
                }
                else temp=temp->left;
            }
            else{
                temp->r++;
                if(temp->right==NULL){
                    temp->right=new node(d);
                    return;
                }
                else temp=temp->right;
            }
        }
    }
    int search(){
        node* temp=root;
        int l=0,r=0;
        while(true){
            if(r+temp->r==l+temp->l)return temp->data;
            else if(r+temp->r>l+temp->l){
                l+=temp->l+1;
                temp=temp->right;
            }
            else{
                r+=temp->r+1;
                temp=temp->left;
            }
        }
    }
};
int main(){
    int n;
    cin>>n;
    int a,b;
    cin>>a;
    tree t(a);
    cout<<a<<endl;  
    int k=n%2==0?n/2-1:n/2;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        t.insert(a);
        t.insert(b);
        cout<<t.search()<<endl;
    }
    if(n%2==0)cin>>k;
}