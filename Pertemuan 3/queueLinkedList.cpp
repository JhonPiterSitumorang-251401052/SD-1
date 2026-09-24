#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int input;

    // memasukkan data ke queue
    while (cin >> input){
        q.push(input);
    }

    // mengeluarkan dan menampilkan semua data
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}
