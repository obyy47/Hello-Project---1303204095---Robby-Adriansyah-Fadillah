#include "edukasi.h"

/**

Faras Perdana Subianto Putra  - 1303204129
Robby Adriansyah Fadillah      - 1303204095

*/

void createListriwayatP(list_riwayatP &faras)
{
    first(faras) = NULL;
}
adr_riwayatP createElmriwayatP(riwayatP riwayatP)
{
    adr_riwayatP p = new elm_riwayatP;
    info(p) = riwayatP;
    next(p) = NULL;
    return p;
}
void createListpegawai(list_pegawai &farasP)
{
    first(farasP) = NULL;
    last(farasP) = NULL;
}
adr_pegawai createElmpegawai(pegawai pegawai)
{
    adr_pegawai p = new elm_pegawai;
    info(p) = pegawai;
    next(p) = NULL;
    return p;
}
void createListrelasi(list_relasi &farasPS)
{
    first(farasPS) = NULL;
    last(farasPS) = NULL;
}
adr_relasi createELmrelasi(list_relasi farasPS)
{
    adr_relasi p = new elm_relasi;
    next(p) = NULL;
    next(p) = NULL;
    next(p) = NULL;
    return p;
}

adr_pegawai searchpegawai(list_pegawai farasP, pegawai pegawai)
{
    adr_pegawai q = first(farasP);
    while (q != NULL){
        if (info(q).namaPW == pegawai.namaPW){
            return q;
        }
        q = next(q);
    }
    return NULL;
}
adr_riwayatP searchriwayatP(list_riwayatP faras, riwayatP riwayatP)
{
    adr_riwayatP p = first(faras);
    while (p != NULL){
        if (info(p).namaRP == riwayatP.namaRP && info(p).tahunRP == riwayatP.tahunRP){
            return p;
        }
        p = next(p);
    }
    return NULL;
}

