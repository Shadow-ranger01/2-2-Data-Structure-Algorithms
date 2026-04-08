#include<iostream>
#include<algorithm>
using namespace std;

struct item
{
    float w;
    float p;
    float ppw;
};

bool compare(item a, item b){
    return a.ppw > b.ppw;
}

int main(){

    int n;
    float c;

    cout << "\n Enter the Number of items: ";
    cin >> n;
    cout << "\n Enter the Knapsack Capacity: ";
    cin >> c;

    item* items = new item[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\n\n Enter the Weight of item NO." << i << " : ";
        cin >> items[i].w;

        cout << "\n Enter the Price of item No." << i << " : ";
        cin >> items[i].p;

        items[i].ppw = items[i].p / items[i].w;

        cout << "\n The PRICE PER WEIGHT(ppw) of item " << i 
             << " is : " << items[i].ppw << endl;
    }


    sort(items, items + n, compare);

    float Profit = 0;
    float Weight_taken = 0;

    for (int i = 0; i < n; i++)
    {
        if (Weight_taken + items[i].w <= c) 
        {
            Weight_taken += items[i].w;
            Profit += items[i].p;
        }
        else
        {
            float remain = c - Weight_taken;
            Profit += remain * items[i].ppw;
            break;
        }
    }

    cout << "\n\n The profit : " << Profit;

    delete[] items; 

    return 0;
}
