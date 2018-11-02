#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdbool.h>
#include <math.h>
#include <iostream>
#define MAX 999999
using namespace std;
struct node
{
	int data;
	struct node *next;
};

struct Itemset
{
	string data;
	struct Itemset *next;
};

struct ItemsetCollection
{
	Itemset *data;
	struct ItemsetCollection *next;
};

struct rules
{
	Itemset *X;
	Itemset *Y;
	double sp;
	double cf;
	struct rules *next;
};

//hien thi danh sach
void print_node(node *head)
{
	struct node *ptr = head;
	if (ptr == NULL) cout<<"this object is empty";


	cout<<"\n[ ";

	//bat dau tu phan dau danh sach
	while (ptr != NULL)
	{
		cout<<ptr->data;
		ptr = ptr->next;
	}

	cout<<" ]";
}
void print_ItemsetRules(Itemset *head)
{
	struct Itemset *ptr = head;
	//bat dau tu phan dau danh sach
	while (ptr != NULL)
	{
		cout<< ptr->data;
		ptr = ptr->next;
	}
}
void print_Itemset(Itemset *head)
{
	struct Itemset *ptr = head;
	if (ptr == NULL) cout<<"\n this object is empty";


	cout<<"\n[ ";

	//bat dau tu phan dau danh sach
	while (ptr != NULL)
	{
		cout<<"("<<ptr->data<<") ";
		ptr = ptr->next;
	}

	cout<<" ]";
}
void print_ItemsetCollection(ItemsetCollection *head)
{
	struct ItemsetCollection *ptr = head;
	cout<<"\n[ ";

	//bat dau tu phan dau danh sach
	while (ptr != NULL)
	{
		print_Itemset(ptr->data);
		ptr = ptr->next;
	}

	cout<<"\n]";
}
void print_rules(rules *head)
{
	struct rules *ptr = head;
	cout<<"\n[\n ";

	//bat dau tu phan dau danh sach
	while (ptr != NULL)
	{
		print_ItemsetRules(ptr->X);
		cout<<" => ";
		print_ItemsetRules(ptr->Y);
		cout<<" "<<ptr->sp<<" ";
		cout<<ptr->cf;
		cout<<"\n";
		ptr = ptr->next;
	}

	cout<<"]";
}

//chen link tai vi tri dau tien
void insertFirst_node(node *&head, int data)
{
	//tao mot link
	struct node *link = (struct node*) malloc(sizeof(struct node));

	link->data = data;

	//tro link nay toi first Itemset cu
	link->next = head;

	//tro first toi first Itemset moi
	head = link;
}
void insertFirst_Itemset(Itemset *&head, string data)
{
	//tao mot link
	 Itemset *link = new Itemset();

	link->data = data;

	//tro link nay toi first Itemset cu
	link->next = head;

	//tro first toi first Itemset moi
	head = link;
}
void insertFirst_rules(rules *&head, Itemset *X, Itemset *Y, double sp, double cf)
{
	//tao mot link
	struct rules *link = (struct rules*) malloc(sizeof(struct rules));

	link->X = X;
	link->Y = Y;
	link->cf = cf;
	link->sp = sp;

	//tro link nay toi first Itemset cu
	link->next = head;

	//tro first toi first Itemset moi
	head = link;
}
void insertFirst_ItemsetCollection(ItemsetCollection *&head, Itemset *data)
{
	//tao mot link
	struct ItemsetCollection *link = (struct ItemsetCollection*) malloc(sizeof(struct ItemsetCollection));

	link->data = data;

	//tro link nay toi first Itemset cu
	link->next = head;

	//tro first toi first Itemset moi
	head = link;
}

//xoa phan tu dau tien
struct Itemset* deleteFirst(Itemset *head)
{

	//luu tham chieu toi first link
	struct Itemset *tempLink = head;

	//danh dau next toi first link la first 
	head = head->next;

	//tra ve link bi xoa
	return tempLink;
}

//kiem tra list co trong hay khong
bool isEmpty(Itemset *head)
{
	return head == NULL;
}

int length_Itemset(Itemset *head)
{
	int length = 0;
	struct Itemset *current;

	for (current = head; current != NULL; current = current->next)
	{
		length++;
	}

	return length;
}
int length_node(node *head)
{
	int length = 0;
	struct node *current;

	for (current = head; current != NULL; current = current->next)
	{
		length++;
	}

	return length;
}

//tim mot link voi key da cho
struct Itemset* find_(Itemset *head, string data) {

	//bat dau tim tu first link
	struct Itemset* current = head;

	//neu list la trong
	if (head == NULL)
	{
		return NULL;
	}

