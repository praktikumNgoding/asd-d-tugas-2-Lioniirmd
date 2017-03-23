#include <iostream>
#include <cstdlib>
using namespace std;
struct node{
	int link_data;
	node *newdata;
};
 node *head;
	int data_kosong(){
	if (head==NULL)
		return 1;
	else 
		return 0;
	}
void Data_depan(int dbaru){
	node *baru;
	baru = new node;
	baru->link_data = dbaru;
	baru->newdata = NULL;
	if(data_kosong()==1){
		head = baru;
		head->newdata = NULL;
	}
	else{
		baru->newdata = head;
		head = baru;
	}
	cout<<"\nData Telah Masuk\n";
}
void Tmpl_data(){
	node *bantu;
	bantu = head;
	if(data_kosong() == 0){
	cout<<"\nData yang sudah masuk kedalam list\n";
	while(bantu !=NULL){
	cout<<bantu->link_data<<"\n";
	bantu=bantu->newdata;
		}
		cout<<endl;
	} 
	else cout<<"Tidak ada data yang dimasukan\n";
}
void Datdpn_hapus(){
	node *hapus;
	int y;
	if(data_kosong()==0){
		if(head->newdata != NULL){
			hapus=head;
			y=hapus->link_data;
			head = head->newdata;
			delete hapus;
		}
		 else {
			y= head->link_data;
			head=NULL;
		}
		cout <<y<< "Data telah dihapus\n";
	}
	else cout<<"Tidak ada data yang dimasukan\n";
}
void Datbel_hapus(){
	node *hapus,*bantu;
	int d;
	if (data_kosong() == 0) {
		if (head->newdata != NULL ){
			bantu = head;
			while (bantu->newdata->newdata != NULL){
				bantu = bantu ->newdata;
			}
			hapus = bantu->newdata;
			d = hapus -> link_data;
			bantu->newdata= NULL;
			delete hapus;
		} 
		else {
			d = head -> link_data;
			head = NULL;
		}
		cout<<"Tidak ada data yang dimasukan\n";
	} 
	else cout<<"masih belom ada data\n";
}
void Blkmsk(int dtbaru) {
	node *baru, *bantu;
	baru = new node;
	baru -> link_data = dtbaru;
	baru -> newdata = NULL;
	if (data_kosong() == 1){
		head = baru;
		head -> newdata = NULL;
	} else {
		bantu = head;
		while (bantu->newdata != NULL) {
			bantu=bantu->newdata;
		}
		bantu -> newdata = baru;
	}
	cout <<"Data telah masuk\n";
}
\
int main(){
	int x;
	int dbaru;
	cout<<"\n"<<"=========================MENU LINKED LIST========================="<<"\n\n";
	cout<<"1. Masukan jumlah data yang ada di depan"<<endl;
	cout<<"2. Masukan jumlah data yang ada di belakang "<<endl;
	cout<<"3. Tampilan Keduan data yang sudah diinputkan"<<endl;
	cout<<"4. Hapus jumlah data yang ada di depan"<<endl;
	cout<<"5. Hapus jumlah data yang ada di belakang "<<endl;
	cout<<"6. Keluar Dari Data "<<endl;
	while (true){
		cout<<"\n"<<"Masukan Pilihan  = ";
		cin>>x;
		if (x== 1 ) {
			cout<<"\n"<<"Jumlah data : ";
			cin>>dbaru;
			Data_depan(dbaru);
		}
		else if (x == 2 ) {
			cout<<"\n"<<"Jumlah data : ";
			cin>>dbaru;
			Blkmsk(dbaru); 
		}	
		else if (x == 3 ) {
			Tmpl_data(); 
		}
		else if (x == 4 ) {
			Datdpn_hapus(); 
		}
		else if (x == 5 ){
			Datbel_hapus(); 
		}
		else if (x == 6 )
		 {
			break;
			
		}
	}
}


