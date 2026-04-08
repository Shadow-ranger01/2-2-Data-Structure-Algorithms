#include<iostream>
#include<algorithm>
#include<iomanip>
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

    // INPUT
    for (int i = 0; i < n; i++)
    {
        cout << "\n\n Enter Weight of item " << i << " : ";
        cin >> items[i].w;

        cout << " Enter Price of item " << i << " : ";
        cin >> items[i].p;

        items[i].ppw = items[i].p / items[i].w;
    }

    sort(items, items + n, compare);

    cout << "\n\n -------- After Sorting by Profit per Weight --------\n";
    cout << "Item\tWeight\tPrice\tPPW\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << items[i].w << "\t" << items[i].p 
             << "\t" << fixed << setprecision(2) << items[i].ppw << endl;
    }

    float Profit = 0;
    float Weight_taken = 0;

    cout << "\n\n -------- Selection Process --------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nConsidering Item " << i << " (W=" << items[i].w 
             << ", P=" << items[i].p << ")\n";

        if (Weight_taken + items[i].w <= c)
        {
            cout << " -> Taking FULL item\n";

            Weight_taken += items[i].w;
            Profit += items[i].p;
        }
        else
        {
            float remain = c - Weight_taken;

            cout << " -> Taking FRACTION of item\n";
            cout << "    Remaining Capacity = " << remain << endl;

            Profit += remain * items[i].ppw;
            Weight_taken += remain;

            break;
        }

        cout << " Current Total Weight = " << Weight_taken << endl;
        cout << " Current Total Profit = " << Profit << endl;
    }

    cout << "\n\n -------- Final Result --------\n";
    cout << " Total Weight Taken = " << Weight_taken << endl;
    cout << " Maximum Profit = " << Profit << endl;

    delete[] items;

    return 0;
}