	//duyet qua list
	while (current->data != data) {

		//neu day la last Itemset
		if (current->next == NULL) {
			return NULL;
		}
		else {
			//di chuyen toi next link
			current = current->next;
		}
	}

	//neu tim thay du lieu, tra ve link hien tai
	return current;
}

//tim gia tri cua node tai vi tri index
int findData_node(node *head, int index)
{
	int dem = 0;
	//bat dau tim tu first link
	struct node* current = head;

	//neu list la trong
	if (head == NULL)
	{
		return NULL;
	}

	//duyet qua list
	while (dem != index)
	{
		//di chuyen toi next link
		current = current->next;
		dem++;
	}

	//neu tim thay du lieu, tra ve link hien tai
	return current->data;

}

//tim gia tri cua itemset tai vi tri index
string findData_Itemset(Itemset *head, int index)
{
	int dem = 0;
	//bat dau tim tu first link
	struct Itemset* current = head;

	//neu list la trong
	if (head == NULL)
	{
		return NULL;
	}

	//duyet qua list
	while (dem != index)
	{
		//di chuyen toi next link
		current = current->next;
		dem++;
	}

	//neu tim thay du lieu, tra ve link hien tai
	return current->data;

}

//xoa mot link voi key da cho
struct Itemset* deleteKey(Itemset *&head, string data) {

	//bat dau tu first link
	struct Itemset* current = head;
	struct Itemset* previous = NULL;

	//neu list la trong
	if (head == NULL) {
		return NULL;
	}

	//duyet qua list
	while (current->data != data) {

		//neu day la last Itemset
		if (current->next == NULL) {
			return NULL;
		}
		else {
			//luu tham chieu toi link hien tai
			previous = current;
			//di chuyen toi next link
			current = current->next;
		}

	}

	//cap nhat link
	if (current == head) {
		//thay doi first de tro toi next link
		//head = NULL;
		head = head->next;
	}
	else {
		//bo qua link hien tai
		previous->next = current->next;
		return current;
	}


}

// ham sap xep
void sort(Itemset *head) {

	int i, j, k, tempKey;
	string tempData;
	struct Itemset *current;
	struct Itemset *next;

	int size = length_Itemset(head);
	k = size;

	for (i = 0; i < size - 1; i++, k--) {
		current = head;
		next = head->next;

		for (j = 1; j < k; j++) {

			if (current->data > next->data) {
				tempData = current->data;
				current->data = next->data;
				next->data = tempData;
			}

			current = current->next;
			next = next->next;
		}
	}
}

// ham dao nguoc list
void reverse_Itemset(struct Itemset** head_ref) {
	struct Itemset* prev = NULL;
	struct Itemset* current = *head_ref;
	struct Itemset* next;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head_ref = prev;
}
void reverse_ItemsetCollection(struct ItemsetCollection** head_ref) {
	struct ItemsetCollection* prev = NULL;
	struct ItemsetCollection* current = *head_ref;
	struct ItemsetCollection* next;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head_ref = prev;
}

////////////////////////////////////////////////////////////////////////////////
//******************************************************************************

//clear all ItemsetCollection
void clearItemsetCollection(ItemsetCollection *&head) {
	//bat dau tu phan dau danh sach
	while (head != NULL)
	{
		head = head->next;
	}
}

//count ItemsetCollection
int countItemsetCollection(ItemsetCollection *head) {
	//bat dau tu phan dau danh sach
	int kq = 0;
	while (head != NULL)
	{
		kq++;
		head = head->next;
	}
	return kq;
}
int countRules(rules *head) {
	//bat dau tu phan dau danh sach
	int kq = 0;
	while (head != NULL)
	{
		kq++;
		head = head->next;
	}
	return kq;
}
//count Itemset
int countItemset(Itemset *head) {
	//bat dau tu phan dau danh sach
	int kq = 0;
	while (head != NULL)
	{
		kq++;
		head = head->next;
	}
	return kq;
}

//ttim so lan xuat hien itemset trong itemcollection
int Appear(ItemsetCollection *db, Itemset *item) {
	int db_size = countItemsetCollection(db);
	int item_size = countItemset(item);
	struct ItemsetCollection *ptr_1 = db;
	int dem_z = 0;
	while (ptr_1 != NULL)
	{
		int dem = 0;
		struct Itemset *tmp = item;
		while (tmp != NULL)
		{
			if (find_(ptr_1->data, tmp->data) != NULL)
			{
				dem++;
			}
			tmp = tmp->next;
			if (dem == item_size) {
				dem_z++;
			}
		}

		ptr_1 = ptr_1->next;
	}
	return dem_z;

}

