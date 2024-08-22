#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct User {
    int userID;
    int balance;
};

struct Transaction {
    int from_userID;
    int to_userID;
    int amount;
};

bool compareUsers(const User &a, const User &b) {
    return a.balance < b.balance;
}

int main() {
    int N, T;
    cin >> N;
    
    vector<User> users(N);
    for (int i = 0; i < N; ++i) {
        cin >> users[i].userID >> users[i].balance;
    }
    
    cin >> T;
    vector<Transaction> transactions(T);
    for (int i = 0; i < T; ++i) {
        cin >> transactions[i].from_userID >> transactions[i].to_userID >> transactions[i].amount;
    }
    
    for (const auto &transaction : transactions) {
        int fromIndex = -1, toIndex = -1;
        for (int i = 0; i < N; ++i) {
            if (users[i].userID == transaction.from_userID) {
                fromIndex = i;
            }
            if (users[i].userID == transaction.to_userID) {
                toIndex = i;
            }
        }
        
        if (fromIndex != -1 && toIndex != -1 && users[fromIndex].balance >= transaction.amount) {
            users[fromIndex].balance -= transaction.amount;
            users[toIndex].balance += transaction.amount;
            cout << "Success" << endl;
        } else {
            cout << "Failure" << endl;
        }
    }
    cout << "\n";
    sort(users.begin(), users.end(), compareUsers);
    
    for (const auto &user : users) {
        cout << user.userID << " " << user.balance << endl;
    }
    
    return 0;
}
