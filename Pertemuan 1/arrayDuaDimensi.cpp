#include <iostream>
using namespace std;

int main(){
    int nilai[3][4] = {
        {90, 75, 90, 85},
        {70, 60, 88, 77},
        {95, 85, 92, 89}
    }; // <<--- ingat titik koma (;) setelah kurung kurawalnya

    for(int i = 0; i < 3 ; i++){
        cout << "Mahasiswa " << i + 1 << " : ";

        for(int j = 0; j < 4; j++){
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