//ham tinh do pho bien
double FindSupport(ItemsetCollection *db, Itemset *item) {
	double kq = 0.0;
	kq = ((double)Appear(db, item) / (double)countItemsetCollection(db)) * 100;
	return kq;
}

int GetBit(int value, int position)
{
	int bit = value & (int)pow(2.0, position);
	return (bit > 0 ? 1 : 0);
}
//doi thap phan sang nhi phan
node* DecimalToBinary(int value, int length)
{
	struct node *binary = NULL;
	for (int position = 0; position < length; position++)
	{
		insertFirst_node(binary, GetBit(value, position));
	}
	return (binary);
}

//dem so bit 1 trong chuoi nhi phan
int GetOnCount(int value, int length)
{
	int dem = 0;
	node* binary = DecimalToBinary(value, length);
	struct node *ptr = binary;
	//bat dau tu phan dau danh sach
	while (ptr != NULL)
	{
		if (ptr->data == 1) dem++;
		ptr = ptr->next;
	}
	return dem;
}

//ham tim tat ca tap con cua tap co k phan tu
struct ItemsetCollection* FindSubsets(Itemset *itemset, int n)
{
	ItemsetCollection *subsets = NULL;
	int subsetCount = (int)pow(2.0, countItemset(itemset));

	for (int i = 0; i < subsetCount; i++)
	{
		if (n == 0 || GetOnCount(i, countItemset(itemset)) == n)
		{
			node* binary = DecimalToBinary(i, countItemset(itemset));

			Itemset *subset = NULL;
			for (int nodeIndex = 0; nodeIndex < length_node(binary); nodeIndex++)
			{
				if (findData_node(binary, nodeIndex) == 1)
				{
					insertFirst_Itemset(subset, findData_Itemset(itemset, nodeIndex));
				}
			}
			insertFirst_ItemsetCollection(subsets, subset);
		}
	}
	return subsets;
}
//--------------------------------mine data with sp----------------------------------------------------------//
struct Itemset* GetUniqueItems(ItemsetCollection *head) {
	Itemset *kq = NULL;
	struct ItemsetCollection *ptr_1 = head;

	insertFirst_Itemset(kq, ptr_1->data->data);
	while (ptr_1 != NULL)
	{
		Itemset *ptr_2 = ptr_1->data;
		while (ptr_2 != NULL)
		{
			if (find_(kq, ptr_2->data) == NULL)
			{
				insertFirst_Itemset(kq, ptr_2->data);
			}
			ptr_2 = ptr_2->next;

		}
		ptr_1 = ptr_1->next;
	}
	return kq;
}
struct ItemsetCollection* doApriori(ItemsetCollection *db, double supportThreshold) {
	Itemset *I = GetUniqueItems(db);
	ItemsetCollection *L = NULL; // tập dữ liệu phổ biến
	ItemsetCollection *Li = NULL;//tập dữ liệu 
	ItemsetCollection *Ci = NULL; //tập dữ liệu được lược bớt

	//duyet su lap lai cua phan tu dau tien trong tap du lieu
	while (I != NULL)
	{
		Itemset *tmp = NULL;
		insertFirst_Itemset(tmp, I->data);
		insertFirst_ItemsetCollection(Ci, tmp);
		I = I->next;
	}
	//su lap lai cac lan ke tiep
	int k = 2;
	while (Ci != NULL)
	{
		//lay Li tu Ci (phan tu dc luot bo)
		clearItemsetCollection(Li);
		ItemsetCollection *Ci_tmp = Ci;
		while (Ci_tmp != NULL)
		{
			double sp = FindSupport(db, Ci_tmp->data);
			if (sp >= supportThreshold)
			{
				insertFirst_ItemsetCollection(Li, Ci_tmp->data);
				insertFirst_ItemsetCollection(L, Ci_tmp->data);
			}
			Ci_tmp = Ci_tmp->next;
		}
		if (Li == NULL) break;
		clearItemsetCollection(Ci);
		Ci = FindSubsets(GetUniqueItems(Li), k);
		k++;
	}

