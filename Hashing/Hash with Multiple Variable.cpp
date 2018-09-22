#include <bits/stdc++.h>
using namespace std;
#define SIZE 20

struct data
{
    string name;
    int roll, reg;
    data(){}
    data(string na, int ro, int re)
    {
        name = na;
        roll = ro;
        reg = re;
    }
};

struct dataItem
{
    int key;
    struct data da;
};

struct dataItem *dataList[SIZE];
struct dataItem *singleItem;
struct dataItem *item;

int getHashCode (int key)
{
    return key%SIZE;
}

void insert (int key, string na, int ro, int re )
{
    struct dataItem *item = (struct dataItem*)malloc(sizeof(struct dataItem));
    item->key = key;
    item->da.name = na;
    item->da.roll = ro;
    item->da.reg = re;

    int hashIndex = getHashCode(key);

    while (dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1){
        hashIndex++;
        hashIndex = getHashCode(hashIndex);
    }
    dataList[hashIndex] = item;
}

struct dataItem *search_(int key)
{
    int hashIndex = getHashCode(key);

    while (dataList[hashIndex] != NULL){
        if(dataList[hashIndex]->key == key){
            return dataList[hashIndex];
        }
        ++hashIndex;
        hashIndex = getHashCode(hashIndex);
    }
    return NULL;
};

struct dataItem *del(struct dataItem *item)
{
    int key = item->key;

    int hashIndex = getHashCode(key);

    while (dataList[hashIndex] != NULL){
        if (dataList[hashIndex]->key == key){
            struct dataItem *temp = dataList[hashIndex];
            dataList[hashIndex] = singleItem;
            return NULL;
        }
        ++hashIndex;
        hashIndex = getHashCode(hashIndex);
    }
};

void display ()
{
    for (int i=0; i<SIZE; i++){
        if (dataList[i] != NULL){
            //printf("(%d, (%s, %d, %d)) \n", dataList[i]->key, dataList[i]->data.name, dataList[i]->data.roll, dataList[i]->data.reg);
            cout<<" ("<<dataList[i]->key<<","<<dataList[i]->da.name<<","<<dataList[i]->da.roll<<","<<dataList[i]->da.reg<<" )"<<endl;
        }
        cout << "~~~" << endl;
    }
}
void search_display(struct dataItem *item)
{
    if (item != NULL){
        cout << "Item Found" << endl;
        cout<<" ("<<item->key<<","<<item->da.name<<","<<item->da.roll<<","<<item->da.reg<<" )"<<endl;
    }
    else {
        cout << "Not Found !!! Better Luck next Time !!!" <<endl;
    }
}

int main()
{
    singleItem = (struct dataItem*)malloc(sizeof(struct dataItem));
    singleItem->key = -1;

    insert(1,"Tamim",1990,36);
    insert(21,"Abcd",2008,37);
    insert(2,"Mushfiq",2000,20);
    insert(22,"Rahim",2014,9);


   display();


    item = search_(22);
    search_display(item);

    del(item);
    item = search_(22);
    search_display(item);

   return 0;
}

