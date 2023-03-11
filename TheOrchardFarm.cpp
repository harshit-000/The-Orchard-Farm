#include<bits/stdc++.h>
using namespace std;

int max_percentage = 40;
int apple_days = 10;
int apple_tree_income = 12000;
int orange_days = 6;
int orange_tree_income = 10000;
int mango_days = 15;
int mango_tree_income = 27500;
int lemon_days = 5;
int lemon_tree_income = 7500;
int coconut_days = 15;
int coconut_tree_income = 8000;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    int a = 1;
    while(t--) {
        int tree,days;
        cin >> tree >> days;
        int max_tree = (tree*max_percentage)/100;
        int income[5];
        int totalIncome = 0;
        income[0] = (days/apple_days)*apple_tree_income;
        income[1] = (days/orange_days)*orange_tree_income;
        income[2] = (days/mango_days)*mango_tree_income;
        income[3] = (days/lemon_days)*lemon_tree_income;
        income[4] = (days/coconut_days)*coconut_tree_income;
        for(auto x : income) totalIncome += x;
        tree -= 5;
        sort(income,income+5,greater<int>());
        int i = 0;
        while(tree > 0 && i < 5) {
            int temp = min(tree,max_tree-1);
            totalIncome += (income[i]*temp);
            tree -= temp;
            i++;
        }
        cout << "Case #" << a << ": ";
        cout << totalIncome << "\n";
        a++;
    }
    return 0;
}