	return (L);
}
void print_ItemsetCollection_sp(ItemsetCollection *head, ItemsetCollection *db)
{
	struct ItemsetCollection *ptr = head;
	cout<<"\n[ ";

	//bat dau tu phan dau danh sach
	while (ptr != NULL)
	{
		print_Itemset(ptr->data);
		cout<< FindSupport(db, ptr->data);
		ptr = ptr->next;
	}

	cout<<"\n]";
}
//--------------------------------mine data with cf---------------------------------------------------------//
struct rules* Mine(ItemsetCollection *db, ItemsetCollection *L, double confidenceThreshold)
{
	rules *allRules = NULL;
	ItemsetCollection *tmp_L = L;
	while (tmp_L != NULL)
	{
		ItemsetCollection *subsets = FindSubsets(tmp_L->data, 0);
		ItemsetCollection *tmp_subset = subsets;

		while (tmp_subset != NULL)
		{
			//tao ra ban copy du lieu cua tmp_L de dung cho viec xoa
			ItemsetCollection *copy_L = NULL;
			ItemsetCollection *tmp_L_L = tmp_L;
			while (tmp_L_L != NULL) {
				Itemset *tmp_L_L_sub = tmp_L_L->data;
				Itemset *chil = NULL;
				while (tmp_L_L_sub != NULL)
				{
					insertFirst_Itemset(chil, tmp_L_L_sub->data);
					tmp_L_L_sub = tmp_L_L_sub->next;
				}
				insertFirst_ItemsetCollection(copy_L, chil);
				tmp_L_L = tmp_L_L->next;
			}
			reverse_ItemsetCollection(&copy_L);
			//

			double confidence = (FindSupport(db, tmp_L->data) / FindSupport(db, tmp_subset->data))*100.0;
			if (confidence >= confidenceThreshold)
			{
				rules *rule = NULL;
				//rule->X = tmp->data;
				Itemset *tmp_X = NULL;
				tmp_X = tmp_subset->data;
				//xoa x ra khoi tmp_L->data
				while (tmp_X != NULL)
				{
					deleteKey(copy_L->data, tmp_X->data);
					tmp_X = tmp_X->next;
				}
				//rule->sp = FindSupport(db, tmp_L->data);
				//rule->cf = confidence;
				if (length_Itemset(tmp_subset->data) > 0 && length_Itemset(copy_L->data) > 0)
				{
					insertFirst_rules(allRules, tmp_subset->data, copy_L->data, FindSupport(db, tmp_L->data), confidence);
				}
			}
			tmp_subset = tmp_subset->next;
		}
		tmp_L = tmp_L->next;
	}

	return (allRules);
}
int main() {
	struct Itemset *tmp = NULL;


	struct Itemset *a = NULL;
	struct Itemset *b = NULL;
	struct Itemset *c = NULL;
	struct Itemset *d = NULL;
	struct Itemset *e = NULL;
	struct Itemset *z = NULL;
	struct Itemset *z1 = NULL;

	insertFirst_Itemset(a, "beer");
	insertFirst_Itemset(a, "diaper");
	insertFirst_Itemset(a, "baby powder");
	insertFirst_Itemset(a, "bread");
	insertFirst_Itemset(a, "umbrella");
	print_Itemset(a);
	cout<<"\n";



	insertFirst_Itemset(b, "diaper");
	insertFirst_Itemset(b, "baby powder");
	print_Itemset(b);
	cout<<"\n";

	insertFirst_Itemset(c, "beer");
	insertFirst_Itemset(c, "diaper");
	insertFirst_Itemset(c, "milk");
	print_Itemset(c);
	cout<<"\n";

	insertFirst_Itemset(d, "diaper");
	insertFirst_Itemset(d, "beer");
	insertFirst_Itemset(d, "detergent");
	print_Itemset(d);
	cout<<"\n";

	insertFirst_Itemset(e, "beer");
	insertFirst_Itemset(e, "milk");
	insertFirst_Itemset(e, "coca-cola");
	print_Itemset(e);
	cout<<"\n";

	struct ItemsetCollection *L = NULL;
	insertFirst_ItemsetCollection(L, a);
	insertFirst_ItemsetCollection(L, b);
	insertFirst_ItemsetCollection(L, c);
	insertFirst_ItemsetCollection(L, d);
	insertFirst_ItemsetCollection(L, e);
	print_ItemsetCollection(L);
	cout<<"\n";

	Itemset *uniqueItems = GetUniqueItems(L);
	print_Itemset(uniqueItems);
	cout<<"\n";

	//test apriori(do pho bien)
	ItemsetCollection *L1 = doApriori(L, 40.0);
	cout<<"\n itemsets in L \n"<< countItemsetCollection(L1);//dem tap du lieu pho bien
	print_ItemsetCollection_sp(L1, L);

	//test mining(tim luat co do tin cay >=70%)
	rules *allRules = Mine(L, L1, 70.0);
	cout<<"\n rules \n"<< countRules(allRules);
	print_rules(allRules);

	system("pause");
	return 0;
}