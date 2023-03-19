#include "edukasi.h"

/**

Faras Perdana Subianto Putra  - 1303204129
Robby Adriansyah Fadillah      - 1303204095

*/

int main()
{
    list_riwayatP d;
    createListriwayatP(d);
    list_pegawai m;
    createListpegawai(m);
    list_relasi r;
    createListrelasi(r);
    adr_riwayatP p;
    adr_pegawai q;
    riwayatP riwayatP;
    pegawai pegawai;
    int pilihan = -1;
    while (pilihan != 0){
        pilihan = menuEdukasi();


        switch(pilihan){
        case 1:
            cout<<endl;
            cout << "Masukan Nama Riwayat Pendikan : "; cin >> riwayatP.namaRP;
            cout << "Masukan Tahun Riwayat Pendidikan : "; cin >> riwayatP.tahunRP;
            cout << "Masukan Kota Riwayat Pendidikan: "; cin >> riwayatP.kotaRP;
            cout << "Masukan Jenis Riwayat Pendidikan (Formal / Non-Formal) : "; cin >> riwayatP.jenisRP;
            p = createElmriwayatP(riwayatP);
            insertriwayatP(d,p);
            cout<<endl;
                system("pause");
                system("cls");
                break;
        case 2:
            cout<<endl;
            cout << "Masukan Jenis Riwayat Pendidikan Pegawai (Formal / Non-Formal) : "; cin >> pegawai.jenisPW;
            cout << "Masukan Nama Pegawai : "; cin >> pegawai.namaPW;
            cout << "Masukan Telepon Pegawai : "; cin >> pegawai.teleponPW;
            cout << "Masukan Agama Pegawai : "; cin >> pegawai.agamaPW;
            q = createElmpegawai(pegawai);
            insertpegawai(m,q);
            cout<<endl;
                system("pause");
                system("cls");
                break;
        case 3:
            cout<<endl;
            findPegawai(m);
            cout<<endl;
                system("pause");
                system("cls");
                break;
        case 4:
            cout<<endl;
            cout << "Masukkan Nama Riwayat Pendidikan: ";
            cin >> riwayatP.namaRP;
            cout << "Masukkan Tahun Riwayat Pendidikan: ";
            cin >> riwayatP.tahunRP;
            cout << "Masukkan Nama Pegawai: ";
            cin >> pegawai.namaPW;
            insertRelasi(m,d,r,riwayatP,pegawai);
            cout<<endl;
                system("pause");
                system("cls");
                break;
        case 5:
            cout<<endl;
            caripegawaiRelasi(r,d);
            cout<<endl;
                system("pause");
                system("cls");
                break;
        case 6:
            cout<<endl;
            cout << "Masukkan Nama Riwayat Pendidikan yang mau dihapus: ";
            cin >> riwayatP.namaRP;
            cout << "Masukkan Tahun Riwayat Pendidikan: ";
            cin >> riwayatP.tahunRP;

            deleteriwayatP(d,r,riwayatP);
            cout<<endl;
                system("pause");
                system("cls");
                break;
        case 7:
            cout<<endl;
            cout << "----- Daftar yang akan dihapus -----" << endl;
            cout << "Masukkan Nama Riwayat Pendidikan: ";
            cin >> riwayatP.namaRP;
            cout << "Masukkan Tahun Riwayat Pendidikan: ";
            cin >> riwayatP.tahunRP;
            cout << "Masukkan Nama Pegawai yang mau dihapus: ";
            cin >> pegawai.namaPW;
            deletepegawai(m,r,pegawai,riwayatP);
                system("pause");
                system("cls");
                break;
        case 8:
            viewRelation(d,r);
                system("pause");
                system("cls");
                break;
        case 9:
            countriwayatP(m,r,pegawai,d,riwayatP);
                system("pause");
                system("cls");
                break;
        case 10:
            countPegawai(m,r,pegawai,d,riwayatP);
                system("pause");
                system("cls");
                break;
        case 11:
            system("cls");
            Tampilan();
                system("pause");
                system("cls");
                break;
        case 12:
            system("cls");
            viewNotRelation(d,m);
                system("pause");
                system("cls");
                break;
        case 0:
            cout << "PROGRAM EDUKASI KELUAR!!" << endl;
        }
    }
    return 0;
}
