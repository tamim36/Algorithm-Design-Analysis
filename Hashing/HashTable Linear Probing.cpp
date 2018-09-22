#include <bits/stdc++.h>
using namespace std;
#define SIZE 20

struct dataItem
{
    int key;
    int data;
};

struct dataItem *dataList[SIZE];
struct dataItem *singleItem;
struct dataItem *item;

int getHashCode(int key)
{
    return key%SIZE;
}

void insert (int key, int data)
{
    item = (struct dataItem*)malloc(sizeof(struct dataItem));
    item->data = data;
    item->key = key;

    int hashIndex = getHashCode(key);

    while (dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1)
    {
        hashIndex++;
        hashIndex = getHashCode(hashIndex);
    }

    dataList[hashIndex] = item;
}

struct dataItem *search_item(int key)
{
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL){
        if (dataList[hashIndex]->key == key) return dataList[hashIndex];

        hashIndex++;
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
            return temp;
        }
        hashIndex++;
        hashIndex = getHashCode(hashIndex);
    }
    return NULL;
};

void display()
{
    for(int i=0; i<SIZE; i++){
        if (dataList[i] != NULL  && dataList[i]->key != -1){
            printf(" (%d, %d) ", dataList[i]->key, dataList[i]->data);
        }
        else{
            cout << " ~~ , ~~ " << endl;
        }
        cout << endl;
    }
}

int main()
{
    singleItem = (struct dataItem*)malloc(sizeof(struct dataItem));
    singleItem->key = -1;
    singleItem->data = -1;

    insert(1, 20) ;
    insert(2, 70) ;
    insert(42, 80) ;
    insert(4, 25) ;
    insert(12, 44) ;
    insert(14, 32) ;
    insert(17, 11) ;
    insert(13, 78) ;
    insert(37, 97) ;

    display();

    item = search_item(37);

    if (item != NULL){
        cout << "Item Found " << "(" << item->key << ", " << item->data <<")"<< endl;
    }
    else {
        cout << "item not found" <<endl;
    }

    del(item);

    //display();

    item = search_item(37);

    if (item != NULL){
        cout << "Item Found " << "(" << item->key << ", " << item->data <<")"<< endl;
    }
    else {
        cout << "item not found" <<endl;
    }

    return 0;
}