void insertriwayatP(list_riwayatP &faras, adr_riwayatP P)
{
    /** Menggunakan Insert Last Single Linked List **/
    adr_riwayatP Q;
    if(first(faras) == NULL) {
        first(faras) = P;
    } else {
        Q = first(faras);
        while(next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
    cout << "PENAMBAHAN BERHASIL!" << endl;
}

void insertpegawai(list_pegawai &farasP, adr_pegawai q)
{
    /** Menggunakan insert First Circular Single linked list dengan Tambahan Pointer Last */

    if(first(farasP) == NULL){
         first(farasP) = q;
         last(farasP) = q;
         next(q) = q;
        next(last(farasP)) = NULL;
    } else {
        next(q) = first(farasP);
        first(farasP) = q;
        q = NULL;
        next(last(farasP)) = q;
    }
    cout << "PENAMBAHAN BERHASIL!" << endl;
}

void findPegawai(list_pegawai farasP)
{
    pegawai pegawai;
    adr_pegawai p = first(farasP);
    cout << "Masukkan Nama Pegawai: ";
    cin >> pegawai.namaPW;
     if (p == NULL){
        cout << "( EMPTY )" << endl;
    }
    while (p != NULL){
        if (info(p).namaPW == pegawai.namaPW){
                cout << "Jenis Riwayat Pendidikan Pegawai : " << info(p).jenisPW << endl;
                cout << "Nama Pegawai                     : " << info(p).namaPW << endl;
                cout << "Telepon Pegawai                  : " << info(p).teleponPW << endl;
                cout << "Agama Pegawai                    : " << info(p).agamaPW << endl;
        }
        p = next(p);
    }
}

void insertRelasi(list_pegawai farasP, list_riwayatP faras, list_relasi &farasPS, riwayatP riwayatP, pegawai pegawai)
{
    /** Menggunakan Insert First Double Linked List Circular **/

    adr_riwayatP p = searchriwayatP(faras,riwayatP);
    adr_pegawai q = searchpegawai(farasP,pegawai);
    adr_relasi rr = createELmrelasi(farasPS);
    if ( p != NULL && q != NULL && info(p).jenisRP == info(q).jenisPW){
        riwayatP(rr) = p;
        pegawai(rr) = q;
        if (first(farasPS) == NULL){
             first(farasPS) = rr;
             last(farasPS) = rr;
        } else{
            next(rr) = first(farasPS);
            prev(rr) = last(farasPS);
            first(farasPS) = rr;
            rr = NULL;
            next(last(farasPS)) = rr;
            prev(first(farasPS)) = rr;
        }
        cout << "BERHASIL DIRELASIKAN" << endl;
    } else if (p == NULL && q == NULL){
        cout << "TIDAK ADA DATA RIWAYAT PENDIDIKAN DAN DATA PEGAWAI!" << endl;
    } else if (p == NULL) {
        cout << "TIDAK ADA DATA RIWAYAT PENDIDIKAN!" << endl;
    } else if (q == NULL) {
        cout << "TIDAK ADA DATA PEGAWAI!" << endl;
    } else if (info(p).jenisRP != info(q).jenisPW) {
        cout << "TIDAK BISA DIRELASIKAN DIKARENAKAN JENIS PENDIDIKAN TIDAK SAMA!" << endl;
    }
}

void caripegawaiRelasi(list_relasi farasPS, list_riwayatP faras)
{
    riwayatP riwayatP;
    adr_riwayatP p = first(faras);
    adr_relasi rr = first(farasPS);
    cout << "Masukkan nama Riwayat Pendidikan : ";
    cin >> riwayatP.namaRP;
    cout << "Masukkan Tahun Riwayat Pendidikan : ";
    cin >> riwayatP.tahunRP;
    if (p != NULL){
            while (rr != NULL){
                pegawai pegawai;
                if (info(riwayatP(rr)).namaRP == riwayatP.namaRP && info(riwayatP(rr)).tahunRP == riwayatP.tahunRP && info(riwayatP(rr)).jenisRP == info(pegawai(rr)).jenisPW ){
                    cout << endl;
                    cout << "Nama Pegawai                     : " << info(pegawai(rr)).namaPW << endl;
                    cout << "Telepon Pegawai                  : " << info(pegawai(rr)).teleponPW << endl;
                    cout << "Agama Pegawai                    : " << info(pegawai(rr)).agamaPW << endl;
                    cout << "Jenis Riwayat Pendidikan Pegawai : " << info(pegawai(rr)).jenisPW;
                    cout << endl;
                }
                rr = next(rr);
            }

    } else {
        cout << "( KOSONG! )" << endl;
    }
}

void deleteAfterRelasi(list_relasi &farasPS, adr_relasi p)
{
    if (p == first(farasPS)){
        first(farasPS) = next(p);
    } else{
        adr_relasi rr = first(farasPS);
        while (next(rr) != p){
            rr = next(rr);
        }
        next(rr) = next(p);
    }
}

void deleteAfterpegawai(list_pegawai &farasP, adr_pegawai p)
{
        if (p == first(farasP)){
        first(farasP) = next(p);
    } else{
        adr_pegawai q = first(farasP);
        while (next(q) != p){
            q = next(q);
        }
        next(q) = next(p);
    }
}

void deleteAfterriwayatP(list_riwayatP &faras, adr_riwayatP p)
{
    if (p == first(faras)){
        first(faras) = next(p);
    } else {
        adr_riwayatP q = first(faras);
        while (next(q) != p){
            q = next(q);
        }
        next(q) = next(p);
    }
}

void deleteriwayatP(list_riwayatP &faras, list_relasi &farasPS, riwayatP riwayatP)
{
    adr_riwayatP p = searchriwayatP(faras,riwayatP);
    adr_relasi rr = first(farasPS);
    if (p != NULL){
        while (rr != NULL){
            if (riwayatP(rr) == p){
                riwayatP(rr) = NULL;
                pegawai(rr) = NULL;
                deleteAfterRelasi(farasPS,rr);
            }
            rr = next(rr);
        }
        if (p == first(faras)){
            first(faras) = next(p);
            next(p) = NULL;
        } else if (next(p) == NULL){
            adr_riwayatP t = first(faras);
            while (next(t) != p){
                t = next(t);
            }
            next(t) = next(p);
            next(p) = NULL;
        } else {
            deleteAfterriwayatP(faras,p);
        }
        cout << "PENGHAPUSAN BERHASIL" << endl;
    } else {
        cout << "( KOSONG! )" << endl;
    }
}

int menuEdukasi()
{
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t   [Dibuat Oleh Faras & Roby] " << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "1.  Menambahkan data riwayat pendidikan" << endl;
    cout << "2.  Menambahkan data pegawai" << endl;
    cout << "3.  Mencari data pegawai tertentu" << endl;
    cout << "4.  Menambahkan relasi data riwayat pendidikan dengan pegawai yang mengikutinya dan sebaliknya" << endl;
    cout << "5.  Mencari data pegawai yang memiliki riwayat pendidikan tertentu." << endl;
    cout << "6.  Menghapus data riwayat pendidikan beserta relasinya." << endl;
    cout << "7.  Menghapus data pegawai yang memiliki riwayat pendidikan tertentu." << endl;
    cout << "8.  Menampilkan seluruh data seluruh pegawai beserta riwayat pendidikannya." << endl;
    cout << "9.  Manampilkan data pegawai yang memiliki riwayat pendidikan terbanyak." << endl;
    cout << "10. Menampilkan data pendidikan yang paling banyak diikuti oleh pegawai." << endl;
    cout << "11. Main program" << endl;
    cout << "12. Menampilkan Data yang belum Direlasikan (Diluar Fungsi)" << endl;
    cout << "0.  Exit" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Pilihan menu : ";
    int pilihan;
    cin >> pilihan;

    return pilihan;
}

void Tampilan()
{
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t [Tampilan Aplikasi Edukasi] " << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "1.  Menambahkan data riwayat pendidikan" << endl;
    cout << "2.  Menambahkan data pegawai" << endl;
    cout << "3.  Mencari data pegawai tertentu" << endl;
    cout << "4.  Menambahkan relasi data riwayat pendidikan dengan pegawai yang mengikutinya dan sebaliknya" << endl;
    cout << "5.  Mencari data pegawai yang memiliki riwayat pendidikan tertentu." << endl;
    cout << "6.  Menghapus data riwayat pendidikan beserta relasinya." << endl;
    cout << "7.  Menghapus data pegawai yang memiliki riwayat pendidikan tertentu." << endl;
    cout << "8.  Menampilkan seluruh data seluruh pegawai beserta riwayat pendidikannya." << endl;
    cout << "9.  Manampilkan data pegawai yang memiliki riwayat pendidikan terbanyak." << endl;
    cout << "10. Menampilkan data pendidikan yang paling banyak diikuti oleh pegawai." << endl;
    cout << "11. Main program" << endl;
    cout << "12. Menampilkan Data yang belum Direlasikan (Diluar Fungsi)" << endl;
    cout << "0.  Exit" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Pilihan menu : ";
}

void viewNotRelation(list_riwayatP faras, list_pegawai farasP){
    adr_riwayatP p = first(faras);
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t    [Data Riwayat Pendidikan Dan Data Pegawai]" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Data Riwayat Pendidikan  : " << endl;
    if (p == NULL){
            cout << "[ KOSONG ], [ KOSONG ], [ KOSONG ], [ KOSONG ]" << endl;
    }else {
        while (p != NULL){
            cout << info(p).namaRP <<", " <<info(p).tahunRP << ", " <<info(p).kotaRP << ", " <<info(p).jenisRP;
            p = next(p);
            cout << endl;
        }
    }

    adr_pegawai q = first(farasP);
    cout << "Data Pegawai : "<< endl;
    if (q == NULL){
            cout << "[ KOSONG ], [ KOSONG ], [ KOSONG ], [ KOSONG ]" << endl;
    } else{
        while (q != NULL){
            cout << info(q).jenisPW << ", " <<info(q).namaPW << ", " <<info(q).teleponPW << ", " <<info(q).agamaPW;
            q = next(q);
            cout << endl;
        }

    }
    cout << "---------------------------------------------------------------------------------------------------" << endl;
}

void viewRelation(list_riwayatP faras, list_relasi farasPS)
{
    adr_riwayatP p = first(faras);
    adr_relasi rr = first(farasPS);
    if (p != NULL && rr != NULL){
        while (p != NULL){
            cout << "Nama Riwayat Pendidikan                      : " << info(p).namaRP << endl;
            cout << "Tahun Riwayat Pendidikan                     : " << info(p).tahunRP << endl;
            cout << "Kota Riwayat Pendidikan                      : " << info(p).kotaRP << endl;
            cout << "Jenis Riwayat Pendidikan (Formal/Non-Formal) : " << info(p).jenisRP << endl;
            cout << endl;
            cout << "------------------------- Riwayat Pendidikan yang memiliki Pegawai ------------------------- " << endl;
            adr_relasi rr = first(farasPS);
            while (rr != NULL){
                if (info(riwayatP(rr)).namaRP == info(p).namaRP && info(riwayatP(rr)).tahunRP == info(p).tahunRP){
                    cout << "Jenis Riwayat Pendidikan untuk Pegawai (Formal/Non-Formal) : " << info(pegawai(rr)).jenisPW<< endl;
                    cout << "Nama Pegawai                                               : " << info(pegawai(rr)).namaPW<< endl;
                    cout << "Nomor Telepon Pegawai                                      : " << info(pegawai(rr)).teleponPW<< endl;
                    cout << "Agama Pegawai                                              : " << info(pegawai(rr)).agamaPW<< endl;
                    cout << endl;
                }
                rr = next(rr);
            }

            cout << "---------------------------------------------------------------------------------------------------" << endl;
            p = next(p);
            cout <<""<< endl;
        }
    } else if (p != NULL && rr == NULL){
        while (p != NULL){
            cout << "Nama Riwayat Pendidikan                      : " << info(p).namaRP << endl;
            cout << "Tahun Riwayat Pendidikan                     : " << info(p).tahunRP << endl;
            cout << "Kota Riwayat Pendidikan                      : " << info(p).kotaRP << endl;
            cout << "Jenis RIwayat Pendidikan (Formal/Non-Formal) : " << info(p).jenisRP << endl;
            cout << endl;
            cout << "Jenis Riwayat Pendidikan untuk Pegawai (Formal/Non-Formal) : ( KOSONG )" << endl;
            cout << "Nama Pegawai                                               : ( KOSONG )" << endl;
            cout << "Nomor Telepon Pegawai                                      : ( KOSONG )" << endl;
            cout << "Agama Pegawai                                              : ( KOSONG )" << endl;
            cout << "---------------------------------------------------------------------------------------------------" << endl;
            p = next(p);
        }
    } else if (p == NULL && rr == NULL){
        cout << "Data Mahasiswa dan Data Makanan Favorite belum direlasikan" << endl;
        cout << "Nama Riwayat Pendidikan                      : ( KOSONG )" << endl;
        cout << "Tahun Riwayat Pendidikan                     : ( KOSONG )" << endl;
        cout << "Kota Riwayat Pendidikan                      : ( KOSONG )" << endl;
        cout << "Jenis RIwayat Pendidikan (Formal/Non-Formal) : ( KOSONG )" << endl;
        cout << endl;
        cout << "------------------------- Riwayat Pendidikan yang memiliki Pegawai ------------------------- " << endl;
        cout << "Jenis Riwayat Pendidikan untuk Pegawai (Formal/Non-Formal) : ( KOSONG )" << endl;
        cout << "Nama Pegawai                                               : ( KOSONG )" << endl;
        cout << "Nomor Telepon Pegawai                                      : ( KOSONG )" << endl;
        cout << "Agama Pegawai                                              : ( KOSONG )" << endl;
        cout << "---------------------------------------------------------------------------------------------------" << endl;
    }
}

void deletepegawai(list_pegawai &m, list_relasi &r, pegawai pegawai,riwayatP riwayatP)
{
    adr_pegawai q = searchpegawai(m, pegawai);
    adr_relasi rr = first(r);
    if (q != NULL){
        while (rr != NULL){
            if (pegawai(rr) == q && info(riwayatP(rr)).tahunRP == riwayatP.tahunRP && info(riwayatP(rr)).namaRP == riwayatP.namaRP && info(pegawai(rr)).jenisPW == info(riwayatP(rr)).jenisRP){
                pegawai(rr) = NULL;
                riwayatP(rr) = NULL;
                deleteAfterRelasi(r,rr);
            }
            rr = next(rr);
        }
        if (q == first(m)){
            first(m) = next(q);
            next(q) = NULL;
        } else if (next(q) == NULL){
            adr_pegawai o = first(m);
            while (next(o) != q){
                o = next(o);
            }
            next(o) = next(q);
            next(q) = NULL;
        } else {
            deleteAfterpegawai(m,q);
        }
        cout << "PENGHAPUSAN BERHASIL" << endl;
    } else {
        cout << "( EMPTY )" << endl;
    }
}

void countriwayatP(list_pegawai m,list_relasi r, pegawai pegawai, list_riwayatP d, riwayatP riwayatP)
{
    cout << "Masukkan Nama Pegawai :";
    cin >> pegawai.namaPW;
    adr_pegawai q = searchpegawai(m,pegawai);
    adr_relasi rr = first(r);
    int n;
    n = 0;
    while(rr != NULL){
        if(info(pegawai(rr)).namaPW == pegawai.namaPW){
            if(info(riwayatP(rr)).jenisRP == info(pegawai(rr)).jenisPW || info(riwayatP(rr)).tahunRP == riwayatP.tahunRP){
                n++;
            } else {
                cout << "Tidak ada Data! "<< endl;
            }
        }
        rr = next(rr);
    }
        if (q == NULL){
            cout << "( KOSONG )" << endl;
        } else {
            cout << "Jenis Riwayat Pendidikan untuk Pegawai (Formal/Non-Formal)         : " << info(q).jenisPW<< endl;
            cout << "Nama Pegawai                                                       : " << info(q).namaPW<< endl;
            cout << "Nomor Telepon Pegawai                                              : " << info(q).teleponPW<< endl;
            cout << "Agama Pegawai                                                      : " << info(q).agamaPW<< endl;
            cout << "Jumlah Data Pegawai ayang memiliki Riwayat Pendidikan sebanyak     : " << n << endl;
        }
}

void countPegawai(list_pegawai m,list_relasi r, pegawai pegawai, list_riwayatP d, riwayatP riwayatP)
{
    cout << "Masukkan Nama Riwayat Pendidikan :";
    cin >> riwayatP.namaRP;
    cout << "Masukkan Tahun Riwayat Pendidikan :";
    cin >> riwayatP.tahunRP;
    adr_riwayatP q = searchriwayatP(d,riwayatP);
    adr_relasi rr = first(r);
    int n;
    n = 0;
    while(rr != NULL){
        if(info(riwayatP(rr)).namaRP == riwayatP.namaRP && info(riwayatP(rr)).tahunRP == riwayatP.tahunRP){
            if(info(riwayatP(rr)).jenisRP == info(pegawai(rr)).jenisPW){
                n++;
            } else {
                cout << "Tidak ada Data! "<< endl;
            }
        }
        rr = next(rr);
    }
        if (q == NULL){
            cout << "( KOSONG )" << endl;
        } else {
            cout << "Nama Riwayat Pendidikan                      : " << info(q).namaRP << endl;
            cout << "Tahun Riwayat Pendidikan                     : " << info(q).tahunRP << endl;
            cout << "Kota Riwayat Pendidikan                      : " << info(q).kotaRP << endl;
            cout << "Jenis RIwayat Pendidikan (Formal/Non-Formal) : " << info(q).jenisRP << endl;
            cout << "Jumlah Data Riwayat Pendidikan sebanyak : " << n << endl;
        }
}
