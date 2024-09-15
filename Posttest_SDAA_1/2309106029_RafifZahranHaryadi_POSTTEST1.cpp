#include <iostream>
using namespace std;

void menara_hanoi(int piringan ,string menara_asal, string menara_tujuan , string menara_sementara ) { 
    if (piringan == 1) {
        cout << "Pindah piringan 1 dari menara " << menara_asal << " ke menara " << menara_tujuan << endl;
        return;}

    menara_hanoi(piringan-1, menara_asal, menara_sementara, menara_tujuan);
    cout << "Pindah piringan " << piringan << " dari menara " << menara_asal << " ke menara " << menara_tujuan << endl;
    menara_hanoi(piringan-1, menara_sementara, menara_tujuan, menara_asal);
}

int main() {
    cout << "Penyelesaian Permasalahan Menara Hanoi:" << endl;
    cout << "" << endl;
    int piringan = 3;
    menara_hanoi(piringan, "Asal", "Tujuan", "Sementara"); //fungsi rekursif
    return 0;
}