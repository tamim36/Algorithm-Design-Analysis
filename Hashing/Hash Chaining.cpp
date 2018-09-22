#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
#define sSIZE 10
#define mod 5

struct dataItem
{
    int key;
    int data;
};

struct dataItem *dataList[SIZE][sSIZE];
struct dataItem *singleItem;
struct dataItem *item;

int getHashCode(int key)
{
    return key%mod;
}

void insert(int key, int data)
{
    item = (struct dataItem*)malloc(sizeof(dataItem));
    item->data = data;
    item->key = key;

    int hashIndex = getHashCode(key);

    for (int i=0; i<sSIZE; i++){
        if (dataList[hashIndex][i] == NULL){
            dataList[hashIndex][i] = item;
            break;
        }
    }
}

struct dataItem *search_item(int key)
{
    int hashIndex = getHashCode(key);

    for (int i=0; i<sSIZE; i++){
        if (dataList[hashIndex][i] == NULL){
            return NULL;
        }
        if (dataList[hashIndex][i]->key == key){
            return dataList[hashIndex][i];
        }
    }
    return NULL;
};

struct dataItem *del(struct dataItem *item)
{
    int key = item->key;

    int hashIndex = getHashCode(key);

    for (int i=0; i<sSIZE; i++){
        if (dataList[hashIndex][i] != NULL){
            if (dataList[hashIndex][i]->key == key){
                struct dataItem *temp = dataList[hashIndex][i];
                dataList[hashIndex][i] = singleItem;
                return temp;
            }
        }
    }
    return NULL;
};

void display()
{
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<sSIZE; j++){
            if (dataList[i][j] != NULL && dataList[i][j]->key != -1){
                printf("(%d, %d)  ", dataList[i][j]->key, dataList[i][j]->data);
            }
            else {
                cout << "~~~  ";
            }
        }
        cout << endl;
    }
}

void search_display(struct dataItem *item)
{
    if(item != NULL && item->key != -1){
        printf("Item found - (%d, %d) \n", item->key, item->data);
    }
    else{
        cout << "Item not found !!! Better Luck Next Time !" << endl;
    }
}

int main()
{
    singleItem = (struct dataItem*)malloc(sizeof(struct dataItem));
    singleItem->key = -1;
    singleItem->data = -1;

    insert(1,20);
    insert(1,25);
    insert(2,70);
    insert(42,80);
    insert(4,25);
    insert(12,44);
    insert(14,32);
    insert(17,11);
    insert(13,78);
    insert(37,97);

    display();
    printf("\n");
    item=search_item(37);
    search_display(item);

    del(item);
    item=search_item(37);
    search_display(item);
    printf("\n");
    return 0;
}

