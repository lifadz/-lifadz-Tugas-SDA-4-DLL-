//Membuat Double Linked List dari modifikasi Single Linked List
#include<iostream>

using namespace std;

 struct doublelinklist{
    int angka;
    doublelinklist *prev;
    doublelinklist *next; 
};
doublelinklist *head, *tail, *current ,*add, *del,*after,*afternd;

//Untuk membuat node awal
void startdoubleLL (int node){
     head = new doublelinklist;
     head-> angka = node;
     head->prev = NULL;
     head->next = NULL;
     tail = head;
}
//Membuat fungsi tambah awal
void tambahhead (int node){
    add = new doublelinklist;
    add->angka = node;
    add->prev = NULL;
    add->next = head;
    head->prev = add;
    head = add;

}
//Membuat fungsi tambah after
void tambahafter (int node,int position){
    after= new doublelinklist;
    after->angka = node;

    current = head;
    int num = 1 ;
    while (num < position -1 ){
        current = current->next;
        num++;       
    }
    afternd = current->next;
    after->prev = current;
    after->next = afternd;
    current->next = after;
    afternd->prev = after; 
}
//Membuat fungsi tambah akhir
void tambahtail (int node){
    add= new doublelinklist;
    add->angka= node;
    add->prev = tail;
    add->next = NULL;
    tail->next = add;
    tail = add;  
    
}
//Membuat fungsi hapus awal
void hapushead (){
    del = head;
    head = head->next;
    delete del; 
}

//Membuat fungsi hapus akhir
void hapustail (){
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;   
}
//Membuat fungsi hapus after
void hapusafter(int position){
    int num = 1;
    current = head;
    while(num < position -1){
        current = current->next;
        num++;
    }
    del = current->next;
    afternd = del->next;
    current->next = afternd;
    afternd->prev = current;
    delete del;
}
//Untuk mencari data yang ingin dicari
int carinode(int data){
    doublelinklist* p = head;
    int i = 1;
    while (p->angka != data){
        p = p->next;
        i++;
    }
    return i;
}

//untuk print data
void printdoubleLL(){ 
    current = head;
    while (current != NULL){
        cout << current-> angka << " ";
        current = current->next;
    }
    cout<<endl;
}


int main(){

    startdoubleLL(3); // untuk deklarasi node awal
    printdoubleLL(); 
    //print data
   
    tambahhead(1); //insert atau tambah awal
    printdoubleLL();
    //print data

    tambahhead(5);//insert atau tambah awal
    printdoubleLL();
    //print data
    
    tambahafter(2,3);//insert atau tambah after 
    printdoubleLL();
    //print data

    tambahafter(11,2);//insert atau tambah after
    printdoubleLL();
    //print data

    tambahtail(6);//insert atau tambah akhir
    printdoubleLL();
    //print data
    
    hapushead();// hapus awal
    printdoubleLL();
    //print data

    hapustail();//hapus akhir
    printdoubleLL();
    //printdata

    hapusafter(1);//hapus after
    printdoubleLL();
    //printdata

    //untuk input data yang ingin dicari
    int data;
    cout << "Masukkan data yang ingin dicari: " << endl;
    cin >> data; 
    cout << "Data yang anda cari terdapat pada urutan ke - " << carinode(data);
    
}